/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortcuts_cartoon.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:16:25 by prossi            #+#    #+#             */
/*   Updated: 2018/04/17 14:37:22 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	fill_ellipse_cartoon(t_stuff *e)
{
	while (--e->bs.width > 0)
		ft_ellipse(e, 0, 0);
	while (--e->bs.height > 0)
		ft_ellipse(e, 0, 0);
}

void	draw_cloud_cartoon_sd(t_stuff *e, int borderx)
{
	e->lt.posx = borderx + (e->i.mlx->img_x / 10) - 7;
	e->lt.posy = ((e->i.mlx->img_y / 3) / 3) + 18;
	e->lt.coeff = 0.65;
	e->lt.space = 40;
	e->lt.couleur = 0x000000;
	awklm_string_put("#", e);
	e->lt.posx = borderx + (e->i.mlx->img_x / 10) + 15;
	e->lt.posy = ((e->i.mlx->img_y / 3) / 3) + 10;
	e->lt.coeff = 0.40;
	awklm_string_put("!", e);
	e->lt.posx = borderx + (e->i.mlx->img_x / 10) - 20;
	e->lt.posy = ((e->i.mlx->img_y / 3) / 3) + 10;
	awklm_string_put("!", e);
}

void	draw_cloud_cartoon(t_stuff *e)
{
	int		borderx;

	borderx = (e->i.mlx->img_x / 10) * 2;
	e->lt.couleur = 0xFFFFFF;
	e->bs.x_arc = borderx + (e->i.mlx->img_x / 10);
	e->bs.y_arc = (e->i.mlx->img_y / 3) / 3;
	e->bs.width = 40;
	e->bs.height = 20;
	ft_ellipse(e, 0, 0);
	fill_ellipse_cartoon(e);
	e->bs.x_arc = borderx + 25;
	e->bs.y_arc = 56;
	e->bs.width = 10;
	e->bs.height = 5;
	ft_ellipse(e, 0, 0);
	fill_ellipse_cartoon(e);
	e->bs.x_arc = borderx + 20;
	e->bs.y_arc = 68;
	e->bs.width = 8;
	e->bs.height = 4;
	ft_ellipse(e, 0, 0);
	fill_ellipse_cartoon(e);
	draw_cloud_cartoon_sd(e, borderx);
}

void	shortcuts_cartoon(t_stuff *e)
{
	draw_cloud_cartoon(e);
}
