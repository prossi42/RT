/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 10:39:00 by prossi            #+#    #+#             */
/*   Updated: 2018/02/22 22:47:00 by Awk-LM           ###   ########.fr       */
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
			pixel_put_to_img(&e->i.mlx, x, y, 0x202020);
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
		// draw_garbage(e);
		// draw_plus(e);
	}
	mlx_put_image_to_window(e->img.mlx_ptr, e->img.win_ptr, e->i.mlx->img, 0, WIN_Y - LENGTH + WIN_Y - LENGTH);
}
