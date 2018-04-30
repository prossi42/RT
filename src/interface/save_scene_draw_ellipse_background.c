/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_scene_draw_ellipse_background.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 13:25:26 by prossi            #+#    #+#             */
/*   Updated: 2018/04/18 14:02:38 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	save_scene_draw_ellipse_background_td(t_stuff *e)
{
	while (e->bs.width > 1)
	{
		e->bs.width--;
		ft_ellipse(e, 0, 0);
	}
	ft_init_value_draw_ellipse_background(e, 16);
	if (e->i.save.select == 3)
		e->lt.couleur = 0xFF0000;
	ft_ellipse(e, 0, 0);
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

void	save_scene_draw_ellipse_background_sd(t_stuff *e)
{
	ft_init_value_draw_ellipse_background(e, 14);
	if (e->i.save.select == 1)
		e->lt.couleur = 0x00FF00;
	ft_ellipse(e, 0, 0);
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
	ft_init_value_draw_ellipse_background(e, 15);
	if (e->i.save.select == 2)
		e->lt.couleur = 0xFF9900;
	ft_ellipse(e, 0, 0);
	while (e->bs.height > 0)
	{
		e->bs.height--;
		ft_ellipse(e, 0, 0);
	}
}

void	save_scene_draw_ellipse_background(t_stuff *e)
{
	save_scene_draw_ellipse_background_sd(e);
	save_scene_draw_ellipse_background_td(e);
}
