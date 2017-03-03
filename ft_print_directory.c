/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_directory.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeblonde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 22:35:54 by jeblonde          #+#    #+#             */
/*   Updated: 2017/03/03 03:17:25 by jeblonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
