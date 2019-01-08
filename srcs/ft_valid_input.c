#include "ft_ls.h"

char			*ft_get_options(int ac, char **av)
{
	int		i;
	char	*options;

	i = 0;
	(void)ac;
	options = ft_strnew(1);
	while (av[++i])
	{
		if (av[i][0] == '-' && ft_strlen(av[i]) > 1)
			options = ft_strjoin(options, av[i] + 1);
	}
	return (options);
}
