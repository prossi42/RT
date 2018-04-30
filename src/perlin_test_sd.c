/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin_test_sd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhermann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 12:24:04 by lhermann          #+#    #+#             */
/*   Updated: 2018/04/13 12:32:40 by lhermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	perlin_cone_sd(t_stuff *e)
{
	int a;

	a = 2;
	e->cone->norml.x = (e->cone->norml.x + \
			smooth_noise_3d(e->c.inter.z, e->c.inter.y, e->c.inter.x \
				- a, e)) - (e->cone->norml.x + \
				smooth_noise_3d(e->c.inter.z, e->c.inter.y, \
					e->c.inter.x + a, e));
}

void	perlin_cone(t_stuff *e)
{
	int a;

	a = 2;
	if (e->i.perlin == 3)
	{
		if (e->i.objet == -1 || (e->c.objcone == e->i.each_obj && \
				e->i.objet == CONE))
		{
			reboot_list_loop(e, 1);
			searchlist(e, e->c.objcone, CONE);
			e->cone->norml.z = (e->cone->norml.z + \
				smooth_noise_3d(e->c.inter.z - a, e->c.inter.y, \
					e->c.inter.x, e)) - (e->cone->norml.z + \
					smooth_noise_3d(e->c.inter.z + a, e->c.inter.y, \
						e->c.inter.x, e));
			e->cone->norml.y = (e->cone->norml.y + \
				smooth_noise_3d(e->c.inter.z, e->c.inter.y - a, \
					e->c.inter.x, e)) - (e->cone->norml.y + \
					smooth_noise_3d(e->c.inter.z, e->c.inter.y + a, \
						e->c.inter.x, e));
			perlin_cone_sd(e);
		}
	}
}

void	perlin_cyl_sd(t_stuff *e)
{
	int a;

	a = 2;
	e->cyl->norml.x = (e->cyl->norml.x + \
		smooth_noise_3d(e->c.inter.z, e->c.inter.y, e->c.inter.x \
			- a, e)) - (e->cyl->norml.x + \
		smooth_noise_3d(e->c.inter.z, e->c.inter.y, \
			e->c.inter.x + a, e));
}

void	perlin_cyl(t_stuff *e)
{
	int a;

	a = 2;
	if (e->i.perlin == 3)
	{
		if (e->i.objet == -1 || (e->c.objcyl == e->i.each_obj && \
					e->i.objet == CYLINDRE))
		{
			reboot_list_loop(e, 1);
			searchlist(e, e->c.objcyl, CYLINDRE);
			e->cyl->norml.z = (e->cyl->norml.z + \
				smooth_noise_3d(e->c.inter.z - a, e->c.inter.y, \
					e->c.inter.x, e)) - (e->cyl->norml.z + \
					smooth_noise_3d(e->c.inter.z + a, e->c.inter.y, \
						e->c.inter.x, e));
			e->cyl->norml.y = (e->cyl->norml.y + \
				smooth_noise_3d(e->c.inter.z, e->c.inter.y - a, \
					e->c.inter.x, e)) - (e->cyl->norml.y + \
					smooth_noise_3d(e->c.inter.z, e->c.inter.y + a, \
						e->c.inter.x, e));
			perlin_cyl_sd(e);
		}
	}
}
