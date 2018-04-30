/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_scene_parsing_fill_list.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 11:06:43 by prossi            #+#    #+#             */
/*   Updated: 2018/04/17 21:50:37 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	save_scene_fill_list_cone_sd(t_stuff *e)
{
	e->cone->angle = e->i.load.tabdcone[9];
	if (e->cone->angle < 0)
		e->cone->angle *= -1;
	e->cone->refrac = e->i.load.tabdcone[10];
	if (e->cone->refrac > 2)
		e->cone->refrac = 2;
	else if (e->cone->refrac < 1 && e->cone->refrac > 0)
		e->cone->refrac = 1;
	else if (e->cone->refrac < 0)
		e->cone->refrac = 0;
	e->cone->conscol = e->i.load.tabdcone[11];
	if (e->cone->conscol > 1)
		e->cone->conscol = 1;
	else if (e->cone->conscol < 0)
		e->cone->conscol = 0;
	e->cone->reflex = e->i.load.tabdcone[12];
	if (e->cone->reflex > 1)
		e->cone->reflex = 1;
	else if (e->cone->reflex < 0)
		e->cone->reflex = 0;
	e->cone->nm = e->i.load.ncone;
	free(e->i.load.tabdcone);
}

void	save_scene_fill_list_cone(t_stuff *e)
{
	e->cone->pos.x = e->i.load.tabdcone[0];
	e->cone->pos.y = e->i.load.tabdcone[1];
	e->cone->pos.z = e->i.load.tabdcone[2];
	e->cone->color.r = e->i.load.tabdcone[3];
	if (e->cone->color.r > 255)
		e->cone->color.r = 255;
	else if (e->cone->color.r < 0)
		e->cone->color.r = 0;
	e->cone->color.g = e->i.load.tabdcone[4];
	if (e->cone->color.g > 255)
		e->cone->color.g = 255;
	else if (e->cone->color.g < 0)
		e->cone->color.g = 0;
	e->cone->color.b = e->i.load.tabdcone[5];
	if (e->cone->color.b > 255)
		e->cone->color.b = 255;
	else if (e->cone->color.b < 0)
		e->cone->color.b = 0;
	e->cone->norm.x = e->i.load.tabdcone[6];
	e->cone->norm.y = e->i.load.tabdcone[7];
	e->cone->norm.z = e->i.load.tabdcone[8];
	vecnorm(&e->cone->norm);
	save_scene_fill_list_cone_sd(e);
}
