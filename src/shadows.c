/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <jgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 14:00:01 by jgaillar          #+#    #+#             */
/*   Updated: 2018/04/13 11:08:17 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		shadows_refrac(t_stuff *e, int j)
{
	if ((e->d.scol > 0.00001 && e->d.scol <= 1) && \
	(e->d.refrac >= 1 && e->d.refrac <= 2) && j > 0)
	{
		e->c.colorf.r = e->c.colorf.r * (e->d.scol + 1.6);
		e->c.colorf.g = e->c.colorf.g * (e->d.scol + 1.6);
		e->c.colorf.b = e->c.colorf.b * (e->d.scol + 1.6);
	}
}

void			init_shadows(t_stuff *e, t_vec *inter)
{
	reboot_list_loop(e, 1);
	getlightdir(e, *inter);
	checklight(e->light, &e->light->lightdir, inter);
	check(e, &e->light->lightdir, inter, 3);
	check_dist(e, 3);
}

double			shadows(t_stuff *e, t_vec *inter, t_rgb color)
{
	int		j;
	t_rgb	caca;
	t_rgb	tmp2;

	init_rgb(&tmp2, e->c.colorf.r, e->c.colorf.g, e->c.colorf.b);
	j = 0;
	init_rgb(&caca, 0, 0, 0);
	reboot_list_loop(e, 2);
	while (e->light)
	{
		init_shadows(e, inter);
		if (e->c.dist < e->light->t && e->c.dist > 0.00001 && e->c.obj != LIGHT)
		{
			j++;
			rgb_add(&e->c.colorf, caca, color, 0.5);
		}
		if (e->light->next != NULL)
			e->light = e->light->next;
		else
			break ;
	}
	shadows_refrac(e, j);
	return (0);
}

void			after_light(t_stuff *e)
{
	if (e->l > 0 && e->u == 0)
		shadows(e, &e->c.inter, e->c.colorf);
	else if (e->u == 0)
	{
		e->d.color.r *= 0.1;
		e->d.color.g *= 0.1;
		e->d.color.b *= 0.1;
		shadows(e, &e->c.inter, e->d.color);
	}
	if (e->ray < RAY && e->test > 0)
	{
		if (e->i.reflex == 1)
			if (e->c.reflex > 0 && e->c.reflex <= 1)
				reflexion(e);
		if (e->i.refrac == 1)
			if (e->c.refrac >= 1 && e->c.refrac <= 2\
				&& e->c.conscol > 0 && e->c.conscol <= 1)
				refraction(e);
	}
}
