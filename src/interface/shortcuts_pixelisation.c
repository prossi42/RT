/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortcuts_pixelisation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 13:34:29 by prossi            #+#    #+#             */
/*   Updated: 2018/04/16 21:41:40 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	draw_split_pixelisation(t_stuff *e)
{
	int		i;

	i = -1;
	e->lt.couleur = 0x202020;
	e->bs.xi = 0;
	e->bs.yi = e->i.mlx->img_y;
	e->bs.xf = ((e->i.mlx->img_x / 10) * 2) - 1;
	e->bs.yf = e->bs.yi - (e->i.mlx->img_y / 3);
	ft_segment_letter(e);
	while (++i < 104)
	{
		e->bs.xi = i;
		e->bs.yi = e->i.mlx->img_y;
		ft_segment_letter(e);
	}
}

void	draw_left_pixelisation(t_stuff *e)
{
	int		i;

	i = (e->i.mlx->img_y / 3) * 2;
	e->bs.xf = ((e->i.mlx->img_x / 10) * 2) - 1;
	while (i < e->i.mlx->img_y)
	{
		i += 10;
		e->bs.xi = 0;
		e->bs.yi = i;
		e->bs.yf = e->bs.yi;
		ft_segment_letter(e);
	}
	i = 0;
	e->bs.yf = e->i.mlx->img_y;
	while (i < ((e->i.mlx->img_x / 10) * 2) - 10)
	{
		i += 10;
		e->bs.xi = i;
		e->bs.yi = ((e->i.mlx->img_y / 3) * 2) + 1;
		e->bs.xf = e->bs.xi;
		ft_segment_letter(e);
	}
}

void	draw_sphere_pixelisation(t_stuff *e, int option)
{
	e->lt.couleur = 0xFFFFFF;
	if (option == 0)
	{
		e->bs.x_arc = ((e->i.mlx->img_x / 10) * 2) / 4;
		e->bs.y_arc = ((e->i.mlx->img_y / 3) * 2) + ((e->i.mlx->img_y / \
			3) / 4);
		e->bs.ray_arc = 10;
		ft_arc(e, 9);
	}
	else
	{
		e->bs.x_arc = (((e->i.mlx->img_x / 10) * 2) / 4) * 3;
		e->bs.y_arc = ((e->i.mlx->img_y / 3) * 2) + (((e->i.mlx->img_y / 3) \
		/ 4) * 3);
		e->bs.ray_arc = 10;
		ft_arc(e, 9);
	}
}

void	shortcuts_pixelisation(t_stuff *e)
{
	draw_sphere_pixelisation(e, 0);
	e->lt.couleur = 0x000000;
	draw_left_pixelisation(e);
	draw_split_pixelisation(e);
	draw_sphere_pixelisation(e, 1);
}
