/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_value_draw_background.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 23:50:13 by prossi            #+#    #+#             */
/*   Updated: 2018/03/12 10:17:31 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	init_value_draw_background_sd(t_stuff *e, int option)
{
	if (option == 3)
	{
		e->bs.x_arc = e->i.mlx->img_x / 2;
		e->bs.y_arc = e->i.mlx->img_y / 2 - 10;
		e->bs.ray_arc = 124;
	}
	else if (option == 4)
	{
		e->bs.x_arc = e->i.mlx->img_x / 2;
		e->bs.y_arc = e->i.mlx->img_y / 2 + 10;
	}
	else if (option == 5)
	{
		e->bs.x_arc = 0;
		e->bs.y_arc = e->i.mlx->img_y / 2;
		e->bs.ray_arc = 100;
	}
	else if (option == 6)
	{
		e->bs.x_arc = e->i.mlx->img_x;
		e->bs.y_arc = e->i.mlx->img_y / 2;
		e->bs.ray_arc = 100;
	}
}

void	init_value_draw_background(t_stuff *e, int option)
{
	if (option == 0)
	{
		e->lt.couleur = e->i.color.nobj.col2;
		e->bs.x_arc = e->i.mlx->img_x / 2;
		e->bs.y_arc = e->i.mlx->img_y / 2;
		e->bs.ray_arc = 100;
	}
	else if (option == 1)
	{
		e->bs.x_arc = (e->i.mlx->img_x / 2) - 10;
		e->bs.ray_arc = 124;
	}
	else if (option == 2)
	{
		e->bs.x_arc = (e->i.mlx->img_x / 2) + 10;
		e->bs.ray_arc = 124;
	}
	else
		init_value_draw_background_sd(e, option);
}
