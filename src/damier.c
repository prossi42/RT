/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   damier.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <jgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 15:11:40 by jgaillar          #+#    #+#             */
/*   Updated: 2018/04/10 12:53:02 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void				dam(t_stuff *e, int obj)
{
	if (obj == SPHERE)
	{
		searchlist(e, e->i.each_obj, obj);
		damier(e, &e->sph->color, &e->sph->pos);
	}
	else if (obj == PLAN)
	{
		searchlist(e, e->i.each_obj, obj);
		damier(e, &e->pla->color, &e->pla->pos);
	}
	else if (obj == CYLINDRE)
	{
		searchlist(e, e->i.each_obj, obj);
		damier(e, &e->cyl->color, &e->cyl->pos);
	}
	else if (obj == CONE)
	{
		searchlist(e, e->i.each_obj, obj);
		damier(e, &e->cone->color, &e->cone->pos);
	}
}

static void			fill_parity(t_stuff *e, t_vec *pos, t_damier *a)
{
	a->px = e->c.inter.x - pos->x;
	a->py = e->c.inter.y - pos->y;
	a->pz = e->c.inter.z - pos->z;
	a->x1 = (int)(floor((a->px / LENGHT_PROCED)));
	a->y1 = (int)(floor((a->py / LENGHT_PROCED)));
	a->z1 = (int)(floor((a->pz / LENGHT_PROCED)));
}

void				damier_sd_plan(t_stuff *e, t_rgb *color, t_damier *a)
{
	if (((a->y1 % 2 == 0) && (a->z1 % 2 == 0)) || \
	(((a->y1 % 2 != 0) && (a->z1 % 2 != 0))))
	{
		color->r = e->i.col_dam2.r;
		color->g = e->i.col_dam2.g;
		color->b = e->i.col_dam2.b;
	}
	else
	{
		color->r = e->i.col_dam1.r;
		color->g = e->i.col_dam1.g;
		color->b = e->i.col_dam1.b;
	}
}

void				damier_sd(t_stuff *e, t_rgb *color, t_damier *a)
{
	if (((a->y1 % 2 == 0) && (a->z1 % 2 == 0)) || \
	(((a->y1 % 2 != 0) && (a->z1 % 2 != 0))))
	{
		color->r = e->i.col_dam1.r;
		color->g = e->i.col_dam1.g;
		color->b = e->i.col_dam1.b;
	}
	else
	{
		color->r = e->i.col_dam2.r;
		color->g = e->i.col_dam2.g;
		color->b = e->i.col_dam2.b;
	}
}

void				damier(t_stuff *e, t_rgb *color, t_vec *pos)
{
	t_damier	a;

	fill_parity(e, pos, &a);
	if (a.x1 % 2 == 0)
	{
		if (((a.y1 % 2 == 0) && (a.z1 % 2 == 0)) || \
		(((a.y1 % 2 != 0) && (a.z1 % 2 != 0))))
			init_rgb(color, e->i.col_dam1.r, e->i.col_dam1.g, e->i.col_dam1.b);
		else
			init_rgb(color, e->i.col_dam2.r, e->i.col_dam2.g, e->i.col_dam2.b);
	}
	else
	{
		if (e->i.objet == PLAN)
			damier_sd_plan(e, color, &a);
		else
			damier_sd(e, color, &a);
	}
}
