/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_value_draw_moins.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 10:23:00 by prossi            #+#    #+#             */
/*   Updated: 2018/03/12 10:28:30 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_init_value_draw_moins_sd(t_stuff *e, int option)
{
	if (option == 2)
	{
		e->lt.couleur = e->i.color.nobj.col3;
		e->bs.xi = 25;
		e->bs.yi = e->i.mlx->img_y / 2;
		e->bs.xf = e->bs.xi + 65;
		e->bs.yf = e->bs.yi;
	}
	else if (option == 3)
	{
		e->bs.xi = 25;
		e->bs.yi++;
		e->bs.xf = e->bs.xi + 65;
		e->bs.yf = e->bs.yi;
	}
}

void	ft_init_value_draw_moins(t_stuff *e, int option)
{
	if (option == 0)
	{
		e->lt.couleur = e->i.color.nobj.col3;
		e->bs.xi = 15;
		e->bs.yi = e->i.mlx->img_y / 2 - 5;
		e->bs.xf = e->bs.xi + 65;
		e->bs.yf = e->bs.yi;
	}
	else if (option == 1)
	{
		e->bs.xi = 15;
		e->bs.yi++;
		e->bs.xf = e->bs.xi + 65;
		e->bs.yf = e->bs.yi;
	}
	else
		ft_init_value_draw_moins_sd(e, option);
}
