/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 03:26:45 by araout            #+#    #+#             */
/*   Updated: 2019/02/18 08:37:19 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_display_simple(t_list *head, uint16_t flag)
{
	t_dir	*rep;
	t_list	*curr;

	curr = head;
	while (curr && (rep = (t_dir *)curr->content))
	{
		if ((flag & FLAGM) && !(flag & FLAGA) && (*(rep->pathname+2) != '.')
				&& rep->next)
			ft_printf("%s, ", rep->pathname+2);
		else if ((flag & FLAGM) && (flag & FLAGA) &&  rep->next)
			ft_printf("%s, ", rep->pathname+2);
		else if (flag & FLAGA)
			ft_printf("%s\n", rep->pathname+2);
		else if (!(flag & FLAGA) && (*(rep->pathname+2) != '.'))
			ft_printf("%s\n", rep->pathname+2);
		curr = curr->next;
	}
}



void		ft_display_root(t_list *head, uint16_t flag)
{
	if (!(flag & FLAGF) && !(flag & FLAGI) && !(flag & FLAGL))
		ft_display_simple(head, flag);
}
