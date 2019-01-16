#include "ft_ls.h"

void		ft_display(t_list *head)
{
	struct dirent	**dir;
	t_dir			*dirs_struct;
	int				i;
	t_list			*list;
	int				j;
	
	j = 0;
	i = -1;
	list = head;
	while (list)
	{
		dirs_struct = list->content;
		dir = dirs_struct->dir;
		if ((list->next && j++) || (j != 0))
				printf("%s:\n", dirs_struct->name);
		while (dir[++i])
			printf("%s  ",dir[i]->d_name);
		if (list->next)
			printf("\n\n");
		else
		printf("\n");
		i = -1;
		list = list->next;
	}
}
