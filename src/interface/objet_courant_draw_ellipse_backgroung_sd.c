/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objet_courant_draw_ellipse_backgroung_sd.c         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:28:06 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 10:28:06 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	draw_ellipse_background_seh(t_stuff *e)
{
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

void	draw_ellipse_background_sh(t_stuff *e)
{
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
	draw_ellipse_background_seh(e);
}
