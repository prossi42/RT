/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 12:28:06 by jgaillar          #+#    #+#             */
/*   Updated: 2018/04/13 12:28:12 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		init_dist(t_stuff *e)
{
	e->c.dist = INFINITY;
	e->c.distsph = INFINITY;
	e->c.distpla = INFINITY;
	e->c.distcyl = INFINITY;
	e->c.distcone = INFINITY;
	e->c.distlight = INFINITY;
}

void		dist_con_sd(t_stuff *e)
{
	e->c.objcone = e->cone->nm;
	e->c.obj = CONE;
	e->c.reflexcone = e->cone->reflex;
	e->c.refraccone = e->cone->refrac;
	e->c.conscolcone = e->cone->conscol;
	e->d.colcone.r = e->cone->color.r;
	e->d.colcone.g = e->cone->color.g;
	e->d.colcone.b = e->cone->color.b;
}

void		dist_con(t_stuff *e, t_vec *raydir, t_vec *pos, int option)
{
	while (e->cone)
	{
		checkcone(e->cone, raydir, pos);
		if (e->cone->t < e->c.distcone && e->cone->t > 0.00001)
		{
			e->c.distcone = e->cone->t;
			if (option == 1)
				dist_con_sd(e);
			else if (option == 3)
			{
				e->d.scolcone = e->cone->conscol;
				e->d.refraccone = e->cone->refrac;
			}
		}
		if (e->cone->next != NULL)
			e->cone = e->cone->next;
		else
			break ;
	}
}

void		dist_cyl_sd(t_stuff *e)
{
	e->c.objcyl = e->cyl->nm;
	e->c.obj = CYLINDRE;
	e->c.reflexcyl = e->cyl->reflex;
	e->c.refraccyl = e->cyl->refrac;
	e->c.conscolcyl = e->cyl->conscol;
	e->d.colcyl.r = e->cyl->color.r;
	e->d.colcyl.g = e->cyl->color.g;
	e->d.colcyl.b = e->cyl->color.b;
}

void		dist_cyl(t_stuff *e, t_vec *raydir, t_vec *pos, int option)
{
	while (e->cyl)
	{
		checkcyl(e->cyl, raydir, pos);
		if (e->cyl->t < e->c.distcyl && e->cyl->t > 0.00001)
		{
			e->c.distcyl = e->cyl->t;
			if (option == 1)
				dist_cyl_sd(e);
			else if (option == 3)
			{
				e->d.scolcyl = e->cyl->conscol;
				e->d.refraccyl = e->cyl->refrac;
			}
		}
		if (e->cyl->next != NULL)
			e->cyl = e->cyl->next;
		else
			break ;
	}
}
