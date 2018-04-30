/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortcuts_pyraspheres.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:54:16 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 10:54:59 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	fill_pyrasphere(t_stuff *e, int option)
{
	if (option == 0)
		e->bs.ray_arc = 10;
	else
		e->bs.ray_arc = 7;
	while (--e->bs.ray_arc > 0)
		ft_arc(e, 9);
}

void	draw_pyrasphere(t_stuff *e)
{
	e->lt.couleur = 0xFFFFFF;
	e->bs.ray_arc = 10;
	ft_arc(e, 9);
	fill_pyrasphere(e, 0);
	e->lt.couleur = 0x000000;
	e->bs.ray_arc = 7;
	ft_arc(e, 9);
	fill_pyrasphere(e, 1);
}

void	first_floor_pyrasphere(t_stuff *e, int tmpx, int tmpy)
{
	int		y;
	int		x;

	y = -1;
	e->bs.x_arc = tmpx + 20;
	e->bs.y_arc = tmpy;
	while (++y < 3)
	{
		x = -1;
		e->bs.x_arc = tmpx - 20;
		while (++x < 3)
		{
			e->bs.x_arc += 20;
			draw_pyrasphere(e);
		}
		e->bs.y_arc -= 20;
	}
}

void	second_floor_pyrasphere(t_stuff *e, int tmpx, int tmpy)
{
	int		y;
	int		x;

	y = -1;
	e->bs.x_arc = tmpx + 20;
	e->bs.y_arc = tmpy;
	while (++y < 2)
	{
		x = -1;
		e->bs.x_arc = tmpx - 20;
		while (++x < 2)
		{
			e->bs.x_arc += 20;
			draw_pyrasphere(e);
		}
		e->bs.y_arc -= 20;
	}
}

void	shortcuts_pyraspheres(t_stuff *e)
{
	e->bs.x_arc = 135;
	e->bs.y_arc = 160;
	first_floor_pyrasphere(e, e->bs.x_arc, e->bs.y_arc);
	e->bs.x_arc = 145;
	e->bs.y_arc = 150;
	second_floor_pyrasphere(e, e->bs.x_arc, e->bs.y_arc);
	e->bs.x_arc = 155;
	e->bs.y_arc = 140;
	draw_pyrasphere(e);
}
