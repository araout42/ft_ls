#include "ft_ls.h"

void		ft_display(t_list *head)
{
	struct dirent	*dir;
	t_dir			*dirs_struct;
	int				i;
	t_list			*list;

	list = head;
	while (list)
	{
		i = 0;
		dirs_struct = list->content;
		dir = dirs_struct->dir[i];
		printf("%s :\n", dirs_struct->name);
		while (dir)
		{
			if (dirs_struct->dir[i + 1] && dir->d_name[0] != '.')
				printf("%s  ", dir->d_name);
			else if (dir->d_name[0] !=  '.')
				printf("%s", dir->d_name);
			dir = dirs_struct->dir[i++];
		}
		list = list->next;
		printf("\n\n");
	}
}
