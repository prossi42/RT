/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 10:39:00 by prossi            #+#    #+#             */
/*   Updated: 2018/02/21 17:03:42 by Awk-LM           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

// void	draw_plus(t_stuff *e, int x, int y)
// {
// 	int		tmpx;
// 	int		tmpy;
//
// 	tmpy = y - 1;
// 	while (++tmpy <= y + 35)
// 	{
// 		tmpx = x - 1;
// 		while (++tmpx < x + 25)
// 		{
// 			if ((tmpx == x + (25 / 2) || tmpx == x + (25 / 2) + 1) && tmpy >= y + (35 / 5) && tmpy <= y + ((35 / 5) * 4))
// 				pixel_put_to_img(&e->i.mlx, tmpx, tmpy, 0x6C0277);
// 			else if ((tmpy == y + (35 / 2) || tmpy == y + (35 / 2) + 1) && tmpx >= x + (25 / 6) && tmpx <= x + ((25 / 6) * 5))
// 				pixel_put_to_img(&e->i.mlx, tmpx, tmpy, 0x6C0277);
// 		}
// 	}
// }

void	draw_plus(t_stuff *e, int x, int y)
{
	e->bs.xi = x + (25 / 2);
	e->bs.yi = y + (25 / 5);
	e->bs.xf = e->bs.xi;
	e->bs.yf = e->bs.yi + 23;
	e->lt.couleur = 0xFFD700;
	ft_segment_letter(e);
	e->bs.xi = x;
	e->bs.yi = y + (35 / 2);
	e->bs.xf = e->bs.xi + 25;
	e->bs.yf = e->bs.yi;
	ft_segment_letter(e);
}

void	draw_box_arrow(t_stuff *e, int x, int y)
{
	int		tmpx;
	int		tmpy;

	tmpy = y - 1;
	while (++tmpy <= y + 35)
	{
		tmpx = x - 1;
		while (++tmpx < x + 25)
		{
			pixel_put_to_img(&e->i.mlx, tmpx, tmpy, 0x000000);
		}
	}
}

void	arrow(t_stuff *e, int x, int y, int option)
{
	e->lt.couleur = 0xFFD700;
	if (option == 0)
	{
		e->bs.xi = x + 24;
		e->bs.yi = y;
		e->bs.xf = x;
		e->bs.yf = y + (35 / 2);
		ft_segment_letter(e);
		e->bs.xi = e->bs.xf;
		e->bs.yi = e->bs.yf;
		e->bs.xf = x + 24;
		e->bs.yf = e->bs.yf + (35 / 2);
		ft_segment_letter(e);
		e->bs.xi = x + 24;
		e->bs.yi = y + 1;
		e->bs.xf = x;
		e->bs.yf = y + 1 + (35 / 2);
		ft_segment_letter(e);
		e->bs.xi = e->bs.xf;
		e->bs.yi = e->bs.yf;
		e->bs.xf = x + 24;
		e->bs.yf = e->bs.yi + (35 / 2);
		ft_segment_letter(e);
	}
	if (option  == 1)
	{
		e->bs.xi = x;
		e->bs.yi = y;
		e->bs.xf = x + 24;
		e->bs.yf = y + (35 / 2);
		ft_segment_letter(e);
		e->bs.xi = e->bs.xf;
		e->bs.yi = e->bs.yf;
		e->bs.xf = x;
		e->bs.yf = e->bs.yi + (35 / 2);
		ft_segment_letter(e);
		e->bs.xi = x;
		e->bs.yi = y + 1;
		e->bs.xf = x + 24;
		e->bs.yf = y + 1 + (35 / 2);
		ft_segment_letter(e);
		e->bs.xi = e->bs.xf;
		e->bs.yi = e->bs.yf;
		e->bs.xf = e->bs.xi - 24;
		e->bs.yf = e->bs.yi + (35 / 2);
		ft_segment_letter(e);
	}
}

void	draw_arrow(t_stuff *e)
{
	//Supprimer les draw_box_arrow quand les hooks de souris seront fait
	// draw_box_arrow(e, (e->i.mlx->img_x / 4) - 30, 5);
	arrow(e, (e->i.mlx->img_x / 4) - 30, 5, 0);
	// draw_box_arrow(e, ((e->i.mlx->img_x / 4) * 3) + 5, 5);
	arrow(e, ((e->i.mlx->img_x / 4) * 3) + 5, 5, 1);
	// draw_box_arrow(e, (e->i.mlx->img_x / 4) - 30, 50);
	arrow(e, (e->i.mlx->img_x / 4) - 30, 50, 0);
	// draw_box_arrow(e, ((e->i.mlx->img_x / 4) * 3) + 5, 50);
	arrow(e, ((e->i.mlx->img_x / 4) * 3) + 5, 50, 1);
	// draw_box_arrow(e, (e->i.mlx->img_x / 4) - 30, 95);
	arrow(e, (e->i.mlx->img_x / 4) - 30, 95, 0);
	// draw_box_arrow(e, ((e->i.mlx->img_x / 4) * 3) + 5, 95);
	arrow(e, ((e->i.mlx->img_x / 4) * 3) + 5, 95, 1);
	// draw_box_arrow(e, (e->i.mlx->img_x / 4) - 30, 140);
	arrow(e, (e->i.mlx->img_x / 4) - 30, 140, 0);
	// draw_box_arrow(e, ((e->i.mlx->img_x / 4) * 3) + 5, 140);
	arrow(e, ((e->i.mlx->img_x / 4) * 3) + 5, 140, 1);
	// draw_box_arrow(e, (e->i.mlx->img_x / 4) - 30, 185);
	arrow(e, (e->i.mlx->img_x / 4) - 30, 185, 0);
	// draw_box_arrow(e, ((e->i.mlx->img_x / 4) * 3) + 5, 185);
	arrow(e, ((e->i.mlx->img_x / 4) * 3) + 5, 185, 1);
	// draw_box_arrow(e, (e->i.mlx->img_x / 4) - 30, 230);
	arrow(e, (e->i.mlx->img_x / 4) - 30, 230, 0);
	// draw_box_arrow(e, ((e->i.mlx->img_x / 4) * 3) + 5, 230);
	arrow(e, ((e->i.mlx->img_x / 4) * 3) + 5, 230, 1);
}

void	draw_new_obj(t_stuff *e)
{
	int		x;
	int		y;

	y = -1;
	while (++y < e->i.mlx->img_y)
	{
		x = -1;
		while (++x < e->i.mlx->img_x)
		{
			// if ((x >= e->i.mlx->img_x / 4 && x <= (e->i.mlx->img_x / 4) * 3 && ((y == 5 || y == 6) || (y == 40 || y == 41))) || ((x == e->i.mlx->img_x / 4 || x == (e->i.mlx->img_x / 4) * 3) && y >= 5 && y <= 41))
			// 	pixel_put_to_img(&e->i.mlx, x, y, 0xFFD700);
			// else if ((x >= e->i.mlx->img_x / 4 && x <= (e->i.mlx->img_x / 4) * 3 && ((y == 50 || y == 51) || (y == 85 || y == 86))) || ((x == e->i.mlx->img_x / 4 || x == (e->i.mlx->img_x / 4) * 3) && y >= 50 && y <= 86))
			// 	pixel_put_to_img(&e->i.mlx, x, y, 0xFFD700);
			// else if ((x >= e->i.mlx->img_x / 4 && x <= (e->i.mlx->img_x / 4) * 3 && ((y == 95 || y == 96) || (y == 130 || y == 131))) || ((x == e->i.mlx->img_x / 4 || x == (e->i.mlx->img_x / 4) * 3) && y >= 95 && y <= 131))
			// 	pixel_put_to_img(&e->i.mlx, x, y, 0xFFD700);
			// else if ((x >= e->i.mlx->img_x / 4 && x <= (e->i.mlx->img_x / 4) * 3 && ((y == 140 || y == 141) || (y == 175 || y == 176))) || ((x == e->i.mlx->img_x / 4 || x == (e->i.mlx->img_x / 4) * 3) && y >= 140 && y <= 176))
			// 	pixel_put_to_img(&e->i.mlx, x, y, 0xFFD700);
			// else if ((x >= e->i.mlx->img_x / 4 && x <= (e->i.mlx->img_x / 4) * 3 && ((y == 185 || y == 186) || (y == 220 || y == 221))) || ((x == e->i.mlx->img_x / 4 || x == (e->i.mlx->img_x / 4) * 3) && y >= 185 && y <= 221))
			// 	pixel_put_to_img(&e->i.mlx, x, y, 0xFFD700);
			// else if ((x >= e->i.mlx->img_x / 4 && x <= (e->i.mlx->img_x / 4) * 3 && ((y == 230 || y == 231) || (y == 265 || y == 266))) || ((x == e->i.mlx->img_x / 4 || x == (e->i.mlx->img_x / 4) * 3) && y >= 230 && y <= 266))
			// 	pixel_put_to_img(&e->i.mlx, x, y, 0xFFD700);
			// else
				pixel_put_to_img(&e->i.mlx, x, y, 0x202020);
		}
	}
}

void	name_new_obj(t_stuff *e)
{
	e->lt.posx = e->i.mlx->img_x / 4 + 100;
	e->lt.posy = 35;
	e->lt.coeff = 0.3;
	e->lt.couleur = 0xFFD700;
	e->lt.space = 40;
	awklm_string_put("SPHERE", e);
	e->lt.posx = e->i.mlx->img_x / 4 + 110;
	e->lt.posy = 80;
	awklm_string_put("PLAN", e);
	e->lt.posx = e->i.mlx->img_x / 4 + 85;
	e->lt.posy = 125;
	awklm_string_put("CYLINDRE", e);
	e->lt.posx = e->i.mlx->img_x / 4 + 110;
	e->lt.posy = 170;
	awklm_string_put("CONE", e);
	e->lt.posx = e->i.mlx->img_x / 4 + 105;
	e->lt.posy = 215;
	awklm_string_put("LIGHT", e);
	e->lt.posx = e->i.mlx->img_x / 4 + 100;
	e->lt.posy = 260;
	awklm_string_put("CAMERA", e);
}

void	add_obj(t_stuff *e)
{
	// draw_box_arrow(e, ((e->i.mlx->img_x / 4) * 3) + 70, 5);
	draw_plus(e, ((e->i.mlx->img_x / 4) * 3) + 70, 5);
	// draw_box_arrow(e, ((e->i.mlx->img_x / 4) * 3) + 70, 50);
	draw_plus(e, ((e->i.mlx->img_x / 4) * 3) + 70, 50);
	// draw_box_arrow(e, ((e->i.mlx->img_x / 4) * 3) + 70, 95);
	draw_plus(e, ((e->i.mlx->img_x / 4) * 3) + 70, 95);
	// draw_box_arrow(e, ((e->i.mlx->img_x / 4) * 3) + 70, 140);
	draw_plus(e, ((e->i.mlx->img_x / 4) * 3) + 70, 140);
	// draw_box_arrow(e, ((e->i.mlx->img_x / 4) * 3) + 70, 185);
	draw_plus(e, ((e->i.mlx->img_x / 4) * 3) + 70, 185);
	// draw_box_arrow(e, ((e->i.mlx->img_x / 4) * 3) + 70, 230);
	draw_plus(e, ((e->i.mlx->img_x / 4) * 3) + 70, 230);
}

void	draw_open_garbage(t_stuff *e, int x, int y)
{
	int		i;

	i = -1;
				// CONTOUR
	e->bs.x_arc = x + 10;
	e->bs.y_arc = y - 18;
	e->bs.ray_arc = 20 + 1;
	e->lt.couleur = 0xAF995B;
	ft_arc(e, 9);
	while (e->bs.ray_arc > 0)
	{
		e->bs.ray_arc--;
		ft_arc(e, 9);
	}
	e->bs.x_arc = x + 10;
	e->bs.y_arc = y - 18;
	e->bs.ray_arc = 20 + 1;
	while (e->bs.ray_arc > 0)
	{
		e->bs.y_arc--;
		e->bs.ray_arc--;
		ft_arc(e, 9);
	}
	e->bs.x_arc = x + 10;
	e->bs.y_arc = y - 18;
	e->bs.ray_arc = 20 + 1;
	while (e->bs.ray_arc > 0)
	{
		e->bs.y_arc++;
		e->bs.ray_arc--;
		ft_arc(e, 9);
	}
	e->bs.x_arc = x + 10;
	e->bs.y_arc = y - 18;
	e->bs.ray_arc = 20 + 1;
	while (e->bs.ray_arc > 0)
	{
		e->bs.x_arc++;
		e->bs.ray_arc--;
		ft_arc(e, 9);
	}
	e->bs.x_arc = x + 10;
	e->bs.y_arc = y - 18;
	e->bs.ray_arc = 20 + 1;
	while (e->bs.ray_arc > 0)
	{
		e->bs.x_arc--;
		e->bs.ray_arc--;
		ft_arc(e, 9);
	}
				// BASE DE LA POUBELLE
	e->bs.xi = x;
	e->bs.yi = y;
	e->bs.xf = e->bs.xi + 20;
	e->bs.yf = e->bs.yi;
	e->lt.couleur = 0x696969;
	while (e->bs.yi > y - 20)
	{
		ft_segment_letter(e);
		e->bs.xi = x;
		e->bs.yi--;
		e->bs.yf = e->bs.yi;
	}
	e->lt.couleur = 0x000000;
	e->bs.xi = x;
	e->bs.yi = y + 1;
	e->bs.yf = e->bs.yi;
	ft_segment_letter(e);
	e->bs.xi = x;
	e->bs.yi = y - 20;
	e->bs.xf =e->bs.xi + 20;
	e->bs.yf = e->bs.yi;
	ft_segment_letter(e);
	e->bs.xi = x;
	e->bs.yi = y - 21;
	e->bs.yf = e->bs.yi;
	ft_segment_letter(e);
	e->bs.xi = x;
	e->bs.xf = e->bs.xi;
	e->bs.yi = y - 20;
	e->bs.yf = y;
	ft_segment_letter(e);
	e->bs.xi = x + 1;
	e->bs.xf = e->bs.xi;
	e->bs.yi = y - 20;
	ft_segment_letter(e);
	e->bs.xi = x + 20;
	e->bs.yi = y - 20;
	e->bs.xf = e->bs.xi;
	e->bs.yf = y;
	ft_segment_letter(e);
	e->bs.xi = x + 21;
	e->bs.yi = y - 20;
	ft_segment_letter(e);
		// COUVERCLE DE LA POUBELLE
	e->bs.xi = x - 4;
	e->bs.yi = y;
	e->bs.xf = e->bs.xi;
	e->bs.yf = e->bs.yi - 24;
	ft_segment_letter(e);
	e->bs.xi = x - 5;
	e->bs.yi = y;
	e->bs.xf = e->bs.xi;
	ft_segment_letter(e);
	e->bs.x_arc = x - 4;
	e->bs.y_arc = y - 12;
	e->bs.ray_arc = 12;
	ft_arc(e, 2);
	// e->bs.ray_arc = 13;
	e->lt.couleur = 0x696969;
	while (--e->bs.ray_arc > 0)
		ft_arc(e, 2);
	e->bs.xi = x - 4 - 13;
	e->bs.yi = y - 10;
	e->bs.xf = e->bs.xi - 4;
	e->bs.yf = e->bs.yi;
	ft_segment_letter(e);
	e->bs.xi = x - 4 - 13;
	e->bs.yi = y - 14;
	e->bs.xf = e->bs.xi - 4;
	e->bs.yf = e->bs.yi;
	ft_segment_letter(e);
	e->bs.xi = e->bs.xf;
	e->bs.yi = e->bs.yf;
	e->bs.xf = e->bs.xi;
	e->bs.yf = e->bs.yi + 4;
	ft_segment_letter(e);
}

void	draw_close_garbage(t_stuff *e, int x, int y)
{
			// BASE DE LA POUBELLE
	e->bs.xi = x;
	e->bs.yi = y;
	e->bs.xf = e->bs.xi + 20;
	e->bs.yf = e->bs.yi;
	e->lt.couleur = 0x6C0277;
	ft_segment_letter(e);
	e->bs.xi = x;
	e->bs.yi = y + 1;
	e->bs.yf = e->bs.yi;
	ft_segment_letter(e);
	e->bs.xi = x;
	e->bs.yi = y - 20;
	e->bs.xf =e->bs.xi + 20;
	e->bs.yf = e->bs.yi;
	ft_segment_letter(e);
	e->bs.xi = x;
	e->bs.yi = y - 21;
	e->bs.yf = e->bs.yi;
	ft_segment_letter(e);
	e->bs.xi = x;
	e->bs.xf = e->bs.xi;
	e->bs.yi = y - 20;
	e->bs.yf = y;
	ft_segment_letter(e);
	e->bs.xi = x + 1;
	e->bs.xf = e->bs.xi;
	e->bs.yi = y - 20;
	ft_segment_letter(e);
	e->bs.xi = x + 20;
	e->bs.yi = y - 20;
	e->bs.xf = e->bs.xi;
	e->bs.yf = y;
	ft_segment_letter(e);
	e->bs.xi = x + 21;
	e->bs.yi = y - 20;
	ft_segment_letter(e);
				// COUVERCLE DE LA POUBELLE
	e->bs.xi = x - 2;
	e->bs.yi = y - 22;
	e->bs.xf = e->bs.xi + 24;
	e->bs.yf = e->bs.yi;
	ft_segment_letter(e);
	e->bs.xi = x - 2;
	e->bs.yi = y - 23;
	e->bs.yf = e->bs.yi;
	ft_segment_letter(e);
	e->bs.x_arc = x + 10;
	e->bs.y_arc = y - 22;
	e->bs.ray_arc = 12;
	ft_arc(e, 3);
	e->bs.ray_arc = 13;
	ft_arc(e, 3);
	e->bs.xi = x + 8;
	e->bs.yi = y - 23 - 13;
	e->bs.xf = e->bs.xi;
	e->bs.yf = e->bs.yi - 2;
	ft_segment_letter(e);
	e->bs.xi = x + 12;
	e->bs.yi = y - 23 - 13;
	e->bs.xf = e->bs.xi;
	ft_segment_letter(e);
	e->bs.xi = x + 8;
	e->bs.xf = x + 12;
	e->bs.yi = y - 23 - 13 - 2;
	e->bs.yf = e->bs.yi;
	ft_segment_letter(e);
}

void	del_obj(t_stuff *e)
{
	if (e->i.nobj.open != 1)
		draw_close_garbage(e, (e->i.mlx->img_x / 4) - 90, 40);
	else if (e->i.nobj.open == 1)
		draw_open_garbage(e, (e->i.mlx->img_x / 4) - 90, 40);
	if (e->i.nobj.open != 2)
		draw_close_garbage(e, (e->i.mlx->img_x / 4) - 90, 85);
	else if (e->i.nobj.open == 2)
		draw_open_garbage(e, (e->i.mlx->img_x / 4) - 90, 85);
	if (e->i.nobj.open != 3)
		draw_close_garbage(e, (e->i.mlx->img_x / 4) - 90, 130);
	else if (e->i.nobj.open == 3)
		draw_open_garbage(e, (e->i.mlx->img_x / 4) - 90, 130);
	if (e->i.nobj.open != 4)
		draw_close_garbage(e, (e->i.mlx->img_x / 4) - 90, 175);
	else if (e->i.nobj.open == 4)
		draw_open_garbage(e, (e->i.mlx->img_x / 4) - 90, 175);
	if (e->i.nobj.open != 5)
		draw_close_garbage(e, (e->i.mlx->img_x / 4) - 90, 220);
	else if (e->i.nobj.open == 5)
		draw_open_garbage(e, (e->i.mlx->img_x / 4) - 90, 220);
	if (e->i.nobj.open != 6)
		draw_close_garbage(e, (e->i.mlx->img_x / 4) - 90, 265);
	else if (e->i.nobj.open == 6)
		draw_open_garbage(e, (e->i.mlx->img_x / 4) - 90, 265);
}

void	ft_init_value_create_obj(t_stuff *e, int option)
{
	if (option == 0)
	{
		e->lt.couleur = 0x000000;
		e->bs.x_arc = e->i.mlx->img_x / 2;
		e->bs.y_arc = e->i.mlx->img_y / 2;
		e->bs.ray_arc = 100;
	}
	else if (option == 1)
	{
		e->bs.x_arc = (e->i.mlx->img_x / 2) - 10;
		e->bs.ray_arc = 124;
	}
	else if (option == 2)
	{
		e->bs.x_arc = (e->i.mlx->img_x / 2) + 10;
		e->bs.ray_arc = 124;
	}
	else if (option == 3)
	{
		e->bs.x_arc = e->i.mlx->img_x / 2;
		e->bs.y_arc = e->i.mlx->img_y / 2 - 10;
		e->bs.ray_arc = 124;
	}
	else if (option == 4)
	{
		e->bs.x_arc = e->i.mlx->img_x / 2;
		e->bs.y_arc = e->i.mlx->img_y / 2 + 10;
	}
	else if (option == 5)
	{
		e->bs.x_arc = 0;
		e->bs.y_arc = e->i.mlx->img_y / 2;
		e->bs.ray_arc = 100;
	}
	else if (option == 6)
	{
		e->bs.x_arc = e->i.mlx->img_x;
		e->bs.y_arc = e->i.mlx->img_y / 2;
		e->bs.ray_arc = 100;
	}
	else if (option == 7)
	{
		e->lt.couleur = 0xFFFFFF;
		e->bs.xi = (e->i.mlx->img_x / 2) + 50;
		e->bs.yi = (e->i.mlx->img_y / 2) + 25;
		e->bs.xf = e->bs.xi;
		e->bs.yf = e->bs.yi - 50;
	}
	else if (option == 8)
	{
		e->bs.xi = (e->i.mlx->img_x / 2) + 50;
		e->bs.yi = (e->i.mlx->img_y / 2) + 25;
		e->bs.xf = e->bs.xi - 75;
		e->bs.yf = e->bs.yi;
	}
	else if (option == 9)
	{
		e->bs.xi = e->bs.xf;
		e->bs.yi = e->bs.yf;
		e->bs.xf = e->bs.xi;
		e->bs.yf = e->bs.yi - 50;
	}
	else if (option == 10)
	{
		e->bs.xi = e->bs.xf;
		e->bs.yi = e->bs.yf;
		e->bs.xf = e->bs.xi + 75;
		e->bs.yf = e->bs.yi;
	}
	else if (option == 11)
	{
		e->bs.x_arc = e->bs.xf - (75 / 5);
		e->bs.y_arc = e->bs.yf - 30;
		e->bs.ray_arc = 20;
	}
	else if (option == 12)
		e->bs.ray_arc = 5;
	else if (option == 13)
	{
		e->bs.x_arc = e->bs.xf - ((75 / 5) * 4);
		e->bs.y_arc = e->bs.yf - 30;
		e->bs.ray_arc = 20;
	}
	else if (option == 14)
	{
		e->bs.xi = e->bs.xf + 5;
		e->bs.yi = e->bs.yf + ((50 / 5) * 2);
		e->bs.xf = e->bs.xi;
		e->bs.yf = e->bs.yi - 10;
	}
	else if (option == 15)
	{
		e->bs.xi = e->bs.xf;
		e->bs.yi = e->bs.yf;
		e->bs.xf = e->bs.xi + 10;
		e->bs.yf = e->bs.yi;
	}
	else if (option == 16)
	{
		e->bs.x_arc = e->bs.xf + 7;
		e->bs.y_arc = e->bs.yf + 5;
		e->bs.ray_arc = 8;
	}
	else if (option == 17)
	{
		e->bs.xi = e->bs.x_arc;
		e->bs.yi = e->bs.y_arc - e->bs.ray_arc;
		e->bs.xf = e->bs.xi;
		e->bs.yf = e->bs.yi + (2 * e->bs.ray_arc);
	}
	else if (option == 18)
	{
		e->bs.xi = (e->i.mlx->img_x / 2) + 55;
		e->bs.yi = (e->i.mlx->img_y / 2) - 25 + ((50 / 5) * 2);
		e->bs.xf = e->bs.xi + 10;
		e->bs.yf = e->bs.yi;
	}
	else if (option == 19)
	{
		e->bs.xi = (e->i.mlx->img_x / 2) - 25;
		e->bs.yi = (e->i.mlx->img_y / 2) + 9;
		e->bs.xf = e->bs.xi - 5;
		e->bs.yf = e->bs.yi;
	}
	else if (option == 20)
	{
		e->bs.xi = e->bs.xf;
		e->bs.yi = e->bs.yf;
		e->bs.xf = e->bs.xi;
		e->bs.yf = e->bs.yi - 17;
	}
	else if (option == 21)
	{
		ft_init_value_create_obj(e, 19);
		e->bs.xi = e->bs.xf - 5;
		e->bs.yi = e->bs.yf;
		e->bs.xf = e->bs.xi;
		e->bs.yf = e->bs.yi - 17;
	}
	else if (option == 22)
	{
		e->bs.xi = e->bs.xf;
		e->bs.yi = e->bs.yf + 17;
		e->bs.xf = e->bs.xi - 15;
		e->bs.yf = e->bs.yi;
	}
	else if (option == 23)
	{
		e->bs.xi = e->bs.xf;
		e->bs.yi = e->bs.yf;
		e->bs.yf = e->bs.yi - 17;
	}
	else if (option == 24)
	{
		e->bs.xi = e->bs.xf - 5;
		e->bs.yi = e->bs.yf + 17;
		e->bs.xf = e->bs.xi;
		e->bs.yf = e->bs.yi - 17;
	}
	else if (option == 25)
	{
		e->bs.xi = e->bs.xf;
		e->bs.yi = e->bs.yf + 17;
		e->bs.xf = e->bs.xi - 20;
		e->bs.yf = e->bs.yi + 14;
	}
	else if (option == 26)
	{
		e->bs.xi = e->bs.xf;
		e->bs.yi = e->bs.yf;
		e->bs.xf = e->bs.xi;
		e->bs.yf = e->bs.yi - 45;
	}
	else if (option == 27)
	{
		e->bs.xf = e->bs.xf + 20;
		e->bs.yf = e->bs.yf + 14;
	}
	else if (option == 28)
	{
		e->bs.xi = e->bs.xf + 5;
		e->bs.yi = e->bs.yf;
		e->bs.xf = e->bs.xi + 15;
		e->bs.yf = e->bs.yi;
	}
	else if (option == 29)
	{
		e->bs.xi = e->bs.xf + 5;
		e->bs.yi = e->bs.yf;
		e->bs.xf = e->bs.xi + 5;
		e->bs.yf = e->bs.yi;
	}
	else if (option == 30)
	{
		ft_init_value_create_obj(e, 7);
		e->bs.xi = e->bs.xi - (75 / 4);
		e->bs.yi = e->bs.yi + 5;
		e->bs.xf = e->bs.xi;
		e->bs.yf = e->bs.yi + 10;
	}
	else if (option == 31)
	{
		ft_init_value_create_obj(e, 30);
		e->bs.xf = e->bs.xi - ((75 / 4) * 2);
		e->bs.yf = e->bs.yi;
	}
	else if (option == 32)
		e->bs.yf = e->bs.yf + 10;
	else if (option == 33)
	{
		e->bs.xi = e->bs.xf;
		e->bs.yi = e->bs.yf;
		e->bs.xf = e->bs.xi + ((75 / 4) * 2);
	}
	else if (option == 34)
	{
		e->bs.x_arc = e->bs.xf - (75 / 4);
		e->bs.y_arc = e->bs.yf;
		e->bs.ray_arc = 8;
	}
	else if (option == 35)
	{
		e->bs.xi = e->bs.xf - 2;
		e->bs.yi = e->bs.yf;
		e->bs.xf = e->bs.xi + 10;
		e->bs.yf = e->bs.yi + 10;
	}
	else if (option == 36)
	{
		e->bs.xi = e->bs.xf - 8;
		e->bs.yi = e->bs.yf - 13;
		e->bs.xf = e->bs.xi + 11;
		e->bs.yf = e->bs.yi + 10;
	}
	else if (option == 37)
	{
		e->bs.x_arc = e->bs.xf;
		e->bs.y_arc = e->bs.yf + 4;
		e->bs.ray_arc = 3;
	}
	else if (option == 38)
	{
		ft_init_value_create_obj(e, 30);
		e->bs.xi = e->bs.xf - (75 / 4);
		e->bs.yi = e->bs.yf + 8;
		e->bs.xf = e->bs.xi + 30;
		e->bs.yf = e->bs.yi + 30;
	}
	else if (option == 39)
	{
		ft_init_value_create_obj(e, 38);
		e->bs.xf = e->bs.xi - 30;
		e->bs.yf = e->bs.yi + 30;
	}
	else if (option == 40)
	{
		ft_init_value_create_obj(e, 38);
		e->bs.xf = e->bs.xi;
		e->bs.yf = e->bs.yi + 20;
	}
}

void	draw_obj(t_stuff *e)
{
	if (e->i.objet == -1)
	{
		ft_init_value_create_obj(e, 7);
		ft_segment_letter(e);
		ft_init_value_create_obj(e, 8);
		ft_segment_letter(e);
		ft_init_value_create_obj(e, 9);
		ft_segment_letter(e);
		ft_init_value_create_obj(e, 10);
		ft_segment_letter(e);
		ft_init_value_create_obj(e, 11);
		ft_arc(e, 9);
		ft_init_value_create_obj(e, 12);
		ft_arc(e, 9);
		ft_init_value_create_obj(e, 13);
		ft_arc(e, 9);
		ft_init_value_create_obj(e, 12);
		ft_arc(e, 9);
		ft_init_value_create_obj(e, 14);
		ft_segment_letter(e);
		ft_init_value_create_obj(e, 15);
		ft_segment_letter(e);
		ft_init_value_create_obj(e, 16);
		ft_arc(e, 2);
		ft_init_value_create_obj(e, 17);
		ft_segment_letter(e);
		ft_init_value_create_obj(e, 18);
		ft_segment_letter(e);
		ft_init_value_create_obj(e, 19);
		ft_segment_letter(e);
		ft_init_value_create_obj(e, 20);
		ft_segment_letter(e);
		ft_init_value_create_obj(e, 21);
		ft_segment_letter(e);
		ft_init_value_create_obj(e, 22);
		ft_segment_letter(e);
		ft_init_value_create_obj(e, 23);
		ft_segment_letter(e);
		ft_init_value_create_obj(e, 24);
		ft_segment_letter(e);
		ft_init_value_create_obj(e, 25);
		ft_segment_letter(e);
		ft_init_value_create_obj(e, 26);
		ft_segment_letter(e);
		ft_init_value_create_obj(e, 27);
		ft_segment_letter(e);
		ft_init_value_create_obj(e, 28);
		ft_segment_letter(e);
		ft_init_value_create_obj(e, 29);
		ft_segment_letter(e);
		ft_init_value_create_obj(e, 30);
		ft_segment_letter(e);
		ft_init_value_create_obj(e, 31);
		ft_segment_letter(e);
		ft_init_value_create_obj(e, 32);
		ft_segment_letter(e);
		ft_init_value_create_obj(e, 33);
		ft_segment_letter(e);
		ft_init_value_create_obj(e, 34);
		ft_arc(e, 4);
		ft_init_value_create_obj(e, 35);
		ft_segment_letter(e);
		ft_init_value_create_obj(e, 36);
		ft_segment_letter(e);
		ft_init_value_create_obj(e, 37);
		ft_arc(e, 9);
		ft_init_value_create_obj(e, 38);
		ft_segment_letter(e);
		ft_init_value_create_obj(e, 39);
		ft_segment_letter(e);
		ft_init_value_create_obj(e, 40);
		ft_segment_letter(e);
	}
}

void	draw_central(t_stuff *e)
{
	int		i;

	i = -1;
	ft_init_value_create_obj(e, 0);
	if (e->i.nobj.power == 0)
	{
		ft_arc(e, 9);
		while (e->bs.ray_arc > 0)
		{
			e->bs.ray_arc--;
			e->bs.x_arc--;
			ft_arc(e, 9);
		}
		ft_init_value_create_obj(e, 0);
		while (e->bs.ray_arc > 0)
		{
			e->bs.ray_arc--;
			e->bs.x_arc++;
			ft_arc(e, 9);
		}
	}
	else if (e->i.nobj.power == 1)
	{
		while (--e->bs.ray_arc >= 0)
		{
			ft_arc(e, 9);
			e->bs.x_arc--;
			ft_arc(e, 9);
			e->bs.x_arc++;
		}
	}
	ft_init_value_create_obj(e, 1);
	while (++i < 5)
	{
		ft_arc(e, 10);
		e->bs.x_arc--;
	}
	ft_init_value_create_obj(e, 2);
	i = -1;
	while (++i < 5)
	{
		ft_arc(e, 11);
		e->bs.x_arc++;
	}
	ft_init_value_create_obj(e, 3);
	i = -1;
	while (++i < 5)
	{
		ft_arc(e, 12);
		e->bs.y_arc--;
	}
	ft_init_value_create_obj(e, 4);
	i = -1;
	while (++i < 5)
	{
		ft_arc(e, 13);
		e->bs.y_arc++;
	}
}

void	draw_del(t_stuff *e)
{
	ft_init_value_create_obj(e, 5);
	if (e->i.nobj.power == 0)
	{
		while (--e->bs.x_arc >= -100)
		{
			ft_arc(e, 1);
			e->bs.ray_arc--;
		}
	}
	else if (e->i.nobj.power == 1)
	{
		while (--e->bs.x_arc >= -100)
		{
			ft_arc(e, 1);
		}
	}
}

void	draw_add(t_stuff *e)
{
	ft_init_value_create_obj(e, 6);
	if (e->i.nobj.power == 0)
	{
		while (++e->bs.x_arc <= e->i.mlx->img_x + 100)
		{
			ft_arc(e, 2);
			e->bs.ray_arc--;
		}
	}
	else if (e->i.nobj.power == 1)
	{
		while (++e->bs.x_arc <= e->i.mlx->img_x + 100)
			ft_arc(e, 2);
	}
}

void	create_obj(t_stuff *e)
{
	if (e->i.first == 0)
	{
		e->i.img_x = WIN_X - WIDTH;
		e->i.img_y = WIN_Y - LENGTH;
		new_img(e);
		init_struct(e, 3);
	}
	else
	{
		reboot_list_interface(e, 1);
		searchlist_interface(e, 2);
	}
	draw_new_obj(e);
	draw_central(e);
	draw_del(e);
	draw_add(e);
	if (e->i.nobj.power == 1)
	{
		draw_obj(e);
		// draw_garbage(e);
		// draw_plus(e);
	}
	// draw_arrow(e);
	// name_new_obj(e);
	// add_obj(e);
	// del_obj(e);
	mlx_put_image_to_window(e->img.mlx_ptr, e->img.win_ptr, e->i.mlx->img, 0, WIN_Y - LENGTH + WIN_Y - LENGTH);
}
