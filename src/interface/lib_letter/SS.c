/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SS.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 14:07:48 by prossi            #+#    #+#             */
/*   Updated: 2018/03/08 22:28:56 by Awk-LM           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/rt.h"

void	ft_init_segment_S(t_stuff *e, int option)
{
	if (option == 1)
	{
		e->bs.x_arc = e->lt.posx;
		e->bs.y_arc = e->lt.posy - (12.5 * e->lt.coeff);
		e->bs.width = 25 * e->lt.coeff;
		e->bs.height = 12.5 * e->lt.coeff;
	}
	if (option == 2)
	{
		e->bs.x_arc = e->lt.posx + (25 * e->lt.coeff);
		e->bs.y_arc = e->lt.posy - (37.5 * e->lt.coeff);
		e->bs.width = 25 * e->lt.coeff;
		e->bs.height = 12.5 * e->lt.coeff;
	}
	if (option == 3)
	{
		e->bs.xi = e->lt.posx + (2.8 * e->lt.coeff);
		e->bs.yi = e->lt.posy - (31 * e->lt.coeff);
		e->bs.xf = e->bs.xi + (19.5 * e->lt.coeff);
		e->bs.yf = e->bs.yi + (13.2 * e->lt.coeff);
	}
	if (option == 4)
	{
		e->bs.xi = e->lt.posx + (2.8 * e->lt.coeff);
		e->bs.yi = e->lt.posy - (31 * e->lt.coeff) - 1;
		e->bs.xf = e->bs.xi + (19.5 * e->lt.coeff);
		e->bs.yf = e->bs.yi + (13.2 * e->lt.coeff);
	}
	if (option == 5)
	{
		e->bs.xi = e->lt.posx + (2.8 * e->lt.coeff);
		e->bs.yi = e->lt.posy - (31 * e->lt.coeff) - 2;
		e->bs.xf = e->bs.xi + (19.5 * e->lt.coeff);
		e->bs.yf = e->bs.yi + (13.2 * e->lt.coeff);
	}
}

void	S(t_stuff *e)
{
	ft_init_segment_S(e, 1);
	ft_ellipse(e, 2, 2);
	ft_ellipse(e, 1, 6);
	e->bs.y_arc--;
	ft_ellipse(e, 2, 2);
	ft_ellipse(e, 1, 6);
	e->bs.y_arc--;
	ft_ellipse(e, 2, 2);
	ft_ellipse(e, 1, 6);
	ft_init_segment_S(e, 2);
	ft_ellipse(e, 2, 1);
	ft_ellipse(e, 1, 3);
	e->bs.y_arc++;
	ft_ellipse(e, 2, 1);
	ft_ellipse(e, 1, 3);
	e->bs.y_arc++;
	ft_ellipse(e, 2, 1);
	ft_ellipse(e, 1, 3);
	ft_init_segment_S(e, 3);
	ft_segment_letter(e);
	ft_init_segment_S(e, 4);
	ft_segment_letter(e);
	ft_init_segment_S(e, 5);
	ft_segment_letter(e);
}
