#include "ft_ls.h"

void		ft_sort_list_time()
{
return ;
}

static void		ft_sort_tabs_alpha(t_list *list)
{
	int		i;
	struct dirent	*tmp;
	struct stat		*tmpstat;
	t_dir	*dir;
	struct dirent	**tab;

	i = 0;
	dir =list->content;
	tab = dir->dir;
	while (tab[i] && tab[i + 1])
	{
		tmp = tab[i];
		tmpstat = dir->lstats[i];
		if (ft_before_alpha(tab[i]->d_name, tab[i + 1]->d_name) < 0)
		{
			tab[i] = tab[i + 1];
			dir->lstats[i] = dir->lstats[i + 1];
			tab[i + 1] = tmp;
			dir->lstats[i + 1] = tmpstat;
			i = 0;
		}
		i++;
	}
	return ;
}

static void		ft_sort_list_alphabet(t_list *list)
{
	t_dir		*dir;
	t_dir		*dir_2;
	t_list		*head;
	void		*tmp;

	head = list;
	while (list && list->next)
	{
		tmp = list->content;
		dir = list->content;
		dir_2 = list->next->content;
		if (ft_before_alpha(dir->name, dir_2->name) < 0)
		{
			list->content = list->next->content;
			list->next->content = tmp;
			list = head;
		}
		else
			list = list->next;
	}
	return ;
}

void			ft_sort_root(t_list *list, int type)
{
	if (type == 1)
	{
		ft_sort_list_alphabet(list);
		while (list)
		{
			ft_sort_tabs_alpha(list);
			list = list->next;
		}
	}
}
