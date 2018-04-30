/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_value_draw_camera_sd.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 17:52:33 by prossi            #+#    #+#             */
/*   Updated: 2018/02/21 18:38:54 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	init_value_draw_camera_eh(t_stuff *e, int option)
{
	if (option == 29)
	{
		e->bs.xi = e->bs.xf + 5;
		e->bs.yi = e->bs.yf;
		e->bs.xf = e->bs.xi + 5;
		e->bs.yf = e->bs.yi;
	}
	else if (option == 30)
	{
		ft_init_value_draw_camera(e, 7);
		e->bs.xi = e->bs.xi - (75 / 4);
		e->bs.yi = e->bs.yi + 5;
		e->bs.xf = e->bs.xi;
		e->bs.yf = e->bs.yi + 10;
	}
	else if (option == 31)
	{
		ft_init_value_draw_camera(e, 30);
		e->bs.xf = e->bs.xi - ((75 / 4) * 2);
		e->bs.yf = e->bs.yi;
	}
	else if (option == 32)
		e->bs.yf = e->bs.yf + 10;
}

void	init_value_draw_camera_seh(t_stuff *e, int option)
{
	if (option == 26)
	{
		e->bs.xi = e->bs.xf;
		e->bs.yi = e->bs.yf;
		e->bs.xf = e->bs.xi;
		e->bs.yf = e->bs.yi - 45;
	}
	else if (option == 27)
	{
		e->bs.xf = e->bs.xf + 20;
		e->bs.yf = e->bs.yf + 14;
	}
	else if (option == 28)
	{
		e->bs.xi = e->bs.xf + 5;
		e->bs.yi = e->bs.yf;
		e->bs.xf = e->bs.xi + 15;
		e->bs.yf = e->bs.yi;
	}
}

void	init_value_draw_camera_sh(t_stuff *e, int option)
{
	if (option == 23)
	{
		e->bs.xi = e->bs.xf;
		e->bs.yi = e->bs.yf;
		e->bs.yf = e->bs.yi - 17;
	}
	else if (option == 24)
	{
		e->bs.xi = e->bs.xf - 5;
		e->bs.yi = e->bs.yf + 17;
		e->bs.xf = e->bs.xi;
		e->bs.yf = e->bs.yi - 17;
	}
	else if (option == 25)
	{
		e->bs.xi = e->bs.xf;
		e->bs.yi = e->bs.yf + 17;
		e->bs.xf = e->bs.xi - 20;
		e->bs.yf = e->bs.yi + 14;
	}
}

void	init_value_draw_camera_fih(t_stuff *e, int option)
{
	if (option == 20)
	{
		e->bs.xi = e->bs.xf;
		e->bs.yi = e->bs.yf;
		e->bs.xf = e->bs.xi;
		e->bs.yf = e->bs.yi - 17;
	}
	else if (option == 21)
	{
		ft_init_value_draw_camera(e, 19);
		e->bs.xi = e->bs.xf - 5;
		e->bs.yi = e->bs.yf;
		e->bs.xf = e->bs.xi;
		e->bs.yf = e->bs.yi - 17;
	}
	else if (option == 22)
	{
		e->bs.xi = e->bs.xf;
		e->bs.yi = e->bs.yf + 17;
		e->bs.xf = e->bs.xi - 15;
		e->bs.yf = e->bs.yi;
	}
}

void	ft_init_value_draw_camera_sd(t_stuff *e, int option)
{
	if (option >= 20 && option <= 22)
		init_value_draw_camera_fih(e, option);
	else if (option >= 23 && option <= 25)
		init_value_draw_camera_sh(e, option);
	else if (option >= 26 && option <= 28)
		init_value_draw_camera_seh(e, option);
	else if (option >= 29 && option <= 32)
		init_value_draw_camera_eh(e, option);
	else
		ft_init_value_draw_camera_td(e, option);
}
