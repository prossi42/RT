/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_scene_load_save_draw_ellipse_background.c     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:44:21 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 10:44:43 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	loop_ellipse(t_stuff *e)
{
	while (e->bs.height > 0)
	{
		e->bs.height--;
		ft_ellipse(e, 0, 0);
	}
	while (e->bs.width > 1)
	{
		e->bs.width--;
		ft_ellipse(e, 0, 0);
	}
}

void	save_scene_load_save_draw_ellipse_background_fh(t_stuff *e)
{
	if (e->i.load.nb_dir - (e->i.load.index_load * 5) > 4)
	{
		ft_init_value_draw_ellipse_background(e, 21);
		if (e->i.load.select == 5)
			e->lt.couleur = e->i.color.saves.col3;
		ft_ellipse(e, 0, 0);
		ft_init_value_draw_ellipse_background(e, 21);
		loop_ellipse(e);
	}
}

void	save_scene_load_save_draw_ellipse_background_td(t_stuff *e)
{
	if (e->i.load.nb_dir - (e->i.load.index_load * 5) > 2)
	{
		ft_init_value_draw_ellipse_background(e, 19);
		if (e->i.load.select == 3)
			e->lt.couleur = e->i.color.saves.col3;
		ft_ellipse(e, 0, 0);
		ft_init_value_draw_ellipse_background(e, 19);
		loop_ellipse(e);
	}
	if (e->i.load.nb_dir - (e->i.load.index_load * 5) > 3)
	{
		ft_init_value_draw_ellipse_background(e, 20);
		if (e->i.load.select == 4)
			e->lt.couleur = e->i.color.saves.col3;
		ft_ellipse(e, 0, 0);
		ft_init_value_draw_ellipse_background(e, 20);
		loop_ellipse(e);
	}
}

void	save_scene_load_save_draw_ellipse_background_sd(t_stuff *e)
{
	if (e->i.load.nb_dir - (e->i.load.index_load * 5) > 0)
	{
		ft_init_value_draw_ellipse_background(e, 17);
		if (e->i.load.select == 1)
			e->lt.couleur = e->i.color.saves.col3;
		ft_ellipse(e, 0, 0);
		ft_init_value_draw_ellipse_background(e, 17);
		loop_ellipse(e);
	}
	if (e->i.load.nb_dir - (e->i.load.index_load * 5) > 1)
	{
		ft_init_value_draw_ellipse_background(e, 18);
		if (e->i.load.select == 2)
			e->lt.couleur = e->i.color.saves.col3;
		ft_ellipse(e, 0, 0);
		ft_init_value_draw_ellipse_background(e, 18);
		loop_ellipse(e);
	}
}

void	save_scene_load_save_draw_ellipse_background(t_stuff *e)
{
	int		x;

	x = 0;
	save_scene_load_save_draw_ellipse_background_sd(e);
	save_scene_load_save_draw_ellipse_background_td(e);
	save_scene_load_save_draw_ellipse_background_fh(e);
	if (e->i.load.nb_dir - (e->i.load.index_load * 5) > 5)
	{
		ft_init_value_draw_ellipse_background(e, 22);
		if (e->i.load.select == 6)
			e->lt.couleur = e->i.color.saves.col3;
		ft_ellipse(e, 0, 0);
		ft_init_value_draw_ellipse_background(e, 22);
		loop_ellipse(e);
		x = 1;
	}
	if (x == 0 && e->i.load.index_load != 0)
	{
		ft_init_value_draw_ellipse_background(e, 22);
		if (e->i.load.select == 6)
			e->lt.couleur = e->i.color.saves.col3;
		ft_ellipse(e, 0, 0);
		ft_init_value_draw_ellipse_background(e, 22);
		loop_ellipse(e);
	}
}
