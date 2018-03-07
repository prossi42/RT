/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook_interface.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 15:28:50 by prossi            #+#    #+#             */
/*   Updated: 2018/02/12 11:20:11 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	mouse_hook_matrice(t_stuff *e, int x, int y)
{
	int		borderx;

	borderx = WIN_X - WIDTH;
	if (x > borderx + 40 && x < borderx + 240 && y > 100 && y < 140)
	{
		if (e->i.mat.act_rot == 0)
		{
			e->i.mat.act_rot = 1;
			e->m.type = 'r';
			e->i.mat.act_trans = 0;
		}
		else
		{
			e->i.mat.act_rot = 0;
			e->m.type = '\0';
		}
	}
	else if (x > borderx + 40 && x < borderx + 240 && y > 160 && y < 200)
	{
		if (e->i.mat.act_trans == 0)
		{
			e->i.mat.act_trans = 1;
			e->m.type = 't';
			e->i.mat.act_rot = 0;
		}
		else
		{
			e->i.mat.act_trans = 0;
			e->m.type = '\0';
		}
	}
	else if (x > borderx + 40 && x < borderx + 240 && y > 220 && y < 260)
	{
		if (e->i.mat.dir_or_pos != 1)
		{
			e->i.mat.dir_or_pos = 1;
			e->m.type_sujet = 2;
		}
		else
		{
			e->i.mat.dir_or_pos = 0;
			e->m.type_sujet = 0;
		}
	}
	else if (x > borderx + 280 && x < borderx + 480 && y > 220 && y < 260)
	{
		if (e->i.mat.dir_or_pos != 2)
		{
			e->i.mat.dir_or_pos = 2;
			e->m.type_sujet = 1;
		}
		else
		{
			e->m.type_sujet = 0;
			e->i.mat.dir_or_pos = 0;
		}
	}
	else if (x > borderx + 280 && x < borderx + 320 && ((y > 100 && y < 140) || (y > 160 && y < 200)))
	{
		if (e->i.mat.act_xyz != 1)
		{
			e->i.mat.act_xyz = 1;
			e->m.axe = 'x';
		}
		else
		{
			e->i.mat.act_xyz = 0;
			e->m.axe = '\0';
		}
	}
	else if (x > borderx + 330 && x < borderx + 370 && ((y > 100 && y < 140) || (y > 160 && y < 200)))
	{
		if (e->i.mat.act_xyz != 2)
		{
			e->i.mat.act_xyz = 2;
			e->m.axe = 'y';
		}
		else
		{
			e->i.mat.act_xyz = 0;
			e->m.axe = '\0';
		}
	}
	else if (x > borderx + 380 && x < borderx + 420 && ((y > 100 && y < 140) || (y > 160 && y < 200)))
	{
		if (e->i.mat.act_xyz != 3)
		{
			e->i.mat.act_xyz = 3;
			e->m.axe = 'z';
		}
		else
		{
			e->i.mat.act_xyz = 0;
			e->m.axe = '\0';
		}
	}
	else if (x > borderx + 430 && x < borderx + 510 && y > 100 && y < 140 && e->i.mat.act_angle == 0)
	{
		if (e->i.term.first == 0)
		{
			malloc2d(e);
		}
		e->i.term.wbuf = ft_strnew(15);
		e->i.mat.act_angle = 1;
		e->i.term.first = 1;
		terminal(e);
	}
	else if (x > borderx + 430 && x < borderx + 510 && y > 160 && y < 200 && e->i.mat.act_value == 0)
	{
		if (e->i.term.first == 0)
		{
			malloc2d(e);
		}
		e->i.term.wbuf = ft_strnew(15);
		e->i.mat.act_value = 1;
		e->i.term.first = 1;
		terminal(e);
	}
	matrice_interface(e);
}

void	mouse_hook_interface(t_stuff *e, int x, int y)
{
	if (x >= WIN_X - WIDTH && x <= WIN_X - WIDTH + WIN_X - WIDTH && y > 0 && y <= WIN_Y - LENGTH)
	{
		mouse_hook_matrice(e, x, y);
	}
	if (x > 0 && x < WIN_X - WIDTH && y > (WIN_Y - LENGTH) * 2 && y < (WIN_Y - LENGTH) * 3)
	{
		mouse_hook_newobj(e, x, y);
		objet_courant(e);
		apercu_courant(e);
	}
}
