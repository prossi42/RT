/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortcuts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 12:55:23 by prossi            #+#    #+#             */
/*   Updated: 2018/04/17 14:19:32 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	draw_shortcuts_filters(t_stuff *e)
{
	shortcuts_black_n_white(e);
	shortcuts_cartoon(e);
	shortcuts_blur(e);
	shortcuts_skybox(e);
	shortcuts_negatif(e);
}

void	draw_shorcuts_multiobj(t_stuff *e)
{
	shortcuts_cubespheres(e);
	shortcuts_pyraspheres(e);
	shortcuts_damier(e);
	shortcuts_perlin(e);
	shortcuts_wave(e);
}

void	draw_shortcuts_divers(t_stuff *e)
{
	shortcuts_pixelisation(e);
	shortcuts_antialiasing(e);
	shortcuts_screenshot(e);
	shortcuts_reflexion(e);
	shortcuts_refraction(e);
}

void	shortcuts(t_stuff *e)
{
	if (e->i.first == 0)
	{
		e->i.img_x = WIN_X - WIDTH;
		e->i.img_y = WIN_Y - LENGTH;
		new_img(e);
		init_struct(e, 8);
	}
	else
	{
		reboot_list_interface(e, 1);
		searchlist_interface(e, 8);
	}
	draw_shortcuts(e);
	draw_square_shortcuts(e);
	draw_shortcuts_filters(e);
	draw_shorcuts_multiobj(e);
	draw_shortcuts_divers(e);
	mlx_put_image_to_window(e->img.mlx_ptr, e->img.win_ptr, \
		e->i.mlx->img, (WIN_X - WIDTH) * 2, 0);
}
