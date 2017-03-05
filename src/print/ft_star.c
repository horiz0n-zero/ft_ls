/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_star.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 01:02:47 by afeuerst          #+#    #+#             */
/*   Updated: 2017/03/05 04:51:13 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "ft_ls.h"

char			*ft_clean(char * const buffer)
{
	write(1, buffer, 8096);
	ft_memset_ll(buffer, 0, 1013);
	return (buffer);
}

char			*ft_star(char *buf, char *ptr, va_list *args)
{
	int				count;
	int				len;
	char			*str;

	count = va_arg(*args, int32_t);
	len = 0;
	str = va_arg(*args, char*);
	if (str == NULL)
		return (NULL);
	while (*str)
	{
		len++;
		if (ptr >= (buf + 8096))
			ptr = ft_clean(buf);
		*ptr++ = *str++;
	}
	count = count - len;
	while (count-- > 0)
	{
		if (ptr >= (buf + 8096))
			ptr = ft_clean(buf);
		*ptr++ = ' ';
	}
	return (ptr);
}
