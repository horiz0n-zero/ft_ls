/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blk_chr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 01:39:11 by afeuerst          #+#    #+#             */
/*   Updated: 2017/03/11 02:23:22 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char				*ft_time(char *str)
{
	char				*ptr;

	while (*str != ' ')
		str++;
	str++;
	ptr = str;
	while (*str)
		str++;
	str -= 9;
	*str = '\0';
	return (ptr);
}

static void				ft_color(mode_t mode)
{
	if (S_ISBLK(mode))
		print(0, "\e[1;32m");
	else if (S_ISCHR(mode))
		print(0, "\e[1;32m");
	else if (S_ISDIR(mode))
		print(0, "\e[1;34m");
	else if (S_ISFIFO(mode))
		print(0, "\e[1;35m");
	else if (S_ISLNK(mode))
		print(0, "\e[1;35m");
	else if (S_ISREG(mode))
	{
		if ((mode & S_IXUSR) || (mode & S_IXGRP))
			print(0, "\e[0;31m");
		else
			return ;
	}
	else if (S_ISSOCK(mode))
		print(0, "\e[1;92m");
	else
		print(0, "\e[1;32m");
}

void					ft_print_l_chr(t_info info, t_flag flag)
{
	static char			buffer[8096];

	ft_memset_ll(buffer, 0, 1012);
	ft_file_type(info.mode);
	ft_permission(info.mode);
	print(0, " %# %* ", flag.link, info.link, flag.user, ft_user(info.uid));
	print(0, "%* %d, %d ", flag.group, ft_group(info.gid),
			((int32_t)((info.dev) & 0xffffff)),
			((int32_t)(((u_int32_t)(info.dev) >> 24) & 0xff)));
	print(0, "%s ", ft_time(ctime(&info.time)));
	ft_color(info.mode);
	print(0, "%*\e[1;37m", flag.len, info.path);
	if (S_ISLNK(info.mode))
	{
		if (readlink(info.fullpath, buffer, 8096) != -1)
			print(0, "\e[1;36m -->> %s\n\e[1;37m", buffer);
		else
			print(0, "\n\e[1;31macces denied : %s\n\e[1;37m", info.path);
	}
	else
		print(0, "\n");
}

void					ft_print_blk_chr(t_info *array, int count, t_flag flag)
{
	while (count-- > 0)
		ft_print_l_chr(*array++, flag);
}
