/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_norme.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 23:47:29 by afeuerst          #+#    #+#             */
/*   Updated: 2017/03/11 02:31:53 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void				ft_permission__(const mode_t perm, char *tab)
{
	tab[6] = perm & S_IROTH ? 'r' : '-';
	tab[7] = perm & S_IWOTH ? 'w' : '-';
	if ((S_ISVTX & perm) && (S_IXOTH & perm))
		tab[8] = 't';
	else if (S_ISVTX & perm)
		tab[8] = 'T';
	else
		tab[8] = perm & S_IXOTH ? 'x' : '-';
	tab[9] = 0;
	print(0, "%s", tab);
}

void					ft_permission(const mode_t perm)
{
	char				tab[10];

	tab[0] = perm & S_IRUSR ? 'r' : '-';
	tab[1] = perm & S_IWUSR ? 'w' : '-';
	if ((S_ISUID & perm) && (perm & S_IXUSR))
		tab[2] = 's';
	else if (S_ISUID & perm)
		tab[2] = 'S';
	else
		tab[2] = perm & S_IXUSR ? 'x' : '-';
	tab[3] = perm & S_IRGRP ? 'r' : '-';
	tab[4] = perm & S_IWGRP ? 'w' : '-';
	if ((S_ISGID & perm) && (perm & S_IRGRP))
		tab[5] = 'S';
	else if (S_ISGID & perm)
		tab[5] = 's';
	else
		tab[5] = perm & S_IXGRP ? 'x' : '-';
	ft_permission__(perm, tab);
}

void					ft_fill(t_info *info, struct stat chat)
{
	info->mode = chat.st_mode;
	info->link = chat.st_nlink;
	info->uid = chat.st_uid;
	info->gid = chat.st_gid;
	info->time = chat.st_mtime;
	info->size = chat.st_size;
}
