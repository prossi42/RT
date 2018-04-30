/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <jgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 09:21:34 by jgaillar          #+#    #+#             */
/*   Updated: 2018/04/13 15:09:23 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		light_sph(t_stuff *e)
{
	searchlist(e, e->c.objsph, SPHERE);
	vecsous(&e->sph->norm, &e->c.inter, &e->sph->pos);
	vecnorm(&e->sph->norm);
	perlin_sphere(e);
	vecnorm(&e->sph->norm);
	if (e->i.objet == SPHERE && e->i.wave == 1)
		e->sph->norm = wave(e->sph->norm, e->c.inter, e->m.axe, 0.5);
	rgb_add(&e->c.colorf, e->c.colorf, \
		getlight(&e->sph->norm, &e->light, &e->sph->color, e), 1);
}

void		light_cyl(t_stuff *e)
{
	searchlist(e, e->c.objcyl, CYLINDRE);
	e->cyl->norml = fix(e->c.inter, e->cyl->norm, e->cyl->pos);
	perlin_cyl(e);
	vecnorm(&e->cyl->norml);
	if (e->i.objet == CYLINDRE && e->i.wave == 1)
		e->cyl->norml = wave(e->cyl->norml, e->c.inter, e->m.axe, 0.5);
	rgb_add(&e->c.colorf, e->c.colorf, \
			getlight(&e->cyl->norml, &e->light, &e->cyl->color, e), 1);
}

void		light_cone(t_stuff *e)
{
	searchlist(e, e->c.objcone, CONE);
	e->cone->norml = \
		fix(e->c.inter, e->cone->norm, e->cone->pos);
	perlin_cone(e);
	vecnorm(&e->cone->norml);
	if (e->i.objet == CONE && e->i.wave == 1)
		e->cone->norml = wave(e->cone->norml, e->c.inter, e->m.axe, 0.5);
	rgb_add(&e->c.colorf, e->c.colorf,\
		getlight(&e->cone->norml, &e->light, &e->cone->color, e), 1);
}

void		lumos_maxima(t_stuff *e, t_vec *raydir)
{
	e->l++;
	if (e->c.obj == SPHERE)
		light_sph(e);
	else if (e->c.obj == PLAN)
		light_plan(e, raydir);
	else if (e->c.obj == CYLINDRE)
		light_cyl(e);
	else if (e->c.obj == CONE)
		light_cone(e);
}
