/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objet_courant_fill_value_current.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:30:08 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 10:30:08 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	fill_value_current_td(t_stuff *e)
{
	if (e->i.objet == PLAN)
	{
		e->i.mlx->data.pos = e->pla->pos;
		e->i.mlx->data.dir = e->pla->norm;
		e->i.mlx->data.color = e->pla->color;
		e->i.mlx->data.text = e->pla->text;
		e->i.mlx->data.ray = 0;
		e->i.mlx->data.refrac = e->pla->refrac;
		e->i.mlx->data.reflex = e->pla->reflex;
		e->i.mlx->data.conscol = e->pla->conscol;
	}
	else if (e->i.objet == CONE)
	{
		e->i.mlx->data.pos = e->cone->pos;
		e->i.mlx->data.dir = e->cone->norm;
		e->i.mlx->data.color = e->cone->color;
		e->i.mlx->data.text = e->cone->text;
		e->i.mlx->data.angle = e->cone->angle;
		e->i.mlx->data.refrac = e->cone->refrac;
		e->i.mlx->data.reflex = e->cone->reflex;
		e->i.mlx->data.conscol = e->cone->conscol;
	}
}

void	fill_value_current_sd(t_stuff *e)
{
	if (e->i.objet == LIGHT)
	{
		e->i.mlx->data.pos = e->light->pos;
		e->i.mlx->data.dir.x = 0;
		e->i.mlx->data.dir.y = 0;
		e->i.mlx->data.dir.z = 0;
		e->i.mlx->data.color = e->light->color;
		e->i.mlx->data.text = e->light->text;
		e->i.mlx->data.ray = e->light->ray;
		e->i.mlx->data.amb = e->light->amb;
		e->i.mlx->data.diff = e->light->diff;
	}
	else if (e->i.objet == CYLINDRE)
	{
		e->i.mlx->data.pos = e->cyl->pos;
		e->i.mlx->data.dir = e->cyl->norm;
		e->i.mlx->data.color = e->cyl->color;
		e->i.mlx->data.text = e->cyl->text;
		e->i.mlx->data.ray = e->cyl->ray;
		e->i.mlx->data.refrac = e->cyl->refrac;
		e->i.mlx->data.reflex = e->cyl->reflex;
		e->i.mlx->data.conscol = e->cyl->conscol;
	}
	fill_value_current_td(e);
}

void	fill_value_current(t_stuff *e)
{
	if (e->i.objet == -1)
	{
		e->i.mlx->data.pos = e->poscam;
		e->i.mlx->data.dir = e->dircam;
	}
	else if (e->i.objet == SPHERE)
	{
		e->i.mlx->data.pos = e->sph->pos;
		e->i.mlx->data.dir.x = 0;
		e->i.mlx->data.dir.y = 0;
		e->i.mlx->data.dir.z = 0;
		e->i.mlx->data.color = e->sph->color;
		e->i.mlx->data.text = e->sph->text;
		e->i.mlx->data.ray = e->sph->ray;
		e->i.mlx->data.refrac = e->sph->refrac;
		e->i.mlx->data.reflex = e->sph->reflex;
		e->i.mlx->data.conscol = e->sph->conscol;
	}
	fill_value_current_sd(e);
}
