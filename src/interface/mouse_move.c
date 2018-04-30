/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:24:08 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 10:24:30 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	mouse_move_load_scene(t_stuff *e, int x, int y)
{
	int		old_select;
	int		borderx;

	borderx = (WIN_X - WIDTH) + ((WIN_X - WIDTH) / 2);
	old_select = e->i.load.select;
	if (x > borderx && x < borderx + ((WIN_X - WIDTH) / 2.5) - 2)
	{
		if (y > 0 && y < 56)
			e->i.load.select = 1;
		else if (y > 56 && y < 112)
			e->i.load.select = 2;
		else if (y > 112 && y < 168)
			e->i.load.select = 3;
		else if (y > 168 && y < 224)
			e->i.load.select = 4;
		else if (y > 224 && y < 280)
			e->i.load.select = 5;
	}
	else
	{
		if (y > 0 && y < WIN_Y - LENGTH)
			e->i.load.select = 6;
	}
	if (e->i.load.select != old_select)
		save_scene_load_save(e);
}

void	mouse_move_objet_courant(t_stuff *e, int x, int y)
{
	if (y > 0 && y < 20 && x > WIN_X - WIDTH - 20 && x < WIN_X - WIDTH)
	{
		if (e->i.cobj.settings == 0)
		{
			e->i.cobj.settings = 1;
			objet_courant(e);
		}
	}
	else
	{
		if (e->i.cobj.settings == 1)
		{
			e->i.cobj.settings = 0;
			objet_courant(e);
		}
	}
}

void	mouse_move_matrice(t_stuff *e, int x, int y)
{
	int		limitx;

	limitx = WIN_X - WIDTH + ((WIN_X - WIDTH) / 2);
	if (y > 0 && y < 20 && x > limitx - 20 && x < limitx)
	{
		if (e->i.mat.settings == 0)
		{
			e->i.mat.settings = 1;
			matrice_interface(e);
		}
	}
	else
	{
		if (e->i.mat.settings == 1)
		{
			e->i.mat.settings = 0;
			matrice_interface(e);
		}
	}
}

int		mouse_move(int x, int y, t_stuff *e)
{
	if (x > 0 && x < WIN_X - WIDTH && y > (WIN_Y - LENGTH) * 2 && y < \
	(WIN_Y - LENGTH) * 3)
		mouse_move_new_obj(x, y, e);
	if (y > 0 && y < WIN_Y - LENGTH && x > (WIN_X - WIDTH) + ((WIN_X - \
		WIDTH) / 2) && x < (WIN_X - WIDTH) * 2)
	{
		if (e->i.save.settings < 2 && e->i.mat.settings < 2)
		{
			if (e->i.save.act_save != 4 && e->i.load.act_load == 0)
				mouse_move_save_scene(y, x, e);
			else
				mouse_move_load_scene(e, x, y);
		}
	}
	if (y > 0 && y < WIN_Y - LENGTH && x > 0 && x < WIN_X - WIDTH)
		mouse_move_objet_courant(e, x, y);
	if (y > 0 && y < WIN_Y - LENGTH && x > WIN_X - WIDTH && x < (WIN_X -\
		WIDTH) + ((WIN_X - WIDTH) / 2))
	{
		if (e->i.save.settings < 2 && e->i.mat.settings < 2)
			mouse_move_matrice(e, x, y);
	}
	return (0);
}
