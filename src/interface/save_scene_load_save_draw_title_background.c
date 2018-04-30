/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_scene_load_save_draw_title_background.c       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 09:14:41 by prossi            #+#    #+#             */
/*   Updated: 2018/04/18 13:27:47 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	save_scene_load_save_draw_title_background_td(t_stuff *e, int x)
{
	if (x == 0 && e->i.load.index_load != 0)
	{
		init_value_draw_title_background(e, 0);
		awklm_string_put("P", e);
		init_value_draw_title_background(e, 1);
		awklm_string_put("R", e);
		init_value_draw_title_background(e, 1);
		awklm_string_put("E", e);
		init_value_draw_title_background(e, 1);
		awklm_string_put("V", e);
	}
}

void	save_scene_load_save_draw_title_background_sd(t_stuff *e)
{
	if (e->i.load.nb_dir - (e->i.load.index_load * 5) > 0)
	{
		init_value_draw_title_background(e, 2);
		awklm_string_put(e->i.load.tab[e->i.load.index], e);
	}
	if (e->i.load.nb_dir - (e->i.load.index_load * 5) > 1)
	{
		init_value_draw_title_background(e, 3);
		awklm_string_put(e->i.load.tab[e->i.load.index + 1], e);
	}
	if (e->i.load.nb_dir - (e->i.load.index_load * 5) > 2)
	{
		init_value_draw_title_background(e, 4);
		awklm_string_put(e->i.load.tab[e->i.load.index + 2], e);
	}
	if (e->i.load.nb_dir - (e->i.load.index_load * 5) > 3)
	{
		init_value_draw_title_background(e, 5);
		awklm_string_put(e->i.load.tab[e->i.load.index + 3], e);
	}
	if (e->i.load.nb_dir - (e->i.load.index_load * 5) > 4)
	{
		init_value_draw_title_background(e, 6);
		awklm_string_put(e->i.load.tab[e->i.load.index + 4], e);
	}
}

void	save_scene_load_save_draw_title_background(t_stuff *e)
{
	int		x;

	x = 0;
	save_scene_load_save_draw_title_background_sd(e);
	if (e->i.load.nb_dir - (e->i.load.index_load * 5) > 5)
	{
		init_value_draw_title_background(e, 0);
		awklm_string_put("N", e);
		init_value_draw_title_background(e, 1);
		awklm_string_put("E", e);
		init_value_draw_title_background(e, 1);
		awklm_string_put("X", e);
		init_value_draw_title_background(e, 1);
		awklm_string_put("T", e);
		x = 1;
	}
	save_scene_load_save_draw_title_background_td(e, x);
}
