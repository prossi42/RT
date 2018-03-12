/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objet_courant.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 22:13:22 by prossi            #+#    #+#             */
/*   Updated: 2018/03/12 11:04:00 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

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
		//DONT FORGET MATERIAUX
	}
	else if (e->i.objet == LIGHT)
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
		//DONT FORGET MATERIAUX
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
		//DONT FORGET MATERIAUX
	}
	else if (e->i.objet == PLAN)
	{
		e->i.mlx->data.pos = e->pla->pos;
		e->i.mlx->data.dir = e->pla->norm;
		e->i.mlx->data.color = e->pla->color;
		e->i.mlx->data.text = e->pla->text;
		e->i.mlx->data.ray = 0;
		e->i.mlx->data.refrac = e->pla->refrac;
		e->i.mlx->data.reflex = e->pla->reflex;
		e->i.mlx->data.conscol = e->pla->conscol;
		//DONT FORGET MATERIAUX
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
		//DONT FORGET MATERIAUX
	}
}

void	get_value_current(t_stuff *e)
{
	reboot_list_loop(e, 3);
	if (e->i.objet == SPHERE)
		searchlist(e, e->i.each_obj, SPHERE);
	else if (e->i.objet == LIGHT)
		searchlist(e, e->i.each_obj, LIGHT);
	else if (e->i.objet == CYLINDRE)
		searchlist(e, e->i.each_obj, CYLINDRE);
	else if (e->i.objet == PLAN)
		searchlist(e, e->i.each_obj, PLAN);
	else if (e->i.objet == CONE)
		searchlist(e, e->i.each_obj, CONE);
	fill_value_current(e);
}

void	aff_data(t_stuff *e)
{
	if (e->i.objet == -1)
		aff_data_camera(e);
	else if (e->i.objet == SPHERE)
		aff_data_sphere(e);
	else if (e->i.objet == LIGHT)
		aff_data_light(e);
	else if (e->i.objet == CYLINDRE)
		aff_data_cylindre(e);
	else if (e->i.objet == PLAN)
		aff_data_plan(e);
	else if (e->i.objet == CONE)
		aff_data_cone(e);
}

void	draw_objet_courant(t_stuff *e)
{
	int		x;
	int		y;

	y = -1;
	while (++y < e->i.mlx->img_y)
	{
		x = -1;
		while (++x < e->i.mlx->img_x)
			pixel_put_to_img(&e->i.mlx, x, y, e->i.color.cobj.col1);
	}
}

void	objet_courant(t_stuff *e)
{
	if (e->i.first == 0)
	{
		e->i.img_x = WIN_X - WIDTH;
		e->i.img_y = WIN_Y - LENGTH;
		new_img(e);
		init_struct(e, 4);
	}
	else
	{
		reboot_list_interface(e, 1);
		searchlist_interface(e, 0);
	}
	get_value_current(e);
	draw_objet_courant(e);
	draw_ellipse_background(e);
	if (e->i.cobj.power == 0)
		draw_title_background(e);
	if (e->i.cobj.power == 1)
		aff_data(e);
	mlx_put_image_to_window(e->img.mlx_ptr, e->img.win_ptr, e->i.mlx->img, 0, 0);
	mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, WIN_X - WIDTH - 10, 0, 0xFFFFFF, "?");
}
