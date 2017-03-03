/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stc_strjoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeblonde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 00:01:41 by jeblonde          #+#    #+#             */
/*   Updated: 2017/03/03 01:50:37 by jeblonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			*ft_stc_sstrjoin(const char *s1, const char *s2)
{
	char		*ptr;
	static char	buffer[1012];

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	ft_memset_ll(buffer, 0, 1012/8);
	ptr = buffer;
	while (*s1)
		*ptr++ = *s1++;
	*ptr++ = '/';
	while (*s2)
		*ptr++ = *s2++;
	return (buffer);
}
