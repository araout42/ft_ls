/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strichr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 23:05:09 by mgheraie          #+#    #+#             */
/*   Updated: 2019/02/27 23:05:16 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strichr(char *s, int c, int i)
{
	while (s[++i])
	{
		if (s[i] == c)
			return (i);
	}
	return (-1);
}