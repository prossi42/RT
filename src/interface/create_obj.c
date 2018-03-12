/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 10:39:00 by prossi            #+#    #+#             */
/*   Updated: 2018/03/12 11:01:06 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

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

void	draw_obj(t_stuff *e)
{
	if (e->i.objet == -1)
		draw_camera(e);
	else
		draw_objects(e);
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
	draw_central_background(e);
	draw_side_background(e);
	if (e->i.nobj.power == 1)
	{
		draw_obj(e);
		draw_moins(e);
		draw_plus(e);
	}
	mlx_put_image_to_window(e->img.mlx_ptr, e->img.win_ptr, e->i.mlx->img, 0, WIN_Y - LENGTH + WIN_Y - LENGTH);
	mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, WIN_X - WIDTH - 10, (WIN_Y - LENGTH) * 2, 0xFFFFFF, "?");
}
