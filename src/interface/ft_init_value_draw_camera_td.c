/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_value_draw_camera_td.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Awk-LM <Awk-LM@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 18:13:35 by Awk-LM            #+#    #+#             */
/*   Updated: 2018/02/21 18:39:46 by Awk-LM           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	init_value_draw_camera_elh(t_stuff *e, int option)
{
	if (option == 39)
	{
		ft_init_value_draw_camera(e, 38);
		e->bs.xf = e->bs.xi - 30;
		e->bs.yf = e->bs.yi + 30;
	}
	else if (option == 40)
	{
		ft_init_value_draw_camera(e, 38);
		e->bs.xf = e->bs.xi;
		e->bs.yf = e->bs.yi + 20;
	}
}

void	init_value_draw_camera_th(t_stuff *e, int option)
{
	if (option == 36)
	{
		e->bs.xi = e->bs.xf - 8;
		e->bs.yi = e->bs.yf - 13;
		e->bs.xf = e->bs.xi + 11;
		e->bs.yf = e->bs.yi + 10;
	}
	else if (option == 37)
	{
		e->bs.x_arc = e->bs.xf;
		e->bs.y_arc = e->bs.yf + 4;
		e->bs.ray_arc = 3;
	}
	else if (option == 38)
	{
		ft_init_value_draw_camera(e, 30);
		e->bs.xi = e->bs.xf - (75 / 4);
		e->bs.yi = e->bs.yf + 8;
		e->bs.xf = e->bs.xi + 30;
		e->bs.yf = e->bs.yi + 30;
	}
}

void	init_value_draw_camera_nh(t_stuff *e, int option)
{
	if (option == 33)
	{
		e->bs.xi = e->bs.xf;
		e->bs.yi = e->bs.yf;
		e->bs.xf = e->bs.xi + ((75 / 4) * 2);
	}
	else if (option == 34)
	{
		e->bs.x_arc = e->bs.xf - (75 / 4);
		e->bs.y_arc = e->bs.yf;
		e->bs.ray_arc = 8;
	}
	else if (option == 35)
	{
		e->bs.xi = e->bs.xf - 2;
		e->bs.yi = e->bs.yf;
		e->bs.xf = e->bs.xi + 10;
		e->bs.yf = e->bs.yi + 10;
	}
}

void	ft_init_value_draw_camera_td(t_stuff *e, int option)
{
	if (option >= 33 && option <= 35)
		init_value_draw_camera_nh(e, option);
	else if (option >= 36 && option <= 38)
		init_value_draw_camera_th(e, option);
	else if (option == 39 || option == 40)
		init_value_draw_camera_elh(e, option);
}
