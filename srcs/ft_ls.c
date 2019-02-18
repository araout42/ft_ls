/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 16:32:16 by mgheraie          #+#    #+#             */
/*   Updated: 2019/02/18 09:01:35 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_dir			*get_rep(char **av, uint16_t flag)
{
	t_dir		*rep;
	DIR			*dir;

	dir = NULL;
	if (!*av)
		rep = read_dir(".", flag, dir);
	else
	{
		while(*av)
		{
			if (flag == 2048)
			{
				rep = read_dir("-", flag, dir);
				flag -= 2048;
				}
			else
				rep = read_dir(*av, flag, dir);
			av++;
		}
	}
	return (rep);
}

static t_list			*to_list(t_dir *rep)
{
	t_list		*head;
	t_list		*curr;

	if (rep)
	{
		if (!(head = ft_lstnew((void *)rep, sizeof(*rep))))
			return (NULL);
		curr = head;
		while (rep->next)
		{
			if (!(curr->next = ft_lstnew((void *)rep->next, sizeof(*(rep->next)))))
				return (NULL);
			rep = rep->next;
			curr = curr->next;
		}
		return (head);
	}
	else 
		return (NULL);
}

int						main(int ac, char **av)
{
	uint16_t	flag;
	t_dir		*rep;
	t_list		*head;

	head = NULL;
	rep = NULL;
	ac++;
	av++;
	flag = getflag(av);
	if(flag == 4096)
		return (-1);
	while(*av && ft_strlen(*av) > 1 && **av == '-' )
		av++;
	rep = get_rep(av, flag);
	head = to_list(rep);
	rep = (t_dir *)head->content;
	ft_sort_root(&head, flag);
	ft_display_root(head, flag);
}
