/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 23:59:54 by afeuerst          #+#    #+#             */
/*   Updated: 2017/03/05 04:50:52 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "ft_ls.h"

static char			*ft_arg(char *str, char *buf, char *ptr, va_list *ar)
{
	char			*input;

	if (*str == '*')
		ptr = ft_star(buf, ptr, ar);
	else if (*str == 's' && *(str - 1) != '*')
	{
		input = va_arg(*ar, char*);
		while (*input)
		{
			if (ptr >= (buf + 8096))
				ft_clean(buf);
			*ptr++ = *input++;
		}
		str++;
	}
	else if (*str == 'd')
		ptr = ft_number(buf, ptr, ar);
	return (ptr);
}

static char				*ft_push(const char *str, char *buf, char *ptr, va_list *ar)
{
	while (*str)
	{
		if (ptr >= (buf + 8096))
		{
			write(1, buf, 8096);
			ft_memset_ll(buf, 0, 1013);
			ptr = buf;
		}
		if (*str == '%')
		{
			ptr = ft_arg((char*)++str, buf, ptr, ar);
			if (*--str == '*')
				str += 2;
			else if (*str == 's')
				str++;
			else if (*str == 'd')
				str++;
		}
		else
			*ptr++ = *str++;
	}
	return (ptr);
}

void				print(const int set, const char *format, ...)
{
	static char		buffer[8104];
	static char		*progress = NULL;
	va_list			args;

	va_start(args, format);
	if (progress == NULL)
	{
		ft_memset_ll(buffer, 0, 1013);
		progress = buffer;
	}
	progress = ft_push(format, buffer, progress, &args);
	if (set)
	{
		write(1, buffer, ft_strlen_s(buffer));
		progress = buffer;
		ft_memset_ll(buffer, 0, 1013);
	}
	va_end(args);
}
