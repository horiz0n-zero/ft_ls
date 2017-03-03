/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeblonde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 20:57:47 by jeblonde          #+#    #+#             */
/*   Updated: 2017/03/03 03:19:12 by jeblonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			ft_not_found(const char *str)
{
	write(2, "ls : ", 5);
	perror(str);
}

static void				ft_fill(t_info *info, struct stat chat)
{
	info->mode = chat.st_mode;
	info->link = chat.st_nlink;
	info->uid = chat.st_uid;
	info->gid = chat.st_gid;
	info->time = chat.st_mtime;
	info->size = chat.st_size;
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
			ft_not_found(*argv++);
			continue ;
		}
		array[index].path = ft_copy(*argv);
		array[index].fullpath = ft_copy(*argv++);
		ft_fill(&array[index++], chat);
	}
	ft_sort(flag, array, index);
	ft_print_directory(array, index, flag);
	ft_open_r(array, index, flag);
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
		ft_arguments(path, flag, argc);
	else
		ft_launch(".", flag, 0);
}
