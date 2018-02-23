/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_value_draw_plan_td.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 14:18:36 by prossi            #+#    #+#             */
/*   Updated: 2018/02/22 14:22:34 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_init_value_draw_plan_td(t_stuff *e, int option)
{
	if (option == 27)
	{
		ft_init_value_draw_plan(e, 26);
		e->bs.xi -= 7;
		e->bs.yi += 6;
		e->bs.xf = e->bs.xi - 50;
		e->bs.yf = e->bs.yi - 50;
	}
	else if (option == 28)
	{
		ft_init_value_draw_plan(e, 27);
		e->bs.xi -= 7;
		e->bs.yi += 5;
		e->bs.xf = e->bs.xi - 50;
		e->bs.yf = e->bs.yi - 50;
	}
	else if (option == 29)
	{
		ft_init_value_draw_plan(e, 28);
		e->bs.xi -= 5;
		e->bs.yi += 4;
		e->bs.xf = e->bs.xi - 50;
		e->bs.yf = e->bs.yi - 50;
	}
}
