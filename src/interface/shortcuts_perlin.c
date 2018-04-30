/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortcuts_perlin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 21:11:23 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 10:53:24 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	init_value_shortcuts_perlin(t_stuff *e, int option, int centerx, \
	int centery)
{
	if (option == 0)
	{
		e->bs.x_arc = centerx;
		e->bs.y_arc = centery;
		e->bs.width = 10;
		e->bs.height = 5;
		e->lt.coeff = 1;
		e->lt.couleur = 0x000000;
	}
	if (option == 1)
	{
		e->bs.width = 8;
		e->bs.height = 3;
		e->lt.couleur = 0xFFFFFF;
	}
	if (option == 2)
	{
		e->lt.couleur = 0x000000;
		e->bs.ray_arc = 7;
	}
	if (option == 3)
	{
		e->lt.couleur = 0xFFFFFF;
		e->bs.ray_arc = 5;
	}
}

void	draw_perlin_stain(t_stuff *e, int centerx, int centery)
{
	init_value_shortcuts_perlin(e, 0, centerx, centery);
	ft_full_ellipse(e, 0, 0);
	init_value_shortcuts_perlin(e, 1, centerx, centery);
	ft_full_ellipse(e, 0, 0);
	init_value_shortcuts_perlin(e, 2, centerx, centery);
	ft_full_arc(e, 9);
	init_value_shortcuts_perlin(e, 3, centerx, centery);
	ft_full_arc(e, 9);
}

void	group_of_perlin_stain(t_stuff *e, int option, int posx, int posy)
{
	int		tmpx;
	int		tmpy;

	tmpx = posx;
	tmpy = posy;
	if (option == 0)
	{
		while (tmpx < posx + 100)
		{
			draw_perlin_stain(e, tmpx, tmpy);
			tmpx += 20;
		}
	}
	if (option == 1)
	{
		while (tmpy <= posy + 60)
		{
			draw_perlin_stain(e, tmpx, tmpy);
			tmpy += 15;
		}
	}
}

void	shortcuts_perlin(t_stuff *e)
{
	int		borderx;
	int		bordery;

	borderx = (e->i.mlx->img_x / 5) * 3;
	bordery = e->i.mlx->img_y / 3;
	group_of_perlin_stain(e, 0, borderx + 12, bordery + 20);
	group_of_perlin_stain(e, 0, borderx + 12, bordery + 40);
	group_of_perlin_stain(e, 0, borderx + 12, bordery + 60);
	group_of_perlin_stain(e, 0, borderx + 12, bordery + 80);
	group_of_perlin_stain(e, 1, borderx + 25, bordery + 12);
	group_of_perlin_stain(e, 1, borderx + 50, bordery + 12);
	group_of_perlin_stain(e, 1, borderx + 80, bordery + 12);
}
