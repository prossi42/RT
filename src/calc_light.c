/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <jgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 09:24:30 by jgaillar          #+#    #+#             */
/*   Updated: 2018/04/13 10:47:41 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec		getrefracray(t_vec *norm, t_vec *pos, t_vec *inter, double fac)
{
	t_vec	res;
	t_vec	v;
	double	a;
	double	b;

	vecsous(&v, inter, pos);
	vecnorm(&v);
	a = dot_product(&v, norm);
	b = 1 / fac;
	res.x = b * v.x - (b * a + sqrt(1 - (b * b) * (1 - (a * a)))) * norm->x;
	res.y = b * v.y - (b * a + sqrt(1 - (b * b) * (1 - (a * a)))) * norm->y;
	res.z = b * v.z - (b * a + sqrt(1 - (b * b) * (1 - (a * a)))) * norm->z;
	vecnorm(&res);
	return (res);
}

t_vec		getrefray(t_vec *norm, t_vec *pos, t_vec *inter)
{
	t_vec	res;
	t_vec	v;
	double	a;

	vecsous(&v, inter, pos);
	vecnorm(&v);
	a = dot_product(&v, norm);
	res.x = v.x - (2 * a * norm->x);
	res.y = v.y - (2 * a * norm->y);
	res.z = v.z - (2 * a * norm->z);
	vecnorm(&res);
	return (res);
}

t_vec		getspeclight2(t_stuff *e, t_vec *norm, t_vec *light)
{
	t_vec	res;
	t_vec	tmp2;
	double	tmp;

	vecsous(&tmp2, &e->c.inter, &e->light->pos);
	tmp = dot_product(norm, &tmp2);
	res.x = 2 * tmp * norm->x + light->x;
	res.y = 2 * tmp * norm->y + light->y;
	res.z = 2 * tmp * norm->z + light->z;
	vecnorm(&res);
	return (res);
}

void		getspeclight(t_stuff *e, t_vec *norm, t_rgb *color, t_light **light)
{
	double	a;
	t_vec	ref;
	t_rgb	tmp;
	t_vec	tmp3;

	ref = getspeclight2(e, norm, &(*light)->lightdir);
	vecsous(&tmp3, &e->poscam, &e->c.inter);
	vecnorm(&tmp3);
	tmp3.x *= -1;
	tmp3.y *= -1;
	tmp3.z *= -1;
	a = pow(dot_product(&ref, &tmp3), 300);
	tmp.r = ((*light)->color.r * (*light)->diff) * a;
	tmp.g = ((*light)->color.g * (*light)->diff) * a;
	tmp.b = ((*light)->color.b * (*light)->diff) * a;
	rgb_add(color, *color, tmp, 1);
}

t_rgb		getlight(t_vec *norm, t_light **light, t_rgb *colorobj, t_stuff *e)
{
	t_rgb	rgb;
	double	angle;

	init_rgb(&rgb, 0, 0, 0);
	angle = ((*light)->ray > 0.00001 ? (dot_product(norm, &(*light)->lightdir))\
		: 0);
	if ((*light)->ray > 0.00001 && angle > 0.00001)
	{
		e->test++;
		if (e->l == 1)
		{
			rgb.r = colorobj->r * (*light)->amb;
			rgb.g = colorobj->g * (*light)->amb;
			rgb.b = colorobj->b * (*light)->amb;
		}
		rgb.r += ((*light)->color.r * (*light)->diff) * angle;
		rgb.g += ((*light)->color.g * (*light)->diff) * angle;
		rgb.b += ((*light)->color.b * (*light)->diff) * angle;
		getspeclight(e, norm, &rgb, light);
		return (rgb);
	}
	if (e->l == 1)
		rgb_add(&rgb, rgb, (*colorobj), (*light)->amb);
	return (rgb);
}
