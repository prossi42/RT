/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UU.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 14:08:27 by prossi            #+#    #+#             */
/*   Updated: 2018/03/09 10:57:10 by Awk-LM           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/rt.h"

void	ft_init_segment_U(t_stuff *e, int option)
{
	if (option == 1)
	{
		e->bs.x_arc = e->lt.posx + (12.5 * e->lt.coeff);
		e->bs.y_arc = e->lt.posy - (25 * e->lt.coeff);
		e->bs.width = 12.5 * e->lt.coeff;
		e->bs.height = 25 * e->lt.coeff;
	}
	if (option == 2)
	{
		e->bs.xi = e->lt.posx;
		e->bs.yi = e->lt.posy - (25 * e->lt.coeff);
		e->bs.xf = e->bs.xi;
		e->bs.yf = e->bs.yi - (25 * e->lt.coeff);
	}
	if (option == 3)
	{
		e->bs.xi = e->lt.posx + 1;
		e->bs.yi = e->lt.posy - (25 * e->lt.coeff);
		e->bs.xf = e->bs.xi;
		e->bs.yf = e->bs.yi - (25 * e->lt.coeff);
	}
	if (option == 4)
	{
		e->bs.xi = e->lt.posx + 2;
		e->bs.yi = e->lt.posy - (25 * e->lt.coeff);
		e->bs.xf = e->bs.xi;
		e->bs.yf = e->bs.yi - (25 * e->lt.coeff);
	}
	if (option == 5)
	{
		e->bs.xi = e->lt.posx + (25 * e->lt.coeff);
		e->bs.yi = e->lt.posy - (25 * e->lt.coeff);
		e->bs.xf = e->bs.xi;
		e->bs.yf = e->bs.yi - (25 * e->lt.coeff);
	}
	if (option == 6)
	{
		e->bs.xi = e->lt.posx + (25 * e->lt.coeff) - 1;
		e->bs.yi = e->lt.posy - (25 * e->lt.coeff);
		e->bs.xf = e->bs.xi;
		e->bs.yf = e->bs.yi - (25 * e->lt.coeff);
	}
	if (option == 7)
	{
		e->bs.xi = e->lt.posx + (25 * e->lt.coeff) - 2;
		e->bs.yi = e->lt.posy - (25 * e->lt.coeff);
		e->bs.xf = e->bs.xi;
		e->bs.yf = e->bs.yi - (25 * e->lt.coeff);
	}
}

void	U(t_stuff *e)
{
	ft_init_segment_U(e, 1);
	ft_ellipse(e, 1, 2);
	ft_ellipse(e, 2, 4);
	ft_ellipse(e, 2, 6);
	e->bs.width--;
	e->bs.height--;
	ft_ellipse(e, 1, 2);
	ft_ellipse(e, 2, 4);
	ft_ellipse(e, 2, 6);
	e->bs.width--;
	e->bs.height--;
	ft_ellipse(e, 1, 2);
	ft_ellipse(e, 2, 4);
	ft_ellipse(e, 2, 6);
	ft_init_segment_U(e, 2);
	ft_segment_letter(e);
	ft_init_segment_U(e, 3);
	ft_segment_letter(e);
	ft_init_segment_U(e, 4);
	ft_segment_letter(e);
	ft_init_segment_U(e, 5);
	ft_segment_letter(e);
	ft_init_segment_U(e, 6);
	ft_segment_letter(e);
	ft_init_segment_U(e, 7);
	ft_segment_letter(e);
}
