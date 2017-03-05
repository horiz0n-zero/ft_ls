/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort__shell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 14:00:15 by afeuerst          #+#    #+#             */
/*   Updated: 2017/03/04 18:25:56 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void				ft_sort_reverse(t_info *array, int count)
{
	int					index;
	int					last;
	t_info				tmp;

	last = count - 1;
	index = 0;
	count /= 2;
	while (index < count)
	{
		tmp = *(array + index);
		*(array + index++) = *(array + last);
		*(array + last--) = tmp;
	}
}

static int				ft_sort_ascii(t_info a, t_info b)
{
	while (*a.path || *b.path)
	{
		if (*a.path != *b.path)
		{
			if (*a.path > *b.path)
				return (1);
			else
				return (0);
		}
		a.path++;
		b.path++;
	}
	return (0);
}

static int				ft_sort_time(t_info a, t_info b)
{
	return (a.time < b.time);
}

static void				ft_sort__shell(int count, t_info *array, f func)
{
	int				i;
	int				j;
	int				space;
	t_info			tmp;

	space = count / 2;
	i = 0;
	j = space;
	while (j > 0)
	{
		while (j < count)
		{
			if (func(*(array + i), *(array + j)))
			{
				tmp = *(array + i);
				*(array + i) = *(array + j);
				*(array + j) = tmp;
			}
			i++;
			j++;
		}
		i = 0;
		j = --space;
	}
}

void			ft_sort(const t_flag flag, t_info *array, const int count)
{
	if (flag.t)
		ft_sort__shell(count, array, ft_sort_time);
	else
		ft_sort__shell(count, array, ft_sort_ascii);
	if (flag.r)
		ft_sort_reverse(array, count);
}
