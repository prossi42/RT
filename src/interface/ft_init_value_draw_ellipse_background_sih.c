/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_value_draw_ellipse_background_sih.c        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 16:19:04 by prossi            #+#    #+#             */
/*   Updated: 2018/04/13 16:23:23 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_init_value_draw_ellipse_background_nh(t_stuff *e, int option)
{
	if (option == 21)
	{
		e->lt.couleur = e->i.color.saves.col2;
		if (e->i.load.select == 5)
			e->lt.couleur = e->i.color.saves.col3;
		e->bs.y_arc = 252;
		e->bs.height = 28;
		e->bs.width = ((WIN_X - WIDTH) / 2.5) - 2;
	}
	if (option == 22)
	{
		e->lt.couleur = e->i.color.saves.col2;
		if (e->i.load.select == 6)
			e->lt.couleur = e->i.color.saves.col3;
		e->bs.x_arc = ((WIN_X - WIDTH) / 2) - 26;
		e->bs.y_arc = (WIN_Y - LENGTH) / 2;
		e->bs.height = (WIN_Y - LENGTH) / 2;
		e->bs.width = 24;
	}
}

void	ft_init_value_draw_ellipse_background_ht(t_stuff *e, int option)
{
	if (option == 19)
	{
		e->lt.couleur = e->i.color.saves.col2;
		if (e->i.load.select == 3)
			e->lt.couleur = e->i.color.saves.col3;
		e->bs.y_arc = 140;
		e->bs.height = 28;
		e->bs.width = ((WIN_X - WIDTH) / 2.5) - 2;
	}
	if (option == 20)
	{
		e->lt.couleur = e->i.color.saves.col2;
		if (e->i.load.select == 4)
			e->lt.couleur = e->i.color.saves.col3;
		e->bs.y_arc = 196;
		e->bs.height = 28;
		e->bs.width = ((WIN_X - WIDTH) / 2.5) - 2;
	}
	ft_init_value_draw_ellipse_background_nh(e, option);
}

void	ft_init_value_draw_ellipse_background_seh(t_stuff *e, int option)
{
	if (option == 17)
	{
		e->lt.couleur = e->i.color.saves.col2;
		if (e->i.load.select == 1)
			e->lt.couleur = e->i.color.saves.col3;
		e->bs.x_arc = 0;
		e->bs.y_arc = 28;
		e->bs.height = 28;
		e->bs.width = ((WIN_X - WIDTH) / 2.5) - 2;
	}
	if (option == 18)
	{
		e->lt.couleur = e->i.color.saves.col2;
		if (e->i.load.select == 2)
			e->lt.couleur = e->i.color.saves.col3;
		e->bs.y_arc = 84;
		e->bs.height = 28;
		e->bs.width = ((WIN_X - WIDTH) / 2.5) - 2;
	}
	ft_init_value_draw_ellipse_background_ht(e, option);
}

void	ft_init_value_draw_ellipse_background_sih(t_stuff *e, int option)
{
	if (option == 15)
	{
		e->lt.couleur = e->i.color.saves.col2;
		e->bs.x_arc = (WIN_X - WIDTH) / 4;
		e->bs.y_arc = (WIN_Y - LENGTH) / 2;
		e->bs.height = 42;
		e->bs.width = ((WIN_X - WIDTH) / 4) - 2;
	}
	if (option == 16)
	{
		e->lt.couleur = e->i.color.saves.col2;
		e->bs.x_arc = (WIN_X - WIDTH) / 4;
		e->bs.y_arc = WIN_Y - LENGTH - (((WIN_Y - LENGTH) / 3) / 2);
		e->bs.height = 42;
		e->bs.width = ((WIN_X - WIDTH) / 4) - 2;
	}
	ft_init_value_draw_ellipse_background_seh(e, option);
}
