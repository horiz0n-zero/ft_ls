/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_thanks_to_the_norme.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 19:38:08 by afeuerst          #+#    #+#             */
/*   Updated: 2017/03/10 23:56:37 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				ft_thks(t_flag *f, t_info *array)
{
	static uid_t	user = ~0;
	static gid_t	group = ~0;

	if (user != array->uid)
	{
		user = array->uid;
		if (ft_strlen_i(getpwuid(user)->pw_name) > f->user)
			f->user = ft_strlen_i(getpwuid(user)->pw_name) + 1;
	}
	if (group != array->gid)
	{
		group = array->gid;
		if (ft_strlen_i(getgrgid(group)->gr_name) > f->group)
			f->group = ft_strlen_i(getgrgid(group)->gr_name) + 1;
	}
	if (ft_strlen_i(array->path) > f->len)
		f->len = ft_strlen_i(array->path) + 1;
	if (ft_intsize(array->size) > f->size)
		f->size = ft_intsize(array->size) + 1;
	if (ft_intsize(array->link) > f->link)
		f->link = ft_intsize(array->link) + 1;
}
