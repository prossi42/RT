/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_scene_load_scene_sd.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:45:30 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 17:08:08 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	save_scene_load_save_sh(t_stuff *e)
{
	e->i.load.act_load = 0;
	e->i.load.act_erase = 0;
	terminal(e);
	mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, (WIN_Y \
		- LENGTH) * 3 + 3 * 40, 0xFFFFFF, "Erreur lors du \
		chargement des sauvegardes");
}

void	save_scene_load_save_fih(t_stuff *e)
{
	e->i.load.act_load = 0;
	terminal(e);
	mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, (WIN_Y - \
		LENGTH) * 3 + 3 * 40, 0xFFFFFF, "Erreur lors du chargement\
		des sauvegardes");
}

void	save_scene_load_save_fh(t_stuff *e)
{
	if (save_scene_load_save_select_dir(e) == -1)
	{
		e->i.save.act_save = 4;
		terminal(e);
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, (WIN_Y - \
			LENGTH) * 3 + 3 * 40, 0xFFFFFF, "Erreur lors du chargement \
			des sauvegardes");
	}
	else
		terminal(e);
}

void	save_scene_load_save_td(t_stuff *e)
{
	if (e->i.load.nb_dir == 0)
	{
		if (e->i.load.act_erase == 0)
			ft_strdel(&e->i.save.save_dir);
		else
		{
			save_scene_erase_save(e);
			ft_strdel(&e->i.save.save_dir);
		}
		e->i.load.first = 0;
		e->i.save.act_save = 0;
		e->i.load.act_erase = 0;
		free_tab(e);
		terminal(e);
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, \
			(WIN_Y - LENGTH) * 3 + 3 * 40, 0xFFFFFF, "Le dossier \
			de sauvegarde est vide");
		save_scene(e);
	}
}

void	save_scene_load_save_sd(t_stuff *e)
{
	e->i.save.act_save = 0;
	e->i.load.act_load = 0;
	terminal(e);
	mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, (WIN_Y - \
		LENGTH) * 3 + 3 * 40, 0xFFFFFF, "Erreur lors du chargement \
		des sauvegardes");
}
