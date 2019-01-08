#include "ft_ls.h"

int main(int ac, char **av)
{
	int	i;
	char **files;

	i = -1;
	printf("OPTIONS : %s\n", ft_get_options(ac, av));
	files = ft_get_files(ac, av);
	while (files[++i])
		printf("FILE : %s\n", files[i]);
	return (0);
}
