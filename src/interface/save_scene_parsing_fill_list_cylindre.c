/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_scene_parsing_fill_list_cylindre.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:45:52 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 10:46:48 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	save_scene_fill_list_cyl_sd(t_stuff *e)
{
	e->cyl->color.b = e->i.load.tabdcyl[9];
	if (e->cyl->color.b > 255)
		e->cyl->color.b = 255;
	else if (e->cyl->color.b < 0)
		e->cyl->color.b = 0;
	e->cyl->refrac = e->i.load.tabdcyl[10];
	if (e->cyl->refrac > 2)
		e->cyl->refrac = 2;
	else if (e->cyl->refrac < 1 && e->cyl->refrac > 0)
		e->cyl->refrac = 1;
	else if (e->cyl->refrac < 0)
		e->cyl->refrac = 0;
	e->cyl->conscol = e->i.load.tabdcyl[11];
	if (e->cyl->conscol > 1)
		e->cyl->conscol = 1;
	else if (e->cyl->conscol < 0)
		e->cyl->conscol = 0;
	e->cyl->reflex = e->i.load.tabdcyl[12];
	if (e->cyl->reflex > 1)
		e->cyl->reflex = 1;
	else if (e->cyl->reflex < 0)
		e->cyl->reflex = 0;
	e->cyl->nm = e->i.load.ncyl;
	free(e->i.load.tabdcyl);
}

void	save_scene_fill_list_cyl(t_stuff *e)
{
	e->cyl->pos.x = e->i.load.tabdcyl[0];
	e->cyl->pos.y = e->i.load.tabdcyl[1];
	e->cyl->pos.z = e->i.load.tabdcyl[2];
	e->cyl->norm.x = e->i.load.tabdcyl[3];
	e->cyl->norm.y = e->i.load.tabdcyl[4];
	e->cyl->norm.z = e->i.load.tabdcyl[5];
	vecnorm(&e->cyl->norm);
	e->cyl->ray = e->i.load.tabdcyl[6];
	if (e->cyl->ray < 0)
		e->cyl->ray *= -1;
	e->cyl->color.r = e->i.load.tabdcyl[7];
	if (e->cyl->color.r > 255)
		e->cyl->color.r = 255;
	else if (e->cyl->color.r < 0)
		e->cyl->color.r = 0;
	e->cyl->color.g = e->i.load.tabdcyl[8];
	if (e->cyl->color.g > 255)
		e->cyl->color.g = 255;
	else if (e->cyl->color.g < 0)
		e->cyl->color.g = 0;
	save_scene_fill_list_cyl_sd(e);
}
