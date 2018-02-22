/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_value_draw_objects.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Awk-LM <Awk-LM@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 00:14:59 by Awk-LM            #+#    #+#             */
/*   Updated: 2018/02/22 08:37:34 by Awk-LM           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_init_value_draw_objects(t_stuff *e, int option)
{
	if (option == 0)
	{
		e->lt.couleur = 0xFFFFFF;
		e->bs.x_arc = (e->i.mlx->img_x / 2);
		e->bs.y_arc = (e->i.mlx->img_y / 2);
		e->bs.ray_arc = 50;
		e->bs.width = 50;
		e->bs.height = 50;
	}
	if (option == 1)
	{
		e->bs.x_arc += 4;
		e->bs.ray_arc--;
	}
	if (option == 2)
	{
		e->bs.x_arc += 3;
		e->bs.ray_arc -= 2;
	}
	if (option == 3)
	{
		e->bs.x_arc -= 4;
		e->bs.ray_arc--;
	}
	if (option == 4)
	{
		e->bs.x_arc -= 3;
		e->bs.ray_arc -= 2;
	}
}
