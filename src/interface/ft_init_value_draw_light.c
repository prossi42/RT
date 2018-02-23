/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_value_draw_light.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 16:15:26 by prossi            #+#    #+#             */
/*   Updated: 2018/02/22 22:24:05 by Awk-LM           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	init_value_draw_light_fh(t_stuff *e, int option)
{
	if (option == 11)
	{
		e->bs.xi = (e->i.mlx->img_x / 2) - 2;
		e->bs.yi = (e->i.mlx->img_y / 2) - 12;
		e->bs.xf = e->bs.xi + 29;
		e->bs.yf = e->bs.yi - 51;
	}
	else if (option == 12)
	{
		ft_init_value_draw_light(e, 11);
		e->bs.xi = e->bs.xi + (29 / 4) + 5;
		e->bs.yi = e->bs.yi - (51 / 4);
		e->bs.xf = e->bs.xi + ((29 / 4) * 2) - 1;
		e->bs.yf = e->bs.yi - ((51 / 4) * 2);
	}
	else if (option == 13)
	{
		ft_init_value_draw_light(e, 11);
		e->bs.x_arc = e->bs.xi + (29 / 2) - 1;
		e->bs.y_arc = e->bs.yi - (51 / 2) - 1;
		e->bs.ray_arc = 15;
	}
}

void	init_value_draw_light_td(t_stuff *e, int option)
{
	if (option == 7)
	{
		e->bs.xi = (e->i.mlx->img_x / 2) - 23;
		e->bs.yi = (e->i.mlx->img_y / 2) - 58;
		e->bs.xf = e->bs.xi - 47;
		e->bs.yf = e->bs.yi + 42;
	}
	else if (option == 8)
	{
		e->bs.x_arc = (e->i.mlx->img_x / 2) - 7;
		e->bs.y_arc = (e->i.mlx->img_y / 2) - 63;
		e->bs.ray_arc = 15;
	}
	else if (option == 9)
	{
		e->bs.x_arc = (e->i.mlx->img_x / 2) + 23;
		e->bs.y_arc = (e->i.mlx->img_y / 2) - 52;
		e->bs.width = 40;
		e->bs.height = 50;
	}
	else if (option == 10)
	{
		e->bs.y_arc += 28;
		e->bs.x_arc -= 20;
	}
}

void	init_value_draw_light_sd(t_stuff *e, int option)
{
	if (option == 3)
	{
		e->bs.xi = (e->i.mlx->img_x / 2) - 17;
		e->bs.yi = (e->i.mlx->img_y / 2) + 56;
		e->bs.xf = e->bs.xi - 49;
		e->bs.yf = e->bs.yi - 56;
	}
	else if (option == 4)
	{
		e->bs.x_arc = e->bs.xf - 3;
		e->bs.y_arc = e->bs.yf - 7;
		e->bs.ray_arc = 7;
	}
	else if (option == 5)
		e->bs.ray_arc -= 3;
	else if (option == 6)
	{
		e->bs.xi = (e->i.mlx->img_x / 2) - 20;
		e->bs.yi = (e->i.mlx->img_y / 2) - 57;
		e->bs.xf = e->bs.xi - 47;
		e->bs.yf = e->bs.yi + 42;
	}
}

void	init_value_draw_light(t_stuff *e, int option)
{
	if (option == 0)
	{
		e->lt.couleur = 0xFFFFFF;
		e->bs.x_arc = (e->i.mlx->img_x / 2);
		e->bs.y_arc = (e->i.mlx->img_y / 2) + 70;
		e->bs.width = 40;
		e->bs.height = 15;
	}
	else if (option == 1)
	{
		e->bs.xi = (e->i.mlx->img_x / 2) - 40;
		e->bs.yi = (e->i.mlx->img_y / 2) + 70;
		e->bs.xf = e->bs.xi + 80;
		e->bs.yf = e->bs.yi;
	}
	else if (option == 2)
	{
		e->bs.xi = (e->i.mlx->img_x / 2) - 20;
		e->bs.yi = (e->i.mlx->img_y / 2) + 57;
		e->bs.xf = e->bs.xi - 50;
		e->bs.yf = e->bs.yi - 57;
	}
}

void	ft_init_value_draw_light(t_stuff *e, int option)
{
	if (option >= 0 && option <= 2)
		init_value_draw_light(e, option);
	if (option >= 3 && option <= 6)
		init_value_draw_light_sd(e, option);
	if (option >= 7 && option <= 10)
		init_value_draw_light_td(e, option);
	if (option >= 11 && option <= 13)
		init_value_draw_light_fh(e, option);
	else
		ft_init_value_draw_light_sd(e, option);
}
