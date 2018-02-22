/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 10:39:00 by prossi            #+#    #+#             */
/*   Updated: 2018/02/22 00:08:43 by Awk-LM           ###   ########.fr       */
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

void	draw_obj(t_stuff *e)
{
	if (e->i.objet == -1)
		draw_camera(e);
	else
		draw_objects(e);
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
	draw_central_background(e);
	draw_side_background(e);
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
