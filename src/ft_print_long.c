/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 13:59:48 by afeuerst          #+#    #+#             */
/*   Updated: 2017/03/05 04:15:38 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void					ft_file_type(const mode_t mode)
{
	if (S_ISBLK(mode))
		print(0, "b");
	else if (S_ISCHR(mode))
		print(0, "c");
	else if (S_ISDIR(mode))
		print(0, "d");
	else if (S_ISFIFO(mode))
		print(0, "p");
	else if (S_ISLNK(mode))
		print(0, "l");
	else if (S_ISREG(mode))
		print(0, "-");
	else if (S_ISSOCK(mode))
		print(0, "s");
	else
		print(0, "?");
}

static void					ft_permission(const mode_t perm)
{
	char			tab[10];

	tab[0] = perm & S_IRUSR ? 'r' : '-';
	tab[1] = perm & S_IWUSR ? 'w' : '-';
	tab[2] = perm & S_IXUSR ? 'x' : '-';
	tab[3] = perm & S_IRGRP ? 'r' : '-';
	tab[4] = perm & S_IWGRP ? 'w' : '-';
	tab[5] = perm & S_IXGRP ? 'x' : '-';
	tab[6] = perm & S_IROTH ? 'r' : '-';
	tab[7] = perm & S_IWOTH ? 'w' : '-';
	tab[8] = perm & S_IXOTH ? 'x' : '-';
	tab[9] = 0;
	print(0, "%s", tab);
}

static char					*ft_time(char *str)
{
	char			*ptr;

	while (*str != ' ')
		str++;
	str++;
	ptr = str;
	while (*str)
		str++;
	str -= 9;
	*str = '\0';
	return (ptr);
}

static void					ft_color(mode_t mode)
{
	if (S_ISBLK(mode))
		print(0, "\e[1;32m");
	else if (S_ISCHR(mode))
		print(0, "\e[1;32m");
	else if (S_ISDIR(mode))
		print(0, "\033[1;34m");
	else if (S_ISFIFO(mode))
		print(0, "\e[1;35m");
	else if (S_ISLNK(mode))
		print(0, "\e[1;35m");
	else if (S_ISREG(mode))
	{
		if ((mode & S_IXUSR) || (mode & S_IXGRP))
			print(0, "\e[0;31m");
		else
			return ;
	}
	else if (S_ISSOCK(mode))
		print(0, "\e[1;92m");
	else
		print(0, "\e[1;32m");
}

void					ft_print_l(t_info info, t_flag flag)
{
	static char			buffer[8096];

	ft_memset_ll(buffer, 0, 1012);
	ft_file_type(info.mode);
	ft_permission(info.mode);
	print(0, " %3d %s ", info.link, getpwuid(info.uid)->pw_name);
	print(0, "%7s %6lld", getgrgid(info.gid)->gr_name, info.size);
	print(0, " %s ", ft_time(ctime(&info.time)));
	ft_color(info.mode);
	print(0, "%*s\e[1;37m", flag.len, info.path);
	if (S_ISLNK(info.mode))
	{
		if (readlink(info.fullpath, buffer, 8096) != -1)
		{
			print(0, "\e[1;36m -->> %s\n\e[1;37m", buffer);
		}
		else
		{
			print(0, "\n\e[1;31macces denied : %s\n\e[1;37m", info.path);
		}
	}
	else
		print(0, "\n");
}
