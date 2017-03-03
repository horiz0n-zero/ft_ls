/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_directory.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 13:59:30 by afeuerst          #+#    #+#             */
/*   Updated: 2017/03/03 13:59:32 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void					ft_pb(t_info *array, int count, t_flag flag, int col)
{
	int					line;

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
				line = col / flag.len;
			}
		}
	}
}

static void				ft_print_long(t_info *array, int count)
{
	while (count-- > 0)
		ft_print_l(*array++);
	printf("\n");
}

static void				ft_print_base(t_info *array, int count, t_flag flag)
{
	uint16_t			index;
	struct winsize		size;
	int					line;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
	index = 0;
	line = size.ws_col / flag.len;
	while (count-- > 0)
	{
		printf("%-*s ", flag.len, array->path);
		if (--line <= 0)
		{
			printf("\n");
			line = size.ws_col / flag.len;
		}
		array++;
	}
}

void			ft_print_directory(t_info *array, int count, t_flag flag)
{
	if (flag.l)
		ft_print_long(array, count);
	else
		ft_print_base(array, count, flag);
}
