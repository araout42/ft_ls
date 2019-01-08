#include "ft_ls.h"

char		 **ft_get_files(int ac, char **av)
{
	char	**files;
	int		i;
	int		j;

	j = 0;
	files = (char **)ft_memalloc(sizeof(*files) * ac);
	i = 0;
	while (av[++i])
	{
		if ((av[i][0] == '-' && ft_strlen(av[i]) == 1) || av[i][0] != '-')
		{
			files[j] = av[i];
			j++;
		}
	}
	return (files);
}
