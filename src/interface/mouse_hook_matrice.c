/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook_matrice.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 10:33:48 by prossi            #+#    #+#             */
/*   Updated: 2018/04/19 14:17:34 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	mouse_hook_matrice_fh(t_stuff *e)
{
	if (e->i.mat.dir_or_pos != 1 && e->i.mat.act_trans == -1)
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

void	mouse_hook_matrice_td(t_stuff *e)
{
	if (e->i.mat.act_trans == -1 && e->i.mat.dir_or_pos != 1)
	{
		e->i.mat.act_trans = 0;
		e->m.type = 't';
		e->i.mat.act_rot = -1;
		e->i.mat.act_value = 1;
		e->i.mat.act_angle = 0;
		terminal(e);
	}
	else if (e->i.mat.act_trans == 1)
	{
		e->i.mat.act_trans = -1;
		e->m.type = '\0';
	}
}

void	mouse_hook_matrice_sd(t_stuff *e)
{
	if (e->i.mat.act_rot == -1)
	{
		terminal(e);
		e->i.mat.act_rot = 0;
		e->m.type = 'r';
		e->i.mat.act_trans = -1;
		e->i.mat.act_angle = 1;
		e->i.mat.act_value = 0;
		terminal(e);
	}
	else if (e->i.mat.act_rot == 1)
	{
		e->i.mat.act_rot = -1;
		e->m.type = '\0';
	}
}

void	mouse_hook_matrice_nh(t_stuff *e, int x, int y)
{
	int		borderx;

	borderx = WIN_X - WIDTH;
	if (x > borderx + ((borderx / 4) - 23) && x < borderx + \
	((borderx / 4) + 23) && y > ((WIN_Y - LENGTH) / 2) - 23 && y < \
	((WIN_Y - LENGTH) / 2) + 23)
		mouse_hook_matrice_seh(e);
	else if (x > borderx + (borderx / 4) + (borderx / 8) - 23 && \
	x < borderx + (borderx / 4) + (borderx / 8) + 23 && y > ((WIN_Y - \
		LENGTH) / 2) - 23 && y < ((WIN_Y - LENGTH) / 2) + 23)
		mouse_hook_matrice_hh(e);
	else if (y > 0 && y < 20 && x > borderx + ((WIN_X - WIDTH) / 2) - \
	20 && x < borderx + ((WIN_X - WIDTH) / 2))
		e->i.mat.settings = 2;
}

void	mouse_hook_matrice(t_stuff *e, int x, int y)
{
	int		borderx;

	borderx = WIN_X - WIDTH;
	if (y >= 7 && y < 57 && x < borderx + ((WIN_X - WIDTH) / 2) - 20)
		mouse_hook_matrice_sd(e);
	else if (y > 65 && y < 115)
		mouse_hook_matrice_td(e);
	else if (y > WIN_Y - LENGTH - 115 && y < WIN_Y - LENGTH - 65)
		mouse_hook_matrice_fh(e);
	else if (y > WIN_Y - LENGTH - 57 && y < WIN_Y - LENGTH - 7)
		mouse_hook_matrice_fih(e);
	else if (x > borderx + ((borderx / 8) - 23) && x < borderx + \
	((borderx / 8) + 23) && y > ((WIN_Y - LENGTH) / 2) - 23 && y < \
	((WIN_Y - LENGTH) / 2) + 23)
		mouse_hook_matrice_sh(e);
	else
		mouse_hook_matrice_nh(e, x, y);
	matrice_interface(e);
}
