/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_scene_draw_title_background.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 16:01:16 by prossi            #+#    #+#             */
/*   Updated: 2018/03/13 18:25:43 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_init_value_save_scene_draw_title_background(t_stuff *e, int option)
{
	if (option == 0)
	{
		e->lt.posx = 95;
		e->lt.posy = 57;
		e->lt.couleur = e->i.color.saves.col3;
		e->lt.space = 40;
		e->lt.coeff = 0.50;
	}
	if (option == 1)
	{
		e->lt.posx = 95;
		e->lt.posy = 152;
		e->lt.couleur = e->i.color.saves.col3;
		e->lt.space = 40;
		e->lt.coeff = 0.50;
	}
	if (option == 2)
	{
		e->lt.posx = 85;
		e->lt.posy = 247;
		e->lt.couleur = e->i.color.saves.col3;
		e->lt.space = 40;
		e->lt.coeff = 0.50;
	}
}

void	save_scene_draw_title_background(t_stuff *e)
{
	ft_init_value_save_scene_draw_title_background(e, 0);
	if (e->i.save.select == 1)
		e->lt.couleur = 0x000000;
	awklm_string_put("Save", e);
	ft_init_value_save_scene_draw_title_background(e, 1);
	if (e->i.save.select == 2)
		e->lt.couleur = 0x000000;
	awklm_string_put("Load", e);
	ft_init_value_save_scene_draw_title_background(e, 2);
	if (e->i.save.select == 3)
		e->lt.couleur = 0x000000;
	awklm_string_put("Erase", e);
}
