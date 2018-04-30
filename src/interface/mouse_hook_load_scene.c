/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook_load_scene.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 10:42:51 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 10:13:03 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		mouse_hook_load_scene_td(t_stuff *e, int y, int lol)
{
	if (y > 168 && y < 224 && e->i.load.nb_dir >= 4)
	{
		e->i.load.index = 3;
		lol = 1;
	}
	else if (y > 224 && y < 280 && e->i.load.nb_dir >= 5)
	{
		e->i.load.index = 4;
		lol = 1;
	}
	return (lol);
}

int		mouse_hook_load_scene_sd(t_stuff *e, int y, int lol)
{
	if (e->i.save.act_save != 0)
		e->i.save.act_save = 5;
	if (e->i.load.act_load == 1)
		e->i.load.act_load = 2;
	if (e->i.load.act_load == 3)
		e->i.load.act_load = 4;
	if (y > 0 && y < 56 && e->i.load.nb_dir >= 1)
	{
		e->i.load.index = 0;
		lol = 1;
	}
	else if (y > 56 && y < 112 && e->i.load.nb_dir >= 2)
	{
		e->i.load.index = 1;
		lol = 1;
	}
	else if (y > 112 && y < 168 && e->i.load.nb_dir >= 3)
	{
		e->i.load.index = 2;
		lol = 1;
	}
	lol = mouse_hook_load_scene_td(e, y, lol);
	return (lol);
}

void	mouse_hook_load_scene(t_stuff *e, int x, int y, int borderx)
{
	int		lol;

	lol = 0;
	if (x > borderx && x < borderx + ((WIN_X - WIDTH) / 2.5) - 2)
		lol = mouse_hook_load_scene_sd(e, y, lol);
	else
	{
		if (y > 0 && y < WIN_Y - LENGTH)
		{
			lol = 1;
			if (e->i.load.nb_dir - (e->i.load.index_load * 5) > 5)
			{
				e->i.load.index_load++;
				e->i.load.index += 5;
			}
			else
			{
				e->i.load.index_load = 0;
				e->i.load.index = 0;
			}
		}
	}
	if (lol == 1)
		save_scene_load_save(e);
}
