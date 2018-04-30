/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_scene_load_scene_td.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 13:16:34 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 17:08:16 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	save_scene_load_save_elh(t_stuff *e)
{
	if (e->i.load.first == 0)
	{
		if (save_scene_open_load_save(e) == -1)
			save_scene_load_save_sd(e);
		else
			save_scene_load_save_td(e);
	}
	if (e->i.save.act_save == 5)
		save_scene_load_save_fh(e);
}

void	save_scene_load_save_th(t_stuff *e)
{
	if (save_scene_erase_save(e) == 0)
	{
		terminal(e);
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, \
			(WIN_Y - LENGTH) * 3 + 3 * 40, 0xFFFFFF, "Fichier \
			efface");
	}
	else
	{
		terminal(e);
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, \
			(WIN_Y - LENGTH) * 3 + 3 * 40, 0xFFFFFF, "Erreur \
			lors de la suppression de la sauvegarde");
	}
}

void	save_scene_load_save_nh(t_stuff *e)
{
	terminal(e);
	if (save_scene_parsing_save(e) == 0)
	{
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, \
			(WIN_Y - LENGTH) * 3 + 3 * 40, 0xFFFFFF, \
			"Chargement de la scene en cours");
		e->i.objet = -1;
		e->i.each_obj = 0;
		multi_thread(e);
	}
	else
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, \
			(WIN_Y - LENGTH) * 3 + 3 * 40, 0xFFFFFF, "Erreur \
			lors du chargement de la sauvegarde");
}

void	save_scene_load_save_hh(t_stuff *e)
{
	e->i.load.act_load = 0;
	e->i.load.act_erase = 0;
	terminal(e);
	mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, (WIN_Y - \
		LENGTH) * 3 + 3 * 40, 0xFFFFFF, "Erreur lors du chargement \
		des sauvegardes");
}

void	save_scene_load_save_seh(t_stuff *e)
{
	if (e->i.load.nb_dir == 0)
	{
		if (e->i.load.act_erase == 0)
			ft_strdel(&e->i.save.save_dir);
		else
			save_scene_erase_save(e);
		e->i.load.first = 0;
		e->i.load.act_load = 0;
		e->i.load.act_erase = 0;
		ft_strdel(&e->i.save.save_dir);
		free_tab(e);
		terminal(e);
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, \
			(WIN_Y - LENGTH) * 3 + 3 * 40, 0xFFFFFF, "Le \
			dossier de sauvegarde est vide");
		save_scene(e);
	}
	e->i.load.act_load = 3;
}
