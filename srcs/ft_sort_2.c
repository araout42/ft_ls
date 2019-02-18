/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 07:06:12 by araout            #+#    #+#             */
/*   Updated: 2019/02/18 07:58:08 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_swap_n(t_list **head, int j, int i)
{
	t_list	*to_i;
	t_list	*to_j;
	void	*tmp;

	to_i = *head;
	to_j = *head;
	while (i-- > 0)
		to_i = to_i->next;
	while (j-- > 0)
		to_j = to_j->next;
	tmp = to_i->content;
	to_i->content = to_j->content;
	to_j->content = tmp;
}


/*
void		sort_flag_u(t_dir **dir)
{
	
}
*/
