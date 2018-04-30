/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortcuts_skybox.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 18:27:23 by prossi            #+#    #+#             */
/*   Updated: 2018/04/17 14:20:49 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	draw_sun_shortcuts_skybox(t_stuff *e, int borderx)
{
	e->bs.x_arc = borderx + 40;
	e->bs.y_arc = 30;
	e->lt.couleur = 0xFFFF00;
	e->bs.ray_arc = 10;
	ft_full_arc(e, 9);
	e->bs.ray_arc = 13;
	ft_arc(e, 9);
}

void	draw_cloud_shortcuts_skybox(t_stuff *e, int posx, int posy)
{
	int		i;

	i = -1;
	e->bs.x_arc = posx;
	e->bs.y_arc = posy;
	e->lt.couleur = 0xFFFFFF;
	while (++i < 20)
	{
		e->bs.ray_arc = 5;
		e->bs.x_arc++;
		ft_full_arc(e, 9);
	}
	e->bs.x_arc = posx + 5;
	e->bs.y_arc = posy - 5;
	while (++i < 31)
	{
		e->bs.ray_arc = 5;
		e->bs.x_arc++;
		ft_full_arc(e, 9);
	}
	e->bs.x_arc = posx + 10;
	e->bs.y_arc = posy - 8;
	e->bs.ray_arc = 5;
	e->bs.x_arc++;
	ft_full_arc(e, 9);
}

void	draw_background_shortcuts_skybox(t_stuff *e, int borderx)
{
	int		i;

	i = -1;
	e->bs.x_arc = borderx + (e->i.mlx->img_x / 10);
	e->bs.y_arc = 20;
	e->bs.width = 42;
	e->bs.height = 10;
	e->lt.couleur = 0x00CCFF;
	ft_full_ellipse(e, 0, 0);
	while (++i < 60)
	{
		e->bs.y_arc++;
		e->bs.width = 42;
		e->bs.height = 10;
		ft_full_ellipse(e, 0, 0);
	}
	e->lt.couleur = 0x202020;
	e->bs.width = 42;
	e->bs.height = 10;
	ft_full_ellipse(e, 0, 0);
}

void	shortcuts_skybox(t_stuff *e)
{
	int		borderx;

	borderx = ((e->i.mlx->img_x / 5) * 3);
	draw_background_shortcuts_skybox(e, borderx);
	draw_sun_shortcuts_skybox(e, borderx);
	draw_cloud_shortcuts_skybox(e, borderx + 10 + (e->i.mlx->img_x / 10) \
	- 1, e->i.mlx->img_y / 6);
	draw_cloud_shortcuts_skybox(e, borderx + 17, (e->i.mlx->img_y / 6) - 20);
	draw_cloud_shortcuts_skybox(e, borderx + 30, (e->i.mlx->img_y / 6) + 16);
}
