/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_value_draw_light_sd.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 22:23:24 by prossi            #+#    #+#             */
/*   Updated: 2018/04/13 16:10:04 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	init_value_draw_light_fih(t_stuff *e, int option)
{
	if (option == 14)
	{
		e->bs.xi = (e->i.mlx->img_x / 2) + 13;
		e->bs.yi = (e->i.mlx->img_y / 2) - 6;
		e->bs.xf = e->bs.xi;
		e->bs.yf = e->bs.yi - 10;
	}
	else if (option == 15)
	{
		e->bs.xi = (e->i.mlx->img_x / 2) + 27;
		e->bs.yi = (e->i.mlx->img_y / 2) - 21;
		e->bs.xf = e->bs.xi + 8;
		e->bs.yf = e->bs.yi + 8;
	}
	else if (option == 16)
	{
		e->bs.xi = (e->i.mlx->img_x / 2) + 32;
		e->bs.yi = (e->i.mlx->img_y / 2) - 35;
		e->bs.xf = e->bs.xi + 10;
		e->bs.yf = e->bs.yi;
	}
}

void	ft_init_value_draw_light_sd(t_stuff *e, int option)
{
	if (option >= 14 && option <= 16)
		init_value_draw_light_fih(e, option);
	else if (option == 17)
	{
		e->bs.xi = (e->i.mlx->img_x / 2) + 31;
		e->bs.yi = (e->i.mlx->img_y / 2) - 49;
		e->bs.xf = e->bs.xi + 8;
		e->bs.yf = e->bs.yi - 8;
	}
	else if (option == 18)
	{
		e->bs.x_arc = (e->i.mlx->img_x / 2) + 10;
		e->bs.y_arc = (e->i.mlx->img_y / 2) + 54;
		e->bs.width = 6;
		e->bs.height = 3;
	}
}
