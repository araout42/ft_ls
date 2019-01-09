#ifndef FT_LS_H
# define FT_LS_H
# include "../libft/libft.h"
# include "stdio.h"
# include <sys/types.h>
# include <dirent.h>
char			*ft_get_options(int ac, char **av);
char			**ft_get_files_input(int ac, char **av);

struct dirent	**ft_get_dir(char **files);









#endif
