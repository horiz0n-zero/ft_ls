/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 01:05:38 by afeuerst          #+#    #+#             */
/*   Updated: 2017/03/05 04:51:37 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "ft_ls.h"

static char			*ft_get(int number, int number_, char *ptr)
{
	if (number < 0)
		(*ptr++ = '-') && (number = -number) && (number_ = number);
	if (number == 0)
		*ptr++ = '0';
	while (number)
	{
		ptr++;
		number /= 10;
	}
	while (number_)
	{
		*--ptr = number_ % 10 + 48;
		number_ /= 10;
	}
	return (ptr);
}

char				*ft_number(char *buffy, char *ptr, va_list *args)
{
	static char		buffer[8096];
	char			*ptr_buffer;
	int				number;

	ft_memset_ll(buffer, 0, 1013);
	number = va_arg(*args, int);
	ptr_buffer = ft_get(number, number, buffer);
	while (*ptr_buffer)
	{
		if (ptr >= (buffy + 8096))
		{
			write(1, buffy, 8096);
			ft_memset_ll(buffy, 0, 1013);
			ptr_buffer = buffy;
		}
		*ptr++ = *ptr_buffer++;
	}
	return (ptr);
}
