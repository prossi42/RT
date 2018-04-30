/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortcuts_sd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 14:18:38 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 10:56:07 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	draw_square_shortcuts(t_stuff *e)
{
	int		x;
	int		y;

	y = -1;
	while (++y < e->i.mlx->img_y)
	{
		x = -1;
		while (++x < e->i.mlx->img_x)
		{
			if (y == e->i.mlx->img_y / 3 || y == (e->i.mlx->img_y / 3) * 2)
				pixel_put_to_img(&e->i.mlx, x, y, 0x000000);
			if (x == 0 || x == (e->i.mlx->img_x / 10) * 2 || \
			x == (e->i.mlx->img_x / 10)\
			* 4 || x == (e->i.mlx->img_x / 10) * 6 || \
			x == (e->i.mlx->img_x / 10) * 8 || x == e->i.mlx->img_x - 1)
				pixel_put_to_img(&e->i.mlx, x, y, 0x000000);
		}
	}
}

void	draw_shortcuts(t_stuff *e)
{
	int		x;
	int		y;

	y = -1;
	while (++y < e->i.mlx->img_y)
	{
		x = -1;
		while (++x < e->i.mlx->img_x)
			pixel_put_to_img(&e->i.mlx, x, y, 0x202020);
	}
}
