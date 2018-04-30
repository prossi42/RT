/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refraction.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <jgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 16:57:07 by jgaillar          #+#    #+#             */
/*   Updated: 2018/04/24 13:09:20 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void			refraction_obj_sd(t_stuff *e, t_vec *tmp, t_rgb *tmp2,\
					int obj)
{
	if (obj == CYLINDRE)
	{
		searchlist(e, e->c.objcyl, CYLINDRE);
		e->tree->tmpcyl = e->cyl;
		*tmp = getrefracray(&e->cyl->norml, &e->poscam, &e->c.inter, \
			e->cyl->refrac);
		reboot_list_loop(e, 3);
		*tmp2 = raythingy(e, tmp, &e->c.inter);
		e->cyl = e->tree->tmpcyl;
	}
	else if (obj == CONE)
	{
		searchlist(e, e->c.objcone, CONE);
		e->tree->tmpcone = e->cone;
		*tmp = getrefracray(&e->cone->norml, &e->poscam, &e->c.inter, \
			e->cone->refrac);
		reboot_list_loop(e, 3);
		*tmp2 = raythingy(e, tmp, &e->c.inter);
		e->cone = e->tree->tmpcone;
	}
}

static void			refraction_obj(t_stuff *e, t_vec *tmp, t_rgb *tmp2, int obj)
{
	if (obj == SPHERE)
	{
		searchlist(e, e->c.objsph, SPHERE);
		e->tree->tmpsph = e->sph;
		*tmp = getrefracray(&e->sph->norm, &e->poscam, &e->c.inter, \
			e->sph->refrac);
		reboot_list_loop(e, 3);
		*tmp2 = raythingy(e, tmp, &e->c.inter);
		e->sph = e->tree->tmpsph;
	}
	else if (obj == PLAN)
	{
		searchlist(e, e->c.objpla, PLAN);
		e->tree->tmpplan = e->pla;
		*tmp = getrefracray(&e->pla->norm, &e->poscam, &e->c.inter, \
			e->pla->refrac);
		reboot_list_loop(e, 3);
		*tmp2 = raythingy(e, tmp, &e->c.inter);
		e->pla = e->tree->tmpplan;
	}
	refraction_obj_sd(e, tmp, tmp2, obj);
}

t_rgb				refrac(t_stuff *e, int obj)
{
	t_vec	tmp;
	t_tree	*tmp3;
	t_rgb	tmp2;

	tmp3 = NULL;
	reboot_list_loop(e, 3);
	if (!e->tree)
	{
		if (init_tree(&e->tree) == -1)
			exit(-1);
	}
	else
		tree_set(e, &tmp3, 2);
	fill_tree(e, 1);
	refraction_obj(e, &tmp, &tmp2, obj);
	fill_tree(e, 2);
	if (e->ray > 0)
	{
		tmp3 = e->tree->prev;
		free(e->tree);
		e->tree = tmp3;
	}
	return (tmp2);
}

void				refraction(t_stuff *e)
{
	if (e->c.obj == SPHERE)
	{
		searchlist(e, e->c.objsph, SPHERE);
		rgb_add(&e->c.colorf, e->c.colorf, refrac(e, SPHERE), e->sph->conscol);
	}
	else if (e->c.obj == PLAN)
	{
		searchlist(e, e->c.objpla, PLAN);
		rgb_add(&e->c.colorf, e->c.colorf, refrac(e, PLAN), e->pla->conscol);
	}
	else if (e->c.obj == CYLINDRE)
	{
		searchlist(e, e->c.objcyl, CYLINDRE);
		rgb_add(&e->c.colorf, e->c.colorf, refrac(e, CYLINDRE), \
		e->cyl->conscol);
	}
	else if (e->c.obj == CONE)
	{
		searchlist(e, e->c.objcone, CONE);
		rgb_add(&e->c.colorf, e->c.colorf, refrac(e, CONE), e->cone->conscol);
	}
}
