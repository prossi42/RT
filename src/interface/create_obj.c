/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 10:39:00 by prossi            #+#    #+#             */
/*   Updated: 2018/04/13 15:33:33 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	create_obj_color(t_stuff *e)
{
	ft_init_value_create_obj_color(e, 0);
	awklm_string_put("Choix des couleurs", e);
	ft_init_value_create_obj_color(e, 1);
	awklm_string_put("Fond", e);
	ft_init_value_create_obj_color(e, 2);
	awklm_string_put("Forme", e);
	ft_init_value_create_obj_color(e, 3);
	awklm_string_put("Police", e);
	ft_init_value_create_obj_color(e, 4);
	empty_box(e);
	ft_init_value_create_obj_color(e, 5);
	full_box(e);
	ft_init_value_create_obj_color(e, 6);
	full_box(e);
}

void	draw_new_obj(t_stuff *e)
{
	int		x;
	int		y;

	y = -1;
	while (++y < e->i.mlx->img_y)
	{
		x = -1;
		while (++x < e->i.mlx->img_x)
			pixel_put_to_img(&e->i.mlx, x, y, e->i.color.nobj.col1);
	}
}

void	draw_objects(t_stuff *e)
{
	if (e->i.objet == SPHERE)
		draw_sphere(e);
	else if (e->i.objet == PLAN)
		draw_plan(e);
	else if (e->i.objet == CYLINDRE)
		draw_cylindre(e);
	else if (e->i.objet == CONE)
		draw_cone(e);
	else
		draw_light(e);
}

void	create_obj_sd(t_stuff *e)
{
	draw_central_background(e);
	draw_side_background(e);
	if (e->i.nobj.power == 1)
	{
		if (e->i.objet == -1)
			draw_camera(e);
		else
			draw_objects(e);
		draw_moins(e);
		draw_plus(e);
	}
}

void	create_obj(t_stuff *e)
{
	if (e->i.first == 0)
	{
		e->i.img_x = WIN_X - WIDTH;
		e->i.img_y = WIN_Y - LENGTH;
		new_img(e);
		init_struct(e, 3);
	}
	else
	{
		reboot_list_interface(e, 1);
		searchlist_interface(e, 2);
	}
	draw_new_obj(e);
	if (e->i.nobj.settings == 0 || e->i.nobj.settings == 1)
		create_obj_sd(e);
	if (e->i.nobj.settings == 1)
	{
		ft_init_value_draw_settings(e, 0);
		settings(e);
	}
	if (e->i.nobj.settings == 2)
		create_obj_color(e);
	mlx_put_image_to_window(e->img.mlx_ptr, e->img.win_ptr, e->i.mlx->img, 0, \
		WIN_Y - LENGTH + WIN_Y - LENGTH);
}
