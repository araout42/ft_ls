#include "ft_ls.h"

static DIR		**ft_open_dir(char **files)
{
	int			i;
	DIR			**dirs;
	int			j;

	j = 0;
	i = 0;
	while (files[i])
		i++;
	dirs = (DIR **)ft_memalloc(sizeof(*dirs) * i);
	i--;
	while (j <= i)
	{
		dirs[j] = opendir(files[j]);
		if (dirs[j] == NULL)
		{
			perror("ERROR : ");
			j--;
		}
		j++;
	}
	return (dirs);
}

struct dirent	**ft_get_dir(char **files)
{
	int			i;
	DIR			**dirs;
	struct	dirent **s_dirs;
	
	while (files[i])
		i++;
	s_dirs = (struct dirent **)ft_memalloc(sizeof(*s_dirs) * i);
	dirs = ft_open_dir(files);
	i = 0;
	while ((*s_dirs = readdir(*dirs)) != NULL)
		printf("%s\n", (*s_dirs)->d_name);
	return (s_dirs);
}
