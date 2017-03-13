/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 19:31:57 by afeuerst          #+#    #+#             */
/*   Updated: 2017/03/10 23:53:53 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char				*ft_user(const uid_t uid)
{
	static char		buffer[80];
	static uid_t	current = ~0;
	char			*ptr;
	char			*progress;

	if (current != uid)
	{
		progress = buffer;
		ptr = getpwuid(uid)->pw_name;
		while (*ptr)
			*progress++ = *ptr++;
		*progress = 0;
	}
	return (buffer);
}

char				*ft_group(const gid_t gid)
{
	static char		buffer[80];
	static gid_t	current = ~0;
	char			*progress;
	char			*ptr;

	if (current != gid)
	{
		progress = buffer;
		ptr = getgrgid(gid)->gr_name;
		while (*ptr)
			*progress++ = *ptr++;
		*progress = 0;
	}
	return (buffer);
}

int					ft_intsize(int32_t nb)
{
	int				count;

	count = 0;
	while (nb)
	{
		count++;
		nb /= 10;
	}
	return (count);
}
