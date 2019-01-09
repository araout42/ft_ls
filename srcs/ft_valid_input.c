#include "ft_ls.h"

static void		ft_clear(char **options)
{
	int			i;
	int			j;
	char		tmp[ft_strlen(*options)];
	
	j = 0;
	i = 0;
	while ((*options)[i])
	{
		if (ft_strchr(tmp, (*options)[i]) == NULL)
			tmp[j++] = (*options)[i];
		i++;
	}
	tmp[j] = '\0';
	ft_strcpy(*options, tmp);
}

char			*ft_get_options(int ac, char **av)
{
	int			i;
	char		*options;

	i = 0;
	(void)ac;
	options = ft_strnew(1);
	while (av[++i])
	{
		if (av[i][0] == '-' && ft_strlen(av[i]) > 1)
			options = ft_strjoin(options, av[i] + 1);
	}
	ft_clear(&options);
	return (options);
}

char			 **ft_get_files_input(int ac, char **av)
{
	char		**files;
	int			i;
	int			j;

	j = 0;
	files = (char **)ft_memalloc(sizeof(*files) * ac);
	i = 0;
	while (av[++i])
	{
		if ((av[i][0] == '-' && ft_strlen(av[i]) == 1) || av[i][0] != '-')
		{
			files[j] = ft_strdup(av[i]);
			j++;
		}
	}
	return (files);
}


