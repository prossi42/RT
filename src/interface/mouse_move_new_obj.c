/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move_new_obj.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Awk-LM <Awk-LM@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 23:39:04 by Awk-LM            #+#    #+#             */
/*   Updated: 2018/02/18 14:56:14 by Awk-LM           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	check_x_n_active(t_stuff *e, int x, int option)
{
	if (x >= (e->i.mlx->img_x / 4) - 90 && x <= (e->i.mlx->img_x / 4) - 70)
	{
		e->i.nobj.open = option;
		create_obj(e);
	}
	else
	{
		if (e->i.nobj.open == option)
		{
			e->i.nobj.open = 0;
			create_obj(e);
		}
	}
}

void	mouse_move_new_obj(int x, int y, t_stuff *e)
{
	int		bordery;

	bordery = (WIN_Y - LENGTH) * 2;
	if (y >= bordery + 5 && y <= bordery + 40)
		check_x_n_active(e, x, 1);
	else if (y >= bordery + 50 && y <= bordery + 85)
		check_x_n_active(e, x, 2);
	else if (y >= bordery + 95 && y <= bordery + 130)
		check_x_n_active(e, x, 3);
	else if (y >= bordery + 140 && y <= bordery + 175)
		check_x_n_active(e, x, 4);
	else if (y >= bordery + 185 && y <= bordery + 220)
		check_x_n_active(e, x, 5);
	else if (y >= bordery + 230 && y <= bordery + 265)
		check_x_n_active(e, x, 6);
}
