/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook_interface.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 15:28:50 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 17:06:41 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	mouse_hook_interface_sd(t_stuff *e, int x, int y)
{
	if (y > 0 && y < WIN_Y - LENGTH && x > 0 && x < WIN_X - WIDTH)
		mouse_hook_objet_courant(e, x, y);
	if (y > 0 && y < WIN_Y - LENGTH && x > (WIN_X - WIDTH) * 2 && x < \
	(WIN_X - WIDTH) * 3)
	{
		if (e->i.scr.act_scr == 0 && e->i.save.act_save == 0 && \
			e->i.load.act_load == 0 && e->i.load.act_erase == 0 && \
			e->i.mat.act_rot == -1 && e->i.mat.act_trans == -1 && \
			e->i.multi == 0 && e->i.damier == -1 && (e->i.perlin == 0 || \
				e->i.perlin == 3))
			mouse_hook_shortcuts(e, x, y);
	}
}

void	mouse_hook_interface(t_stuff *e, int x, int y)
{
	if (x > WIN_X - WIDTH && x <= (WIN_X - WIDTH) * 2)
	{
		if (e->i.scr.act_scr == 0 && e->i.multi == 0 && e->i.damier == -1 && \
			(e->i.perlin == 0 || e->i.perlin == 3))
			mouse_hook_matrice_save(e, x, y);
	}
	if (x > 0 && x < WIN_X - WIDTH && y > (WIN_Y - LENGTH) * 2 && y < \
	(WIN_Y - LENGTH) * 3)
	{
		if (e->i.save.act_save == 0 && e->i.load.act_load == 0 && \
			e->i.load.act_erase == 0 && e->i.mat.act_rot == -1 && \
			e->i.mat.act_trans == -1 && e->i.scr.act_scr == 0 && \
			e->i.multi == 0 && e->i.damier == -1 && (e->i.perlin == 0 || \
				e->i.perlin == 3))
		{
			mouse_hook_newobj(e, x, y);
			objet_courant(e);
			apercu_courant(e);
		}
	}
	mouse_hook_interface_sd(e, x, y);
}
