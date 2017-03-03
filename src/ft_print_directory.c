/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_directory.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 13:59:30 by afeuerst          #+#    #+#             */
/*   Updated: 2017/03/03 22:21:37 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			ft_color(mode_t mode)
{
	if (S_ISBLK(mode))
		printf("\e[1;32m");
	else if (S_ISCHR(mode))
		printf("\e[1;32m");
	else if (S_ISDIR(mode))
		printf("\033[1;34m");
	else if (S_ISFIFO(mode))
		printf("\e[1;35m");
	else if (S_ISLNK(mode))
		printf("\e[1;36m");
	else if (S_ISREG(mode))
		return ;
	else if (S_ISSOCK(mode))
		printf("\e[1;97m");
	else
		printf("\e[1;32m");
}

void				ft_pb(t_info *array, int count, t_flag flag, int col)
{
	int				line;

	if (col && flag.len)
		line = col / flag.len;
	while (count-- > 0)
	{
		if (S_ISDIR(array->mode) && !(*array->path == '.' &&
			(array->path[1] == '.' || !array->path[1])))
			continue ;
		if (flag.l)
			ft_print_l(*array++);
		else
		{
			printf("%-*s ", flag.len, array++->path);
			if (--line <= 0)
			{
				printf("\n");
				if (col && flag.len)
					line = col / flag.len;
			}
		}
	}
}

static void			ft_print_long(t_info *array, int count, t_flag flag)
{
	while (count-- > 0)
		ft_print_l(*array++);
	(void)flag;
}

static void			ft_print_base(t_info *array, int count, t_flag flag)
{
	uint16_t		index;
	struct winsize	size;
	int				line;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
	index = 0;
	line = size.ws_col / flag.len;
	while (count-- > 0)
	{
		ft_color(array->mode);
		printf("%-*s", flag.len, array->path);
		if (--line <= 0)
		{
			printf("\n");
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
