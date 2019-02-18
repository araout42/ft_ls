/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 04:34:41 by araout            #+#    #+#             */
/*   Updated: 2019/02/18 07:58:46 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			sort_ascii(t_list **head)
{
	t_dir	*rep;
	t_list	*curr;
	void	*tmp;
	t_dir	*rep_next;

	curr = *head;
	while (curr && curr->next && (rep = (t_dir *)curr->content)
			&& (rep_next = (t_dir *)curr->next->content))
	{
		if (ft_strcmp(rep->pathname, rep_next->pathname) > 0)
		{
			tmp = curr->content;
			curr->content = curr->next->content;
			curr->next->content = tmp;
			curr = *head;
		}
		curr = curr->next;
	}
}


static void			sort_flag_rev(t_list **head)
{
	t_list	*curr;
	t_list	*end;
	int		i;
	int		j;

	i = 0;
	j = 0;
	curr = *head;
	end = *head;
	while (end && end->next)
	{
		end = end->next;
		i++;
	}
	while (i > j)
	{
		ft_swap_n(head, i, j);
		j++;
		i--;
	}
}
/*
static void			sort_flag_t(t_dir **rep)
{
}

static void			sort_flag_c(t_dir **rep)
{
}
*/

void				ft_sort_root(t_list **head, uint16_t flag)
{
	if (!(flag & FLAGT) && !(flag & FLAGC))
		sort_ascii(head);




	if ((flag & FLAGREV))
		sort_flag_rev(head);
}
