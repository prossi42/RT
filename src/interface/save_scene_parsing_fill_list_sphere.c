/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_scene_parsing_fill_list_sphere.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 21:39:27 by prossi            #+#    #+#             */
/*   Updated: 2018/04/17 21:59:19 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	save_scene_fill_list_sph_sd(t_stuff *e)
{
	e->sph->refrac = e->i.load.tabdsph[7];
	if (e->sph->refrac > 2)
		e->sph->refrac = 2;
	else if (e->sph->refrac < 1 && e->sph->refrac > 0)
		e->sph->refrac = 1;
	else if (e->sph->refrac < 0)
		e->sph->refrac = 0;
	e->sph->conscol = e->i.load.tabdsph[8];
	if (e->sph->conscol > 1)
		e->sph->conscol = 1;
	else if (e->sph->conscol < 0)
		e->sph->conscol = 0;
	e->sph->reflex = e->i.load.tabdsph[9];
	if (e->sph->reflex > 1)
		e->sph->reflex = 1;
	else if (e->sph->reflex < 0)
		e->sph->reflex = 0;
	e->sph->nm = e->i.load.nsph;
	free(e->i.load.tabdsph);
}

void	save_scene_fill_list_sph(t_stuff *e)
{
	e->sph->pos.x = e->i.load.tabdsph[0];
	e->sph->pos.y = e->i.load.tabdsph[1];
	e->sph->pos.z = e->i.load.tabdsph[2];
	e->sph->ray = e->i.load.tabdsph[3];
	if (e->sph->ray < 0)
		e->sph->ray *= -1;
	e->sph->color.r = e->i.load.tabdsph[4];
	if (e->sph->color.r > 255)
		e->sph->color.r = 255;
	else if (e->sph->color.r < 0)
		e->sph->color.r = 0;
	e->sph->color.g = e->i.load.tabdsph[5];
	if (e->sph->color.g > 255)
		e->sph->color.g = 255;
	else if (e->sph->color.g < 0)
		e->sph->color.g = 0;
	e->sph->color.b = e->i.load.tabdsph[6];
	if (e->sph->color.b > 255)
		e->sph->color.b = 255;
	else if (e->sph->color.b < 0)
		e->sph->color.b = 0;
	save_scene_fill_list_sph_sd(e);
}
