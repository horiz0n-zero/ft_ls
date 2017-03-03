/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeblonde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 23:51:55 by jeblonde          #+#    #+#             */
/*   Updated: 2017/03/03 02:46:42 by jeblonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void				ft_unfind(const char *path)
{
	printf("%s no such file or directory\n", path);
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

void					ft_launch(const char *path, t_flag flag, const int set)
{
	DIR					*reper;
	int					size;

	size = 2;
	reper = opendir(path);
	if (reper == NULL)
	{
		ft_unfind(path);
		return ;
	}
	if (set)
		printf("\e[34m%s :\n\e[37m", path);
	while (ft_opend(path, reper, flag, size))
	{
		size *= 2;
		closedir(reper);
		reper = opendir(path);
	}
	closedir(reper);
}

void				ft_open_r(const t_info *array, int n, t_flag f)
{
	while (n-- > 0)
	{
		if (S_ISDIR(array->mode) && !(*array->path == '.' &&
			(array->path[1] == '.' || !array->path[1])))
			ft_launch(array->fullpath, f, 1);
		array++;
	}
}

int					ft_opend(const char *path, DIR *reper, t_flag flag, int n)
{
	t_info			array[n];
	struct dirent	*tmp;
	struct stat		chat;
	int				index;

	index = 0;
	while ((tmp = readdir(reper)))
	{
		if (stat(ft_stc_sstrjoin(path, tmp->d_name), &chat) == -1)
			continue ;
		if (*tmp->d_name == '.' && !flag.a)
			continue ;
		array[index].path = ft_copy(tmp->d_name);
		array[index].fullpath = ft_sstrjoin(path, tmp->d_name);
		ft_fill(&array[index], chat);
		if (LENI(array[index].path) > flag.len)
			flag.len = LENI(array[index].path);
		if (++index >= n)
			return (1);
	}
	ft_sort(flag, array, index);
	ft_print_directory(array, index, flag);
	if (flag._r)
		ft_open_r(array, index, flag);
	return (0);
}
