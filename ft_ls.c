/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeblonde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 20:57:47 by jeblonde          #+#    #+#             */
/*   Updated: 2017/03/03 05:02:53 by jeblonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void				ft_fill(t_info *info, struct stat chat)
{
	info->mode = chat.st_mode;
	info->link = chat.st_nlink;
	info->uid = chat.st_uid;
	info->gid = chat.st_gid;
	info->time = chat.st_mtime;
	info->size = chat.st_size;
}

static void			ft_restrict_print(t_info *array, int count, t_flag flag)
{
	int				save;
	struct winsize	size;
	int				line;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
	save = count;
	while (save-- > 0)
	{
		if (LENI(array->path) > flag.len)
			flag.len = LENI(array->path);
		array++;
	}
	line = size.ws_col / flag.len;
	array = array - count;
	ft_pb(array, count, flag, size.ws_col);
}

static void			ft_print_arguments(t_info *array, int count, t_flag f)
{
	int				first;

	first = 1;
	ft_restrict_print(array, count, f);
	while (count-- > 0)
	{
		if (S_ISDIR(array->mode) && array->path[0] == '.' &&
				array->path[1] == '.')
		{
			ft_launch(array->fullpath, f, 0);
			continue ;
		}
		if (S_ISDIR(array->mode) && !(*array->path == '.' &&
			(array->path[1] == '.' || !array->path[1])))
		{
			printf("\n");
			ft_launch(array->fullpath, f, 1);
		}
		array++;
	}
}

static void			ft_arguments(char **argv, t_flag flag, const int argc)
{
	struct stat		chat;
	t_info			array[argc];
	int				index;

	index = 0;
	while (*argv)
	{
		if (stat(*argv, &chat) == -1)
		{
			write(1, "ls : ", 5);
			perror(*argv++);
			continue ;
		}
		array[index].path = ft_copy(*argv);
		array[index].fullpath = ft_copy(*argv++);
		ft_fill(&array[index++], chat);
	}
	ft_sort(flag, array, index);
	ft_print_arguments(array, index, flag);
}

int					main(int argc, char **argv)
{
	t_flag		flag;
	void		*path;

	path = NULL;
	flag.self = 0;
	if (argc > 1)
		path = ft_parse_param(++argv, &flag);
	if (path != NULL)
	{
		ft_arguments(path, flag, argc);
	}
	else
	{
		ft_launch(".", flag, 0);
	}
}
