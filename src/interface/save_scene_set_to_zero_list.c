/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_scene_set_to_zero_list.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 21:04:46 by prossi            #+#    #+#             */
/*   Updated: 2018/04/17 21:06:04 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	set_to_zero_list_sph(t_stuff *e)
{
	e->sph->pos.x = 0;
	e->sph->pos.y = 0;
	e->sph->pos.z = 0;
	e->sph->color.r = 0;
	e->sph->color.g = 0;
	e->sph->color.b = 0;
	e->sph->ray = 0;
	e->sph->nm = 0;
	e->sph->refrac = 0;
	e->sph->conscol = 0;
	e->sph->reflex = 0;
}

void	set_to_zero_list_plan(t_stuff *e)
{
	e->pla->pos.x = 0;
	e->pla->pos.y = 0;
	e->pla->pos.z = 0;
	e->pla->color.r = 0;
	e->pla->color.g = 0;
	e->pla->color.b = 0;
	e->pla->norm.x = 0;
	e->pla->norm.y = 0;
	e->pla->norm.z = 0;
	e->pla->nm = 0;
	e->pla->refrac = 0;
	e->pla->reflex = 0;
	e->pla->conscol = 0;
	e->pla->ray = 0;
}

void	set_to_zero_list_light(t_stuff *e)
{
	e->light->pos.x = 0;
	e->light->pos.y = 0;
	e->light->pos.z = 0;
	e->light->color.r = 0;
	e->light->color.g = 0;
	e->light->color.b = 0;
	e->light->ray = 0;
	e->light->amb = 0;
	e->light->diff = 0;
	e->light->nm = 0;
}

void	set_to_zero_list_cylindre(t_stuff *e)
{
	e->cyl->pos.x = 0;
	e->cyl->pos.y = 0;
	e->cyl->pos.z = 0;
	e->cyl->color.r = 0;
	e->cyl->color.g = 0;
	e->cyl->color.b = 0;
	e->cyl->norm.x = 0;
	e->cyl->norm.y = 0;
	e->cyl->norm.z = 0;
	e->cyl->ray = 0;
	e->cyl->nm = 0;
	e->cyl->refrac = 0;
	e->cyl->reflex = 0;
	e->cyl->conscol = 0;
}

void	set_to_zero_list_cone(t_stuff *e)
{
	e->cone->pos.x = 0;
	e->cone->pos.y = 0;
	e->cone->pos.z = 0;
	e->cone->color.r = 0;
	e->cone->color.g = 0;
	e->cone->color.b = 0;
	e->cone->norm.x = 0;
	e->cone->norm.y = 0;
	e->cone->norm.z = 0;
	e->cone->angle = 0;
	e->cone->nm = 0;
	e->cone->refrac = 0;
	e->cone->conscol = 0;
	e->cone->reflex = 0;
}
