/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ellipse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Awk-LM <Awk-LM@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 08:15:48 by Awk-LM            #+#    #+#             */
/*   Updated: 2018/02/22 18:09:54 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	select_part_height(t_stuff *e, int x, int y, int option)
{
	//HAUT ET BAS
	if (option == 0)
	{
		pixel_put_to_img(&e->i.mlx, e->bs.x_arc + x, e->bs.y_arc + y, e->lt.couleur);
		pixel_put_to_img(&e->i.mlx, e->bs.x_arc - x, e->bs.y_arc + y, e->lt.couleur);
		pixel_put_to_img(&e->i.mlx, e->bs.x_arc + x, e->bs.y_arc - y, e->lt.couleur);
		pixel_put_to_img(&e->i.mlx, e->bs.x_arc - x, e->bs.y_arc - y, e->lt.couleur);
	}
	// HAUT
	else if (option == 1)
	{
		pixel_put_to_img(&e->i.mlx, e->bs.x_arc + x, e->bs.y_arc - y, e->lt.couleur);
		pixel_put_to_img(&e->i.mlx, e->bs.x_arc - x, e->bs.y_arc - y, e->lt.couleur);
	}
	// BAS
	else if (option == 2)
	{
		pixel_put_to_img(&e->i.mlx, e->bs.x_arc + x, e->bs.y_arc + y, e->lt.couleur);
		pixel_put_to_img(&e->i.mlx, e->bs.x_arc - x, e->bs.y_arc + y, e->lt.couleur);
	}
	// HAUT GAUCHE
	else if (option == 3)
		pixel_put_to_img(&e->i.mlx, e->bs.x_arc - x, e->bs.y_arc - y, e->lt.couleur);
	// HAUT DROITE
	else if (option == 4)
		pixel_put_to_img(&e->i.mlx, e->bs.x_arc + x, e->bs.y_arc - y, e->lt.couleur);
	// BAS GAUCHE
	else if (option == 5)
		pixel_put_to_img(&e->i.mlx, e->bs.x_arc - x, e->bs.y_arc + y, e->lt.couleur);
	// BAS DROITE
	else if (option == 6)
		pixel_put_to_img(&e->i.mlx, e->bs.x_arc + x, e->bs.y_arc + y, e->lt.couleur);
}

void	select_part_width(t_stuff *e, int x, int y, int option)
{
	//GAUCHE ET DROITE
	if (option == 0)
	{
		pixel_put_to_img(&e->i.mlx, e->bs.x_arc + x, e->bs.y_arc + y, e->lt.couleur);
		pixel_put_to_img(&e->i.mlx, e->bs.x_arc - x, e->bs.y_arc + y, e->lt.couleur);
		pixel_put_to_img(&e->i.mlx, e->bs.x_arc + x, e->bs.y_arc - y, e->lt.couleur);
		pixel_put_to_img(&e->i.mlx, e->bs.x_arc - x, e->bs.y_arc - y, e->lt.couleur);
	}
	// GAUCHE
	else if (option == 1)
	{
		pixel_put_to_img(&e->i.mlx, e->bs.x_arc - x, e->bs.y_arc + y, e->lt.couleur);
		pixel_put_to_img(&e->i.mlx, e->bs.x_arc - x, e->bs.y_arc - y, e->lt.couleur);
	}
	// DROITE
	else if (option == 2)
	{
		pixel_put_to_img(&e->i.mlx, e->bs.x_arc + x, e->bs.y_arc + y, e->lt.couleur);
		pixel_put_to_img(&e->i.mlx, e->bs.x_arc + x, e->bs.y_arc - y, e->lt.couleur);
	}
	// HAUT GAUCHE
	else if (option == 3)
		pixel_put_to_img(&e->i.mlx, e->bs.x_arc - x, e->bs.y_arc - y, e->lt.couleur);
	// BAS GAUCHE
	else if (option == 4)
		pixel_put_to_img(&e->i.mlx, e->bs.x_arc - x, e->bs.y_arc + y, e->lt.couleur);
	// HAUT DROITE
	else if (option == 5)
		pixel_put_to_img(&e->i.mlx, e->bs.x_arc + x, e->bs.y_arc - y, e->lt.couleur);
	// BAS DROITE
	else if (option == 6)
		pixel_put_to_img(&e->i.mlx, e->bs.x_arc + x, e->bs.y_arc + y, e->lt.couleur);
}

void	ft_ellipse(t_stuff *e, int piece, int option)
{
	int		a2;
	int		b2;
	int		fa2;
	int		fb2;
	int		x;
	int		y;
	int		sigma;

	a2 = e->bs.width * e->bs.width;
	b2 = e->bs.height * e->bs.height;
	fa2 = 4 * a2;
	fb2 = 4 * b2;
	x = 0;
	y = e->bs.height;
	sigma = (2 * b2) + (a2 * (1 - (2 * e->bs.height)));
	while (b2 * x <= a2 * y)
	{
		if (piece == 0 || piece == 1)
			select_part_height(e, x, y, option);
		if (sigma >= 0)
		{
			sigma += fa2 * (1 - y);
			y--;
		}
		sigma += b2 * ((4 * x) + 6);
		x++;
	}
	x = e->bs.width;
	y = 0;
	sigma = (2 * a2) + (b2 * (1 - (2 * e->bs.width)));
	while (a2 * y <= b2 * x)
	{
		if (piece == 0 || piece == 2)
			select_part_width(e, x, y, option);
		if (sigma >= 0)
		{
			sigma += fb2 * (1 - x);
			x--;
		}
		sigma += a2 * ((4 * y) + 6);
		y++;
	}
}
