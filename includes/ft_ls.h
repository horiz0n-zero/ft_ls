/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 13:58:00 by afeuerst          #+#    #+#             */
/*   Updated: 2017/03/11 02:14:38 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H

# define FT_LS_H

# include <errno.h>
# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <sys/types.h>
# include <sys/ioctl.h>
# include <sys/xattr.h>
# include <time.h>
# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>
# include <grp.h>
# include <stdio.h>

typedef struct	s_flag
{
	char		t;
	char		l;
	char		a;
	char		r;
	char		r_r;
	int32_t		len;
	char		set;
	int32_t		total;
	int32_t		bytes;
	int32_t		link;
	int32_t		size;
	int32_t		name;
	int32_t		user;
	int32_t		group;
}				t_flag;

typedef struct	s_info
{
	char		*path;
	char		*fullpath;
	mode_t		mode;
	nlink_t		link;
	uid_t		uid;
	gid_t		gid;
	time_t		time;
	off_t		size;
	dev_t		dev;
}				t_info;

void			ft_sort(const t_flag flag, t_info *array, const int count);
void			ft_print_l(t_info info, t_flag flag);

typedef struct	s_global
{
	char		*buffer;
	int			size;
	int			len;
}				t_global;

void			ft_permission(const mode_t perm);
void			ft_file_type(const mode_t mode);
void			print(const int set, const char *format, ...);
void			ft_print_blk_chr(t_info *array, int count, t_flag flag);
char			*ft_group(const gid_t gid);
char			*ft_user(const uid_t uid);
void			ft_to_print(t_info *array, int count, t_flag flag);
int				ft_process(t_flag flag, t_info *array, int index);
void			ft_launch(const char *path, t_flag flag, const int set);
int				ft_go(const char *p, DIR *r, t_flag flag, int n);
void			ft_print_directory(t_info *a, int c, t_flag f);
void			ft_open_r(const t_info *array, int n, t_flag f);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_sstrjoin(const char *s1, const char *s2);
char			*ft_copy(const char *str);
size_t			ft_strlen_s(const char *str);
int				ft_strlen_i(const char *str);
char			*ft_stc_sstrjoin(const char *s1, const char *s2);
void			ft_free(t_info *array, int count);
void			ft_fill(t_info *info, struct stat chat);
void			ft_thks(t_flag *f, t_info *a);
void			ft_pb(t_info *array, int count, t_flag flag, int col);
char			**ft_parse_param(char **argv, t_flag *flag);
void			ft_memset_ll(void *const ptr, const int64_t value, size_t len);
void			ft_memset(void *ptr, const int8_t value, size_t len);
int				ft_intsize(int32_t nb);
#endif
