/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_value_draw_sphere.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 13:43:45 by prossi            #+#    #+#             */
/*   Updated: 2018/03/12 10:18:48 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_init_value_draw_sphere(t_stuff *e, int option)
{
	if (option == 0)
	{
		e->lt.couleur = e->i.color.nobj.col3;
		e->bs.x_arc = (e->i.mlx->img_x / 2);
		e->bs.y_arc = (e->i.mlx->img_y / 2);
		e->bs.width = 50;
		e->bs.height = 50;
	}
	else if (option == 1)
		e->bs.width -= 10;
	else if (option == 2)
		e->bs.height -= 10;
}
