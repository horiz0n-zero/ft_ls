/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stc_strjoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 14:01:37 by afeuerst          #+#    #+#             */
/*   Updated: 2017/03/03 20:41:38 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			*ft_stc_sstrjoin(const char *s1, const char *s2)
{
	char		*ptr;
	static char	buffer[8096];

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	ft_memset_ll(buffer, 0, 1012);
	ptr = buffer;
	while (*s1)
		*ptr++ = *s1++;
	*ptr++ = '/';
	while (*s2)
		*ptr++ = *s2++;
	return (buffer);
}
