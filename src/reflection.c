/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <jgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 16:54:31 by jgaillar          #+#    #+#             */
/*   Updated: 2018/04/24 13:09:29 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		reflect_obj_sd(t_stuff *e, t_vec *tmp, t_rgb *tmp2, int obj)
{
	if (obj == CYLINDRE)
	{
		searchlist(e, e->c.objcyl, CYLINDRE);
		e->tree->tmpcyl = e->cyl;
		e->tree->tmpnm = e->c.objcyl;
		*tmp = getrefray(&e->cyl->norml, &e->poscam, &e->c.inter);
		reboot_list_loop(e, 3);
		*tmp2 = raythingy(e, tmp, &e->c.inter);
		e->cyl = e->tree->tmpcyl;
		e->c.objcyl = e->tree->tmpnm;
	}
	else if (obj == CONE)
	{
		searchlist(e, e->c.objcone, CONE);
		e->tree->tmpcone = e->cone;
		e->tree->tmpnm = e->c.objcone;
		*tmp = getrefray(&e->cone->norml, &e->poscam, &e->c.inter);
		reboot_list_loop(e, 3);
		*tmp2 = raythingy(e, tmp, &e->c.inter);
		e->cone = e->tree->tmpcone;
		e->c.objcone = e->tree->tmpnm;
	}
}

static void		reflect_obj(t_stuff *e, t_vec *tmp, t_rgb *tmp2, int obj)
{
	if (obj == SPHERE)
	{
		searchlist(e, e->c.objsph, SPHERE);
		e->tree->tmpsph = e->sph;
		e->tree->tmpnm = e->c.objsph;
		*tmp = getrefray(&e->sph->norm, &e->poscam, &e->c.inter);
		reboot_list_loop(e, 3);
		*tmp2 = raythingy(e, tmp, &e->c.inter);
		e->sph = e->tree->tmpsph;
		e->c.objsph = e->tree->tmpnm;
	}
	else if (obj == PLAN)
	{
		searchlist(e, e->c.objpla, PLAN);
		e->tree->tmpplan = e->pla;
		e->tree->tmpnm = e->c.objpla;
		*tmp = getrefray(&e->pla->norm, &e->poscam, &e->c.inter);
		reboot_list_loop(e, 3);
		*tmp2 = raythingy(e, tmp, &e->c.inter);
		e->pla = e->tree->tmpplan;
		e->c.objpla = e->tree->tmpnm;
	}
	reflect_obj_sd(e, tmp, tmp2, obj);
}

t_rgb			reflect(t_stuff *e, int obj)
{
	t_vec	tmp;
	t_tree	*tmp3;
	t_rgb	tmp2;

	reboot_list_loop(e, 3);
	if (!e->tree)
	{
		if (init_tree(&e->tree) == -1)
			exit(-1);
	}
	else
		tree_set(e, &tmp3, 1);
	fill_tree(e, 1);
	reflect_obj(e, &tmp, &tmp2, obj);
	fill_tree(e, 2);
	if (e->ray > 0)
	{
		tmp3 = e->tree->prev;
		free(e->tree);
		e->tree = tmp3;
	}
	return (tmp2);
}

void			reflexion_sd(t_stuff *e)
{
	if (e->c.obj == CYLINDRE)
	{
		searchlist(e, e->c.objcyl, CYLINDRE);
		if (e->cyl->reflex == 1)
			e->c.colorf = reflect(e, CYLINDRE);
		else
			rgb_add(&e->c.colorf, e->c.colorf, \
				reflect(e, CYLINDRE), e->cyl->reflex);
	}
	else if (e->c.obj == CONE)
	{
		searchlist(e, e->c.objcone, CONE);
		if (e->cone->reflex == 1)
			e->c.colorf = reflect(e, CONE);
		else
			rgb_add(&e->c.colorf, e->c.colorf, reflect(e, CONE), \
			e->cone->reflex);
	}
}

void			reflexion(t_stuff *e)
{
	if (e->c.obj == SPHERE)
	{
		searchlist(e, e->c.objsph, SPHERE);
		if (e->sph->reflex == 1)
			e->c.colorf = reflect(e, SPHERE);
		else
			rgb_add(&e->c.colorf, e->c.colorf, reflect(e, SPHERE),\
			e->sph->reflex);
	}
	else if (e->c.obj == PLAN)
	{
		searchlist(e, e->c.objpla, PLAN);
		if (e->pla->reflex == 1)
			e->c.colorf = reflect(e, PLAN);
		else
			rgb_add(&e->c.colorf, e->c.colorf, reflect(e, PLAN), \
			e->pla->reflex);
	}
	reflexion_sd(e);
}
