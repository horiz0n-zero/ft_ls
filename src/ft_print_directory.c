/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_directory.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 13:59:30 by afeuerst          #+#    #+#             */
/*   Updated: 2017/03/05 19:03:04 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			ft_color(mode_t mode)
{
	if (S_ISBLK(mode))
		print(0, "\e[1;32m");
	else if (S_ISCHR(mode))
		print(0, "\e[1;32m");
	else if (S_ISDIR(mode))
		print(0, "\033[1;34m");
	else if (S_ISFIFO(mode))
		print(0,"\e[1;35m");
	else if (S_ISLNK(mode))
		print(0,"\e[1;35m");
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

void				ft_pb(t_info *array, int count, t_flag flag, int col)
{
	int				line;

	if (col && flag.len)
		line = col / flag.len;
	while (count-- > 0)
	{
		if (flag.l)
			ft_print_l(*array++, flag);
		else
		{
			print(0, "%* ", flag.len, array++->path);
			if (--line <= 0)
			{
				print(0, "\n");
				if (col && flag.len)
					line = col / flag.len;
			}
		}
	}
}

static void			ft_print_long(t_info *array, int count, t_flag flag)
{
	while (count-- > 0)
		ft_print_l(*array++, flag);
}

static void			ft_print_base(t_info *array, int count, t_flag flag)
{
	uint16_t		index;
	struct winsize	size;
	int				line;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
	index = 0;
	if (size.ws_col && flag.len)
		line = size.ws_col / flag.len;
	while (count-- > 0)
	{
		ft_color(array->mode);
		print(0, "%*\e[37m", flag.len, array->path);
		if (--line <= 0)
		{
			print(0, "\n");
			if (size.ws_col && flag.len)
				line = size.ws_col / flag.len;
		}
		array++;
	}
}

void				ft_print_directory(t_info *array, int count, t_flag flag)
{
	if (flag.l)
	{
		ft_print_long(array, count, flag);
	}
	else
	{
		ft_print_base(array, count, flag);
	}
}
