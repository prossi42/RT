/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook_newobj.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:19:00 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 10:19:22 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	mouse_hook_newobj_fih(t_stuff *e)
{
	if (e->i.objet > -1)
	{
		e->i.objet--;
		e->i.each_obj = 0;
	}
}

void	mouse_hook_newobj_fh(t_stuff *e)
{
	if (e->i.objet < LIGHT)
	{
		e->i.objet++;
		e->i.each_obj = 0;
	}
}

void	mouse_hook_newobj_td(t_stuff *e)
{
	if (e->i.nobj.power == 0)
		e->i.nobj.power = 1;
	else
		e->i.nobj.power = 0;
}

void	mouse_hook_newobj_sd(t_stuff *e, int x, int y)
{
	int		centery;
	int		centerx;
	int		bordery;

	bordery = (WIN_Y - LENGTH) * 2;
	centery = bordery + ((((WIN_Y - LENGTH) * 3) - ((WIN_Y - LENGTH) * 2)) / 2);
	centerx = (WIN_X - WIDTH) / 2;
	if (e->i.nobj.power == 1 && y > centery - 100 && y < \
		centery + 100 && x > centerx + 100 && x < 402)
		switch_next_objet(e);
	else if (e->i.nobj.power == 1 && y > centery - 100 && y < \
		centery + 100 && x < centerx - 100 && x > 123)
		switch_prev_objet(e);
	else if (e->i.nobj.power == 1 && y > centery - 100 && y < \
		centery + 100 && x > WIN_X - WIDTH - 100 && x < WIN_X - WIDTH)
		set_new_obj(e);
	else if (e->i.nobj.power == 1 && y > centery - 100 && y < \
		centery + 100 && x > 0 && x < 100)
		set_del_objet(e);
	else if (y > bordery && y < bordery + 20 && x > WIN_X - \
		WIDTH - 20 && x < WIN_X - WIDTH)
		e->i.nobj.settings = 2;
}

void	mouse_hook_newobj(t_stuff *e, int x, int y)
{
	int		centery;
	int		centerx;
	int		bordery;

	bordery = (WIN_Y - LENGTH) * 2;
	centery = bordery + ((((WIN_Y - LENGTH) * 3) - ((WIN_Y - LENGTH) * 2)) / 2);
	centerx = (WIN_X - WIDTH) / 2;
	if (e->i.nobj.settings > 1)
		mouse_hook_new_obj_color(e, x, y);
	else
	{
		if (y >= centery - 100 && y <= centery + 100 && x > centerx - \
			100 && x <= centerx + 100)
			mouse_hook_newobj_td(e);
		else if (e->i.nobj.power == 1 && y > bordery && y < centery - \
			100 && x > centerx - 100 && x < centerx + 100)
			mouse_hook_newobj_fh(e);
		else if (e->i.nobj.power == 1 && y > centery + 100 && y < \
			(WIN_Y - LENGTH) * 3 && x > centerx - 100 && x < centerx + 100)
			mouse_hook_newobj_fih(e);
		else
			mouse_hook_newobj_sd(e, x, y);
		create_obj(e);
	}
}
