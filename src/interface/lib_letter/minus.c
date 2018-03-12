/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Awk-LM <Awk-LM@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 12:57:47 by Awk-LM            #+#    #+#             */
/*   Updated: 2018/03/07 13:23:27 by Awk-LM           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_init_value_minus(t_stuff *e, int option)
{
	if (option == 0)
	{
		e->bs.xi = e->lt.posx + (12.5 * e->lt.coeff);
		e->bs.yi = e->lt.posy - (15 * e->lt.coeff);
		e->bs.xf = e->bs.xi + (12.5 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
	if (option == 1)
	{
		e->bs.xi = e->lt.posx + (12.5 * e->lt.coeff);
		e->bs.yi = e->lt.posy - (15 * e->lt.coeff) - 1;
		e->bs.xf = e->bs.xi + (12.5 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
	if (option == 2)
	{
		e->bs.xi = e->lt.posx + (12.5 * e->lt.coeff);
		e->bs.yi = e->lt.posy - (15 * e->lt.coeff) - 2;
		e->bs.xf = e->bs.xi + (12.5 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
	if (option == 3)
	{
		e->bs.xi = e->lt.posx + (12.5 * e->lt.coeff);
		e->bs.yi = e->lt.posy - (15 * e->lt.coeff) - 3;
		e->bs.xf = e->bs.xi + (12.5 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
	if (option == 4)
	{
		e->bs.xi = e->lt.posx + (12.5 * e->lt.coeff);
		e->bs.yi = e->lt.posy - (15 * e->lt.coeff) - 4;
		e->bs.xf = e->bs.xi + (12.5 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
	if (option == 5)
	{
		e->bs.xi = e->lt.posx + (12.5 * e->lt.coeff);
		e->bs.yi = e->lt.posy - (15 * e->lt.coeff) - 5;
		e->bs.xf = e->bs.xi + (12.5 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
	if (option == 6)
	{
		e->bs.xi = e->lt.posx + (12.5 * e->lt.coeff);
		e->bs.yi = e->lt.posy - (15 * e->lt.coeff) - 6;
		e->bs.xf = e->bs.xi + (12.5 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
	if (option == 7)
	{
		e->bs.xi = e->lt.posx + (12.5 * e->lt.coeff);
		e->bs.yi = e->lt.posy - (15 * e->lt.coeff) - 7;
		e->bs.xf = e->bs.xi + (12.5 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
	if (option == 8)
	{
		e->bs.xi = e->lt.posx + (12.5 * e->lt.coeff);
		e->bs.yi = e->lt.posy - (15 * e->lt.coeff) - 8;
		e->bs.xf = e->bs.xi + (12.5 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
	if (option == 9)
	{
		e->bs.xi = e->lt.posx + (12.5 * e->lt.coeff);
		e->bs.yi = e->lt.posy - (15 * e->lt.coeff) - 9;
		e->bs.xf = e->bs.xi + (12.5 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
}

void	minus(t_stuff *e)
{
	ft_init_value_minus(e, 0);
	ft_segment_letter(e);
	ft_init_value_minus(e, 1);
	ft_segment_letter(e);
	ft_init_value_minus(e, 2);
	ft_segment_letter(e);
	ft_init_value_minus(e, 3);
	ft_segment_letter(e);
	ft_init_value_minus(e, 4);
	ft_segment_letter(e);
	// ft_init_value_minus(e, 5);
	// ft_segment_letter(e);
	// ft_init_value_minus(e, 6);
	// ft_segment_letter(e);
	// ft_init_value_minus(e, 7);
	// ft_segment_letter(e);
	// ft_init_value_minus(e, 8);
	// ft_segment_letter(e);
	// ft_init_value_minus(e, 9);
	// ft_segment_letter(e);
}
