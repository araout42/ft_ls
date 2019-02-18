/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 17:27:03 by mgheraie          #+#    #+#             */
/*   Updated: 2019/02/14 01:45:47 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_puttype(struct dirent *dir)
{
	int			type;

	type = dir->d_type;
	(type == DT_REG) ? ft_putchar('-') : 0;
	(type == DT_DIR) ? ft_putchar('d') : 0;
	(type == DT_BLK) ? ft_putchar('b') : 0;
	(type == DT_CHR) ? ft_putchar('c') : 0;
	(type == DT_LNK) ? ft_putchar('l') : 0;
	(type == DT_FIFO) ? ft_putchar('p') : 0;
	(type == DT_SOCK) ? ft_putchar('s') : 0;
}
