/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <jgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:09:06 by jgaillar          #+#    #+#             */
/*   Updated: 2018/04/12 13:29:04 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		raythingy_sd(t_stuff *e, t_vec *raydir)
{
	if (e->c.obj == LIGHT)
	{
		searchlist(e, e->c.objlight, LIGHT);
		rgb_add(&e->c.colorf, e->c.colorf, e->light->color, 1);
	}
	else if (e->c.obj == -1 && e->tex.act_skybox == 1)
		e->c.colorf = skybox(e, e->c.colorf, raydir);
}

t_rgb			raythingy(t_stuff *e, t_vec *raydir, t_vec *pos)
{
	init_raythingy(e, raydir, pos);
	if (e->c.obj >= 0 && e->c.obj <= 3)
	{
		if (e->i.filtre == 5)
			dam(e, e->i.objet);
		getintersection(e, e->c.dist, raydir, pos);
		while (e->light)
		{
			light_set(e);
			if (e->c.dist > e->light->t && e->c.dist > 0.00001 && \
			e->light->t > 0.00001)
				lumos_maxima(e, raydir);
			if (e->light->next != NULL)
				e->light = e->light->next;
			else
				break ;
		}
		after_light(e);
	}
	raythingy_sd(e, raydir);
	return (e->c.colorf);
}

void			pixelisation(t_stuff *e, double color)
{
	int j;
	int i;

	j = -1;
	while (++j <= e->pix)
	{
		i = -1;
		while (++i <= e->pix)
			mlx_pixel_put_to_image(e->img, e->c.posx + i,\
				e->c.posy + j, color);
	}
	e->c.posx += e->pix;
}

void			init_raythingy(t_stuff *e, t_vec *raydir, t_vec *pos)
{
	e->l = 0;
	e->ray++;
	e->test = 0;
	init_rgb(&e->c.colorf, 0, 0, 0);
	e->u = 0;
	check(e, raydir, pos, 1);
	check_dist(e, 1);
	reboot_list_loop(e, 3);
}
