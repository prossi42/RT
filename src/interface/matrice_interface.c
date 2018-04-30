/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_interface.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 22:29:49 by prossi            #+#    #+#             */
/*   Updated: 2018/04/13 16:45:27 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	draw_matrice_interface(t_stuff *e)
{
	int		x;
	int		y;

	y = -1;
	while (++y < e->i.mlx->img_y)
	{
		x = -1;
		while (++x < e->i.mlx->img_x)
		{
			pixel_put_to_img(&e->i.mlx, x, y, e->i.color.mat.col1);
		}
	}
}

void	matrice_interface_sd(t_stuff *e)
{
	draw_matrice_interface(e);
	if (e->i.mat.settings == 0 || e->i.mat.settings == 1)
	{
		matrice_draw_ellipse_background(e);
		matrice_draw_title_background(e);
		redraw_ellipse(e);
	}
	if (e->i.mat.settings == 1)
	{
		ft_init_value_draw_settings(e, 0);
		settings(e);
	}
	if (e->i.mat.settings == 2)
		settings_color(e);
}

void	matrice_interface(t_stuff *e)
{
	if (e->i.first == 0)
	{
		e->i.img_x = (WIN_X - WIDTH) / 2;
		e->i.img_y = WIN_Y - LENGTH;
		new_img(e);
		init_struct(e, 1);
	}
	else
	{
		reboot_list_interface(e, 1);
		searchlist_interface(e, 4);
	}
	matrice_interface_sd(e);
	mlx_put_image_to_window(e->img.mlx_ptr, e->img.win_ptr, e->i.mlx->img, \
		WIN_X - WIDTH, 0);
}
