/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortcuts_draw_shortcuts_refraction.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 14:28:46 by prossi            #+#    #+#             */
/*   Updated: 2018/04/17 14:28:54 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	draw_arrow_shortcuts_refraction_sd(t_stuff *e, int centerx, int centery)
{
	e->bs.xi = centerx - 20;
	e->bs.yi = centery - 12;
	e->bs.xf = e->bs.xi;
	e->bs.yf = e->bs.yi + 6;
	ft_segment_letter(e);
	e->bs.xi = centerx - 20;
	e->bs.yi = centery + 12;
	e->bs.xf = e->bs.xi + 6;
	e->bs.yf = e->bs.yi;
	ft_segment_letter(e);
	e->bs.xi = centerx - 20;
	e->bs.yi = centery + 12;
	e->bs.xf = e->bs.xi;
	e->bs.yf = e->bs.yi - 6;
	ft_segment_letter(e);
}

void	draw_arrow_shortcuts_refraction(t_stuff *e, int centerx, int centery)
{
	e->lt.couleur = 0xFFFFFF;
	e->bs.xi = centerx + 20;
	e->bs.yi = centery;
	e->bs.xf = e->bs.xi + 5;
	e->bs.yf = e->bs.yi - 5;
	ft_segment_letter(e);
	e->bs.xi = centerx + 20;
	e->bs.yi = centery;
	e->bs.xf = e->bs.xi + 5;
	e->bs.yf = e->bs.yi + 5;
	ft_segment_letter(e);
	e->lt.couleur = 0x000000;
	e->bs.xi = centerx - 20;
	e->bs.yi = centery - 12;
	e->bs.xf = e->bs.xi + 6;
	e->bs.yf = e->bs.yi;
	ft_segment_letter(e);
	draw_arrow_shortcuts_refraction_sd(e, centerx, centery);
}

void	draw_ray_shortcuts_refraction_sd(t_stuff *e, int centerx, int centery)
{
	e->bs.xi = e->bs.xf;
	e->bs.yi = e->bs.yf;
	e->bs.xf = e->bs.xi - 30;
	e->bs.yf = e->bs.yi + 18;
	ft_segment_letter(e);
	e->bs.xi = centerx;
	e->bs.yi = centery;
	e->bs.xf = e->bs.xi - 30;
	e->bs.yf = e->bs.yi + 17;
	ft_segment_letter(e);
}

void	draw_ray_shortcuts_refraction(t_stuff *e, int centerx, int centery)
{
	e->bs.xi = centerx + 35;
	e->bs.yi = centery;
	e->bs.xf = e->bs.xi - 35;
	e->bs.yf = e->bs.yi;
	e->lt.couleur = 0xFFFFFF;
	ft_segment_letter(e);
	e->lt.couleur = 0x000000;
	e->bs.xi = e->bs.xf;
	e->bs.yi = e->bs.yf;
	e->bs.xf = e->bs.xi - 30;
	e->bs.yf = e->bs.yi - 18;
	ft_segment_letter(e);
	e->bs.xi = centerx;
	e->bs.yi = centery;
	e->bs.xf = e->bs.xi - 30;
	e->bs.yf = e->bs.yi - 17;
	ft_segment_letter(e);
	draw_ray_shortcuts_refraction_sd(e, centerx, centery);
}
