/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook_objet_courant.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 10:23:28 by prossi            #+#    #+#             */
/*   Updated: 2018/04/19 13:45:46 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	mouse_hook_objet_courant_select_color(t_stuff *e, int x, int y)
{
	int		i;
	int		j;

	j = -1;
	while (++j < 12)
	{
		i = -1;
		while (++i < 18)
		{
			if (x >= e->i.color.tabxd[j][i] && x <= e->i.color.tabxf[j][i] \
			&& y >= e->i.color.tabyd[j][i] && y <= e->i.color.tabyf[j][i])
			{
				if (e->i.cobj.settings == 3)
					e->i.color.cobj.col1 = e->i.color.tab[j][i];
				else if (e->i.cobj.settings == 4)
					e->i.color.cobj.col2 = e->i.color.tab[j][i];
				else if (e->i.cobj.settings == 5)
					e->i.color.cobj.col3 = e->i.color.tab[j][i];
				e->i.cobj.settings = 0;
			}
		}
	}
}

void	mouse_hook_objet_courant_color(t_stuff *e, int x, int y)
{
	if (e->i.cobj.settings == 2)
	{
		if (x > 250 && x < 320 && y < 110 && y > 70)
			e->i.cobj.settings = 3;
		if (x > 250 && x < 320 && y < 180 && y > 140)
			e->i.cobj.settings = 4;
		if (x > 250 && x < 320 && y < 250 && y > 210)
			e->i.cobj.settings = 5;
		settings_color(e);
	}
	else
	{
		mouse_hook_objet_courant_select_color(e, x, y);
		objet_courant(e);
	}
}

void	mouse_hook_objet_courant(t_stuff *e, int x, int y)
{
	if (e->i.cobj.settings < 2)
	{
		if (y > 0 && y < 20 && x > WIN_X - WIDTH - 20 && x < WIN_X - WIDTH)
			e->i.cobj.settings = 2;
		else
		{
			if (e->i.cobj.power == 0)
				e->i.cobj.power = 1;
			else
				e->i.cobj.power = 0;
		}
		objet_courant(e);
	}
	else
		mouse_hook_objet_courant_color(e, x, y);
}
