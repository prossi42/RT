/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook_matrice_save.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 10:36:43 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 17:06:47 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	mouse_hook_matrice_save(t_stuff *e, int x, int y)
{
	if (e->i.mat.settings < 2 && e->i.save.settings < 2)
	{
		if (x >= WIN_X - WIDTH && x <= WIN_X - WIDTH + ((WIN_X - WIDTH) / 2) \
		&& y > 0 && y <= WIN_Y - LENGTH)
		{
			if (e->i.save.act_save == 0 && e->i.load.act_load == 0 && \
				e->i.load.act_erase == 0)
				mouse_hook_matrice(e, x, y);
		}
		if (y > 0 && y < WIN_Y - LENGTH && x > (WIN_X - WIDTH) + ((WIN_X - \
			WIDTH) / 2) && x < (WIN_X - WIDTH) * 2)
		{
			if (e->i.mat.act_rot == -1 && e->i.mat.act_trans == -1)
			{
				if (e->i.save.act_save != 4 && e->i.load.act_load == 0 && \
					e->i.load.act_erase == 0)
					mouse_hook_save_scene(e, x, y);
				else
					mouse_hook_load_scene(e, x, y, \
						(WIN_X - WIDTH) + ((WIN_X - WIDTH) / 2));
			}
		}
	}
	else
		mouse_hook_matrice_save_color(e, x, y);
}
