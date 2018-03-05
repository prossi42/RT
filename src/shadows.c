/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <jgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 14:00:01 by jgaillar          #+#    #+#             */
/*   Updated: 2018/02/08 15:24:07 by lhermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double		shadows(t_stuff *e, t_vec *inter, t_rgb color)
{
	t_rgb caca;

	caca.r = 0;
	caca.g = 0;
	caca.b = 0;

	reboot_list_loop(e, 2);
	while (e->light)
	{
		reboot_list_loop(e, 1);
		getlightdir(e, e->c.inter);
		check(e, &e->light->lightdir, &e->c.inter, 2);
		check_dist(e, 2);
		if (e->c.dist < e->light->t && e->c.dist > 0.00001 && e->c.obj != LIGHT)
			rgb_add(&e->c.colorf, caca, color, 0.8);
		e->light = e->light->next;
	}
	return (0);
}

t_rgb		reflect(t_stuff *e, int obj, int nm)
{
	t_vec tmp;
	t_tree *tmp3;
	t_rgb tmp2;

	reboot_list_loop(e, 3);
	if (!e->tree)
	{
		if (init_tree(&e->tree) == -1)
			exit(-1);
	}
	else
	{
		tmp3 = e->tree;
		if (init_tree(&e->tree->left) == -1)
			exit(-1);
		e->tree = e->tree->left;
		e->tree->prev = tmp3;
	}
	e->tree->tmpcolor = e->c.colorf;
	e->tree->tmpl = e->l;
	e->tree->tmpinter = e->c.inter;
	e->tree->tmpscolor = e->d.color;
	e->tree->objet = e->c.obj;
	if (obj == SPHERE)
	{
		searchlist(e, e->c.objsph, SPHERE);
		e->tree->tmpsph = e->sph;
		tmp = getrefray(e, &e->sph->norm, &e->poscam, &e->c.inter);
		reboot_list_loop(e, 3);
		tmp2 = raythingy(e, &tmp, &e->c.inter);
		e->sph = e->tree->tmpsph;
	}
	else if (obj == PLAN)
	{
		searchlist(e, e->c.objpla, PLAN);
		e->tree->tmpplan = e->pla;
		tmp = getrefray(e, &e->pla->norm, &e->poscam, &e->c.inter);
		reboot_list_loop(e, 3);
		tmp2 = raythingy(e, &tmp, &e->c.inter);
		e->pla = e->tree->tmpplan;
	}
	else if (obj == CYLINDRE)
	{
		searchlist(e, e->c.objcyl, CYLINDRE);
		e->tree->tmpcyl = e->cyl;
		tmp = getrefray(e, &e->cyl->norml, &e->poscam, &e->c.inter);
		reboot_list_loop(e, 3);
		tmp2 = raythingy(e, &tmp, &e->c.inter);
		e->cyl = e->tree->tmpcyl;
	}
	else if (obj == CONE)
	{
		searchlist(e, e->c.objcone, CONE);
		e->tree->tmpcone = e->cone;
		tmp = getrefray(e, &e->cone->norml, &e->poscam, &e->c.inter);
		reboot_list_loop(e, 3);
		tmp2 = raythingy(e, &tmp, &e->c.inter);
		e->cone = e->tree->tmpcone;
	}
	e->c.colorf = e->tree->tmpcolor;
	e->l = e->tree->tmpl;
	e->c.inter = e->tree->tmpinter;
	e->d.color = e->tree->tmpscolor;
	e->c.obj = e->tree->objet;
	if (e->ray > 1)
	{
		tmp3 = e->tree->prev;
		free(e->tree);
		e->tree = tmp3;
	}
	return (tmp2);
}

t_rgb		refrac(t_stuff *e, int obj, int nm)
{
	t_vec tmp;
	t_tree *tmp3;
	t_rgb tmp2;

	reboot_list_loop(e, 3);
	if (!e->tree)
	{
		if (init_tree(&e->tree) == -1)
			exit(-1);
	}
	else
	{
		tmp3 = e->tree;
		if (init_tree(&e->tree->right) == -1)
			exit(-1);
		e->tree = e->tree->right;
		e->tree->prev = tmp3;
	}
	e->tree->tmpcolor = e->c.colorf;
	e->tree->tmpl = e->l;
	e->tree->tmpinter = e->c.inter;
	e->tree->tmpscolor = e->d.color;
	e->tree->objet = e->c.obj;
	if (obj == SPHERE)
	{
		searchlist(e, e->c.objsph, SPHERE);
		e->tree->tmpsph = e->sph;
		tmp = getrefracray(&e->sph->norm, &e->poscam, &e->c.inter, 1);
		reboot_list_loop(e, 3);
		tmp2 = raythingy(e, &tmp, &e->c.inter);
		e->sph = e->tree->tmpsph;
	}
	else if (obj == PLAN)
	{
		searchlist(e, e->c.objpla, PLAN);
		e->tree->tmpplan = e->pla;
		tmp = getrefracray(&e->pla->norm, &e->poscam, &e->c.inter, 1);
		reboot_list_loop(e, 3);
		tmp2 = raythingy(e, &tmp, &e->c.inter);
		e->pla = e->tree->tmpplan;
	}
	else if (obj == CYLINDRE)
	{
		searchlist(e, e->c.objcyl, CYLINDRE);
		e->tree->tmpcyl = e->cyl;
		tmp = getrefracray(&e->cyl->norml, &e->poscam, &e->c.inter, 1);
		reboot_list_loop(e, 3);
		tmp2 = raythingy(e, &tmp, &e->c.inter);
		e->cyl = e->tree->tmpcyl;
	}
	else if (obj == CONE)
	{
		searchlist(e, e->c.objcone, CONE);
		e->tree->tmpcone = e->cone;
		tmp = getrefracray(&e->cone->norml, &e->poscam, &e->c.inter, 1);
		reboot_list_loop(e, 3);
		tmp2 = raythingy(e, &tmp, &e->c.inter);
		e->cone = e->tree->tmpcone;
	}
	e->c.colorf = e->tree->tmpcolor;
	e->l = e->tree->tmpl;
	e->c.inter = e->tree->tmpinter;
	e->d.color = e->tree->tmpscolor;
	e->c.obj = e->tree->objet;
	if (e->ray > 1)
	{
		tmp3 = e->tree->prev;
		free(e->tree);
		e->tree = tmp3;
	}
	return (tmp2);
}
