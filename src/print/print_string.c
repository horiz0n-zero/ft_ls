/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 18:20:27 by afeuerst          #+#    #+#             */
/*   Updated: 2017/03/05 19:11:47 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "ft_ls.h"

char			*ft_push_str(char *const buffer, char *progress, va_list *args)
{
	char		*str;

	str = va_arg(*args, char*);
	while (*str)
	{
		if (progress >= (buffer + BUFFY))
			progress = ft_clean(buffer);
		*progress++ = *str++;
	}
	return (progress);
}
