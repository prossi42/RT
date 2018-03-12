/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <jgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 09:44:13 by jgaillar          #+#    #+#             */
/*   Updated: 2018/02/20 11:33:23 by Awk-LM           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		veclength(t_vec *i)
{
	i->length = sqrt((i->x * i->x) + (i->y * i->y) + (i->z * i->z));
}

void		vecnorm(t_vec *i)
{
	veclength(i);
	i->x = i->x / i->length;
	i->y = i->y / i->length;
	i->z = i->z / i->length;
	veclength(i);
}

void		getintersection(t_stuff *e, double dist, t_vec *raydir, t_vec *pos)
{
	e->c.inter.x = pos->x + (raydir->x * dist);
	e->c.inter.y = pos->y + (raydir->y * dist);
	e->c.inter.z = pos->z + (raydir->z * dist);
}

void		getlightdir(t_stuff *e, t_vec inter)
{
	vecsous(&e->light->lightdir, &e->light->pos, &inter);
	vecnorm(&e->light->lightdir);
}
