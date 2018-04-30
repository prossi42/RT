/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook_save_scene.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:16:16 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 17:07:02 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	mouse_hook_save_scene_fh(t_stuff *e)
{
	if (check_existing_save_dir(e) == 0)
	{
		e->i.load.act_erase = 1;
		e->i.load.act_load = 1;
		save_scene_load_save(e);
	}
	else
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, (WIN_Y - \
			LENGTH) * 3 + 3 * 40, 0xFFFFFF, "Impossible d'ouvrir le \
			dossier de sauvegarde");
}

void	mouse_hook_save_scene_td(t_stuff *e)
{
	if (check_existing_save_dir(e) == 0)
	{
		e->i.load.act_load = 1;
		save_scene_load_save(e);
	}
	else
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, (WIN_Y -\
			LENGTH) * 3 + 3 * 40, 0xFFFFFF, "Impossible d'ouvrir le \
			dossier de sauvegarde");
}

void	mouse_hook_save_scene_sd(t_stuff *e)
{
	if (check_existing_save_dir(e) == 0)
	{
		e->i.save.act_save = 1;
		save_scene_create_save(e);
	}
	else
	{
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, (WIN_Y - \
			LENGTH) * 3 + 3 * 40, 0xFFFFFF, "Impossible d'ouvrir le \
			dossier de sauvegarde");
		e->i.save.act_save = 0;
	}
}

void	mouse_hook_save_scene(t_stuff *e, int x, int y)
{
	if (y > (((WIN_Y - LENGTH) / 3) / 2) - 42 && y < (((WIN_Y - LENGTH) / 3)\
	/ 2) + 42 && x < ((WIN_X - WIDTH) * 2) - 20)
		mouse_hook_save_scene_sd(e);
	else if (y > ((WIN_Y - LENGTH) / 2) - 42 && y < ((WIN_Y - LENGTH) / 2) + 42)
		mouse_hook_save_scene_td(e);
	else if (y > (WIN_Y - LENGTH - (((WIN_Y - LENGTH) / 3) / 2)) - 42 && y \
	< (WIN_Y - LENGTH - (((WIN_Y - LENGTH) / 3) / 2)) + 42)
		mouse_hook_save_scene_fh(e);
	else if (y > 0 && y < 20 && x > ((WIN_X - WIDTH) * 2) - 20 && x < \
	((WIN_X - WIDTH) * 2))
	{
		e->i.save.settings = 2;
		save_scene(e);
	}
}
