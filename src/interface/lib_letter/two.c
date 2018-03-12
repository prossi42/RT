/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Awk-LM <Awk-LM@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 07:52:27 by Awk-LM            #+#    #+#             */
/*   Updated: 2018/03/06 19:02:37 by Awk-LM           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_init_value_two(t_stuff *e, int option)
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
		e->bs.xi = e->lt.posx;
		e->bs.yi = e->lt.posy;
		e->bs.xf = e->bs.xi + (25 * e->lt.coeff);
		e->bs.yf = e->bs.yi - (25 * e->lt.coeff);
	}
	if (option == 2)
	{
		e->bs.xi = e->lt.posx;
		e->bs.yi = e->lt.posy - 1;
		e->bs.xf = e->bs.xi + (25 * e->lt.coeff) - 1;
		e->bs.yf = e->bs.yi - (25 * e->lt.coeff) + 1;
	}
	if (option == 3)
	{
		e->bs.xi = e->lt.posx;
		e->bs.yi = e->lt.posy - 2;
		e->bs.xf = e->bs.xi + (25 * e->lt.coeff) - 2;
		e->bs.yf = e->bs.yi - (25 * e->lt.coeff) + 2;
	}
	if (option == 4)
	{
		e->bs.xi = e->lt.posx;
		e->bs.yi = e->lt.posy;
		e->bs.xf = e->bs.xi + (25 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
	if (option == 5)
	{
		e->bs.xi = e->lt.posx;
		e->bs.yi = e->lt.posy - 1;
		e->bs.xf = e->bs.xi + (25 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
	if (option == 6)
	{
		e->bs.xi = e->lt.posx;
		e->bs.yi = e->lt.posy - 2;
		e->bs.xf = e->bs.xi + (25 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
	if (option == 7)
	{
		e->bs.x_arc = e->lt.posx + (12.5 * e->lt.coeff);
		e->bs.y_arc = e->lt.posy - (37.5 * e->lt.coeff);
		e->bs.ray_arc = 12.5 * e->lt.coeff;
	}
	if (option == 8)
	{
		e->bs.xi = e->lt.posx;
		e->bs.yi = e->lt.posy;
		e->bs.xf = e->bs.xi + (25 * e->lt.coeff);
		e->bs.yf = e->bs.yi - (37.5 * e->lt.coeff);
	}
	if (option == 9)
	{
		e->bs.xi = e->lt.posx;
		e->bs.yi = e->lt.posy - 1;
		e->bs.xf = e->bs.xi + (25 * e->lt.coeff) - 1;
		e->bs.yf = e->bs.yi - (37.5 * e->lt.coeff) + 1;
	}
	if (option == 10)
	{
		e->bs.xi = e->lt.posx;
		e->bs.yi = e->lt.posy - 2;
		e->bs.xf = e->bs.xi + (25 * e->lt.coeff) - 2;
		e->bs.yf = e->bs.yi - (37.5 * e->lt.coeff) + 2;
	}
	if (option == 11)
	{
		e->bs.xi = e->lt.posx;
		e->bs.yi = e->lt.posy;
		e->bs.xf = e->bs.xi + (25 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
	if (option == 12)
	{
		e->bs.xi = e->lt.posx;
		e->bs.yi = e->lt.posy - 1;
		e->bs.xf = e->bs.xi + (25 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
	if (option == 13)
	{
		e->bs.xi = e->lt.posx;
		e->bs.yi = e->lt.posy - 2;
		e->bs.xf = e->bs.xi + (25 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
}

void	two(t_stuff *e)
{
	// ft_init_value_two(e, 0);
	// ft_ellipse(e, 1, 1);
	// ft_ellipse(e, 2, 3);
	// ft_ellipse(e, 2, 5);
	// e->bs.width--;
	// ft_ellipse(e, 1, 1);
	// ft_ellipse(e, 2, 3);
	// ft_ellipse(e, 2, 5);
	// e->bs.width--;
	// ft_ellipse(e, 1, 1);
	// ft_ellipse(e, 2, 3);
	// ft_ellipse(e, 2, 5);
	// ft_init_value_two(e, 1);
	// ft_segment_letter(e);
	// ft_init_value_two(e, 2);
	// ft_segment_letter(e);
	// ft_init_value_two(e, 3);
	// ft_segment_letter(e);
	// ft_init_value_two(e, 4);
	// ft_segment_letter(e);
	// ft_init_value_two(e, 5);
	// ft_segment_letter(e);
	// ft_init_value_two(e, 6);
	// ft_segment_letter(e);
	ft_init_value_two(e, 7);
	ft_arc(e, 3);
	e->bs.ray_arc--;
	ft_arc(e, 3);
	e->bs.ray_arc--;
	ft_arc(e, 3);
	ft_init_value_two(e, 8);
	ft_segment_letter(e);
	ft_init_value_two(e, 9);
	ft_segment_letter(e);
	ft_init_value_two(e, 10);
	ft_segment_letter(e);
	ft_init_value_two(e, 11);
	ft_segment_letter(e);
	ft_init_value_two(e, 12);
	ft_segment_letter(e);
	ft_init_value_two(e, 13);
	ft_segment_letter(e);
}
