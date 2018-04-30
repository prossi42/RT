/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortcuts_damier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 18:22:12 by prossi            #+#    #+#             */
/*   Updated: 2018/03/27 07:49:55 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	setup_value_shortcuts_damier(t_stuff *e)
{
	int		borderx;
	int		bordery;

	borderx = (e->i.mlx->img_x / 5) * 2;
	bordery = e->i.mlx->img_y / 3;
	e->bs.width = (e->i.mlx->img_x / 5) / 10;
	e->bs.height = (e->i.mlx->img_y / 3) / 10;
	e->lt.posx = borderx + 2;
	e->lt.posy = bordery + e->bs.height + 2;
	e->lt.coeff = 1;
}

int		loopx_shortcuts_damier(t_stuff *e, int option)
{
	if (option == 0)
	{
		e->lt.couleur = 0x000000;
		option = 1;
	}
	else
	{
		e->lt.couleur = 0xFFFFFF;
		option = 0;
	}
	full_box(e);
	e->lt.posx += e->bs.width;
	return (option);
}

void	loopy_shortcuts_damier(t_stuff *e)
{
	int		y;
	int		x;
	int		option;
	int		tmp;

	y = -1;
	option = 0;
	tmp = e->lt.posx;
	while (++y < 10)
	{
		x = -1;
		e->lt.posx = tmp;
		while (++x < 10)
			option = loopx_shortcuts_damier(e, option);
		e->lt.posy += e->bs.height;
		if (option == 0)
			option = 1;
		else
			option = 0;
	}
}

void	shortcuts_damier(t_stuff *e)
{
	setup_value_shortcuts_damier(e);
	loopy_shortcuts_damier(e);
}
