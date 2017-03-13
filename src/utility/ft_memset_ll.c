/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_ll.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 02:57:01 by afeuerst          #+#    #+#             */
/*   Updated: 2017/03/06 00:37:13 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_memset(void *ptr, const int8_t value, size_t len)
{
	int8_t		*str;

	str = ptr;
	while (len-- > 0)
		*str++ = value;
}

void			ft_memset_ll(void *ptr, const int64_t value, size_t len)
{
	int64_t		*ll_ptr;

	ll_ptr = (int64_t*)ptr;
	while (len-- > 0)
		*ll_ptr++ = value;
}
