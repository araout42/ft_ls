#include "ft_ls.h"

int					main(int ac, char **av)
{
	char			**files;
	char			*options;
	struct dirent	**dir;
//	int				i;
	
//	i = 0;
	options = ft_get_options(ac, av);
	printf("%s\n", options);
	files = ft_get_files_input(ac, av);
	dir = ft_get_dir(files);
	printf("%s  ",(*dir)->d_name);
	return (0);
}
