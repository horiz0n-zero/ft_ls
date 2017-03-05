/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 13:59:10 by afeuerst          #+#    #+#             */
/*   Updated: 2017/03/05 03:36:34 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			ft_fill(t_info *info, struct stat chat)
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
	t_info			new_array[count];
	int				index;

	index = 0;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
	save = count;
	while (save-- > 0)
	{
		if (S_ISDIR(array->mode))
		{
			array++;
			continue ;
		}
		if (S_ISLNK(array->mode))
		{
			array++;
			continue ;
		}
		if (LENI(array->path) > flag.len)
			flag.len = LENI(array->path) + 1;
		new_array[index++] = *array++;
	}
	if (flag.len != 0 && size.ws_col != 0)
		line = size.ws_col / flag.len;
	array = array - count;
	ft_pb(new_array, index, flag, size.ws_col);
}

static void			ft_print_arguments(t_info *array, int c, t_flag f, int s)
{
	int				first;
	char			buffer[8096];

	ft_memset_ll(buffer, 0, 1012);
	first = 1;
	ft_restrict_print(array, c, f);
	while (c-- > 0)
	{
		if (S_ISDIR(array->mode))
		{
			if (!first || c > 1)
				print(0, "\n\e[1;36m%s :\n\e[1;37m", array->fullpath);
			else
				first = 0;
			ft_launch(array->fullpath, f, 1);
		}
		if (S_ISLNK(array->mode))
		{
			if (readlink(array->fullpath, buffer, 8096) != -1)
			{
				if (!first && s > 0)
					print(0, "\n\e[1;35m%s :\n\e[1;37m", array++->fullpath);
				ft_launch(buffer, f, 1);
			}
		}
		array++;
		first = 0;
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
		if (lstat(*argv, &chat) == -1)
		{
			print(0, "ls : No such file or directory\n");
			// perror(*argv++); todo : a remplacer
			continue ;
		}
		array[index].path = ft_copy(*argv);
		array[index].fullpath = ft_copy(*argv++);
		ft_fill(&array[index++], chat);
	}
	ft_sort(flag, array, index);
	ft_print_arguments(array, index, flag, index);
}

int					main(int argc, char **argv)
{
	t_flag			flag;
	void			*path;

	path = NULL;
	flag.self = 0;
	flag.set = 1;
	print(0, "\e[1m");
	if (argc > 1)
		path = ft_parse_param(++argv, &flag);
	if (path != NULL)
		ft_arguments(path, flag, argc);
	else
		ft_launch(".", flag, 1);
	print(1, "");
}
