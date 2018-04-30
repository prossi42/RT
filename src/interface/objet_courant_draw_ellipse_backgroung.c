/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objet_courant_draw_ellipse_backgroung.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:27:07 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 10:27:07 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	draw_ellipse_background_fih(t_stuff *e)
{
	if (e->i.objet != -1)
	{
		ft_init_value_draw_ellipse_background(e, 4);
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
	draw_ellipse_background_sh(e);
}

void	draw_ellipse_background_fh(t_stuff *e)
{
	if (e->i.objet != -1 && e->i.objet != PLAN)
	{
		ft_init_value_draw_ellipse_background(e, 3);
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
	draw_ellipse_background_fih(e);
}

void	draw_ellipse_background_td(t_stuff *e)
{
	if (e->i.objet != -1)
	{
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
	draw_ellipse_background_fh(e);
}

void	draw_ellipse_background_sd(t_stuff *e)
{
	if (e->i.objet != SPHERE && e->i.objet != LIGHT)
	{
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
	}
	draw_ellipse_background_td(e);
}

void	draw_ellipse_background(t_stuff *e)
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
	draw_ellipse_background_sd(e);
}
