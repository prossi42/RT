/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_obj_draw_side_background.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 00:06:56 by prossi            #+#    #+#             */
/*   Updated: 2018/02/22 00:06:58 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	draw_side_background_sd(t_stuff *e)
{
	init_value_draw_background(e, 6);
	if (e->i.nobj.power == 0)
	{
		while (++e->bs.x_arc <= e->i.mlx->img_x + 100)
		{
			ft_arc(e, 2);
			e->bs.ray_arc--;
		}
	}
	else if (e->i.nobj.power == 1)
	{
		while (++e->bs.x_arc <= e->i.mlx->img_x + 100)
			ft_arc(e, 2);
	}
}

void	draw_side_background(t_stuff *e)
{
	init_value_draw_background(e, 5);
	if (e->i.nobj.power == 0)
	{
		while (--e->bs.x_arc >= -100)
		{
			ft_arc(e, 1);
			e->bs.ray_arc--;
		}
	}
	else if (e->i.nobj.power == 1)
	{
		while (--e->bs.x_arc >= -100)
		{
			ft_arc(e, 1);
		}
	}
	draw_side_background_sd(e);
}
