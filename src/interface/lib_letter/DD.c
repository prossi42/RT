/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DD.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 14:01:04 by prossi            #+#    #+#             */
/*   Updated: 2018/03/08 14:57:33 by Awk-LM           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/rt.h"

void	ft_init_segment_D(t_stuff *e, int option)
{
	if (option == 1)
	{
		e->bs.xi = e->lt.posx;
		e->bs.yi = e->lt.posy;
		e->bs.xf = e->bs.xi;
		e->bs.yf = e->bs.yi - (50 * e->lt.coeff);
	}
	if (option == 2)
	{
		e->bs.xi = e->lt.posx + 1;
		e->bs.yi = e->lt.posy;
		e->bs.xf = e->bs.xi;
		e->bs.yf = e->bs.yi - (50 * e->lt.coeff);
	}
	if (option == 3)
	{
		e->bs.xi = e->lt.posx + 2;
		e->bs.yi = e->lt.posy;
		e->bs.xf = e->bs.xi;
		e->bs.yf = e->bs.yi - (50 * e->lt.coeff);
	}
	if (option == 4)
	{
		e->bs.x_arc = e->lt.posx;
		e->bs.y_arc = e->lt.posy - (25 * e->lt.coeff);
		e->bs.width = 25 * e->lt.coeff;
		e->bs.height = 25 * e->lt.coeff;
	}
}

void	D(t_stuff *e)
{
	ft_init_segment_D(e, 1);
	ft_segment_letter(e);
	ft_init_segment_D(e, 2);
	ft_segment_letter(e);
	ft_init_segment_D(e, 3);
	ft_segment_letter(e);
	ft_init_segment_D(e, 4);
	ft_ellipse(e, 2, 2);
	ft_ellipse(e, 1, 6);
	ft_ellipse(e, 1, 4);
	e->bs.width--;
	e->bs.height--;
	ft_ellipse(e, 2, 2);
	ft_ellipse(e, 1, 6);
	ft_ellipse(e, 1, 4);
	e->bs.width--;
	e->bs.height--;
	ft_ellipse(e, 2, 2);
	ft_ellipse(e, 1, 6);
	ft_ellipse(e, 1, 4);
}
