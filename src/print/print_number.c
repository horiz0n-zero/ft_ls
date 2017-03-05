/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 01:05:38 by afeuerst          #+#    #+#             */
/*   Updated: 2017/03/05 19:20:53 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "ft_ls.h"

char				*ft_stc_number(int number)
{
	int				save;
	static char		buffer[24];
	char			*ptr;

	ptr = buffer;
	save = number;
	ft_memset_ll(buffer, 0, 3);
	if (number == 0)
		*ptr++ = '0';
	while (number)
	{
		ptr++;
		number /= 10;
	}
	while (save)
	{
		*--ptr = save % 10 + 48;
		save /= 10;
	}
	return (buffer);
}

char				*ft_number(char *const buffer, char *ptr, va_list *args)
{
	char	*str;

	str = ft_stc_number(va_arg(*args, int));
	while (*str)
	{
		if (ptr >= (buffer + BUFFY))
			ptr = ft_clean(buffer);
		*ptr++ = *str++;
	}
	return (ptr);
}
