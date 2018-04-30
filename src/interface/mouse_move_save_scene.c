/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move_save_scene.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:22:05 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 10:23:20 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	mouse_move_save_scene_sd(int y, t_stuff *e)
{
	if (y > (((WIN_Y - LENGTH) / 3) / 2) - 42 && y < (((WIN_Y - LENGTH) \
	/ 3) / 2) + 42)
		e->i.save.select = 1;
	else if (y > ((WIN_Y - LENGTH) / 2) - 42 && y < ((WIN_Y - LENGTH) \
	/ 2) + 42)
		e->i.save.select = 2;
	else if (y > (WIN_Y - LENGTH - (((WIN_Y - LENGTH) / 3) / 2)) - 42 && \
	y < (WIN_Y - LENGTH - (((WIN_Y - LENGTH) / 3) / 2)) + 42)
		e->i.save.select = 3;
	else
		e->i.save.select = 0;
}

void	mouse_move_save_scene(int y, int x, t_stuff *e)
{
	int		old_select;

	old_select = e->i.save.select;
	mouse_move_save_scene_sd(y, e);
	if (e->i.save.select != old_select)
		save_scene(e);
	if (y > 0 && y < 20 && x > ((WIN_X - WIDTH) * 2) - 20 && x < (WIN_X - \
		WIDTH) * 2)
	{
		if (e->i.save.settings == 0)
		{
			e->i.save.settings = 1;
			save_scene(e);
		}
	}
	else
	{
		if (e->i.save.settings == 1)
		{
			e->i.save.settings = 0;
			save_scene(e);
		}
	}
}
