/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_scene_init_value_draw_title_background.c      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 13:24:29 by prossi            #+#    #+#             */
/*   Updated: 2018/04/18 13:24:36 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	init_value_draw_title_background_td(t_stuff *e, int option)
{
	if (option == 6)
	{
		e->lt.couleur = e->i.color.saves.col3;
		if (e->i.load.select == 5)
			e->lt.couleur = e->i.color.saves.col2;
		e->lt.posy += 56;
	}
}

void	init_value_draw_title_background_sd(t_stuff *e, int option)
{
	if (option == 3)
	{
		e->lt.couleur = e->i.color.saves.col3;
		if (e->i.load.select == 2)
			e->lt.couleur = e->i.color.saves.col2;
		e->lt.posy += 56;
	}
	if (option == 4)
	{
		e->lt.couleur = e->i.color.saves.col3;
		if (e->i.load.select == 3)
			e->lt.couleur = e->i.color.saves.col2;
		e->lt.posy += 56;
	}
	if (option == 5)
	{
		e->lt.couleur = e->i.color.saves.col3;
		if (e->i.load.select == 4)
			e->lt.couleur = e->i.color.saves.col2;
		e->lt.posy += 56;
	}
}

void	init_value_draw_title_background(t_stuff *e, int option)
{
	if (option == 0)
	{
		e->lt.couleur = e->i.color.saves.col3;
		if (e->i.load.select == 6)
			e->lt.couleur = e->i.color.saves.col2;
		e->lt.posx = ((WIN_X - WIDTH) / 2) - 30;
		e->lt.posy = 90;
		e->lt.space = 40;
		e->lt.coeff = 0.40;
	}
	if (option == 1)
		e->lt.posy += 40;
	if (option == 2)
	{
		e->lt.couleur = e->i.color.saves.col3;
		if (e->i.load.select == 1)
			e->lt.couleur = e->i.color.saves.col2;
		e->lt.posx = 10;
		e->lt.posy = 38;
		e->lt.space = 40;
		e->lt.coeff = 0.40;
	}
	init_value_draw_title_background_sd(e, option);
	init_value_draw_title_background_td(e, option);
}
