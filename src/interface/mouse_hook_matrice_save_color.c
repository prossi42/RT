/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook_matrice_save_color.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:14:04 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 10:14:04 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	mouse_hook_matrice_save_color_fh(t_stuff *e)
{
	if (e->i.mat.settings == 2)
		e->i.mat.settings = 5;
	else
		e->i.save.settings = 5;
}

void	mouse_hook_matrice_save_color_td(t_stuff *e)
{
	if (e->i.mat.settings == 2)
		e->i.mat.settings = 4;
	else
		e->i.save.settings = 4;
}

void	mouse_hook_matrice_save_color_sd(t_stuff *e)
{
	if (e->i.mat.settings == 2)
		e->i.mat.settings = 3;
	else
		e->i.save.settings = 3;
}

void	mouse_hook_matrice_save_color(t_stuff *e, int x, int y)
{
	int		borderx;

	borderx = (WIN_X - WIDTH);
	if (e->i.mat.settings == 2 || e->i.save.settings == 2)
	{
		if (x > borderx + 250 && x < borderx + 320 && y < 110 && y > 70)
			mouse_hook_matrice_save_color_sd(e);
		if (x > borderx + 250 && x < borderx + 320 && y < 180 && y > 140)
			mouse_hook_matrice_save_color_td(e);
		if (x > borderx + 250 && x < borderx + 320 && y < 250 && y > 210)
			mouse_hook_matrice_save_color_fh(e);
		settings_color(e);
	}
	else
	{
		mouse_hook_matrice_save_select_color(e, x, y);
		settings_color(e);
	}
}
