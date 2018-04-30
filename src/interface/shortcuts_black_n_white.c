/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortcuts_black_n_white.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 14:00:54 by prossi            #+#    #+#             */
/*   Updated: 2018/04/17 14:49:21 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	draw_letters_black_n_white(t_stuff *e)
{
	e->lt.couleur = 0x000000;
	e->lt.posx = 20;
	e->lt.posy = 72;
	e->lt.coeff = 1;
	e->lt.space = 40;
	awklm_string_put("B", e);
	e->lt.couleur = 0xFFFFFF;
	e->lt.posx = 60;
	e->lt.posy = 72;
	awklm_string_put("W", e);
}

void	draw_circle_black_n_white_sd(t_stuff *e)
{
	e->bs.width = e->i.mlx->img_x / 10;
	e->bs.height = (e->i.mlx->img_y / 3) / 2;
	ft_ellipse(e, 1, 4);
	ft_ellipse(e, 2, 2);
	ft_ellipse(e, 1, 6);
	e->lt.couleur = 0x000000;
	e->bs.height--;
	while (--e->bs.width > 0)
	{
		ft_ellipse(e, 1, 4);
		ft_ellipse(e, 2, 2);
		ft_ellipse(e, 1, 6);
	}
	while (--e->bs.height > 0)
	{
		ft_ellipse(e, 1, 4);
		ft_ellipse(e, 2, 2);
		ft_ellipse(e, 1, 6);
	}
}

void	draw_circle_black_n_white(t_stuff *e)
{
	e->bs.x_arc = e->i.mlx->img_x / 10;
	e->bs.y_arc = (e->i.mlx->img_y / 3) / 2;
	e->lt.couleur = 0x000000;
	e->bs.width = e->i.mlx->img_x / 10;
	e->bs.height = (e->i.mlx->img_y / 3) / 2;
	ft_ellipse(e, 1, 3);
	ft_ellipse(e, 2, 1);
	ft_ellipse(e, 1, 5);
	e->lt.couleur = 0xFFFFFF;
	while (--e->bs.width > 0)
	{
		ft_ellipse(e, 1, 3);
		ft_ellipse(e, 2, 1);
		ft_ellipse(e, 1, 5);
	}
	while (--e->bs.height > 0)
	{
		ft_ellipse(e, 1, 3);
		ft_ellipse(e, 2, 1);
		ft_ellipse(e, 1, 5);
	}
	draw_circle_black_n_white_sd(e);
}

void	shortcuts_black_n_white(t_stuff *e)
{
	draw_circle_black_n_white(e);
	draw_letters_black_n_white(e);
}
