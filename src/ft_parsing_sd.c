/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_sd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:11:09 by prossi            #+#    #+#             */
/*   Updated: 2018/03/06 14:02:47 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		ft_parsing_sd(t_stuff *e)
{
	if (e->b.buf[0] != '-')
		return (-1);
	if (!(e->b.tab = ft_strsplit(e->b.buf, '\n')))
		return (-1);
	if ((e->d.nbl = ft_counttabchar(e->b.tab)) == -1)
		return (-1);
	if (check_format(e) == -1)
		return (-1);
	if (e->d.nbmsph == 0 && e->d.nbmpla == 0 && e->d.nbmlight == 0 && e->d.nbmcyl == 0 && e->d.nbmcone == 0)
		return (-1);
	return (0);
}
