/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seven.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 16:01:55 by prossi            #+#    #+#             */
/*   Updated: 2018/03/06 17:06:49 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_init_value_seven(t_stuff *e, int option)
{
	if (option == 0)
	{
		e->bs.xi = e->lt.posx;
		e->bs.yi = e->lt.posy - (50 * e->lt.coeff);
		e->bs.xf = e->bs.xi + (25 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
	if (option == 1)
	{
		e->bs.xi = e->lt.posx;
		e->bs.yi = e->lt.posy - (50 * e->lt.coeff) + 1;
		e->bs.xf = e->bs.xi + (25 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
	if (option == 2)
	{
		e->bs.xi = e->lt.posx;
		e->bs.yi = e->lt.posy - (50 * e->lt.coeff) + 2;
		e->bs.xf = e->bs.xi + (25 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
	if (option == 3)
	{
		e->bs.xi = e->lt.posx + (25 * e->lt.coeff);
		e->bs.yi = e->lt.posy - (50 * e->lt.coeff);
		e->bs.xf = e->bs.xi - (12.5 * e->lt.coeff);
		e->bs.yf = e->bs.yi + (50 * e->lt.coeff);
	}
	if (option == 4)
	{
		e->bs.xi = e->lt.posx + (25 * e->lt.coeff) - 1;
		e->bs.yi = e->lt.posy - (50 * e->lt.coeff);
		e->bs.xf = e->bs.xi - (12.5 * e->lt.coeff);
		e->bs.yf = e->bs.yi + (50 * e->lt.coeff);
	}
	if (option == 5)
	{
		e->bs.xi = e->lt.posx + (25 * e->lt.coeff) - 2;
		e->bs.yi = e->lt.posy - (50 * e->lt.coeff);
		e->bs.xf = e->bs.xi - (12.5 * e->lt.coeff);
		e->bs.yf = e->bs.yi + (50 * e->lt.coeff);
	}
	if (option == 6)
	{
		e->bs.xi = e->lt.posx + (25 * e->lt.coeff);
		e->bs.yi = e->lt.posy - (25 * e->lt.coeff);
		e->bs.xf = e->bs.xi - (12.5 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
	if (option == 7)
	{
		e->bs.xi = e->lt.posx + (25 * e->lt.coeff);
		e->bs.yi = e->lt.posy - (25 * e->lt.coeff) - 1;
		e->bs.xf = e->bs.xi - (12.5 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
	if (option == 8)
	{
		e->bs.xi = e->lt.posx + (25 * e->lt.coeff);
		e->bs.yi = e->lt.posy - (25 * e->lt.coeff) - 2;
		e->bs.xf = e->bs.xi - (12.5 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
}

void	seven(t_stuff *e)
{
	ft_init_value_seven(e, 0);
	ft_segment_letter(e);
	ft_init_value_seven(e, 1);
	ft_segment_letter(e);
	ft_init_value_seven(e, 2);
	ft_segment_letter(e);
	ft_init_value_seven(e, 3);
	ft_segment_letter(e);
	ft_init_value_seven(e, 4);
	ft_segment_letter(e);
	ft_init_value_seven(e, 5);
	ft_segment_letter(e);
	ft_init_value_seven(e, 6);
	ft_segment_letter(e);
	ft_init_value_seven(e, 7);
	ft_segment_letter(e);
	ft_init_value_seven(e, 8);
	ft_segment_letter(e);
}
