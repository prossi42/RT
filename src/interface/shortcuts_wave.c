/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortcuts_wave.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 16:06:12 by prossi            #+#    #+#             */
/*   Updated: 2018/04/05 16:54:28 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	draw_arc_shortcuts_wave(t_stuff *e, int x, int y)
{
	e->bs.x_arc = x + 22;
	e->bs.y_arc = y;
	e->bs.ray_arc = 8;
	ft_arc(e, 3);
	e->bs.x_arc += 30;
	ft_arc(e, 3);
	e->bs.x_arc += 30;
	ft_arc(e, 3);
}

void	draw_line_shortcuts_wave(t_stuff *e, int x, int y)
{
	e->lt.couleur = 0xFFFFFF;
	e->bs.xi = x;
	e->bs.yi = y;
	e->bs.xf = e->bs.xi + 14;
	e->bs.yf = e->bs.yi;
	ft_segment_letter(e);
	e->bs.xi = e->bs.xf + 16;
	e->bs.yi = e->bs.yf;
	e->bs.xf = e->bs.xi + 14;
	e->bs.yf = e->bs.yi;
	ft_segment_letter(e);
	e->bs.xi = e->bs.xf + 16;
	e->bs.yi = e->bs.yf;
	e->bs.xf = e->bs.xi + 14;
	e->bs.yf = e->bs.yi;
	ft_segment_letter(e);
	e->bs.xi = e->bs.xf + 16;
	e->bs.yi = e->bs.yf;
	e->bs.xf = e->bs.xi + 11;
	e->bs.yf = e->bs.yi;
	ft_segment_letter(e);
}

void	shortcuts_wave(t_stuff *e)
{
	int		borderx;
	int		bordery;
	int		i;

	borderx = ((e->i.mlx->img_x / 5) * 4) + 1;
	bordery = (e->i.mlx->img_y / 3) + 10;
	i = -1;
	while (++i < 40)
	{
		draw_line_shortcuts_wave(e, borderx, bordery);
		draw_arc_shortcuts_wave(e, borderx, bordery);
		bordery += 2;
	}
}
