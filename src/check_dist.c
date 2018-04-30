/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 11:52:53 by jgaillar          #+#    #+#             */
/*   Updated: 2018/04/13 11:53:03 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		comp_cone(t_stuff *e, int option)
{
	if (e->c.distcone < e->c.dist && e->c.distcone > 0.00001)
	{
		if (option == 1)
		{
			e->c.obj = (e->c.distcone < e->c.dist ? CONE : e->c.obj);
			e->c.reflex = e->c.reflexcone;
			e->c.refrac = e->c.refraccone;
			e->c.conscol = e->c.conscolcone;
			e->d.color.r = e->d.colcone.r;
			e->d.color.g = e->d.colcone.g;
			e->d.color.g = e->d.colcone.b;
		}
		else if (option == 3)
		{
			e->d.scol = e->d.scolcone;
			e->d.refrac = e->d.refraccone;
		}
		e->c.dist = e->c.distcone;
	}
}

void		comp_cyl(t_stuff *e, int option)
{
	if (e->c.distcyl < e->c.dist && e->c.distcyl > 0.00001)
	{
		if (option == 1)
		{
			e->c.obj = (e->c.distcyl < e->c.dist ? CYLINDRE : e->c.obj);
			e->c.reflex = e->c.reflexcyl;
			e->c.refrac = e->c.refraccyl;
			e->c.conscol = e->c.conscolcyl;
			e->d.color.r = e->d.colcyl.r;
			e->d.color.g = e->d.colcyl.g;
			e->d.color.b = e->d.colcyl.b;
		}
		else if (option == 3)
		{
			e->d.scol = e->d.scolcyl;
			e->d.refrac = e->d.refraccyl;
		}
		e->c.dist = e->c.distcyl;
	}
}

void		comp_pla(t_stuff *e, int option)
{
	if (e->c.distpla < e->c.dist && e->c.distpla > 0.00001)
	{
		if (option == 1)
		{
			e->c.obj = (e->c.distpla < e->c.dist ? PLAN : e->c.obj);
			e->c.reflex = e->c.reflexpla;
			e->c.refrac = e->c.refracpla;
			e->c.conscol = e->c.conscolpla;
			e->d.color.r = e->d.colpla.r;
			e->d.color.g = e->d.colpla.g;
			e->d.color.b = e->d.colpla.b;
		}
		else if (option == 3)
		{
			e->d.scol = e->d.scolpla;
			e->d.refrac = e->d.refracpla;
		}
		e->c.dist = e->c.distpla;
	}
}

void		comp_sph(t_stuff *e, int option)
{
	if (e->c.distsph < e->c.dist && e->c.distsph > 0.00001)
	{
		if (option == 1)
		{
			e->c.obj = (e->c.distsph < e->c.dist ? SPHERE : -1);
			e->c.reflex = e->c.reflexsph;
			e->c.refrac = e->c.refracsph;
			e->c.conscol = e->c.conscolsph;
			e->d.color.r = e->d.colsph.r;
			e->d.color.g = e->d.colsph.g;
			e->d.color.b = e->d.colsph.b;
		}
		else if (option == 3)
		{
			e->d.scol = e->d.scolsph;
			e->d.refrac = e->d.refracsph;
		}
		e->c.dist = e->c.distsph;
	}
}

void		check_dist(t_stuff *e, int option)
{
	comp_sph(e, option);
	comp_pla(e, option);
	comp_cyl(e, option);
	comp_cone(e, option);
	if (e->c.distlight < e->c.dist && e->c.distlight > 0.00001 && option == 1)
	{
		e->c.obj = (e->c.distlight < e->c.dist ? LIGHT : e->c.obj);
		e->c.dist = e->c.distlight;
	}
}
