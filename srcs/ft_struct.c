/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 13:33:13 by mgheraie          #+#    #+#             */
/*   Updated: 2019/02/18 09:00:03 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dir		*init_lst(struct dirent *rep, char *filename, uint16_t flag)
{
	t_dir			*new;
	struct stat		buf;
	struct passwd	*usr;
	struct group	*grp;
	char			*s;
	char			*tmp;

	if (!(new = (t_dir *)ft_memalloc(sizeof(t_dir))))
		return (NULL);
	new->name = ft_strdup(rep->d_name);
	usr = NULL;
	grp = NULL;
	if (!(s = ft_strjoin(filename, "/")))
		return (NULL);
	tmp = s;
	if (!(s = ft_strjoin(s, rep->d_name)))
		return (NULL);
	ft_memdel((void *)&tmp);
	if ((stat(s, &buf)) < 0)
		return (NULL);
	errno = 0;
	new->pathname = s;
	new->type = rep->d_type;
	if((new->error = errno) < 0)
		return (new);
	new->mode = buf.st_mode;
	new->nlink = buf.st_nlink;
	new->size = buf.st_size;
	new->time = settime(buf, flag);
	if (!(usr = getpwuid(buf.st_uid)))
		return (NULL);
	new->usrname = usr->pw_name;
	if (!(grp = getgrgid(buf.st_gid)))
		return (NULL);
	new->grpname = grp->gr_name;
	if(flag & FLAGR && rep->d_type == DT_DIR && rep->d_name[0] != '.')
		new->next = read_dir(s, flag, NULL);
	else
		new->next = NULL;
	return (new);
}
