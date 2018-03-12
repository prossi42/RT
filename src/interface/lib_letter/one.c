/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Awk-LM <Awk-LM@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 00:13:53 by Awk-LM            #+#    #+#             */
/*   Updated: 2018/03/06 00:45:39 by Awk-LM           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_init_value_one(t_stuff *e, int option)
{
	if (option == 0)
	{
		e->bs.xi = e->lt.posx;
		e->bs.yi = e->lt.posy - (25 * e->lt.coeff);
		e->bs.xf = e->bs.xi + (25 * e->lt.coeff);
		e->bs.yf = e->bs.yi - (25 * e->lt.coeff);
	}
	if (option == 1)
	{
		e->bs.xi = e->lt.posx;
		e->bs.yi = (e->lt.posy - (25 * e->lt.coeff)) - 1;
		e->bs.xf = e->bs.xi + (25 * e->lt.coeff) - 1;
		e->bs.yf = e->bs.yi - (25 * e->lt.coeff) + 1;
	}
	if (option == 2)
	{
		e->bs.xi = e->lt.posx;
		e->bs.yi = (e->lt.posy - (25 * e->lt.coeff)) - 2;
		e->bs.xf = e->bs.xi + (25 * e->lt.coeff) - 2;
		e->bs.yf = e->bs.yi - (25 * e->lt.coeff) + 2;
	}
	if (option == 3)
	{
		e->bs.xi = e->lt.posx + (25 * e->lt.coeff);
		e->bs.yi = e->lt.posy - (50 * e->lt.coeff);
		e->bs.xf = e->bs.xi;
		e->bs.yf = e->bs.yi + (50 * e->lt.coeff);
	}
	if (option == 4)
	{
		e->bs.xi = e->lt.posx - 1 + (25 * e->lt.coeff);
		e->bs.yi = e->lt.posy - (50 * e->lt.coeff);
		e->bs.xf = e->bs.xi;
		e->bs.yf = e->bs.yi + (50 * e->lt.coeff);
	}
	if (option == 5)
	{
		e->bs.xi = e->lt.posx - 2 + (25 * e->lt.coeff);
		e->bs.yi = e->lt.posy - (50 * e->lt.coeff);
		e->bs.xf = e->bs.xi;
		e->bs.yf = e->bs.yi + (50 * e->lt.coeff);
	}
}

void	one(t_stuff *e)
{
	ft_init_value_one(e, 0);
	ft_segment_letter(e);
	ft_init_value_one(e, 1);
	ft_segment_letter(e);
	ft_init_value_one(e, 2);
	ft_segment_letter(e);
	ft_init_value_one(e, 3);
	ft_segment_letter(e);
	ft_init_value_one(e, 4);
	ft_segment_letter(e);
	ft_init_value_one(e, 5);
	ft_segment_letter(e);
}
