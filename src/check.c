/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 13:58:36 by afeuerst          #+#    #+#             */
/*   Updated: 2017/03/11 01:18:55 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_exit(const char c)
{
	write(2, "ls: illegal option -- ", sizeof("ls: illegal option -- "));
	write(2, &c, 1);
	write(2, "\nusage: ls [-altrR] [file ...]\n", 31);
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
			flag->r_r = 1;
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
			if (*(*argv + 1) == '-' && *(*argv + 2) == 0 && *(argv + 1))
				return (++argv);
			else if (*(*argv + 1) == '-' && *(*argv + 2) == 0)
				return (NULL);
			else if (*(*argv + 1) == '\0')
				return (argv);
			else if (*((*argv) + 1) == '-' && *((*argv) + 2) != '\0')
				ft_exit('-');
			ft_get_param(*argv, flag);
			argv++;
		}
		else
			return (argv);
	}
	return (NULL);
}
