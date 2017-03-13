/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 13:59:10 by afeuerst          #+#    #+#             */
/*   Updated: 2017/03/11 02:30:44 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			ft_to_open(t_info *array, int count, t_flag flag, int first)
{
	char			buffer[8096];
	int				save;

	save = count;
	if (count == 0)
		return ;
	ft_memset_ll(buffer, 0, 1012);
	while (count-- > 0)
	{
		if (first == 1 && save > 1)
		{
			print(0, "\e[1;34m%s :\n", array->fullpath);
		}
		if (S_ISDIR(array->mode))
		{
			ft_launch(array->fullpath, flag, first);
			if (save > 1 && count != 0)
				print(0, "\n");
		}
		array++;
		first = 0;
	}
}

static void			ft_pr_args(t_info *array, int c, t_flag f)
{
	t_info			to_open[c];
	t_info			to_print[c];
	int				index_open;
	int				index_print;

	index_open = 0;
	index_print = 0;
	while (c-- > 0)
	{
		if (S_ISDIR(array->mode))
		{
			to_open[index_open++] = *array++;
			continue ;
		}
		else
		{
			to_print[index_print++] = *array++;
			continue ;
		}
	}
	ft_to_print(to_print, index_print, f);
	if (index_print == 0)
		ft_to_open(to_open, index_open, f, 1);
	else
		ft_to_open(to_open, index_open, f, 0);
}

static void			ft_argument(char **argv, t_flag flag, const int argc, int i)
{
	struct stat		chat;
	t_info			array[argc];

	while (*argv)
	{
		if ((flag.l && lstat(*argv, &chat) == -1) || (!flag.l && \
			stat(*argv, &chat) == -1))
		{
			print(0, "ls: %s: No such file or directory\n", *argv++);
			continue ;
		}
		array[i].path = ft_copy(*argv);
		array[i].fullpath = ft_copy(*argv++);
		if (S_ISDIR(array->mode) || S_ISLNK(array->mode))
			;
		else
		{
			if (ft_strlen_i(array->path) > flag.len)
				flag.len = ft_strlen_i(array->path) + 1;
			flag.total += chat.st_blocks;
		}
		ft_fill(&array[i++], chat);
	}
	ft_sort(flag, array, i);
	ft_pr_args(array, i, flag);
}

int					main(int argc, char **argv)
{
	t_flag			flag;
	void			*path;

	path = NULL;
	ft_memset(&flag, 0, sizeof(t_flag));
	flag.set = 1;
	print(0, "\e[1m");
	if (argc > 1)
		path = ft_parse_param(++argv, &flag);
	if (path != NULL)
		ft_argument(path, flag, argc, 0);
	else
		ft_launch(".", flag, 1);
	print(1, "");
	return (0);
}
