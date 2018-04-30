/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortcuts_negatif.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 21:19:52 by prossi            #+#    #+#             */
/*   Updated: 2018/04/11 22:13:28 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	draw_rope_shortcuts_negatif(t_stuff *e, int x, int y)
{
	e->bs.x_arc = x + (e->i.mlx->img_x / 10);
	e->bs.y_arc = y + 15;
	e->bs.width = (e->i.mlx->img_x / 10) - 2;
	e->bs.height = 7;
	e->lt.couleur = 0xFFFFFF;
	ft_ellipse(e, 1, 2);
}

void	draw_photo_shortcuts_negatif(t_stuff *e, int x, int y)
{
	e->lt.couleur = 0xFFFFFF;
	e->lt.posx = x;
	e->lt.posy = y;
	e->lt.coeff = 1;
	e->bs.width = 18;
	e->bs.height = 24;
	full_box(e);
	e->lt.couleur = 0x000000;
	e->lt.posx = x + 2;
	e->lt.posy = y - 5;
	e->bs.width = 14;
	e->bs.height = 15;
	full_box(e);
}

void	draw_clothespin_shortcuts_negatif(t_stuff *e, int x, int y)
{
	e->lt.couleur = 0x000000;
	e->lt.posx = x + 8;
	e->lt.posy = y - 22;
	e->bs.width = 2;
	e->bs.height = 11;
	full_box(e);
}

void	shortcuts_negatif(t_stuff *e)
{
	int		borderx;

	borderx = ((e->i.mlx->img_x / 5) * 4) - 1;
	draw_rope_shortcuts_negatif(e, borderx, 0);
	draw_rope_shortcuts_negatif(e, borderx, 38);
	draw_photo_shortcuts_negatif(e, borderx + 15, 50);
	draw_clothespin_shortcuts_negatif(e, borderx + 15, 50);
	draw_photo_shortcuts_negatif(e, borderx + 43, 52);
	draw_clothespin_shortcuts_negatif(e, borderx + 43, 52);
	draw_photo_shortcuts_negatif(e, borderx + 70, 50);
	draw_clothespin_shortcuts_negatif(e, borderx + 70, 50);
	draw_photo_shortcuts_negatif(e, borderx + 15, 88);
	draw_clothespin_shortcuts_negatif(e, borderx + 15, 88);
	draw_photo_shortcuts_negatif(e, borderx + 43, 90);
	draw_clothespin_shortcuts_negatif(e, borderx + 43, 90);
	draw_photo_shortcuts_negatif(e, borderx + 70, 88);
	draw_clothespin_shortcuts_negatif(e, borderx + 70, 88);
}
