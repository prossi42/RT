/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 12:07:17 by prossi            #+#    #+#             */
/*   Updated: 2018/04/13 12:30:16 by lhermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	perlin_sphere(t_stuff *e)
{
	int a;

	a = 2;
	if (e->i.perlin == 3)
	{
		if (e->i.objet == -1 || (e->c.objsph == e->i.each_obj && \
					e->i.objet == SPHERE))
		{
			reboot_list_loop(e, 1);
			searchlist(e, e->c.objsph, SPHERE);
			e->sph->norm.z = (e->sph->norm.z + smooth_noise_3d(e->c.inter.z \
						- a, e->c.inter.y, e->c.inter.x, e)) - \
							(e->sph->norm.z + smooth_noise_3d(e->c.inter.z + \
											a, e->c.inter.y, e->c.inter.x, e));
			e->sph->norm.y = (e->sph->norm.y + smooth_noise_3d(e->c.inter.z, \
						e->c.inter.y - a, e->c.inter.x, e)) - (e->sph->norm.y \
						+ smooth_noise_3d(e->c.inter.z, e->c.inter.y + a, \
							e->c.inter.x, e));
			e->sph->norm.x = (e->sph->norm.x + smooth_noise_3d(e->c.inter.z, \
						e->c.inter.y, e->c.inter.x - a, e)) - (e->sph->norm.x \
						+ smooth_noise_3d(e->c.inter.z, e->c.inter.y, \
							e->c.inter.x + a, e));
		}
	}
}

void	perlin_plan(t_stuff *e)
{
	int a;

	a = 2;
	if (e->i.perlin == 3)
	{
		if (e->i.objet == -1 || (e->c.objpla == e->i.each_obj && \
					e->i.objet == PLAN))
		{
			reboot_list_loop(e, 1);
			searchlist(e, e->c.objpla, PLAN);
			e->pla->norm.z = (e->pla->norm.z + smooth_noise_3d(e->c.inter.z \
						- a, e->c.inter.y, e->c.inter.x, e)) - \
							(e->pla->norm.z + smooth_noise_3d(e->c.inter.z + \
											a, e->c.inter.y, e->c.inter.x, e));
			e->pla->norm.y = (e->pla->norm.y + smooth_noise_3d(e->c.inter.z, \
						e->c.inter.y - a, e->c.inter.x, e)) - (e->pla->norm.y \
						+ smooth_noise_3d(e->c.inter.z, e->c.inter.y + a, \
							e->c.inter.x, e));
			e->pla->norm.x = (e->pla->norm.x + smooth_noise_3d(e->c.inter.z, \
				e->c.inter.y, e->c.inter.x - a, e)) - (e->pla->norm.x + \
				smooth_noise_3d(e->c.inter.z, e->c.inter.y, \
					e->c.inter.x + a, e));
		}
	}
}
