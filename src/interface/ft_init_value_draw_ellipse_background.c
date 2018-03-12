/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_value_draw_ellipse_background.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Awk-LM <Awk-LM@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:37:22 by Awk-LM            #+#    #+#             */
/*   Updated: 2018/03/12 10:26:33 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_init_value_draw_ellipse_background(t_stuff *e, int option)
{
	//GROSSE ELLIPSE HAUT : POSITION
	if (option == 0)
	{
		e->lt.couleur = e->i.color.cobj.col2;
		e->bs.x_arc = e->i.mlx->img_x / 2;
		e->bs.y_arc = 49;
		e->bs.height = 44;
		e->bs.width = 150;
	}
	//GROSSE ELLIPSE MILIEU : DIRECTION
	if (option == 1)
	{
		e->lt.couleur = e->i.color.cobj.col2;
		e->bs.x_arc = e->i.mlx->img_x / 2;
		e->bs.y_arc = e->i.mlx->img_y / 2;
		e->bs.height = 44;
		e->bs.width = 150;
	}
	//GROSSE ELLIPSE BAS : COULEUR
	if (option == 2)
	{
		e->lt.couleur = e->i.color.cobj.col2;
		e->bs.x_arc = e->i.mlx->img_x / 2;
		e->bs.y_arc = WIN_Y - LENGTH - 49;
		e->bs.height = 44;
		e->bs.width = 150;
	}
	//PETITE ELLIPSE HAUT GAUCHE : RAYON / ANGLE
	if (option == 3)
	{
		e->lt.couleur = e->i.color.cobj.col2;
		e->bs.x_arc = 75;
		e->bs.y_arc = 94;
		e->bs.height = 30;
		e->bs.width = 75;
	}
	//PETITE ELLIPSE BAS GAUCHE : Ambiant / refrac
	if (option == 4)
	{
		e->lt.couleur = e->i.color.cobj.col2;
		e->bs.x_arc = 75;
		e->bs.y_arc = WIN_Y - LENGTH - 94;
		e->bs.height = 30;
		e->bs.width = 75;
	}
	//PETITE ELLIPSE HAUT DROITE : diffu / reflex
	if (option == 5)
	{
		e->lt.couleur = e->i.color.cobj.col2;
		e->bs.x_arc = WIN_X - WIDTH - 75;
		e->bs.y_arc = 94;
		e->bs.height = 30;
		e->bs.width = 75;
	}
	//PETITE ELLIPSE BAS DROITE : conscol
	if (option == 6)
	{
		e->lt.couleur = e->i.color.cobj.col2;
		e->bs.x_arc = WIN_X - WIDTH - 75;
		e->bs.y_arc = WIN_Y - LENGTH - 94;
		e->bs.height = 30;
		e->bs.width = 75;
	}
}
