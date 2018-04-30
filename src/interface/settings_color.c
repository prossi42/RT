/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 10:47:43 by prossi            #+#    #+#             */
/*   Updated: 2018/04/17 20:49:03 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	settings_color_fih(t_stuff *e)
{
	if (e->i.mat.settings > 2 || e->i.save.settings > 2)
	{
		draw_settings_color(e);
		fill_tab_pix_sd(e);
		mlx_put_image_to_window(e->img.mlx_ptr, e->img.win_ptr, \
			e->i.mlx->img, WIN_X - WIDTH, 0);
	}
}

void	settings_color_fh(t_stuff *e)
{
	if (e->i.mat.settings == 2 || e->i.save.settings == 2)
	{
		draw_settings_color(e);
		if (e->i.mat.settings == 2)
			settings_color_bind(e, e->i.color.mat);
		if (e->i.save.settings == 2)
			settings_color_bind(e, e->i.color.saves);
		mlx_put_image_to_window(e->img.mlx_ptr, e->img.win_ptr, \
			e->i.mlx->img, WIN_X - WIDTH, 0);
	}
}

void	settings_color_td(t_stuff *e)
{
	if (e->i.cobj.settings > 2)
	{
		fill_tab_pix_sd(e);
		mlx_put_image_to_window(e->img.mlx_ptr, e->img.win_ptr, \
			e->i.mlx->img, 0, 0);
	}
}

void	settings_color_sd(t_stuff *e)
{
	if (e->i.nobj.settings > 2)
	{
		fill_tab_pix_sd(e);
		mlx_put_image_to_window(e->img.mlx_ptr, e->img.win_ptr, \
			e->i.mlx->img, 0, WIN_Y - LENGTH + WIN_Y - LENGTH);
	}
}

void	settings_color(t_stuff *e)
{
	if (e->i.first == 0)
	{
		e->i.img_x = WIN_X - WIDTH;
		e->i.img_y = WIN_Y - LENGTH;
		new_img(e);
		init_struct(e, 7);
		fill_tab_pix(e);
	}
	else
	{
		reboot_list_interface(e, 1);
		searchlist_interface(e, 7);
		settings_color_sd(e);
		settings_color_td(e);
		settings_color_fh(e);
		settings_color_fih(e);
	}
}
