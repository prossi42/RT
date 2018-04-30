/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortcuts_draw_bier_shortcuts.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 14:40:12 by prossi            #+#    #+#             */
/*   Updated: 2018/04/17 14:43:40 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	draw_bier_blur_fh(t_stuff *e, int borderx)
{
	e->lt.couleur = 0x000000;
	e->lt.posx = borderx + (e->i.mlx->img_x / 10) + 28;
	e->lt.posy = 65;
	e->bs.width = 25;
	e->bs.height = 60;
	full_box(e);
	e->lt.couleur = 0xFFFFFF;
	e->lt.posy = 60;
	e->bs.width = 15;
	e->bs.height = 35;
	full_box(e);
}

void	draw_bier_blur_td(t_stuff *e, int borderx)
{
	e->lt.couleur = 0xFFFFFF;
	e->bs.x_arc = borderx + (e->i.mlx->img_x / 10);
	e->bs.y_arc = 47;
	e->bs.ray_arc = 3;
	ft_arc(e, 9);
	fill_beer_foam(e, 1);
	e->bs.x_arc = borderx + (e->i.mlx->img_x / 10) - 15;
	e->bs.y_arc = 45;
	e->bs.ray_arc = 3;
	ft_arc(e, 9);
	fill_beer_foam(e, 1);
	e->bs.x_arc = borderx + (e->i.mlx->img_x / 10) + 15;
	e->bs.y_arc = 45;
	e->bs.ray_arc = 3;
	ft_arc(e, 9);
	fill_beer_foam(e, 1);
	draw_bier_blur_fh(e, borderx);
}

void	draw_bier_blur_sd(t_stuff *e, int borderx)
{
	e->lt.couleur = 0xFFFFFF;
	e->bs.width = 15;
	e->bs.height = 15;
	ft_ellipse(e, 0, 0);
	fill_ellipse_blur(e);
	e->lt.couleur = 0x000000;
	e->bs.x_arc = borderx + 35;
	e->bs.y_arc = 23;
	e->bs.ray_arc = 15;
	ft_arc(e, 9);
	fill_arc_blur(e);
	e->lt.couleur = 0x000000;
	e->bs.x_arc = borderx + 68;
	e->bs.y_arc = 23;
	e->bs.ray_arc = 15;
	ft_arc(e, 9);
	fill_arc_blur(e);
	e->lt.couleur = 0xFFFFFF;
	e->bs.x_arc = borderx + 35;
	e->bs.ray_arc = 10;
	ft_arc(e, 9);
	fill_arc_blur(e);
	fill_beer_foam(e, 0);
	draw_bier_blur_td(e, borderx);
}

void	draw_bier_blur(t_stuff *e)
{
	int		borderx;

	borderx = (e->i.mlx->img_x / 10) * 4;
	e->lt.couleur = 0x000000;
	e->bs.x_arc = borderx + (e->i.mlx->img_x / 10);
	e->bs.y_arc = 75;
	e->bs.width = 30;
	e->bs.height = 10;
	ft_ellipse(e, 0, 0);
	fill_ellipse_blur(e);
	e->lt.posx = borderx + 25;
	e->lt.posy = 75;
	e->bs.width = 135;
	e->bs.height = 145;
	full_box(e);
	e->lt.couleur = 0x000000;
	e->bs.x_arc = borderx + (e->i.mlx->img_x / 10);
	e->bs.y_arc = 23;
	e->bs.width = 20;
	e->bs.height = 20;
	ft_ellipse(e, 0, 0);
	fill_ellipse_blur(e);
	draw_bier_blur_sd(e, borderx);
}
