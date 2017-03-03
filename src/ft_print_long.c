/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 13:59:48 by afeuerst          #+#    #+#             */
/*   Updated: 2017/03/03 17:33:10 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			ft_file_type(const mode_t mode)
{
	if (S_ISBLK(mode))
		printf("b");
	else if (S_ISCHR(mode))
		printf("c");
	else if (S_ISDIR(mode))
		printf("d");
	else if (S_ISFIFO(mode))
		printf("p");
	else if (S_ISLNK(mode))
		printf("l");
	else if (S_ISREG(mode))
		printf("-");
	else if (S_ISSOCK(mode))
		printf("s");
	else
		printf("?");
}

static void			ft_permission(const mode_t perm)
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
	printf("%s", tab);
}

static char			*ft_time(char *str)
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

static void			ft_color(mode_t mode)
{
	if (S_ISBLK(mode))
		printf("\e[1;32m");
	else if (S_ISCHR(mode))
		printf("\e[1;32m");
	else if (S_ISDIR(mode))
		printf("\033[1;34m");
	else if (S_ISFIFO(mode))
		printf("\e[1;35m");
	else if (S_ISLNK(mode))
		printf("\e[1;36m");
	else if (S_ISREG(mode))
		return ;
	else if (S_ISSOCK(mode))
		printf("\e[1;97m");
	else
		printf("\e[1;32m");
}

void			ft_print_l(t_info info)
{
	ft_file_type(info.mode);
	ft_permission(info.mode);
	printf(" %3d %s ", info.link, getpwuid(info.uid)->pw_name);
	printf("%7s %6lld", getgrgid(info.gid)->gr_name, info.size);
	printf(" %s ", ft_time(ctime(&info.time)));
	ft_color(info.mode);
	printf("%s\e[37m\n", info.path);
}
