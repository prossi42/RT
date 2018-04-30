/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apercu_courant_fill_value.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 07:58:05 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 12:38:22 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	fill_value_apercu_td(t_stuff *e)
{
	if (e->i.objet == PLAN)
	{
		e->i.mlx->data.pos = e->pla->pos;
		e->i.mlx->data.dir = e->pla->norm;
		e->i.mlx->data.color = e->pla->color;
		e->i.mlx->data.text = e->pla->text;
		e->i.mlx->data.ray = 0;
	}
	else if (e->i.objet == CONE)
	{
		e->i.mlx->data.pos = e->cone->pos;
		e->i.mlx->data.dir = e->cone->norm;
		e->i.mlx->data.color = e->cone->color;
		e->i.mlx->data.text = e->cone->text;
		e->i.mlx->data.ray = 0;
	}
}

void	fill_value_apercu_sd(t_stuff *e)
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
	}
	else if (e->i.objet == CYLINDRE)
	{
		e->i.mlx->data.pos = e->cyl->pos;
		e->i.mlx->data.dir = e->cyl->norm;
		e->i.mlx->data.color = e->cyl->color;
		e->i.mlx->data.text = e->cyl->text;
		e->i.mlx->data.ray = e->cyl->ray;
	}
}

void	fill_value_apercu(t_stuff *e)
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
	}
	else if (e->i.objet == LIGHT || e->i.objet == CYLINDRE)
		fill_value_apercu_sd(e);
	else if (e->i.objet == PLAN || e->i.objet == CONE)
		fill_value_apercu_td(e);
}
