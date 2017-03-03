/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_ll.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeblonde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 03:59:18 by jeblonde          #+#    #+#             */
/*   Updated: 2017/03/03 01:50:19 by jeblonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>

void		ft_memset_ll(void *const ptr, const int64_t value, size_t len)
{
	int64_t	*ll_ptr;

	if (ptr == NULL)
		return ;
	ll_ptr = (int64_t*)ptr;
	while (len--)
		*ll_ptr++ = value;
}
