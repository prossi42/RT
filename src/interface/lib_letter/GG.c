/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GG.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 14:01:55 by prossi            #+#    #+#             */
/*   Updated: 2018/03/08 15:11:20 by Awk-LM           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/rt.h"

void	ft_init_segment_G(t_stuff *e, int option)
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
		e->bs.xi = e->lt.posx + (25 * e->lt.coeff);
		e->bs.yi = e->lt.posy - (25 * e->lt.coeff);
		e->bs.xf = e->bs.xi - (12.5 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
	if (option == 3)
	{
		e->bs.xi = e->lt.posx + (25 * e->lt.coeff);
		e->bs.yi = e->lt.posy - (25 * e->lt.coeff) + 1;
		e->bs.xf = e->bs.xi - (12.5 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
	if (option == 4)
	{
		e->bs.xi = e->lt.posx + (25 * e->lt.coeff);
		e->bs.yi = e->lt.posy - (25 * e->lt.coeff) - 1;
		e->bs.xf = e->bs.xi - (12.5 * e->lt.coeff);
		e->bs.yf = e->bs.yi;
	}
}

void	G(t_stuff *e)
{
	ft_init_segment_G(e, 1);
	ft_ellipse(e, 2, 1);
	ft_ellipse(e, 1, 0);
	ft_ellipse(e, 2, 6);
	e->bs.width--;
	e->bs.height--;
	ft_ellipse(e, 2, 1);
	ft_ellipse(e, 1, 0);
	ft_ellipse(e, 2, 6);
	e->bs.width--;
	e->bs.height--;
	ft_ellipse(e, 2, 1);
	ft_ellipse(e, 1, 0);
	ft_ellipse(e, 2, 6);
	ft_init_segment_G(e, 2);
	ft_segment_letter(e);
	ft_init_segment_G(e, 3);
	ft_segment_letter(e);
	ft_init_segment_G(e, 4);
	ft_segment_letter(e);
}
