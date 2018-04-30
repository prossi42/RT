/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_interface_redraw_ellipse.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 16:40:51 by prossi            #+#    #+#             */
/*   Updated: 2018/04/13 16:45:35 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	redraw_ellipse_td(t_stuff *e, int couleur)
{
	if (e->i.mat.act_xyz == 2)
	{
		ft_init_value_draw_ellipse_background(e, 11);
		e->lt.couleur = couleur;
		ft_arc(e, 9);
	}
	if (e->i.mat.act_xyz == 3)
	{
		ft_init_value_draw_ellipse_background(e, 13);
		e->lt.couleur = couleur;
		ft_arc(e, 9);
	}
}

void	redraw_ellipse_sd(t_stuff *e, int couleur)
{
	if (e->i.mat.dir_or_pos == 1)
	{
		ft_init_value_draw_ellipse_background(e, 10);
		e->lt.couleur = couleur;
		ft_ellipse(e, 0, 0);
	}
	if (e->i.mat.dir_or_pos == 2)
	{
		ft_init_value_draw_ellipse_background(e, 9);
		e->lt.couleur = couleur;
		ft_ellipse(e, 0, 0);
	}
	if (e->i.mat.act_xyz == 1)
	{
		ft_init_value_draw_ellipse_background(e, 12);
		e->lt.couleur = couleur;
		ft_arc(e, 9);
	}
	redraw_ellipse_td(e, couleur);
}

void	redraw_ellipse(t_stuff *e)
{
	int		couleur;

	if (e->i.color.mat.col2 > 0x000000 && e->i.color.mat.col2 <= 0xFFFFFF / 2)
		couleur = e->i.color.mat.col2 + (0xFFFFFF / 2);
	else if (e->i.color.mat.col2 <= 0xFFFFFF && e->i.color.mat.col2 >= \
		0xFFFFFF / 2)
		couleur = e->i.color.mat.col2 - (0xFFFFFF / 2);
	else
		couleur = 0xFFFFFF;
	if (e->i.mat.act_rot != -1)
	{
		ft_init_value_draw_ellipse_background(e, 7);
		e->lt.couleur = couleur;
		ft_ellipse(e, 0, 0);
	}
	if (e->i.mat.act_trans != -1)
	{
		ft_init_value_draw_ellipse_background(e, 8);
		e->lt.couleur = couleur;
		ft_ellipse(e, 0, 0);
	}
	redraw_ellipse_sd(e, couleur);
}
