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
		if (dir != NULL && (ft_list_size(head) > 1 || errno != 0))
			printf("%s :\n", dirs_struct->name);
		while (dir || dirs_struct->lstats[i])
		{
			if (!dir)
				printf("%s\n", dirs_struct->name);
			if (dirs_struct->dir[i] && dir->d_name[0] != '.')
				printf("%s  ", dir->d_name);
			else if (dir->d_name[0] !=  '.')
				printf("%s", dir->d_name);
			dir = dirs_struct->dir[i++];
		}
		list = list->next;
		if (list)
			printf("\n\n");
	}
}
