/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 12:24:56 by jgaillar          #+#    #+#             */
/*   Updated: 2018/04/13 12:25:00 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		dist_pla_sd(t_stuff *e)
{
	e->c.objpla = e->pla->nm;
	e->c.obj = PLAN;
	e->c.reflexpla = e->pla->reflex;
	e->c.refracpla = e->pla->refrac;
	e->c.conscolpla = e->pla->conscol;
	e->d.colpla.r = e->pla->color.r;
	e->d.colpla.g = e->pla->color.g;
	e->d.colpla.b = e->pla->color.b;
}

void		dist_pla(t_stuff *e, t_vec *raydir, t_vec *pos, int option)
{
	while (e->pla)
	{
		if (e->pla->ray == 0)
			checkplan(e->pla, raydir, pos);
		else if (e->pla->ray > 0)
			checkdisk(e->pla, raydir, pos);
		if (e->pla->t < e->c.distpla && e->pla->t > 0.00001)
		{
			e->c.distpla = e->pla->t;
			if (option == 1)
				dist_pla_sd(e);
			else if (option == 3)
			{
				e->d.scolpla = e->pla->conscol;
				e->d.refracpla = e->pla->refrac;
			}
		}
		if (e->pla->next != NULL)
			e->pla = e->pla->next;
		else
			break ;
	}
}

void		dist_sph_sd(t_stuff *e)
{
	e->c.objsph = e->sph->nm;
	e->c.obj = SPHERE;
	e->c.reflexsph = e->sph->reflex;
	e->c.refracsph = e->sph->refrac;
	e->c.conscolsph = e->sph->conscol;
	e->d.colsph.r = e->sph->color.r;
	e->d.colsph.g = e->sph->color.g;
	e->d.colsph.b = e->sph->color.b;
}

void		dist_sph(t_stuff *e, t_vec *raydir, t_vec *pos, int option)
{
	while (e->sph)
	{
		checksphere(e->sph, raydir, pos);
		if (e->sph->t < e->c.distsph && e->sph->t > 0.00001)
		{
			e->c.distsph = e->sph->t;
			if (option == 1)
				dist_sph_sd(e);
			else if (option == 3)
			{
				e->d.scolsph = e->sph->conscol;
				e->d.refracsph = e->sph->refrac;
			}
		}
		if (e->sph->next != NULL)
			e->sph = e->sph->next;
		else
			break ;
	}
}

void		check(t_stuff *e, t_vec *raydir, t_vec *pos, int option)
{
	init_dist(e);
	if (option == 1)
		e->c.obj = -1;
	dist_sph(e, raydir, pos, option);
	dist_pla(e, raydir, pos, option);
	dist_cyl(e, raydir, pos, option);
	dist_con(e, raydir, pos, option);
	while (e->light && option == 1)
	{
		checklight(e->light, raydir, pos);
		if (e->light->t < e->c.distlight && e->light->t > 0.00001)
		{
			e->c.distlight = e->light->t;
			e->c.objlight = e->light->nm;
			e->c.obj = LIGHT;
		}
		if (e->light->next != NULL)
			e->light = e->light->next;
		else
			break ;
	}
}
