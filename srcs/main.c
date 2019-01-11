#include "ft_ls.h"

int					main(int ac, char **av)
{
	char			**files;
	t_list			*list;
	//char			*options;

	//options = ft_get_options(ac, av);
	files = ft_get_files_input(ac, av);
	list = ft_get_dir(files);
	ft_display(list);
	return (0);
}
