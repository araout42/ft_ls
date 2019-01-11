#include "libft.h"

int				ft_list_push_back(t_list **list, t_list *new)
{
	t_list		*tmp;

	if (new == NULL || list == NULL)
		return (0);
	if (*list == NULL)
	{
		*list = new;
		return (1);
	}
	tmp = *list;
	while (*list && (*list)->next)
		tmp = tmp->next;
	tmp->next = new;
	return (1);
}
