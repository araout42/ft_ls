/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 16:32:42 by mgheraie          #+#    #+#             */
/*   Updated: 2019/02/18 07:55:02 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <errno.h>
# include "../libft/ft_printf.h"
# include <stdio.h>

typedef struct		s_dir
{
	char			*pathname;
	char			*name;
	uint8_t			type;
	uint16_t		mode;
	unsigned char	nlink;
	char			*usrname;
	char			*grpname;
	long long		size;
	time_t			time;
	struct s_dir	*rec;
	struct s_dir	*next;
	int				error;
}					t_dir;

# define ISROOT(x) ft_strcmp(x,".") == 0
# define ISBACK(x) ft_strcmp(x,"..") == 0
# define PUT ft_printf
# define PUTNAME(x) ft_printf("%s\t",x);
# define BLUE "\x1B[36m"
# define RED "\x1B[31m"
# define RESET "\x1B[0m"
# define ERROR return(NULL)
# define FREE(x) ft_strdel(x);

# define RU 1
# define WU 2
# define XU 4
# define RG 8
# define WG 16
# define XG 32
# define RO 64
# define WO 128
# define XO 256
# define ISREG 1
# define ISDIR 2
# define ISBLK 4
# define ISCHR 8
# define ISLNK 16
# define ISFIFO 32
# define ISSOCK 64
# define ISUNK 128
# define PTNAME(x) x->pathname
# define NAME(x) x->name
# define TYPE(x) x->type
# define MODE(x) x->mode
# define NLNK(x) x->nlink
# define UNAME(x) x->usrname
# define GNAME(x) x->grpname
# define SIZE(x) x->size
# define TIME(x) x->time
# define REC(x) x->rec
# define NEXT(x) x->next
# define FLAGL 1
# define FLAGR 2
# define FLAGA 4
# define FLAGREV 8
# define FLAGT 16
# define FLAGF 32
# define FLAGC 64
# define FLAGI 128
# define FLAGU 256
# define FLAG1 512
# define FLAGM 1024

int			ft_isflagls(char c);
void		ft_checkflag(char c, uint16_t *flag);
uint16_t	getflag(char **av);
void		*read_error(char *name);
uint8_t		ft_setmode(mode_t i);
time_t		settime(struct stat buf, uint16_t flag);
uint16_t	error_flag(char c);
DIR			*open_error(char *filename);
DIR			**open_all(char **files, int size);
DIR			*open_mydir(char *dirname);
t_dir		*read_dir(char *filename, uint16_t flag, DIR *dir);
t_dir		*init_lst(struct dirent *rep, char *filename, uint16_t flag);
void		ft_display_root(t_list *head, uint16_t flag);
void		ft_sort_root(t_list **head, uint16_t flag);
void		sort_flag_u(t_dir **dir);
void		ft_swap_n(t_list **head, int j, int i);

#endif
