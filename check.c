/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeblonde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 20:57:31 by jeblonde          #+#    #+#             */
/*   Updated: 2017/03/03 03:06:01 by jeblonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_exit(const char c)
{
	write(1, "ls: illegal option -- ", sizeof("ls: illegal option -- "));
	write(1, &c, 1);
	write(1, "\nusage: ls [-altrR] [file ...]\n", 31);
	exit(1);
}

static void		ft_get_param(const char *arguments, t_flag *const flag)
{
	if (*++arguments == '\0')
		return ;
	while (*arguments)
	{
		if (*arguments == 'l')
			flag->l = 1;
		else if (*arguments == 't')
			flag->t = 1;
		else if (*arguments == 'a')
			flag->a = 1;
		else if (*arguments == 'R')
			flag->_r = 1;
		else if (*arguments == 'r')
			flag->r = 1;
		else
			ft_exit(*arguments);
		arguments++;
	}
}

char			**ft_parse_param(char **argv, t_flag *const flag)
{
	while (*argv)
	{
		if (**argv == '-')
		{
			if (*(*argv + 1) == '-')
				return (++argv);
			else if (*(*argv + 1) == '\0')
				return (argv);
			ft_get_param(*argv, flag);
			argv++;
		}
		else
			return (argv);
	}
	return (NULL);
}
