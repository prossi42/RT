/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_value_draw_plus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Awk-LM <Awk-LM@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 11:59:15 by Awk-LM            #+#    #+#             */
/*   Updated: 2018/03/12 10:29:31 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_init_value_draw_plus_td(t_stuff *e, int option)
{
	if (option == 6)
	{
		e->bs.xi = (WIN_X - WIDTH) - 25 - 27;
		e->bs.yi = (e->i.mlx->img_y / 2) - 27;
		e->bs.xf = e->bs.xi;
		e->bs.yf = e->bs.yi + 65;
	}
	else if (option == 7)
	{
		e->bs.xi--;
		e->bs.yi = e->bs.yi = (e->i.mlx->img_y / 2) - 27;
		e->bs.xf = e->bs.xi;
		e->bs.yf = e->bs.yi + 65;
	}
}

void	ft_init_value_draw_plus_sd(t_stuff *e, int option)
{
	if (option == 3)
	{
		e->bs.xi--;
		e->bs.yi = e->i.mlx->img_y / 2 - 32;
		e->bs.xf = e->bs.xi;
		e->bs.yf = e->bs.yi + 65;
	}
	else if (option == 4)
	{
		e->lt.couleur = e->i.color.nobj.col3;
		e->bs.xi = (WIN_X - WIDTH) - 25;
		e->bs.yi = e->i.mlx->img_y / 2;
		e->bs.xf = e->bs.xi - 65;
		e->bs.yf = e->bs.yi;
	}
	else if (option == 5)
	{
		e->bs.xi = (WIN_X - WIDTH) - 25;
		e->bs.yi++;
		e->bs.xf = e->bs.xi - 65;
		e->bs.yf = e->bs.yi;
	}
	else
		ft_init_value_draw_plus_td(e, option);
}

void	ft_init_value_draw_plus(t_stuff *e, int option)
{
	if (option == 0)
	{
		e->lt.couleur = e->i.color.nobj.col3;
		e->bs.xi = (WIN_X - WIDTH) - 15;
		e->bs.yi = e->i.mlx->img_y / 2 - 5;
		e->bs.xf = e->bs.xi - 65;
		e->bs.yf = e->bs.yi;
	}
	else if (option == 1)
	{
		e->bs.xi = (WIN_X - WIDTH) - 15;
		e->bs.yi++;
		e->bs.xf = e->bs.xi - 65;
		e->bs.yf = e->bs.yi;
	}
	else if (option == 2)
	{
		e->bs.xi = (WIN_X - WIDTH) - 15 - 27;
		e->bs.yi = e->i.mlx->img_y / 2 - 32;
		e->bs.xf = e->bs.xi;
		e->bs.yf = e->bs.yi + 65;
	}
	else
		ft_init_value_draw_plus_sd(e, option);
}
