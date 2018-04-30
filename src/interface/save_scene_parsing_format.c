/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_scene_parsing_format.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 21:11:01 by prossi            #+#    #+#             */
/*   Updated: 2018/04/17 21:16:56 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		parsing_format_each_objet(t_stuff *e)
{
	int		y;

	y = -1;
	while (++y < e->i.load.nbl)
	{
		if (ft_strcmp(e->i.load.tab_load[y], "SPHERE") == 0)
			if (parsing_sphere(e, y) == -1)
				return (-1);
		if (ft_strcmp(e->i.load.tab_load[y], "PLAN") == 0)
			if (parsing_plan(e, y) == -1)
				return (-1);
		if (ft_strcmp(e->i.load.tab_load[y], "LIGHT") == 0)
			if (parsing_light(e, y) == -1)
				return (-1);
		if (ft_strcmp(e->i.load.tab_load[y], "CYLINDRE") == 0)
			if (parsing_cylindre(e, y) == -1)
				return (-1);
		if (ft_strcmp(e->i.load.tab_load[y], "CONE") == 0)
			if (parsing_cone(e, y) == -1)
				return (-1);
	}
	free_tab_parsing(e);
	return (0);
}

int		parsing_format(t_stuff *e)
{
	if (e->i.load.buf[0] != '-')
		return (-1);
	if (!(e->i.load.tab_load = ft_strsplit(e->i.load.buf, '\n')))
		return (-1);
	e->i.load.nbl = ft_counttabchar(e->i.load.tab_load);
	if (ft_strcmp(e->i.load.tab_load[0], "------") != 0)
		return (-1);
	if (ft_strcmp(e->i.load.tab_load[e->i.load.nbl - 1], "------") != 0)
		return (-1);
	e->i.load.nsph = 0;
	e->i.load.nlight = 0;
	e->i.load.npla = 0;
	e->i.load.ncyl = 0;
	e->i.load.ncone = 0;
	if (parsing_format_each_objet(e) == -1)
		return (-1);
	del_excessed_mail(e);
	reboot_list_loop(e, 3);
	empty_list(e);
	e->d.nbmsph = e->i.load.nsph;
	e->d.nbmpla = e->i.load.npla;
	e->d.nbmlight = e->i.load.nlight;
	e->d.nbmcyl = e->i.load.ncyl;
	e->d.nbmcone = e->i.load.ncone;
	return (0);
}
