/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_value_objet_courant_color.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:01:27 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 10:01:28 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_init_value_objet_courant_color_td(t_stuff *e, int option)
{
	if (option == 6)
	{
		e->lt.posx = 250;
		e->lt.posy = 250;
		e->bs.width = 70;
		e->bs.height = 40;
		e->lt.coeff = 1;
		e->lt.couleur = e->i.color.cobj.col3;
	}
}

void	ft_init_value_objet_courant_color_sd(t_stuff *e, int option)
{
	if (option == 4)
	{
		e->lt.posx = 250;
		e->lt.posy = 110;
		e->bs.width = 70;
		e->bs.height = 40;
		e->lt.coeff = 1;
		e->lt.couleur = 0x000000;
	}
	if (option == 5)
	{
		e->lt.posx = 250;
		e->lt.posy = 180;
		e->bs.width = 70;
		e->bs.height = 40;
		e->lt.coeff = 1;
		e->lt.couleur = e->i.color.cobj.col2;
	}
	ft_init_value_objet_courant_color_td(e, option);
}

void	ft_init_value_objet_courant_color(t_stuff *e, int option)
{
	if (option == 0)
	{
		e->lt.posx = 90;
		e->lt.posy = 50;
		e->lt.couleur = e->i.color.cobj.col3;
		e->lt.coeff = 0.50;
		e->lt.space = 40;
	}
	if (option == 1)
	{
		e->lt.posx = 160;
		e->lt.posy = 100;
		e->lt.coeff = 0.35;
	}
	if (option == 2)
	{
		e->lt.posx = 152;
		e->lt.posy = 170;
	}
	if (option == 3)
	{
		e->lt.posx = 145;
		e->lt.posy = 240;
	}
	ft_init_value_objet_courant_color_sd(e, option);
}
