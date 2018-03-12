/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_value_draw_plan_sd.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 14:00:12 by prossi            #+#    #+#             */
/*   Updated: 2018/02/22 14:22:46 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	init_value_draw_plan_eh(t_stuff *e, int option)
{
	if (option == 24)
	{
		ft_init_value_draw_plan(e, 23);
		e->bs.xi -= 7;
		e->bs.yi += 5;
		e->bs.xf = e->bs.xi - 50;
		e->bs.yf = e->bs.yi - 50;
	}
	else if (option == 25)
	{
		ft_init_value_draw_plan(e, 24);
		e->bs.xi -= 7;
		e->bs.yi += 5;
		e->bs.xf = e->bs.xi - 50;
		e->bs.yf = e->bs.yi - 50;
	}
	else if (option == 26)
	{
		ft_init_value_draw_plan(e, 25);
		e->bs.xi -= 7;
		e->bs.yi += 5;
		e->bs.xf = e->bs.xi - 50;
		e->bs.yf = e->bs.yi - 50;
	}
}

void	init_value_draw_plan_seh(t_stuff *e, int option)
{
	if (option == 21)
	{
		ft_init_value_draw_plan(e, 20);
		e->bs.xi -= 7;
		e->bs.yi += 5;
		e->bs.xf = e->bs.xi - 50;
		e->bs.yf = e->bs.yi - 50;
	}
	else if (option == 22)
	{
		ft_init_value_draw_plan(e, 21);
		e->bs.xi -= 7;
		e->bs.yi += 5;
		e->bs.xf = e->bs.xi - 50;
		e->bs.yf = e->bs.yi - 50;
	}
	else if (option == 23)
	{
		ft_init_value_draw_plan(e, 22);
		e->bs.xi -= 7;
		e->bs.yi += 5;
		e->bs.xf = e->bs.xi - 50;
		e->bs.yf = e->bs.yi - 50;
	}
}

void	init_value_draw_plan_sh(t_stuff *e, int option)
{
	if (option == 18)
	{
		ft_init_value_draw_plan(e, 17);
		e->bs.xi -= 6;
		e->bs.yi += 5;
		e->bs.xf = e->bs.xi - 50;
		e->bs.yf = e->bs.yi - 50;
	}
	else if (option == 19)
	{
		ft_init_value_draw_plan(e, 18);
		e->bs.xi -= 6;
		e->bs.yi += 5;
		e->bs.xf = e->bs.xi - 50;
		e->bs.yf = e->bs.yi - 50;
	}
	else if (option == 20)
	{
		ft_init_value_draw_plan(e, 19);
		e->bs.xi -= 7;
		e->bs.yi += 5;
		e->bs.xf = e->bs.xi - 50;
		e->bs.yf = e->bs.yi - 50;
	}
}

void	init_value_draw_plan_fih(t_stuff *e, int option)
{
	if (option == 15)
	{
		ft_init_value_draw_plan(e, 14);
		e->bs.xi -= 7;
		e->bs.yi += 5;
		e->bs.xf = e->bs.xi - 50;
		e->bs.yf = e->bs.yi - 50;
	}
	else if (option == 16)
	{
		ft_init_value_draw_plan(e, 15);
		e->bs.xi -= 7;
		e->bs.yi += 5;
		e->bs.xf = e->bs.xi - 50;
		e->bs.yf = e->bs.yi - 50;
	}
	else if (option == 17)
	{
		ft_init_value_draw_plan(e, 16);
		e->bs.xi -= 6;
		e->bs.yi += 5;
		e->bs.xf = e->bs.xi - 50;
		e->bs.yf = e->bs.yi - 50;
	}
}

void	ft_init_value_draw_plan_sd(t_stuff *e, int option)
{
	if (option >= 15 && option <= 17)
		init_value_draw_plan_fih(e, option);
	else if (option >= 18 && option <= 20)
		init_value_draw_plan_sh(e, option);
	else if (option >= 21 && option <= 23)
		init_value_draw_plan_seh(e, option);
	else if (option >= 24 && option <= 26)
		init_value_draw_plan_eh(e, option);
	else
		ft_init_value_draw_plan_td(e, option);
}
