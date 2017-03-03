#ifndef FT_LS_H

# define FT_LS_H

#include <errno.h>
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
// supr :
# include <stdio.h>

typedef union	u_flag
{
	uint64_t	self;
	struct
	{
		char	l:1;
		char	_r:1;
		char	a:1;
		char	r:1;
		char	t:1;
		int		len;
	};
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
}				t_info;

typedef int (*f)(t_info a, t_info b);
void			ft_sort(const t_flag flag, t_info *array, const int count);
void			ft_print_l(t_info info);
typedef struct	s_global
{
	char		*buffer;
	int			size;
	int			len;
}				t_global;

void			ft_launch(const char *path, t_flag flag, const int set);
int				ft_opend(const char *path, DIR *reper, t_flag flag, int n);
void			ft_print_directory(t_info *array, int count, t_flag flag);
void			ft_open_r(const t_info *array, int n, t_flag f);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_sstrjoin(const char *s1, const char *s2);
char			*ft_copy(const char *str);
size_t			ft_strlen_s(const char *str);
int				ft_strlen_i(const char *str);
char			*ft_stc_sstrjoin(const char *s1, const char *s2);
# define LENS(str) ft_strlen_s(str)
# define LENI(str) ft_strlen_i(str)
void			ft_pb(t_info *array, int count, t_flag flag, int col);
void			ft_afficher(const t_global global, const t_info info, const char *path);
void			ft_tiny_printf(const char set, char *buf, const char *s, ...);
void			ft_got_path(char **argv, const t_flag flag, const int count);
char			**ft_parse_param(char **argv, t_flag *flag);
int				ft_call_ls(DIR *r, uint16_t n, size_t l, const t_flag flag, char *path);
void			ft_show_l(const struct dirent *array, uint16_t n);
//size_t			ft_strlen(const char *str);
//char			*ft_strjoin(const char *s1, const char *s2);
void			ft_memset_ll(void *const ptr, const int64_t value, size_t len);
//char			*ft_strcopy(const char *str);
void			ft_processing(const t_flag flag, char *path);
void			ft_print_file(const char *path, const t_flag flag);
void			ft_show_line(struct stat info, const char *path);
#endif
