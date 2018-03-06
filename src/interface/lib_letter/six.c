/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   six.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:53:01 by prossi            #+#    #+#             */
/*   Updated: 2018/03/06 15:57:28 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_init_value_six(t_stuff *e, int option)
{
	if (option == 0)
	{
		e->bs.x_arc = e->lt.posx + (12.5 * e->lt.coeff);
		e->bs.y_arc = e->lt.posy - (25 * e->lt.coeff);
		e->bs.width = 12.5 * e->lt.coeff;
		e->bs.height = 25 * e->lt.coeff;
	}
	if (option == 1)
	{
		e->bs.x_arc = e->lt.posx + (12.5 * e->lt.coeff);
		e->bs.y_arc = e->lt.posy - (12.5 * e->lt.coeff);
		e->bs.height = 12.5 * e->lt.coeff;
	}
	if (option == 2)
	{
		e->bs.xi = e->lt.posx;
		e->bs.yi = e->lt.posy - (25 * e->lt.coeff);
		e->bs.xf = e->bs.xi + (12.5 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
	if (option == 3)
	{
		e->bs.xi = e->lt.posx;
		e->bs.yi = e->lt.posy - (25 * e->lt.coeff) + 1;
		e->bs.xf = e->bs.xi + (12.5 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
	if (option == 4)
	{
		e->bs.xi = e->lt.posx;
		e->bs.yi = e->lt.posy - (25 * e->lt.coeff) + 2;
		e->bs.xf = e->bs.xi + (12.5 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
}

void	six(t_stuff *e)
{
	ft_init_value_six(e, 0);
	ft_ellipse(e, 2, 1);
	ft_ellipse(e, 1, 3);
	ft_ellipse(e, 1, 5);
	e->bs.height--;
	ft_ellipse(e, 2, 1);
	ft_ellipse(e, 1, 3);
	ft_ellipse(e, 1, 5);
	e->bs.height--;
	ft_ellipse(e, 2, 1);
	ft_ellipse(e, 1, 3);
	ft_ellipse(e, 1, 5);
	ft_init_value_six(e, 1);
	ft_ellipse(e, 2, 2);
	ft_ellipse(e, 1, 4);
	ft_ellipse(e, 1, 6);
	e->bs.height--;
	ft_ellipse(e, 2, 2);
	ft_ellipse(e, 1, 4);
	ft_ellipse(e, 1, 6);
	e->bs.height--;
	ft_ellipse(e, 2, 2);
	ft_ellipse(e, 1, 4);
	ft_ellipse(e, 1, 6);
	ft_init_value_six(e, 2);
	ft_segment_letter(e);
	ft_init_value_six(e, 3);
	ft_segment_letter(e);
	ft_init_value_six(e, 4);
	ft_segment_letter(e);
}
