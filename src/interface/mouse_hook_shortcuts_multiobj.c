/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook_shortcuts_multiobj.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:20:15 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 10:20:16 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	mouse_hook_shortcuts_multiobj_fih(t_stuff *e)
{
	if (e->i.perlin == 0)
	{
		e->i.perlin = 1;
		terminal(e);
	}
	else
	{
		e->i.perlin = 0;
		multi_thread(e);
		apercu_courant(e);
	}
}

void	mouse_hook_shortcuts_multiobj_fh(t_stuff *e)
{
	if (e->i.filtre != 5)
	{
		e->i.filtre = 5;
		e->i.damier = 0;
		terminal(e);
	}
	else
	{
		e->i.filtre = 0;
		multi_thread(e);
	}
}

void	mouse_hook_shortcuts_multiobj_td(t_stuff *e)
{
	if (e->i.mobj.start == 0 && e->i.mobj.end == 0)
	{
		e->i.multi = 2;
		terminal(e);
		multi_thread(e);
	}
	else
	{
		e->i.multi = 0;
		terminal(e);
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, (WIN_Y - \
			LENGTH) * 3 + 3 * 40, 0xFFFFFF, "Merci de supprimer la \
			precedente pyrasphere");
	}
}

void	mouse_hook_shortcuts_multiobj_sd(t_stuff *e)
{
	if (e->i.mobj.start == 0 && e->i.mobj.end == 0)
	{
		e->i.multi = 1;
		terminal(e);
	}
	else
	{
		e->i.multi = 0;
		terminal(e);
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, (WIN_Y - \
			LENGTH) * 3 + 3 * 40, 0xFFFFFF, "Merci de supprimer le \
			precedent cubesphere");
	}
}

void	mouse_hook_shortcuts_multiobj(t_stuff *e, int x)
{
	int		borderx;

	borderx = (WIN_X - WIDTH) * 2;
	if (x > borderx && x < borderx + ((WIN_X - WIDTH) / 5))
		mouse_hook_shortcuts_multiobj_sd(e);
	else if (x > borderx + ((WIN_X - WIDTH) / 5) && x < borderx + \
	(((WIN_X - WIDTH) / 5) * 2))
		mouse_hook_shortcuts_multiobj_td(e);
	else if (x > borderx + (((WIN_X - WIDTH) / 5) * 2) && x < borderx + \
	(((WIN_X - WIDTH) / 5) * 3))
		mouse_hook_shortcuts_multiobj_fh(e);
	else if (x > borderx + (((WIN_X - WIDTH) / 5) * 3) && x < borderx + \
	(((WIN_X - WIDTH) / 5) * 4))
		mouse_hook_shortcuts_multiobj_fih(e);
	else if (x > borderx + (((WIN_X - WIDTH) / 5) * 4) && x < borderx + \
	(((WIN_X - WIDTH) / 5) * 5))
		mouse_hook_shortcuts_multiobj_sh(e);
}
