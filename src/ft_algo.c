/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 13:58:57 by afeuerst          #+#    #+#             */
/*   Updated: 2017/03/11 02:28:04 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void					ft_launch(const char *path, t_flag flag, const int set)
{
	DIR					*reper;
	static int			size;

	size = 2;
	reper = opendir(path);
	flag.total = 0;
	flag.bytes = 0;
	flag.link = 0;
	flag.size = 0;
	if (reper == NULL)
	{
		print(1, "ls : %s ", path);
		perror(NULL);
		return ;
	}
	if (!set)
		print(0, "\n\e[34m%s :\n\e[37m", path);
	while (ft_go(path, reper, flag, size))
	{
		size *= 2;
		closedir(reper);
		reper = opendir(path);
	}
	closedir(reper);
}

void					ft_open_r(const t_info *array, int n, t_flag f)
{
	while (n-- > 0)
	{
		f.total = 0;
		f.bytes = 0;
		f.link = 0;
		f.size = 0;
		f.group = 0;
		f.user = 0;
		if (S_ISDIR(array->mode) && !(*array->path == '.' &&
			(array->path[1] == '.' || !array->path[1])))
			ft_launch(array->fullpath, f, 0);
		array++;
	}
}

int						ft_process(t_flag flag, t_info *array, int index)
{
	ft_sort(flag, array, index);
	if (flag.l)
		print(0, "\e[1;34m[ total : %d ] [ count: %d ] [ Bytes : %d ]\e[1;37m\n"
				, flag.total, index, flag.bytes);
	ft_print_directory(array, index, flag);
	if (flag.r_r)
		ft_open_r(array, index, flag);
	ft_free(array, index);
	return (0);
}

static void				ft_no(t_info *array, char *p, char *s, struct stat chat)
{
	array->path = ft_copy(s);
	array->fullpath = ft_sstrjoin(p, s);
	array->dev = chat.st_rdev;
	ft_fill(array, chat);
}

int						ft_go(const char *p, DIR *r, t_flag f, int n)
{
	t_info			array[n];
	struct dirent	*tmp;
	struct stat		chat;
	int				index;

	index = 0;
	f.len = 0;
	while ((tmp = readdir(r)))
	{
		if (lstat(ft_stc_sstrjoin(p, tmp->d_name), &chat) == -1)
		{
			print(1, "ls : ");
			perror(NULL);
			continue ;
		}
		if (*tmp->d_name == '.' && !f.a)
			continue ;
		ft_no(array + index, (char*)p, tmp->d_name, chat);
		ft_thks(&f, &array[index]);
		f.total += chat.st_blocks;
		f.bytes += chat.st_size;
		if (++index >= n)
			return (1);
	}
	return (ft_process(f, array, index));
}
