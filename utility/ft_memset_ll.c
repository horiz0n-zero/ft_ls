/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_ll.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 14:01:09 by afeuerst          #+#    #+#             */
/*   Updated: 2017/03/03 14:01:21 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_memset_ll(void *const ptr, const int64_t value, size_t len)
{
	int64_t	*ll_ptr;

	if (ptr == NULL)
		return ;
	ll_ptr = (int64_t*)ptr;
	while (len--)
		*ll_ptr++ = value;
}
