/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <jgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:57:18 by jgaillar          #+#    #+#             */
/*   Updated: 2018/04/10 15:32:23 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		checksphere(t_sphere *sphere, t_vec *raydir, t_vec *poscam)
{
	double	a;
	double	b;
	double	c;

	a = (raydir->x * raydir->x) + (raydir->y * raydir->y) + (raydir->z * \
		raydir->z);
	b = 2 * (raydir->x * (poscam->x - sphere->pos.x) + raydir->y * \
	(poscam->y - sphere->pos.y) + raydir->z * (poscam->z - sphere->pos.z));
	c = (((poscam->x - sphere->pos.x) * (poscam->x - sphere->pos.x)) + \
	((poscam->y - sphere->pos.y) * (poscam->y - sphere->pos.y)) + \
	((poscam->z - sphere->pos.z) * (poscam->z - sphere->pos.z))) - \
	(sphere->ray * sphere->ray);
	sphere->det = (b * b) - 4 * a * c;
	if (sphere->det < 0)
		sphere->t = -1;
	else if (sphere->det == 0)
		sphere->t = (-b + sqrt(sphere->det)) / (2 * a);
	else if (sphere->det > 0)
	{
		sphere->t1 = ((b * -1) + sqrt(sphere->det)) / (2 * a);
		sphere->t2 = ((b * -1) - sqrt(sphere->det)) / (2 * a);
		sphere->t = (sphere->t1 <= sphere->t2 ? sphere->t1 : sphere->t2);
	}
}

void		checklight(t_light *light, t_vec *raydir, t_vec *poscam)
{
	double	a;
	double	b;
	double	c;

	a = (raydir->x * raydir->x) + (raydir->y * raydir->y) + (raydir->z * \
		raydir->z);
	b = 2 * (raydir->x * (poscam->x - light->pos.x) + raydir->y * \
	(poscam->y - light->pos.y) + raydir->z * (poscam->z - light->pos.z));
	c = (((poscam->x - light->pos.x) * (poscam->x - light->pos.x)) + \
	((poscam->y - light->pos.y) * (poscam->y - light->pos.y)) + \
	((poscam->z - light->pos.z) * (poscam->z - light->pos.z))) - \
	(light->ray * light->ray);
	light->det = (b * b) - 4 * a * c;
	if (light->det < 0)
		light->t = -1;
	else if (light->det == 0)
		light->t = (-b + sqrt(light->det)) / (2 * a);
	else if (light->det > 0)
	{
		light->t1 = ((b * -1) + sqrt(light->det)) / (2 * a);
		light->t2 = ((b * -1) - sqrt(light->det)) / (2 * a);
		light->t = (light->t1 <= light->t2 ? light->t1 : light->t2);
	}
}

void		checkplan(t_plan *plan, t_vec *raydir, t_vec *poscam)
{
	t_vec	tmp;
	double	tmp1;
	double	tmp2;

	vecsous(&tmp, poscam, &plan->pos);
	tmp1 = dot_product(&tmp, &plan->norm);
	tmp2 = dot_product(raydir, &plan->norm);
	if (tmp2 != 0)
		plan->t = -tmp1 / tmp2;
}

void		checkcyl(t_cyl *cyl, t_vec *raydir, t_vec *poscam)
{
	double	a;
	double	b;
	double	c;
	t_vec	l;

	vecsous(&l, poscam, &cyl->pos);
	a = dot_product(raydir, raydir) - (dot_product(raydir, &cyl->norm) \
	* dot_product(raydir, &cyl->norm));
	b = 2 * (dot_product(raydir, &l) - (dot_product(raydir, &cyl->norm) \
	* dot_product(&l, &cyl->norm)));
	c = dot_product(&l, &l) - (dot_product(&l, &cyl->norm) \
	* dot_product(&l, &cyl->norm)) - cyl->ray * cyl->ray;
	cyl->det = (b * b) - 4 * a * c;
	cyl->t1 = (-b - sqrt(cyl->det)) / (2 * a);
	cyl->t2 = (-b + sqrt(cyl->det)) / (2 * a);
	cyl->t = (cyl->t1 <= cyl->t2 ? cyl->t1 : cyl->t2);
}

int			checkdisk(t_plan *plan, t_vec *raydir, t_vec *poscam)
{
	int		ray;
	t_vec	tmp;
	t_vec	tmp2;
	t_vec	point;
	double	tmp3;

	ray = 10;
	checkplan(plan, raydir, poscam);
	if (plan->t > 0)
	{
		tmp.x = raydir->x * plan->t;
		tmp.y = raydir->y * plan->t;
		tmp.z = raydir->z * plan->t;
		vecadd(&point, &tmp, poscam);
		vecsous(&tmp2, &point, &plan->pos);
		tmp3 = dot_product(&tmp2, &tmp2);
		if (sqrt(tmp3) < ray)
			return (1);
		else
			plan->t = -1;
	}
	else
		plan->t = -1;
	return (-1);
}
