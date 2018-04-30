/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortcuts_draw_shortcuts_reflexion.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 14:33:37 by prossi            #+#    #+#             */
/*   Updated: 2018/04/17 14:33:43 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	draw_arrow_shortcuts_reflexion_sd(t_stuff *e, int centerx, int centery)
{
	e->bs.xi = centerx + 31;
	e->bs.yi = centery - 30;
	e->bs.xf = e->bs.xi - 5;
	e->bs.yf = e->bs.yi;
	ft_segment_letter(e);
	e->bs.xi = centerx + 21;
	e->bs.yi = centery + 20;
	e->bs.xf = e->bs.xi;
	e->bs.yf = e->bs.yi - 5;
	ft_segment_letter(e);
	e->bs.xi = centerx + 21;
	e->bs.yi = centery + 20;
	e->bs.xf = e->bs.xi - 5;
	e->bs.yf = e->bs.yi;
	ft_segment_letter(e);
}

void	draw_arrow_shortcuts_reflexion(t_stuff *e, int centerx, int centery)
{
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
	e->bs.xi = centerx + 31;
	e->bs.yi = centery - 30;
	e->bs.xf = e->bs.xi;
	e->bs.yf = e->bs.yi + 5;
	ft_segment_letter(e);
	draw_arrow_shortcuts_reflexion_sd(e, centerx, centery);
}
