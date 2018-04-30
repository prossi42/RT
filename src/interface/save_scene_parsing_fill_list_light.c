/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_scene_parsing_fill_list_light.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 21:43:28 by prossi            #+#    #+#             */
/*   Updated: 2018/04/17 21:46:32 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	save_scene_fill_list_light_sd(t_stuff *e)
{
	e->light->color.b = e->i.load.tabdlight[6];
	if (e->light->color.b > 255)
		e->light->color.b = 255;
	else if (e->light->color.b < 0)
		e->light->color.b = 0;
	e->light->amb = e->i.load.tabdlight[7];
	if (e->light->amb < 0)
		e->light->amb *= -1;
	if (e->light->amb > 1)
		e->light->amb = 1;
	e->light->diff = e->i.load.tabdlight[8];
	if (e->light->diff < 0)
		e->light->diff *= -1;
	if (e->light->diff > 1)
		e->light->diff = 1;
	e->light->nm = e->i.load.nlight;
	free(e->i.load.tabdlight);
}

void	save_scene_fill_list_light(t_stuff *e)
{
	e->light->pos.x = e->i.load.tabdlight[0];
	e->light->pos.y = e->i.load.tabdlight[1];
	e->light->pos.z = e->i.load.tabdlight[2];
	e->light->ray = e->i.load.tabdlight[3];
	if (e->light->ray < 0)
		e->light->ray *= -1;
	e->light->color.r = e->i.load.tabdlight[4];
	if (e->light->color.r > 255)
		e->light->color.r = 255;
	else if (e->light->color.r < 0)
		e->light->color.r = 0;
	e->light->color.g = e->i.load.tabdlight[5];
	if (e->light->color.g > 255)
		e->light->color.g = 255;
	else if (e->light->color.g < 0)
		e->light->color.g = 0;
	save_scene_fill_list_light_sd(e);
}
