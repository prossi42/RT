/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_scene_draw_ellipse_background.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 13:25:26 by prossi            #+#    #+#             */
/*   Updated: 2018/03/12 13:27:10 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	save_scene_draw_ellipse_background(t_stuff *e)
{
	ft_init_value_draw_ellipse_background(e, 0);
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
	ft_init_value_draw_ellipse_background(e, 1);
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
	ft_init_value_draw_ellipse_background(e, 2);
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
