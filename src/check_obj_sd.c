/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_obj_sd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 11:39:52 by jgaillar          #+#    #+#             */
/*   Updated: 2018/04/13 11:39:57 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		checkcone_sd(t_cone *cone, double a, double b)
{
	if (cone->det < 0)
		cone->t = -1;
	else if (cone->det != 0)
	{
		cone->t1 = (-b - sqrt(cone->det)) / (2 * a);
		cone->t2 = (-b + sqrt(cone->det)) / (2 * a);
		cone->t = (cone->t1 <= cone->t2 ? cone->t1 : cone->t2);
	}
	else
		cone->t = (-b / 2 * a);
}

void		checkcone(t_cone *cone, t_vec *raydir, t_vec *poscam)
{
	t_vec	tmp;
	t_vec	l;
	double	a;
	double	b;
	double	c;

	tmp.x = 1;
	tmp.y = 0;
	tmp.z = 0;
	vecsous(&l, poscam, &cone->pos);
	a = dot_product(raydir, raydir) - (1 + tan(cone->angle) * tan(cone->angle))\
	* (dot_product(raydir, &cone->norm) * dot_product(raydir, &cone->norm));
	b = 2 * (dot_product(raydir, &l) - (1 + tan(cone->angle) * \
	tan(cone->angle)) * (dot_product(raydir, &cone->norm) * \
	dot_product(&l, &cone->norm)));
	c = dot_product(&l, &l) - (1 + tan(cone->angle) * tan(cone->angle)) \
	* (dot_product(&l, &cone->norm) * dot_product(&l, &cone->norm));
	cone->det = (b * b) - 4 * a * c;
	checkcone_sd(cone, a, b);
}
