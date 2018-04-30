/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_color_fill_tab_pix.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 20:40:06 by prossi            #+#    #+#             */
/*   Updated: 2018/04/17 20:40:31 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	fill_tab_pix_td(t_stuff *e, int x, int y)
{
	int		i;
	int		j;

	j = e->i.color.tabyd[y][x];
	while (++j < e->i.color.tabyf[y][x])
	{
		i = e->i.color.tabxd[y][x];
		while (++i < e->i.color.tabxf[y][x])
		{
			pixel_put_to_img(&e->i.mlx, i, j, e->i.color.tab[y][x]);
		}
	}
}

void	fill_tab_pix_sd(t_stuff *e)
{
	int		y;
	int		x;

	y = -1;
	while (++y < 12)
	{
		x = -1;
		while (++x < 18)
		{
			fill_tab_pix_td(e, x, y);
		}
	}
}

void	fill_tab_pix(t_stuff *e)
{
	int		y;
	int		x;

	y = -1;
	e->i.color.padx = 8;
	e->i.color.pady = 2;
	while (++y < 12)
	{
		x = -1;
		while (++x < 18)
		{
			e->i.color.tabxd[y][x] = e->i.color.padx;
			e->i.color.tabyd[y][x] = e->i.color.pady;
			e->i.color.tabxf[y][x] = e->i.color.tabxd[y][x] + 28;
			e->i.color.tabyf[y][x] = e->i.color.tabyd[y][x] + 23;
			e->i.color.padx += 28;
		}
		e->i.color.padx = 8;
		e->i.color.pady += 23;
	}
}
