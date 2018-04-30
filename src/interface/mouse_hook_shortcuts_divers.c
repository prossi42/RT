/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook_shortcuts_divers.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:20:39 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 10:21:54 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	mouse_hook_shortcuts_divers_td(t_stuff *e, int option)
{
	if (option == 0)
	{
		if (screenshots(e) == -1)
			mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, (WIN_Y - \
				LENGTH) * 3 + 3 * 40, 0xFFFFFF, "Erreur lors de la \
				creation du screenshot");
	}
	else if (option == 1)
	{
		if (e->i.reflex == 0)
			e->i.reflex = 1;
		else
			e->i.reflex = 0;
		if (e->i.filtre != 0)
			multi_thread(e);
	}
	else if (option == 2)
	{
		if (e->i.refrac == 0)
			e->i.refrac = 1;
		else
			e->i.refrac = 0;
		if (e->i.filtre != 0)
			multi_thread(e);
	}
}

void	mouse_hook_shortcuts_divers_sd(t_stuff *e, int option)
{
	if (option == 0)
	{
		if (e->pix != 0)
			e->pix = 0;
		else
			e->pix = 10;
		multi_thread(e);
	}
	else if (option == 1)
	{
		if (e->i.filtre != 4)
		{
			e->i.filtre = 4;
			interface_filtres(e);
			mlx_put_image_to_window(e->img.mlx_ptr, e->img.win_ptr, \
				e->img.img_ptr, WIN_X - WIDTH, WIN_Y - LENGTH);
		}
		else
			e->i.filtre = 0;
	}
}

void	mouse_hook_shortcuts_divers(t_stuff *e, int x)
{
	int		borderx;

	borderx = (WIN_X - WIDTH) * 2;
	if (x > borderx && x < borderx + ((WIN_X - WIDTH) / 5))
		mouse_hook_shortcuts_divers_sd(e, 0);
	if (x > borderx + ((WIN_X - WIDTH) / 5) && x < borderx + \
	(((WIN_X - WIDTH) / 5) * 2))
		mouse_hook_shortcuts_divers_sd(e, 1);
	else if (x > borderx + (((WIN_X - WIDTH) / 5) * 2) && x < borderx + \
	(((WIN_X - WIDTH) / 5) * 3))
		mouse_hook_shortcuts_divers_td(e, 0);
	else if (x > borderx + (((WIN_X - WIDTH) / 5) * 3) && x < borderx + \
	(((WIN_X - WIDTH) / 5) * 4))
		mouse_hook_shortcuts_divers_td(e, 1);
	else if (x > borderx + (((WIN_X - WIDTH) / 5) * 4) && x < borderx + \
	(((WIN_X - WIDTH) / 5) * 5))
		mouse_hook_shortcuts_divers_td(e, 2);
	if (e->i.filtre == 0)
		multi_thread(e);
}
