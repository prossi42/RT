/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 22:26:52 by prossi            #+#    #+#             */
/*   Updated: 2018/04/16 21:19:51 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	draw_terminal(t_stuff *e)
{
	int		x;
	int		y;

	y = -1;
	while (++y < e->i.mlx->img_y)
	{
		x = -1;
		while (++x < e->i.mlx->img_x)
		{
			pixel_put_to_img(&e->i.mlx, x, y, 0x000000);
		}
	}
	mlx_put_image_to_window(e->img.mlx_ptr, e->img.win_ptr, \
		e->i.mlx->img, 0, (WIN_Y - LENGTH) * 3);
}

void	redraw_tab(t_stuff *e)
{
	int		x;
	int		y;

	y = ((WIN_Y - LENGTH) * 3) - 1;
	while (++y < WIN_Y - 40)
	{
		x = -1;
		while (++x < WIN_X - WIDTH)
		{
			mlx_pixel_put(e->img.mlx_ptr, e->img.win_ptr, x, y, 0x000000);
		}
	}
}

void	terminal_td(t_stuff *e)
{
	if (e->i.term.wbuf[e->i.term.index] == '\n')
	{
		if (e->i.mat.act_angle != 0 || e->i.mat.act_value != 0)
		{
			end_aff_matrice(e);
			e->i.mat.act_angle = 0;
			e->i.mat.act_value = 0;
		}
		else if (e->i.nobj.first != -1)
			end_aff_newobj(e);
		else if (e->i.save.act_save != 0)
			end_aff_save(e);
		else if (e->i.multi != 0)
			end_aff_multiobj(e);
		else if (e->i.perlin == 1 || e->i.perlin == 2)
			end_aff_perlin(e);
		else if (e->i.scr.act_scr == 1)
			end_aff_screenshots(e);
		else if (e->i.damier != -1)
			end_aff_damier(e);
		e->i.term.index = 0;
		if (e->i.term.indextab <= 3)
			e->i.term.indextab++;
		e->i.term.dot = 0;
	}
}

void	terminal_sd(t_stuff *e)
{
	if (e->i.mat.act_angle == 1 && e->i.term.wbuf[e->i.term.index] != '\n')
		aff_angle(e);
	if (e->i.mat.act_value == 1 && e->i.term.wbuf[e->i.term.index] != '\n')
		aff_value(e);
	if (e->i.nobj.first != -1 && e->i.term.wbuf[e->i.term.index] != '\n')
		aff_new_obj(e);
	if (e->i.multi != 0)
		aff_new_multiobj_cubesphere(e);
	if (e->i.perlin == 1)
		aff_perlin(e);
	if (e->i.scr.act_scr == 1)
		aff_screenshots(e);
	if (e->i.damier != -1)
		aff_damier(e);
}

void	terminal(t_stuff *e)
{
	if (e->i.first == 0)
	{
		e->i.img_x = WIN_X - WIDTH;
		e->i.img_y = WIN_Y - ((WIN_Y - LENGTH) * 3);
		new_img(e);
		init_struct(e, 2);
		draw_terminal(e);
	}
	else
	{
		reboot_list_interface(e, 1);
		searchlist_interface(e, 3);
		draw_terminal(e);
		terminal_sd(e);
		terminal_td(e);
		if (e->i.save.act_save == 1 || e->i.save.act_save == 2 || \
			e->i.save.act_save == 6 || e->i.save.act_save == 7)
			aff_save(e);
		else if (e->i.save.act_save == 3)
			save_scene_create_save(e);
		if (e->i.perlin == 2)
			aff_perlin(e);
		aff_tab(e);
	}
}
