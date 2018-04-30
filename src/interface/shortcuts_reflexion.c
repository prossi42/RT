/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortcuts_reflexion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 23:47:38 by prossi            #+#    #+#             */
/*   Updated: 2018/04/17 14:33:34 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	draw_sphere_shortcuts_reflexion(t_stuff *e, int centerx, int centery)
{
	e->bs.x_arc = centerx - 20;
	e->bs.y_arc = centery;
	e->bs.ray_arc = 20;
	e->lt.couleur = 0x000000;
	ft_full_arc(e, 9);
	e->bs.ray_arc = 18;
	e->lt.couleur = 0xFFFFFF;
	ft_full_arc(e, 9);
}

void	draw_ray_shortcuts_reflexion(t_stuff *e, int centerx, int centery)
{
	e->bs.xi = centerx + 35;
	e->bs.yi = centery;
	e->bs.xf = e->bs.xi - 34;
	e->bs.yf = e->bs.yi;
	e->lt.couleur = 0xFFFFFF;
	ft_segment_letter(e);
	e->bs.xi = e->bs.xf;
	e->bs.yi = e->bs.yf;
	e->bs.xf = e->bs.xi + 30;
	e->bs.yf = e->bs.yi - 30;
	ft_segment_letter(e);
	e->bs.xi = centerx + 1;
	e->bs.yi = centery;
	e->bs.xf = e->bs.xi + 20;
	e->bs.yf = e->bs.yi + 20;
	ft_segment_letter(e);
}

void	draw_eye_shortcuts_reflexion(t_stuff *e, int centerx, int centery)
{
	e->lt.couleur = 0xFFFFFF;
	e->bs.x_arc = centerx + 50;
	e->bs.y_arc = centery;
	e->bs.width = 9;
	e->bs.height = 4;
	ft_full_ellipse(e, 0, 0);
	e->lt.couleur = 0x000000;
	e->bs.ray_arc = 5;
	ft_full_arc(e, 9);
	e->lt.couleur = 0xFFFFFF;
	e->bs.xi = e->bs.x_arc;
	e->bs.yi = centery - 10;
	e->bs.xf = e->bs.xi;
	e->bs.yf = e->bs.yi - 4;
	ft_segment_letter(e);
	e->bs.xi = e->bs.x_arc - 5;
	e->bs.yi = centery - 8;
	e->bs.xf = e->bs.xi - 3;
	e->bs.yf = e->bs.yi - 3;
	ft_segment_letter(e);
	e->bs.xi = e->bs.x_arc + 5;
	e->bs.yi = centery - 8;
	e->bs.xf = e->bs.xi + 3;
	e->bs.yf = e->bs.yi - 3;
	ft_segment_letter(e);
}

void	shortcuts_reflexion(t_stuff *e)
{
	int		centerx;
	int		centery;

	centerx = ((e->i.mlx->img_x / 10) * 7) - 10;
	centery = (e->i.mlx->img_y / 3) * 2.5;
	draw_eye_shortcuts_reflexion(e, centerx, centery);
	draw_sphere_shortcuts_reflexion(e, centerx, centery);
	draw_ray_shortcuts_reflexion(e, centerx, centery);
	draw_arrow_shortcuts_reflexion(e, centerx, centery);
}
