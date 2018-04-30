/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook_shortcuts_filtres.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:20:25 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 10:21:22 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	mouse_hook_shortcuts_filtres_td(t_stuff *e, int option)
{
	if (option == 0)
	{
		if (e->i.filtre != 3)
		{
			e->i.filtre = 3;
			interface_filtres(e);
			mlx_put_image_to_window(e->img.mlx_ptr, e->img.win_ptr, \
				e->img.img_ptr, WIN_X - WIDTH, WIN_Y - LENGTH);
		}
		else
			e->i.filtre = 0;
	}
	else if (option == 1)
	{
		if (e->tex.act_skybox == 0)
			e->tex.act_skybox = 1;
		else
			e->tex.act_skybox = 0;
	}
}

void	mouse_hook_shortcuts_filtres_sd(t_stuff *e, int option)
{
	if (option == 0)
	{
		if (e->i.filtre != 1)
			e->i.filtre = 1;
		else
			e->i.filtre = 0;
		multi_thread(e);
	}
	else if (option == 1)
	{
		if (e->i.filtre != 2)
			e->i.filtre = 2;
		else
			e->i.filtre = 0;
	}
}

void	mouse_hook_shortcuts_filtres(t_stuff *e, int x)
{
	int		borderx;

	borderx = (WIN_X - WIDTH) * 2;
	if (x > borderx && x < borderx + ((WIN_X - WIDTH) / 5))
		mouse_hook_shortcuts_filtres_sd(e, 0);
	else if (x > borderx + ((WIN_X - WIDTH) / 5) && x < borderx + \
	(((WIN_X - WIDTH) / 5) * 2))
		mouse_hook_shortcuts_filtres_sd(e, 1);
	else if (x > borderx + (((WIN_X - WIDTH) / 5) * 2) && x < borderx + \
	(((WIN_X - WIDTH) / 5) * 3))
		mouse_hook_shortcuts_filtres_td(e, 0);
	else if (x > borderx + (((WIN_X - WIDTH) / 5) * 3) && x < borderx + \
	(((WIN_X - WIDTH) / 5) * 4))
		mouse_hook_shortcuts_filtres_td(e, 1);
	else if (x > borderx + (((WIN_X - WIDTH) / 5) * 4) && x < borderx + \
	(((WIN_X - WIDTH) / 5) * 5))
	{
		if (e->i.filtre != 6)
			e->i.filtre = 6;
		else
			e->i.filtre = 0;
	}
	if (e->i.filtre == 0 || e->i.filtre == 1 || e->i.filtre == 2 || \
		e->i.filtre == 6)
		multi_thread(e);
}
