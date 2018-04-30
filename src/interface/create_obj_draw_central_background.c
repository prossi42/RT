/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_obj_draw_central_background.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 23:40:05 by prossi            #+#    #+#             */
/*   Updated: 2018/04/13 15:34:40 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	draw_central_background_fh(t_stuff *e)
{
	int		i;

	init_value_draw_background(e, 3);
	i = -1;
	while (++i < 5)
	{
		ft_arc(e, 12);
		e->bs.y_arc--;
	}
	init_value_draw_background(e, 4);
	i = -1;
	while (++i < 5)
	{
		ft_arc(e, 13);
		e->bs.y_arc++;
	}
}

void	draw_central_background_td(t_stuff *e)
{
	int		i;

	i = -1;
	init_value_draw_background(e, 1);
	while (++i < 5)
	{
		ft_arc(e, 10);
		e->bs.x_arc--;
	}
	init_value_draw_background(e, 2);
	i = -1;
	while (++i < 5)
	{
		ft_arc(e, 11);
		e->bs.x_arc++;
	}
	draw_central_background_fh(e);
}

void	draw_central_background_sd(t_stuff *e)
{
	while (--e->bs.ray_arc >= 0)
	{
		ft_arc(e, 9);
		e->bs.x_arc--;
		ft_arc(e, 9);
		e->bs.x_arc++;
	}
}

void	draw_central_background(t_stuff *e)
{
	init_value_draw_background(e, 0);
	if (e->i.nobj.power == 0)
	{
		ft_arc(e, 9);
		while (e->bs.ray_arc > 0)
		{
			e->bs.ray_arc--;
			e->bs.x_arc--;
			ft_arc(e, 9);
		}
		init_value_draw_background(e, 0);
		while (e->bs.ray_arc > 0)
		{
			e->bs.ray_arc--;
			e->bs.x_arc++;
			ft_arc(e, 9);
		}
	}
	else if (e->i.nobj.power == 1)
		draw_central_background_sd(e);
	draw_central_background_td(e);
}
