/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_interface.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 22:29:49 by prossi            #+#    #+#             */
/*   Updated: 2018/03/12 08:23:31 by Awk-LM           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	cadre_valangle(t_stuff *e, int x, int y)
{
	int		tmpx;
	int		tmpy;

	tmpy = y - 1;
	while (++tmpy < y + 40)
	{
		tmpx = x - 1;
		while (++tmpx < x + 80)
		{
			if (tmpx == x || tmpx == x + 1 || tmpx == x + 78 || tmpx == x + 79)
				pixel_put_to_img(&e->i.mlx, tmpx, tmpy, 0x000000);
			else if (tmpy == y || tmpy == y + 1 || tmpy == y + 38 || tmpy == y + 39)
				pixel_put_to_img(&e->i.mlx, tmpx, tmpy, 0x000000);
			else
				pixel_put_to_img(&e->i.mlx, tmpx, tmpy, 0x6A455D);
		}
	}
}

void	cadre_xyz(t_stuff *e, int x, int y)
{
	int		tmpx;
	int		tmpy;

	tmpy = y - 1;
	while (++tmpy < y + 40)
	{
		tmpx = x - 1;
		while (++tmpx < x + 40)
		{
			if (tmpx == x  || tmpx == x + 1 || tmpx == x + 38 || tmpx == x + 39)
				pixel_put_to_img(&e->i.mlx, tmpx, tmpy, 0x000000);
			else if (tmpy == y || tmpy == y + 1 || tmpy == y + 38 || tmpy == y + 39)
				pixel_put_to_img(&e->i.mlx, tmpx, tmpy, 0x000000);
			else
				pixel_put_to_img(&e->i.mlx, tmpx, tmpy, e->i.mat.col_box);
		}
	}
}

void	cadre_matrice(t_stuff *e, int x, int y)
{
	int		tmpx;
	int		tmpy;

	tmpy = y - 1;
	while (++tmpy < y + 40)
	{
		tmpx = x - 1;
		while (++tmpx < x + 200)
		{
			if (tmpx == x || tmpx == x + 1 || tmpx == x + 199 || tmpx == x + 198)
				pixel_put_to_img(&e->i.mlx, tmpx, tmpy, 0x000000);
			else if (tmpy == y || tmpy ==y + 1 || tmpy == y + 38 || tmpy == y + 39)
				pixel_put_to_img(&e->i.mlx, tmpx, tmpy, 0x000000);
			else
				pixel_put_to_img(&e->i.mlx, tmpx, tmpy, e->i.mat.col_box);
		}
	}
}

void	title_matrice(t_stuff *e)
{
	e->lt.posx = 180;
	e->lt.posy = 50;
	e->lt.coeff = 0.5;
	e->lt.couleur = 0x000000;
	e->lt.space = 40;
	awklm_string_put("MATRICES", e);
	e->lt.posx = 73;
	e->lt.posy = 135;
	e->lt.coeff = 0.4;
	awklm_string_put("ROTATION", e);
	e->lt.posx = 290;
	awklm_string_put("X", e);
	e->lt.posx = 340;
	awklm_string_put("Y", e);
	e->lt.posx = 390;
	awklm_string_put("Z", e);
	e->lt.posx = 437;
	e->lt.posy = 130;
	e->lt.coeff = 0.30;
	awklm_string_put("ANGLE", e);
	e->lt.coeff = 0.40;
	e->lt.posx = 50;
	e->lt.posy = 195;
	awklm_string_put("TRANSLATION", e);
	e->lt.posx = 290;
	awklm_string_put("X", e);
	e->lt.posx = 340;
	awklm_string_put("Y", e);
	e->lt.posx = 390;
	awklm_string_put("Z", e);
	e->lt.posx = 435;
	e->lt.posy = 192;
	e->lt.coeff = 0.27;
	awklm_string_put("VALEUR", e);
	e->lt.coeff = 0.40;
	e->lt.posx = 65;
	e->lt.posy = 255;
	awklm_string_put("DIRECTION", e);
	e->lt.posx = 313;
	awklm_string_put("POSITION", e);
}

void	cadre_title(t_stuff *e)
{
	int		x;
	int		y;

	y = -1;
	while (++y < e->i.mlx->img_y)
	{
		x = -1;
		while (++x < e->i.mlx->img_x)
		{
			//	COULEUR DE L IMAGE
			pixel_put_to_img(&e->i.mlx, x, y, e->i.mat.col_fond);
			if (((y == 5 || y == 6) && x >= 150 && x <= 370) || \
			((y == 60 || y == 61) && x >= 150 && x <= 370) || \
			(y >= 5 && y <= 60 && ((x == 150 || x == 151) || \
			(x == 369 || x == 370))))
				pixel_put_to_img(&e->i.mlx, x, y, 0x000000);
			if (y >= 7 && y <= 59 && x >= 152 && x <= 368)
				pixel_put_to_img(&e->i.mlx, x, y, 0x6A455D);
		}
	}
	if (e->i.mat.act_rot == 1)
		e->i.mat.col_box = 0x00FF00;
	cadre_matrice(e, 40, 100);	//Rotation
	e->i.mat.col_box = 0x6A455D;
	if (e->i.mat.act_trans == 1)
		e->i.mat.col_box = 0x00FF00;
	cadre_matrice(e, 40, 160);	//Translation
	e->i.mat.col_box = 0x6A455D;
	if (e->i.mat.dir_or_pos == 1)
		e->i.mat.col_box = 0x00FF00;
	cadre_matrice(e, 40, 220);	//Direction
	e->i.mat.col_box = 0x6A455D;
	if (e->i.mat.dir_or_pos == 2)
		e->i.mat.col_box = 0x00FF00;
	cadre_matrice(e, 280, 220);	//Position
	e->i.mat.col_box = 0x6A455D;
	if (e->i.mat.act_xyz == 1 && e->i.mat.act_rot == 1)
		e->i.mat.col_box = 0x00FF00;
	cadre_xyz(e, 280, 100);
	e->i.mat.col_box = 0x6A455D;
	if (e->i.mat.act_xyz == 2 && e->i.mat.act_rot == 1)
		e->i.mat.col_box = 0x00FF00;
	cadre_xyz(e, 330, 100);
	e->i.mat.col_box = 0x6A455D;
	if (e->i.mat.act_xyz == 3 && e->i.mat.act_rot == 1)
		e->i.mat.col_box = 0x00FF00;
	cadre_xyz(e, 380, 100);
	e->i.mat.col_box = 0x6A455D;
	if (e->i.mat.act_xyz == 1 && e->i.mat.act_trans == 1)
		e->i.mat.col_box = 0x00FF00;
	cadre_xyz(e, 280, 160);
	e->i.mat.col_box = 0x6A455D;
	if (e->i.mat.act_xyz == 2 && e->i.mat.act_trans == 1)
		e->i.mat.col_box = 0x00FF00;
	cadre_xyz(e, 330, 160);
	e->i.mat.col_box = 0x6A455D;
	if (e->i.mat.act_xyz == 3 && e->i.mat.act_trans == 1)
		e->i.mat.col_box = 0x00FF00;
	cadre_xyz(e, 380, 160);
	e->i.mat.col_box = 0x6A455D;
	cadre_valangle(e, 430, 100);
	cadre_valangle(e, 430, 160);
}

void	matrice_interface(t_stuff *e)
{
	if (e->i.first == 0)
	{
		e->i.img_x = WIN_X - WIDTH;
		e->i.img_y = WIN_Y - LENGTH;
		new_img(e);
	}
	else
	{
		reboot_list_interface(e, 1);
		searchlist_interface(e, 4);
	}
	init_struct(e, 1);
	cadre_title(e);
	title_matrice(e);
	mlx_put_image_to_window(e->img.mlx_ptr, e->img.win_ptr, e->i.mlx->img, WIN_X - WIDTH, 0);
}
