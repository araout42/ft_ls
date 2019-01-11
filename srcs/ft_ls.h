#ifndef FT_LS_H
# define FT_LS_H
# include <sys/types.h>
# include <sys/stat.h>
# include "../libft/libft.h"
# include "stdio.h"
# include <errno.h>
# include <dirent.h>
# define MAX 10000
typedef struct s_dirs
{
	struct dirent	**dir;
	struct stat		**lstats;
	DIR				*dd;
	char			*name;
}				t_dir;

char			*ft_get_options(int ac, char **av);
char			**ft_get_files_input(int ac, char **av);
t_list			*ft_get_dir(char **files);
void			ft_display(t_list *list);









#endif
