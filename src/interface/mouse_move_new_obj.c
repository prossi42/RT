/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move_new_obj.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Awk-LM <Awk-LM@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 23:39:04 by Awk-LM            #+#    #+#             */
/*   Updated: 2018/03/05 11:30:16 by Awk-LM           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	mouse_move_new_obj(int x, int y, t_stuff *e)
{
	int			centery;
	int			centerx;
	int			bordery;

	bordery = (WIN_Y - LENGTH) * 2;
	centery = bordery + ((((WIN_Y - LENGTH) * 3) - ((WIN_Y - LENGTH) * 2)) / 2);
	centerx = (WIN_X - WIDTH) / 2;
	e->i.nobj.old_open = e->i.nobj.open;
	if (y > centery - 100 && y < centery + 100)
	{
		if (x > 0 && x < 100)
			e->i.nobj.open = 1;
		else if (x < WIN_X - WIDTH && x > (WIN_X - WIDTH) - 100)
			e->i.nobj.open = 2;
		else
			e->i.nobj.open = 0;
	}
	if (e->i.nobj.open != e->i.nobj.old_open)
		create_obj(e);
}
