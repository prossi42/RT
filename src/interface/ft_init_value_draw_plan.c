/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_value_draw_plan.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 13:46:03 by prossi            #+#    #+#             */
/*   Updated: 2018/02/22 14:22:25 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	init_value_draw_plan_fh(t_stuff *e, int option)
{
	if (option == 12)
	{
		ft_init_value_draw_plan(e, 11);
		e->bs.xi -= 5;
		e->bs.yi -= 5;
		e->bs.xf = e->bs.xi - 100;
		e->bs.yf = e->bs.yi + 75;
	}
	else if (option == 13)
	{
		ft_init_value_draw_plan(e, 12);
		e->bs.xi -= 5;
		e->bs.yi -= 5;
		e->bs.xf = e->bs.xi - 100;
		e->bs.yf = e->bs.yi + 75;
	}
	else if (option == 14)
	{
		e->bs.xi = (e->i.mlx->img_x / 2) + 75;
		e->bs.yi = (e->i.mlx->img_y / 2) - 10;
		e->bs.xf = e->bs.xi - 50;
		e->bs.yf = e->bs.yi - 50;
	}
}

void	init_value_draw_plan_td(t_stuff *e, int option)
{
	if (option == 9)
	{
		ft_init_value_draw_plan(e, 8);
		e->bs.xi -= 5;
		e->bs.yi -= 5;
		e->bs.xf = e->bs.xi - 100;
		e->bs.yf = e->bs.yi + 75;
	}
	else if (option == 10)
	{
		ft_init_value_draw_plan(e, 9);
		e->bs.xi -= 5;
		e->bs.yi -= 5;
		e->bs.xf = e->bs.xi - 100;
		e->bs.yf = e->bs.yi + 75;
	}
	else if (option == 11)
	{
		ft_init_value_draw_plan(e, 10);
		e->bs.xi -= 5;
		e->bs.yi -= 5;
		e->bs.xf = e->bs.xi - 100;
		e->bs.yf = e->bs.yi + 75;
	}
}

void	init_value_draw_plan_sd(t_stuff *e, int option)
{
	if (option == 6)
	{
		ft_init_value_draw_plan(e, 5);
		e->bs.xi -= 5;
		e->bs.yi -= 5;
		e->bs.xf = e->bs.xi - 100;
		e->bs.yf = e->bs.yi + 75;
	}
	else if (option == 7)
	{
		ft_init_value_draw_plan(e, 6);
		e->bs.xi -= 5;
		e->bs.yi -= 5;
		e->bs.xf = e->bs.xi - 100;
		e->bs.yf = e->bs.yi + 75;
	}
	else if (option == 8)
	{
		ft_init_value_draw_plan(e, 7);
		e->bs.xi -= 5;
		e->bs.yi -= 5;
		e->bs.xf = e->bs.xi - 100;
		e->bs.yf = e->bs.yi + 75;
	}
}

void	init_value_draw_plan(t_stuff *e, int option)
{
	if (option == 3)
	{
		e->lt.couleur = 0xFFFFFF;
		e->bs.xi = (e->i.mlx->img_x / 2) + 75;
		e->bs.yi = (e->i.mlx->img_y / 2) - 10;
		e->bs.xf = e->bs.xi - 100;
		e->bs.yf = e->bs.yi + 75;
	}
	else if (option == 4)
	{
		ft_init_value_draw_plan(e, 3);
		e->bs.xi -= 5;
		e->bs.yi -= 5;
		e->bs.xf = e->bs.xi - 100;
		e->bs.yf = e->bs.yi + 75;
	}
	else if (option == 5)
	{
		ft_init_value_draw_plan(e, 4);
		e->bs.xi -= 5;
		e->bs.yi -= 5;
		e->bs.xf = e->bs.xi - 100;
		e->bs.yf = e->bs.yi + 75;
	}
}

void	ft_init_value_draw_plan(t_stuff *e, int option)
{
	if (option >= 3 && option <= 5)
		init_value_draw_plan(e, option);
	else if (option >= 6 && option <= 8)
		init_value_draw_plan_sd(e, option);
	else if (option >= 9 && option <= 11)
		init_value_draw_plan_td(e, option);
	else if (option >= 12 && option <= 14)
		init_value_draw_plan_fh(e, option);
	else
		ft_init_value_draw_plan_sd(e, option);
}
