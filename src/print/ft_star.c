/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_star.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 01:02:47 by afeuerst          #+#    #+#             */
/*   Updated: 2017/03/06 20:33:41 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "ft_ls.h"

char			*ft_clean(char *const buffer)
{
	write(1, buffer, BUFFY);
	ft_memset_ll(buffer, 0, BUFFY / 8 + 1);
	return (buffer);
}

char			*ft_nstar(char *const buffer, char *ptr, va_list *args, int n)
{
	char		*str;
	int			len;

	len = 0;
	str = va_arg(*args, char*);
	while (*str)
	{
		len++;
		if (ptr >= (buffer + BUFFY))
			ptr = ft_clean(buffer);
		*ptr++ = *str++;
	}
	n = n - len;
	while (n-- > 0)
	{
		if (ptr >= (buffer + BUFFY))
			ptr = ft_clean(buffer);
		*ptr++ = ' ';
	}
	return (ptr);
}

char			*ft_star(char *const buffer, char *ptr, va_list *args)
{
	int			count;
	char		*str;
	int			len;

	len = 0;
	count = va_arg(*args, int);
	str = va_arg(*args, char*);
	if (str == (void*)0)
		return (ptr);
	while (*str)
	{
		len++;
		if (ptr >= (buffer + BUFFY))
			ptr = ft_clean(buffer);
		*ptr++ = *str++;
	}
	count = count - len;
	while (count-- > 0)
	{
		if (ptr >= (buffer + BUFFY))
			ptr = ft_clean(buffer);
		*ptr++ = ' ';
	}
	return (ptr);
}
