/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortcuts_blur.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 17:22:29 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 10:52:59 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	fill_ellipse_blur(t_stuff *e)
{
	while (--e->bs.width > 0)
		ft_ellipse(e, 0, 0);
	while (--e->bs.height > 0)
		ft_ellipse(e, 0, 0);
}

void	fill_arc_blur(t_stuff *e)
{
	while (--e->bs.ray_arc > 0)
		ft_arc(e, 9);
}

void	fill_beer_foam(t_stuff *e, int option)
{
	int		i;

	i = -1;
	if (option == 0)
	{
		while (++i < 35)
		{
			e->bs.x_arc++;
			e->lt.couleur = 0xFFFFFF;
			e->bs.ray_arc = 10;
			ft_arc(e, 9);
			fill_arc_blur(e);
		}
	}
	else
	{
		while (++i < 24)
		{
			e->bs.y_arc++;
			e->bs.ray_arc = 3;
			ft_arc(e, 9);
			fill_arc_blur(e);
		}
	}
}

void	draw_shortcuts_blur(t_stuff *e)
{
	int		x;
	int		y;

	y = -1;
	while (++y < e->i.mlx->img_y / 3)
	{
		x = ((e->i.mlx->img_x / 10) * 4) - 1;
		while (++x < (e->i.mlx->img_x / 10) * 6)
		{
			pixel_put_to_img(&e->i.mlx, x, y, 0xFFFFFF);
		}
	}
}

void	shortcuts_blur(t_stuff *e)
{
	draw_shortcuts_blur(e);
	draw_bier_blur(e);
}
