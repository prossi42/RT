/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objet_courant_draw_ellipse_backgroung.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Awk-LM <Awk-LM@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:36:47 by Awk-LM            #+#    #+#             */
/*   Updated: 2018/03/09 14:07:00 by Awk-LM           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

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
	if (e->i.objet != -1)
	{
		ft_init_value_draw_ellipse_background(e, 5);
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
	if (e->i.objet != LIGHT && e->i.objet != -1)
	{
		ft_init_value_draw_ellipse_background(e, 6);
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
}
