#include "ft_ls.h"

static struct stat		*ft_get_file_info(struct dirent *dir, char *file)
{
	struct stat			*buf;
	char				*pathname;
	char				*tmp;
	int					res;

	buf = (struct stat *)ft_memalloc(sizeof(*buf));
	if (dir != NULL)
	{
		pathname = ft_strjoin(file, "/");
		tmp = pathname;
		pathname = ft_strjoin(dir->d_name, file);
		res = lstat(pathname, buf);
		ft_memdel((void **)&tmp);
		ft_memdel((void **)&pathname);
		if (res < 0)
			return (NULL);
		return(buf);
	}
	else
		pathname = file;
	res = lstat(pathname, buf);
	if (res < 0)
		return (NULL);
	return (buf);
}

static t_list			*ft_create_list(char *files)
{
	t_list				*list;
	t_dir				*d;
	int					i;
	
	i = -1;
	d = (t_dir *)ft_memalloc(sizeof(*d) * MAX);
	d->name = files;
	if (!(d->dir = (struct dirent **)ft_memalloc(sizeof(d->dir) * MAX)))
		return (NULL);
	if (!(d->lstats = (struct stat **)ft_memalloc(sizeof(d->lstats) * MAX)))
		return (NULL);
	if ((d->dd = opendir(files)) == NULL)
	{
		if (!(d->lstats[i] = ft_get_file_info(NULL, files)))
			return (NULL);
	}
	else
		while ((d->dir[++i] = readdir(d->dd)) != NULL)
			d->lstats[i] = ft_get_file_info(d->dir[i], files);
	list = ft_lstnew((void *)d, sizeof(*d));
	return (list);
}

t_list					*ft_get_dir(char **files)
{
	int					i;
	t_list				*list;
	t_list				*head;

	list = NULL;
	i = 0;
	head = ft_create_list(files[0]);
	list = head;
	while (files[++i])
	{
		list->next = ft_create_list(files[i]);
		if (!list->next)
			perror(strerror(errno));
		else
			list = list->next;
	}
	return (head);
}
