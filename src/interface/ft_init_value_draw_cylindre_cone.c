/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_value_draw_cylindre_cone.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 15:10:35 by prossi            #+#    #+#             */
/*   Updated: 2018/03/12 10:19:36 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_init_value_draw_cylindre_cone(t_stuff *e, int option)
{
	if (option == 0)
	{
		e->lt.couleur = e->i.color.nobj.col3;
		e->bs.x_arc = (e->i.mlx->img_x / 2);
		e->bs.y_arc = (e->i.mlx->img_y / 2) - 50;
		e->bs.width = 50;
		e->bs.height = 20;
	}
	if (option == 1)
	{
		e->bs.y_arc += 5;
	}
	if (option == 2)
	{
		e->lt.couleur = e->i.color.nobj.col3;
		e->bs.x_arc = (e->i.mlx->img_x / 2);
		e->bs.y_arc = (e->i.mlx->img_y / 2) - 60;
		e->bs.width = 50;
		e->bs.height = 20;
	}
	if (option == 3)
	{
		e->bs.width -= 5;
		e->bs.y_arc += 5;
	}
	if (option == 4)
	{
		e->bs.width += 5;
		e->bs.y_arc += 5;
	}
}
