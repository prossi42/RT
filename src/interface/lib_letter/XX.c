/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   XX.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 14:09:28 by prossi            #+#    #+#             */
/*   Updated: 2018/03/09 10:11:14 by Awk-LM           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/rt.h"

void	ft_init_segment_X(t_stuff *e, int option)
{
	if (option == 1)
	{
		e->bs.xi = e->lt.posx;
		e->bs.yi = e->lt.posy - (50 * e->lt.coeff);
		e->bs.xf = e->lt.posx + (25 * e->lt.coeff) - 2;
		e->bs.yf = e->lt.posy;
	}
	if (option == 2)
	{
		e->bs.xi = e->lt.posx + 1;
		e->bs.yi = e->lt.posy - (50 * e->lt.coeff);
		e->bs.xf = e->lt.posx + (25 * e->lt.coeff) - 1;
		e->bs.yf = e->lt.posy;
	}
	if (option == 3)
	{
		e->bs.xi = e->lt.posx + 2;
		e->bs.yi = e->lt.posy - (50 * e->lt.coeff);
		e->bs.xf = e->lt.posx + (25 * e->lt.coeff);
		e->bs.yf = e->lt.posy;
	}
	if (option == 4)
	{
		e->bs.xi = e->lt.posx;
		e->bs.xf = e->lt.posx + (25 * e->lt.coeff) - 2;
		e->bs.yi = e->lt.posy;
		e->bs.yf = e->lt.posy - (50 * e->lt.coeff);
	}
	if (option == 5)
	{
		e->bs.xi = e->lt.posx + 1;
		e->bs.xf = e->lt.posx + (25 * e->lt.coeff) - 1;
		e->bs.yi = e->lt.posy;
		e->bs.yf = e->lt.posy - (50 * e->lt.coeff);
	}
	if (option == 6)
	{
		e->bs.xi = e->lt.posx + 2;
		e->bs.xf = e->lt.posx + (25 * e->lt.coeff);
		e->bs.yi = e->lt.posy;
		e->bs.yf = e->lt.posy - (50 * e->lt.coeff);
	}
}

void	X(t_stuff *e)
{
	ft_init_segment_X(e, 1);
	ft_segment_letter(e);
	ft_init_segment_X(e, 2);
	ft_segment_letter(e);
	ft_init_segment_X(e, 3);
	ft_segment_letter(e);
	ft_init_segment_X(e, 4);
	ft_segment_letter(e);
	ft_init_segment_X(e, 5);
	ft_segment_letter(e);
	ft_init_segment_X(e, 6);
	ft_segment_letter(e);
}
