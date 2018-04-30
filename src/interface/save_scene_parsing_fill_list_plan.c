/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_scene_parsing_fill_list_plan.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 21:42:14 by prossi            #+#    #+#             */
/*   Updated: 2018/04/17 21:43:17 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	save_scene_fill_list_pla_sd(t_stuff *e)
{
	e->pla->refrac = e->i.load.tabdpla[9];
	if (e->pla->refrac > 2)
		e->pla->refrac = 2;
	else if (e->pla->refrac < 1 && e->pla->refrac > 0)
		e->pla->refrac = 1;
	else if (e->pla->refrac < 0)
		e->pla->refrac = 0;
	e->pla->conscol = e->i.load.tabdpla[10];
	if (e->pla->conscol > 1)
		e->pla->conscol = 1;
	else if (e->pla->conscol < 0)
		e->pla->conscol = 0;
	e->pla->reflex = e->i.load.tabdpla[11];
	if (e->pla->reflex > 1)
		e->pla->reflex = 1;
	else if (e->pla->reflex < 0)
		e->pla->reflex = 0;
	e->pla->ray = e->i.load.tabdpla[12];
	if (e->pla->ray < 0)
		e->pla->ray *= -1;
	e->pla->nm = e->i.load.npla;
	free(e->i.load.tabdpla);
}

void	save_scene_fill_list_pla(t_stuff *e)
{
	e->pla->pos.x = e->i.load.tabdpla[0];
	e->pla->pos.y = e->i.load.tabdpla[1];
	e->pla->pos.z = e->i.load.tabdpla[2];
	e->pla->color.r = e->i.load.tabdpla[3];
	if (e->pla->color.r > 255)
		e->pla->color.r = 255;
	else if (e->pla->color.r < 0)
		e->pla->color.r = 0;
	e->pla->color.g = e->i.load.tabdpla[4];
	if (e->pla->color.g > 255)
		e->pla->color.g = 255;
	else if (e->pla->color.g < 0)
		e->pla->color.g = 0;
	e->pla->color.b = e->i.load.tabdpla[5];
	if (e->pla->color.b > 255)
		e->pla->color.b = 255;
	else if (e->pla->color.b < 0)
		e->pla->color.b = 0;
	e->pla->norm.x = e->i.load.tabdpla[6];
	e->pla->norm.y = e->i.load.tabdpla[7];
	e->pla->norm.z = e->i.load.tabdpla[8];
	vecnorm(&e->pla->norm);
	save_scene_fill_list_pla_sd(e);
}
