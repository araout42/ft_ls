#include "ft_ls.h"

void		ft_display(t_list *list)
{

	struct dirent	*dir;
	t_dir			*dirs_struct;
	int				i;

	while (list)
	{
		i = 0;
		dirs_struct = list->content;
		dir = dirs_struct->dir[i];
		if (!dir)
			printf("%s\n", dirs_struct->name);
		while (dir)
		{
			if (dirs_struct->dir[i + 1] && dir->d_name[0] != '.')
				printf("%s\t", dir->d_name);
			else if (dir->d_name[0] !=  '.')
				printf("%s", dir->d_name);
			i++;
			dir = dirs_struct->dir[i];
		}
		list = list->next;
	}
}
