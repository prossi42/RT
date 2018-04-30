/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortcuts_antialiasing.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 09:38:53 by prossi            #+#    #+#             */
/*   Updated: 2018/04/16 21:43:34 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	draw_up_antialiasing(t_stuff *e, int borderx, int bordery)
{
	int		option;

	option = 0;
	e->lt.couleur = 0xFFFFFF;
	e->bs.xi = borderx + 10;
	e->bs.yi = bordery - 1;
	e->bs.xf = e->bs.xi;
	e->bs.yf = e->bs.yi - 10;
	ft_segment_letter(e);
	while (e->bs.yi > ((e->i.mlx->img_y / 3) * 2) + 10)
	{
		if (option == 0)
		{
			option = 1;
			e->bs.xf += 30;
			ft_segment_letter(e);
		}
		else
		{
			option = 0;
			e->bs.yf -= 11;
			ft_segment_letter(e);
		}
	}
}

void	draw_down_antialiasing(t_stuff *e, int endx)
{
	e->bs.x_arc = endx;
	e->bs.y_arc = e->i.mlx->img_y;
	e->bs.width = endx / 2;
	e->bs.height = 40;
	ft_ellipse(e, 1, 3);
	ft_ellipse(e, 2, 1);
}

void	draw_separate_antialiasing(t_stuff *e)
{
	e->lt.couleur = 0x000000;
	e->bs.xi = (e->i.mlx->img_x / 10) * 2 + 1;
	e->bs.yi = (e->i.mlx->img_y / 3) * 2.5;
	e->bs.xf = (e->i.mlx->img_x / 10) * 4 - 1;
	e->bs.yf = e->bs.yi;
	ft_segment_letter(e);
	e->bs.xi = (e->i.mlx->img_x / 10) * 2 + 1;
	e->bs.yi = ((e->i.mlx->img_y / 3) * 2.5) - 1;
	e->bs.xf = (e->i.mlx->img_x / 10) * 4 - 1;
	e->bs.yf = e->bs.yi;
	ft_segment_letter(e);
	e->bs.xi = (e->i.mlx->img_x / 10) * 2 + 1;
	e->bs.yi = ((e->i.mlx->img_y / 3) * 2.5) + 1;
	e->bs.xf = (e->i.mlx->img_x / 10) * 4 - 1;
	e->bs.yf = e->bs.yi;
	ft_segment_letter(e);
}

void	shortcuts_antialiasing(t_stuff *e)
{
	draw_up_antialiasing(e, (e->i.mlx->img_x / 10) * 2, \
	(e->i.mlx->img_y / 3) * 2.5);
	draw_down_antialiasing(e, (e->i.mlx->img_x / 10) * 4);
	draw_separate_antialiasing(e);
}
