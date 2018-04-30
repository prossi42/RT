/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhermann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 11:46:54 by lhermann          #+#    #+#             */
/*   Updated: 2018/04/13 11:48:24 by lhermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		getlightdir(t_stuff *e, t_vec inter)
{
	vecsous(&e->light->lightdir, &e->light->pos, &inter);
	vecnorm(&e->light->lightdir);
}

t_vec		wave(t_vec norm, t_vec inter, char axe, double coef)
{
	if (axe == 'x')
		norm.x += sin(inter.x) * coef;
	else if (axe == 'y')
		norm.y += sin(inter.y) * coef;
	else if (axe == 'z')
		norm.z += sin(inter.z) * coef;
	else if (axe == '\0')
	{
		norm.x -= sin(inter.x) * coef;
		norm.y -= sin(inter.y) * coef;
		norm.z -= sin(inter.z) * coef;
	}
	vecnorm(&norm);
	return (norm);
}

t_vec		fix(t_vec inter, t_vec norm, t_vec pos)
{
	t_vec	v;
	t_vec	project;
	double	doti;

	vecsous(&v, &inter, &pos);
	doti = dot_product(&v, &norm);
	project.x = doti * norm.x;
	project.y = doti * norm.y;
	project.z = doti * norm.z;
	vecsous(&norm, &v, &project);
	vecnorm(&norm);
	return (norm);
}

void		light_set(t_stuff *e)
{
	getlightdir(e, e->c.inter);
	reboot_list_loop(e, 1);
	check(e, &e->light->lightdir, &e->c.inter, 2);
	check_dist(e, 2);
	checklight(e->light, &e->light->lightdir, &e->c.inter);
	reboot_list_loop(e, 1);
}
