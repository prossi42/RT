/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_draw_title_background.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 07:51:48 by prossi            #+#    #+#             */
/*   Updated: 2018/04/13 16:12:56 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_init_value_matrice_draw_title_background_sd(t_stuff *e, int option)
{
	if (option == 4)
	{
		e->lt.posx = ((WIN_X - WIDTH) / 4) + 60;
		e->lt.posy = 150;
	}
	if (option == 5)
	{
		e->lt.posx = ((WIN_X - WIDTH) / 4) - 67;
		e->lt.posy = 200;
	}
	if (option == 6)
	{
		e->lt.posx = ((WIN_X - WIDTH) / 4) - 60;
		e->lt.posy = 257;
	}
}

void	ft_init_value_matrice_draw_title_background(t_stuff *e, int option)
{
	if (option == 0)
	{
		e->lt.couleur = e->i.color.mat.col3;
		e->lt.posx = (WIN_X - WIDTH) / 4 - 60;
		e->lt.posy = 43;
		e->lt.coeff = 0.40;
		e->lt.space = 40;
	}
	if (option == 1)
	{
		e->lt.posx = (WIN_X - WIDTH) / 4 - 85;
		e->lt.posy = 100;
	}
	if (option == 2)
	{
		e->lt.posx = (WIN_X - WIDTH) / 4 - 70;
		e->lt.posy = 150;
	}
	if (option == 3)
	{
		e->lt.posx = ((WIN_X - WIDTH) / 4) - 5;
		e->lt.posy = 150;
	}
	ft_init_value_matrice_draw_title_background_sd(e, option);
}

void	matrice_draw_title_background(t_stuff *e)
{
	ft_init_value_matrice_draw_title_background(e, 0);
	awklm_string_put("Rotation", e);
	ft_init_value_matrice_draw_title_background(e, 1);
	awklm_string_put("Translation", e);
	ft_init_value_matrice_draw_title_background(e, 2);
	awklm_string_put("X", e);
	ft_init_value_matrice_draw_title_background(e, 3);
	awklm_string_put("Y", e);
	ft_init_value_matrice_draw_title_background(e, 4);
	awklm_string_put("Z", e);
	ft_init_value_matrice_draw_title_background(e, 5);
	awklm_string_put("Direction", e);
	ft_init_value_matrice_draw_title_background(e, 6);
	awklm_string_put("Position", e);
}
