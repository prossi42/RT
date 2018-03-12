/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nine.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Awk-LM <Awk-LM@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 18:36:06 by Awk-LM            #+#    #+#             */
/*   Updated: 2018/03/06 18:49:26 by Awk-LM           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_init_value_nine(t_stuff *e, int option)
{
	if (option == 0)
	{
		e->bs.x_arc = e->lt.posx + (12.5 * e->lt.coeff);
		e->bs.y_arc = e->lt.posy - (37.5 * e->lt.coeff);
		e->bs.ray_arc = 12.5 * e->lt.coeff;
	}
	if (option == 1)
	{
		e->bs.xi = e->lt.posx + (25 * e->lt.coeff);
		e->bs.yi = e->lt.posy - (37.5 * e->lt.coeff);
		e->bs.xf = e->bs.xi - (12.5 * e->lt.coeff);
		e->bs.yf = e->bs.yi + (37.5 * e->lt.coeff);
	}
	if (option == 2)
	{
		e->bs.xi = e->lt.posx + (25 * e->lt.coeff) - 1;
		e->bs.yi = e->lt.posy - (37.5 * e->lt.coeff);
		e->bs.xf = e->bs.xi - (12.5 * e->lt.coeff);
		e->bs.yf = e->bs.yi + (37.5 * e->lt.coeff);
	}
	if (option == 3)
	{
		e->bs.xi = e->lt.posx + (25 * e->lt.coeff) - 2;
		e->bs.yi = e->lt.posy - (37.5 * e->lt.coeff);
		e->bs.xf = e->bs.xi - (12.5 * e->lt.coeff);
		e->bs.yf = e->bs.yi + (37.5 * e->lt.coeff);
	}
}

void	nine(t_stuff *e)
{
	ft_init_value_nine(e, 0);
	ft_arc(e, 9);
	e->bs.ray_arc--;
	ft_arc(e, 9);
	e->bs.ray_arc--;
	ft_arc(e, 9);
	ft_init_value_nine(e, 1);
	ft_segment_letter(e);
	ft_init_value_nine(e, 2);
	ft_segment_letter(e);
	ft_init_value_nine(e, 3);
	ft_segment_letter(e);
}
