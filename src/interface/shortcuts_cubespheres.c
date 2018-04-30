/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortcuts_cubespheres.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 09:43:55 by prossi            #+#    #+#             */
/*   Updated: 2018/04/13 11:17:14 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	fill_wall_spheres(t_stuff *e, int option)
{
	if (option == 0)
		e->bs.ray_arc = 10;
	else
		e->bs.ray_arc = 6;
	while (--e->bs.ray_arc > 0)
		ft_arc(e, 9);
}

void	draw_wall_spheres(t_stuff *e, int tmpx)
{
	e->bs.ray_arc = 10;
	e->lt.couleur = 0xFFFFFF;
	ft_arc(e, 9);
	fill_wall_spheres(e, 0);
	e->bs.x_arc += 20;
	e->bs.ray_arc = 10;
	ft_arc(e, 9);
	fill_wall_spheres(e, 0);
	e->bs.ray_arc = 10;
	e->bs.x_arc += 20;
	ft_arc(e, 9);
	fill_wall_spheres(e, 0);
	e->bs.x_arc = tmpx;
	e->bs.ray_arc = 6;
	e->lt.couleur = 0x000000;
	ft_arc(e, 9);
	fill_wall_spheres(e, 1);
	e->bs.ray_arc = 6;
	e->bs.x_arc += 20;
	ft_arc(e, 9);
	fill_wall_spheres(e, 1);
	e->bs.ray_arc = 6;
	e->bs.x_arc += 20;
	ft_arc(e, 9);
	fill_wall_spheres(e, 1);
}

void	repeat_wall_spheres(t_stuff *e, int tmpx)
{
	draw_wall_spheres(e, e->bs.x_arc);
	e->bs.x_arc = tmpx;
	e->bs.y_arc += 20;
	draw_wall_spheres(e, e->bs.x_arc);
	e->bs.x_arc = tmpx;
	e->bs.y_arc += 20;
	draw_wall_spheres(e, e->bs.x_arc);
}

void	repeat_repeat_wall_spheres(t_stuff *e)
{
	e->bs.y_arc = 110;
	e->bs.x_arc = 40;
	repeat_wall_spheres(e, e->bs.x_arc);
	e->bs.y_arc = 120;
	e->bs.x_arc = 30;
	repeat_wall_spheres(e, e->bs.x_arc);
	e->bs.y_arc = 130;
	e->bs.x_arc = 20;
	repeat_wall_spheres(e, e->bs.x_arc);
}

void	shortcuts_cubespheres(t_stuff *e)
{
	repeat_repeat_wall_spheres(e);
}
