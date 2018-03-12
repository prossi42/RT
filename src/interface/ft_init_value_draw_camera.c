/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_value_draw_camera.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Awk-LM <Awk-LM@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 17:34:50 by Awk-LM            #+#    #+#             */
/*   Updated: 2018/03/12 10:17:52 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	init_value_draw_camera_fh(t_stuff *e, int option)
{
	if (option == 17)
	{
		e->bs.xi = e->bs.x_arc;
		e->bs.yi = e->bs.y_arc - e->bs.ray_arc;
		e->bs.xf = e->bs.xi;
		e->bs.yf = e->bs.yi + (2 * e->bs.ray_arc);
	}
	else if (option == 18)
	{
		e->bs.xi = (e->i.mlx->img_x / 2) + 55;
		e->bs.yi = (e->i.mlx->img_y / 2) - 25 + ((50 / 5) * 2);
		e->bs.xf = e->bs.xi + 10;
		e->bs.yf = e->bs.yi;
	}
	else if (option == 19)
	{
		e->bs.xi = (e->i.mlx->img_x / 2) - 25;
		e->bs.yi = (e->i.mlx->img_y / 2) + 9;
		e->bs.xf = e->bs.xi - 5;
		e->bs.yf = e->bs.yi;
	}
}

void	init_value_draw_camera_td(t_stuff *e, int option)
{
	if (option == 14)
	{
		e->bs.xi = e->bs.xf + 5;
		e->bs.yi = e->bs.yf + ((50 / 5) * 2);
		e->bs.xf = e->bs.xi;
		e->bs.yf = e->bs.yi - 10;
	}
	else if (option == 15)
	{
		e->bs.xi = e->bs.xf;
		e->bs.yi = e->bs.yf;
		e->bs.xf = e->bs.xi + 10;
		e->bs.yf = e->bs.yi;
	}
	else if (option == 16)
	{
		e->bs.x_arc = e->bs.xf + 7;
		e->bs.y_arc = e->bs.yf + 5;
		e->bs.ray_arc = 8;
	}
}

void	init_value_draw_camera_sd(t_stuff *e, int option)
{
	if (option == 10)
	{
		e->bs.xi = e->bs.xf;
		e->bs.yi = e->bs.yf;
		e->bs.xf = e->bs.xi + 75;
		e->bs.yf = e->bs.yi;
	}
	else if (option == 11)
	{
		e->bs.x_arc = e->bs.xf - (75 / 5);
		e->bs.y_arc = e->bs.yf - 30;
		e->bs.ray_arc = 20;
	}
	else if (option == 12)
		e->bs.ray_arc = 5;
	else if (option == 13)
	{
		e->bs.x_arc = e->bs.xf - ((75 / 5) * 4);
		e->bs.y_arc = e->bs.yf - 30;
		e->bs.ray_arc = 20;
	}
}

void	init_value_draw_camera(t_stuff *e, int option)
{
	if (option == 7)
	{
		e->lt.couleur = e->i.color.nobj.col3;
		e->bs.xi = (e->i.mlx->img_x / 2) + 50;
		e->bs.yi = (e->i.mlx->img_y / 2) + 25;
		e->bs.xf = e->bs.xi;
		e->bs.yf = e->bs.yi - 50;
	}
	else if (option == 8)
	{
		e->bs.xi = (e->i.mlx->img_x / 2) + 50;
		e->bs.yi = (e->i.mlx->img_y / 2) + 25;
		e->bs.xf = e->bs.xi - 75;
		e->bs.yf = e->bs.yi;
	}
	else if (option == 9)
	{
		e->bs.xi = e->bs.xf;
		e->bs.yi = e->bs.yf;
		e->bs.xf = e->bs.xi;
		e->bs.yf = e->bs.yi - 50;
	}
}

void	ft_init_value_draw_camera(t_stuff *e, int option)
{
	if (option >= 7 && option <= 9)
		init_value_draw_camera(e, option);
	else if (option >= 10 && option <= 13)
		init_value_draw_camera_sd(e, option);
	else if (option >= 14 && option <= 16)
		init_value_draw_camera_td(e, option);
	else if (option >= 17 && option <= 19)
		init_value_draw_camera_fh(e, option);
	else
		ft_init_value_draw_camera_sd(e, option);
}
