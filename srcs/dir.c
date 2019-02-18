/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 01:46:57 by mgheraie          #+#    #+#             */
/*   Updated: 2019/02/18 06:59:57 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static DIR		*open_dir(char *name)
{
	DIR			*dir;

	if (!(dir = opendir(name)))
	{
		if (errno == 20)
			ft_printf("%s\n", name);
		else
			perror(name);
		return (NULL);
	}
	return (dir);
}

t_dir			*read_dir(char *name, uint16_t flag, DIR *dir)
{
	struct dirent	*rep;
	t_dir			*fst;
	t_dir			*tmp;

	if (!(dir = open_dir(name)))
		return (NULL);
	while ((rep = readdir(dir)))
	{
		if (ft_strcmp(rep->d_name, ".") == 0)
		{
			if (!(fst = init_lst(rep, name, flag)))
				return (NULL);
			tmp = fst;
		}
		else
		{
			if (!(tmp->next = init_lst(rep, name, flag)))
				return (NULL);
			while (tmp->next)
				tmp = tmp->next;
		}
	}
	closedir(dir);
	return (fst);
}
