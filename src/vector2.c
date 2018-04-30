/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <jgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 09:44:13 by jgaillar          #+#    #+#             */
/*   Updated: 2018/04/13 11:48:14 by lhermann         ###   ########.fr       */
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

t_vec		revvec(t_vec vec)
{
	vec.x *= -1;
	vec.y *= -1;
	vec.z *= -1;
	return (vec);
}

void		init_rgb(t_rgb *rgb, int r, int g, int b)
{
	rgb->r = r;
	rgb->g = g;
	rgb->b = b;
}

void		getintersection(t_stuff *e, double dist, t_vec *raydir, t_vec *pos)
{
	e->c.inter.x = pos->x + (raydir->x * dist);
	e->c.inter.y = pos->y + (raydir->y * dist);
	e->c.inter.z = pos->z + (raydir->z * dist);
}
