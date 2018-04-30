/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_value_draw_ellipse_background.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:37:22 by prossi            #+#    #+#             */
/*   Updated: 2018/04/13 16:21:55 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_init_value_draw_ellipse_background_fih(t_stuff *e, int option)
{
	if (option == 12)
	{
		e->lt.couleur = e->i.color.mat.col2;
		e->bs.x_arc = (WIN_X - WIDTH) / 8;
		e->bs.y_arc = (WIN_Y - LENGTH) / 2;
		e->bs.ray_arc = 23;
	}
	if (option == 13)
	{
		e->lt.couleur = e->i.color.mat.col2;
		e->bs.x_arc = ((WIN_X - WIDTH) / 4) + ((WIN_X - WIDTH) / 8);
		e->bs.y_arc = (WIN_Y - LENGTH) / 2;
		e->bs.ray_arc = 23;
	}
	if (option == 14)
	{
		e->lt.couleur = e->i.color.saves.col2;
		e->bs.x_arc = (WIN_X - WIDTH) / 4;
		e->bs.y_arc = ((WIN_Y - LENGTH) / 3) / 2;
		e->bs.height = 42;
		e->bs.width = ((WIN_X - WIDTH) / 4) - 2;
	}
	ft_init_value_draw_ellipse_background_sih(e, option);
}

void	ft_init_value_draw_ellipse_background_fh(t_stuff *e, int option)
{
	if (option == 9)
	{
		e->lt.couleur = e->i.color.mat.col2;
		e->bs.x_arc = (WIN_X - WIDTH) / 4;
		e->bs.y_arc = WIN_Y - LENGTH - 32;
		e->bs.height = 25;
		e->bs.width = ((WIN_X - WIDTH) / 4) - 2;
	}
	if (option == 10)
	{
		e->lt.couleur = e->i.color.mat.col2;
		e->bs.x_arc = (WIN_X - WIDTH) / 4;
		e->bs.y_arc = WIN_Y - LENGTH - 90;
		e->bs.height = 25;
		e->bs.width = ((WIN_X - WIDTH) / 4) - 2;
	}
	if (option == 11)
	{
		e->lt.couleur = e->i.color.mat.col2;
		e->bs.x_arc = (WIN_X - WIDTH) / 4;
		e->bs.y_arc = (WIN_Y - LENGTH) / 2;
		e->bs.ray_arc = 23;
	}
	ft_init_value_draw_ellipse_background_fih(e, option);
}

void	ft_init_value_draw_ellipse_background_td(t_stuff *e, int option)
{
	if (option == 6)
	{
		e->lt.couleur = e->i.color.cobj.col2;
		e->bs.x_arc = WIN_X - WIDTH - 75;
		e->bs.y_arc = WIN_Y - LENGTH - 94;
		e->bs.height = 30;
		e->bs.width = 75;
	}
	if (option == 7)
	{
		e->lt.couleur = e->i.color.mat.col2;
		e->bs.x_arc = (WIN_X - WIDTH) / 4;
		e->bs.y_arc = 32;
		e->bs.height = 25;
		e->bs.width = ((WIN_X - WIDTH) / 4) - 2;
	}
	if (option == 8)
	{
		e->lt.couleur = e->i.color.mat.col2;
		e->bs.x_arc = (WIN_X - WIDTH) / 4;
		e->bs.y_arc = 90;
		e->bs.height = 25;
		e->bs.width = ((WIN_X - WIDTH) / 4) - 2;
	}
	ft_init_value_draw_ellipse_background_fh(e, option);
}

void	ft_init_value_draw_ellipse_background_sd(t_stuff *e, int option)
{
	if (option == 3)
	{
		e->lt.couleur = e->i.color.cobj.col2;
		e->bs.x_arc = 75;
		e->bs.y_arc = 94;
		e->bs.height = 30;
		e->bs.width = 75;
	}
	if (option == 4)
	{
		e->lt.couleur = e->i.color.cobj.col2;
		e->bs.x_arc = 75;
		e->bs.y_arc = WIN_Y - LENGTH - 94;
		e->bs.height = 30;
		e->bs.width = 75;
	}
	if (option == 5)
	{
		e->lt.couleur = e->i.color.cobj.col2;
		e->bs.x_arc = WIN_X - WIDTH - 75;
		e->bs.y_arc = 94;
		e->bs.height = 30;
		e->bs.width = 75;
	}
	ft_init_value_draw_ellipse_background_td(e, option);
}

void	ft_init_value_draw_ellipse_background(t_stuff *e, int option)
{
	if (option == 0)
	{
		e->lt.couleur = e->i.color.cobj.col2;
		e->bs.x_arc = e->i.mlx->img_x / 2;
		e->bs.y_arc = 49;
		e->bs.height = 44;
		e->bs.width = 150;
	}
	if (option == 1)
	{
		e->lt.couleur = e->i.color.cobj.col2;
		e->bs.x_arc = e->i.mlx->img_x / 2;
		e->bs.y_arc = e->i.mlx->img_y / 2;
		e->bs.height = 44;
		e->bs.width = 150;
	}
	if (option == 2)
	{
		e->lt.couleur = e->i.color.cobj.col2;
		e->bs.x_arc = e->i.mlx->img_x / 2;
		e->bs.y_arc = WIN_Y - LENGTH - 49;
		e->bs.height = 44;
		e->bs.width = 150;
	}
	ft_init_value_draw_ellipse_background_sd(e, option);
}
