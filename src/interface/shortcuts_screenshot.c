/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortcuts_screenshot.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 14:14:47 by prossi            #+#    #+#             */
/*   Updated: 2018/04/17 14:22:30 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	shortcuts_screenshot_circle_background(t_stuff *e)
{
	e->lt.couleur = 0xFFFFFF;
	e->bs.x_arc = (e->i.mlx->img_x / 10) * 5;
	e->bs.y_arc = ((e->i.mlx->img_y / 3) * 2.5) + 1;
	e->bs.width = e->i.mlx->img_x / 10;
	e->bs.height = (e->i.mlx->img_y / 3) / 2;
	ft_ellipse(e, 0, 0);
	while (--e->bs.width > 0)
		ft_ellipse(e, 0, 0);
	while (--e->bs.height > 0)
		ft_ellipse(e, 0, 0);
}

void	shortcuts_screenshot_draw_photo_sd(t_stuff *e)
{
	e->lt.couleur = 0xFFFFFF;
	e->bs.x_arc = (e->i.mlx->img_x / 10) * 5;
	e->bs.y_arc = ((e->i.mlx->img_y / 3) * 2.5) + 1;
	e->bs.ray_arc = 15;
	ft_arc(e, 9);
	while (--e->bs.ray_arc > 10)
		ft_arc(e, 9);
	e->bs.x_arc += 25;
	e->bs.y_arc -= 15;
	e->bs.ray_arc = 4;
	ft_arc(e, 9);
	while (--e->bs.ray_arc >= 0)
		ft_arc(e, 9);
}

void	shortcuts_screenshot_draw_photo(t_stuff *e, int centerx, int centery)
{
	e->lt.couleur = 0x000000;
	e->lt.posx = centerx - 35;
	e->lt.posy = centery + 25;
	e->lt.coeff = 1;
	e->bs.width = 70;
	e->bs.height = 50;
	full_box(e);
	e->lt.couleur = 0x000000;
	e->lt.posx = centerx - 15;
	e->lt.posy = centery - 25;
	e->bs.width = 30;
	e->bs.height = 10;
	full_box(e);
	shortcuts_screenshot_draw_photo_sd(e);
}

void	shortcuts_screenshot(t_stuff *e)
{
	shortcuts_screenshot_circle_background(e);
	shortcuts_screenshot_draw_photo(e, (e->i.mlx->img_x / 10) * 5, \
	((e->i.mlx->img_y / 3) * 2.5) + 1);
}
