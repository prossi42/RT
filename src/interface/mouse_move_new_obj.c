/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move_new_obj.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Awk-LM <Awk-LM@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 23:39:04 by Awk-LM            #+#    #+#             */
/*   Updated: 2018/02/20 08:43:38 by Awk-LM           ###   ########.fr       */
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
	int			centery;
	int			centerx;

	centery = (WIN_Y - LENGTH * 2) + ((WIN_Y - LENGTH) / 2);
	centerx = (WIN_X - WIDTH) / 2;
	if (x > centerx - 100 && x <= centerx + 100)
		e->i.nobj.power = 1;
	else if (x > 0 && x <= 100)
		e->i.nobj.power = 2;
	else if (x >= (WIN_X - WIDTH) - 100 && x < (WIN_X - WIDTH))
		e->i.nobj.power = 3;
	else
		e->i.nobj.power = 0;
	create_obj(e);
}
