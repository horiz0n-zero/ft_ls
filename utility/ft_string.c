/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeblonde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 22:39:39 by jeblonde          #+#    #+#             */
/*   Updated: 2017/03/03 01:49:54 by jeblonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*ft_copy(const char *str)
{
	char	*ptr;
	char	*new;

	if (str == NULL)
		return (NULL);
	new = malloc(ft_strlen_s(str) + 1);
	ptr = new;
	while (*str)
		*ptr++ = *str++;
	*ptr = 0;
	return (new);
}

char		*ft_strjoin(const char *s1, const char *s2)
{
	char	*ptr;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = malloc(ft_strlen_s(s1) + ft_strlen_s(s2) + 1);
	ptr = str;
	while (*s1)
		*ptr++ = *s1++;
	while (*s2)
		*ptr++ = *s2++;
	*ptr = 0;
	return (str);
}

char		*ft_sstrjoin(const char *s1, const char *s2)
{
	char	*ptr;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = malloc(ft_strlen_s(s1) + ft_strlen_s(s2) + 2);
	ptr = str;
	while (*s1)
		*ptr++ = *s1++;
	*ptr++ = '/';
	while (*s2)
		*ptr++ = *s2++;
	*ptr = 0;
	return (str);
}

size_t		ft_strlen_s(const char *str)
{
	size_t	len;

	len = 0;
	if (str == NULL)
		return (0);
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

int			ft_strlen_i(const char *str)
{
	int		len;

	len = 0;
	if (str == NULL)
		return (0);
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}
