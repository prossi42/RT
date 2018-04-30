/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_scene_load_scene_fh.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 13:17:17 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 15:29:27 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	save_scene_load_save_fhh(t_stuff *e)
{
	if (e->i.load.act_load == 4)
	{
		free_tab(e);
		e->i.load.first = 0;
		e->i.load.act_load = 0;
		e->i.load.index_load = 0;
		e->i.load.act_erase = 0;
		ft_strdel(&e->i.save.save_dir);
		save_scene(e);
	}
}

void	save_scene_load_save_thh(t_stuff *e)
{
	if (e->i.load.act_load == 4)
	{
		if (save_scene_load_save_select_dir(e) == -1)
			save_scene_load_save_hh(e);
		else
		{
			if (e->i.load.act_erase == 0)
				save_scene_load_save_nh(e);
			else
				save_scene_load_save_th(e);
		}
	}
}

void	save_scene_load_save_twh(t_stuff *e)
{
	if (e->i.load.act_load == 2)
	{
		if (save_scene_load_save_select_dir(e) == -1)
			save_scene_load_save_fih(e);
		else
		{
			free_tab(e);
			e->i.load.first = 0;
			if (save_scene_open_load_save(e) == -1)
				save_scene_load_save_sh(e);
			else
				save_scene_load_save_seh(e);
		}
	}
}
