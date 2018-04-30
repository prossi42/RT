/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_draw_ellipse_background.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:32:39 by prossi            #+#    #+#             */
/*   Updated: 2018/04/13 16:26:53 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	matrice_draw_ellipse_background_fh(t_stuff *e)
{
	ft_init_value_draw_ellipse_background(e, 13);
	ft_arc(e, 9);
	while (--e->bs.ray_arc >= 0)
	{
		ft_arc(e, 9);
		e->bs.x_arc--;
		ft_arc(e, 9);
		e->bs.x_arc++;
	}
}

void	matrice_draw_ellipse_background_td(t_stuff *e)
{
	ft_init_value_draw_ellipse_background(e, 11);
	ft_arc(e, 9);
	while (--e->bs.ray_arc >= 0)
	{
		ft_arc(e, 9);
		e->bs.x_arc--;
		ft_arc(e, 9);
		e->bs.x_arc++;
	}
	ft_init_value_draw_ellipse_background(e, 12);
	ft_arc(e, 9);
	while (--e->bs.ray_arc >= 0)
	{
		ft_arc(e, 9);
		e->bs.x_arc--;
		ft_arc(e, 9);
		e->bs.x_arc++;
	}
	matrice_draw_ellipse_background_fh(e);
}

void	matrice_draw_ellipse_background_sd(t_stuff *e)
{
	ft_init_value_draw_ellipse_background(e, 9);
	ft_ellipse(e, 0, 0);
	while (e->bs.height > 0)
	{
		e->bs.height--;
		ft_ellipse(e, 0, 0);
	}
	while (e->bs.width > 1)
	{
		e->bs.width--;
		ft_ellipse(e, 0, 0);
	}
	ft_init_value_draw_ellipse_background(e, 10);
	ft_ellipse(e, 0, 0);
	while (e->bs.height > 0)
	{
		e->bs.height--;
		ft_ellipse(e, 0, 0);
	}
	while (e->bs.width > 1)
	{
		e->bs.width--;
		ft_ellipse(e, 0, 0);
	}
	matrice_draw_ellipse_background_td(e);
}

void	matrice_draw_ellipse_background(t_stuff *e)
{
	ft_init_value_draw_ellipse_background(e, 7);
	ft_ellipse(e, 0, 0);
	while (e->bs.height > 0)
	{
		e->bs.height--;
		ft_ellipse(e, 0, 0);
	}
	while (e->bs.width > 1)
	{
		e->bs.width--;
		ft_ellipse(e, 0, 0);
	}
	ft_init_value_draw_ellipse_background(e, 8);
	ft_ellipse(e, 0, 0);
	while (e->bs.height > 0)
	{
		e->bs.height--;
		ft_ellipse(e, 0, 0);
	}
	while (e->bs.width > 1)
	{
		e->bs.width--;
		ft_ellipse(e, 0, 0);
	}
	matrice_draw_ellipse_background_sd(e);
}
