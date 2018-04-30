/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_scene_create_save.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 12:06:42 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 10:29:26 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	save_scene_create_save_fih(t_stuff *e)
{
	if (check_existing_user_save_file(e) == 0)
	{
		if (save_scene_fill_save(e) == 0)
			mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, (WIN_Y - \
				LENGTH) * 3 + 3 * 40, 0xFFFFFF, "Sauvegarde effectuee");
		else
			mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, (WIN_Y - \
				LENGTH) * 3 + 3 * 40, 0xFFFFFF, "Erreur lors de la \
				sauvegarde");
	}
	else
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, (WIN_Y - LENGTH)\
		* 3 + 3 * 40, 0xFFFFFF, "Le fichier existe deja");
	e->i.save.act_save = 0;
	e->i.load.first = 0;
	save_scene(e);
	shortcuts(e);
}

void	save_scene_create_save_fh(t_stuff *e)
{
	mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, (WIN_Y - LENGTH) * \
	3 + 3 * 40, 0xFFFFFF, "Selectionnez le dossier de sauvegarde");
	save_scene_load_save(e);
}

void	save_scene_create_save_td(t_stuff *e)
{
	if (check_existing_save_file(e) == 0)
	{
		if (save_scene_fill_save(e) == 0)
			mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, (WIN_Y - \
				LENGTH) * 3 + 3 * 40, 0xFFFFFF, "Sauvegarde effectuee");
		else
			mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, (WIN_Y - \
				LENGTH) * 3 + 3 * 40, 0xFFFFFF, "Erreur lors de la \
				sauvegarde");
	}
	else
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, (WIN_Y - LENGTH)\
		* 3 + 3 * 40, 0xFFFFFF, "Le fichier existe deja");
	e->i.save.act_save = 0;
	e->i.load.first = 0;
	free_tab(e);
	ft_strdel(&e->i.save.save_dir);
	save_scene(e);
}

void	save_scene_create_save_sd(t_stuff *e)
{
	if (check_existing_user_save_dir(e) == 0)
		e->i.save.act_save = 7;
	else
	{
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, (WIN_Y - LENGTH)\
		* 3 + 3 * 40, 0xFFFFFF, "Le dossier existe deja");
		e->i.save.act_save = 0;
	}
}

void	save_scene_create_save(t_stuff *e)
{
	if (e->i.save.act_save == 1)
		terminal(e);
	else if (e->i.save.act_save == 2)
		save_scene_create_save_sd(e);
	else if (e->i.save.act_save == 6)
		save_scene_create_save_td(e);
	else if (e->i.save.act_save == 3)
		save_scene_create_save_fh(e);
	else if (e->i.save.act_save == 7)
		save_scene_create_save_fih(e);
}
