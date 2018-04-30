/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move_new_obj.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:17:15 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 10:17:16 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	mouse_move_new_obj_fh(t_stuff *e)
{
	if (e->i.nobj.settings == 1)
	{
		e->i.nobj.settings = 0;
		create_obj(e);
	}
}

void	mouse_move_new_obj_td(t_stuff *e)
{
	if (e->i.nobj.settings == 0)
	{
		e->i.nobj.settings = 1;
		create_obj(e);
	}
}

void	mouse_move_new_obj_sd(int x, t_stuff *e)
{
	if (x > 0 && x < 100)
		e->i.nobj.open = 1;
	else if (x < WIN_X - WIDTH && x > (WIN_X - WIDTH) - 100)
		e->i.nobj.open = 2;
	else
		e->i.nobj.open = 0;
}

void	mouse_move_new_obj(int x, int y, t_stuff *e)
{
	int			centery;
	int			centerx;
	int			bordery;

	bordery = (WIN_Y - LENGTH) * 2;
	centery = bordery + ((((WIN_Y - LENGTH) * 3) - ((WIN_Y - LENGTH) * 2)) / 2);
	centerx = (WIN_X - WIDTH) / 2;
	if (e->i.nobj.settings < 2)
	{
		e->i.nobj.old_open = e->i.nobj.open;
		if (y > centery - 100 && y < centery + 100)
			mouse_move_new_obj_sd(x, e);
		if (e->i.nobj.open != e->i.nobj.old_open)
			create_obj(e);
		if (y > bordery && y < bordery + 20 && x > WIN_X - WIDTH - 20 && \
			x < WIN_X - WIDTH)
			mouse_move_new_obj_td(e);
		else
			mouse_move_new_obj_fh(e);
	}
}
