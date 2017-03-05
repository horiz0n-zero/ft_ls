/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 23:59:54 by afeuerst          #+#    #+#             */
/*   Updated: 2017/03/05 19:29:22 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "ft_ls.h"

static char			*ft_nnumber(char *const buffer, char *ptr, va_list *args)
{
	int				count;
	char			*str;
	int				len;

	len = 0;
	count = va_arg(*args, int);
	str = ft_stc_number(va_arg(*args, int));
	while (*str)
	{
		if (ptr >= (buffer + BUFFY))
			ptr = ft_clean(buffer);
		*ptr++ = *str++;
		len++;
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

static char			*ft_push(const char *s, char *const b, char *p, va_list *a)
{
	while (*s)
	{
		if (*s == '%')
		{
			if (*++s == '*')
				p = ft_star(b, p, a);
			else if (*s == 's')
				p = ft_push_str(b, p, a);
			else if (*s == 'd')
				p = ft_number(b, p, a);
			else if (*s == '#')
				p = ft_nnumber(b, p, a);
			else if (*s & 48)
				p = ft_nstar(b, p, a, *s - 48);
			s++;
		}
		else
		{
			if (p >= (b + BUFFY))
				p = ft_clean(b);
			*p++ = *s++;
		}
	}
	return (p);
}

void				print(const int set, const char *format, ...)
{
	static char		buffer[BUFFY + 8];
	static char		*progress = NULL;
	va_list			args;

	va_start(args, format);
	if (progress == NULL)
	{
		ft_memset_ll(buffer, 0, BUFFY/8 + 1);
		progress = buffer;
	}
	progress = ft_push(format, buffer, progress, &args);
	if (set)
	{
		write(1, buffer, ft_strlen_s(buffer));
		progress = buffer;
		ft_memset_ll(buffer, 0, BUFFY/8 + 1);
	}
	va_end(args);
}
