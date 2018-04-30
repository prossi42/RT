/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_value_aff_data_sphere.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 14:40:37 by prossi            #+#    #+#             */
/*   Updated: 2018/03/12 10:26:02 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_init_value_aff_data_sphere_fvth(t_stuff *e, int option, int len)
{
	if (option == 12)
	{
		e->lt.couleur = e->i.color.cobj.col3;
		e->lt.posx = 50 - (len * 6);
		e->lt.posy = 100;
		e->lt.coeff = 0.30;
	}
	if (option == 13)
	{
		e->lt.posx = 57 - (len * 6);
		e->lt.posy = WIN_Y - LENGTH - 87;
		e->lt.coeff = 0.30;
	}
	if (option == 14)
	{
		e->lt.posx = WIN_X - WIDTH - 93;
		e->lt.posy = 100;
		e->lt.coeff = 0.30;
	}
	if (option == 15)
	{
		e->lt.posx = WIN_X - WIDTH - 93;
		e->lt.posy = WIN_Y - LENGTH - 87;
		e->lt.coeff = 0.30;
	}
}

void	ft_init_value_aff_data_sphere_fth(t_stuff *e, int option, int len)
{
	if (option == 9)
	{
		e->lt.couleur = 0x00FF00;
		e->lt.posx = 250 - (len * 10);
		e->lt.posy = 236;
		e->lt.coeff = 0.30;
	}
	if (option == 10)
	{
		e->lt.couleur = e->i.color.cobj.col3;
		e->lt.posx = 230 - (len * 10);
		e->lt.posy = 261;
		e->lt.coeff = 0.25;
	}
	if (option == 11)
	{
		e->lt.couleur = 0x0000FF;
		e->lt.posx = 250 - (len * 10);
		e->lt.posy = 263;
		e->lt.coeff = 0.30;
	}
	ft_init_value_aff_data_sphere_fvth(e, option, len);
}

void	ft_init_value_aff_data_sphere_td(t_stuff *e, int option, int len)
{
	if (option == 6)
	{
		e->lt.posx = 230 - (len * 10);
		e->lt.posy = 209;
		e->lt.coeff = 0.25;
	}
	if (option == 7)
	{
		e->lt.couleur = 0xFF0000;
		e->lt.posx = 250 - (len * 10);
		e->lt.posy = 211;
		e->lt.coeff = 0.30;
	}
	if (option == 8)
	{
		e->lt.couleur = e->i.color.cobj.col3;
		e->lt.posx = 230 - (len * 10);
		e->lt.posy = 235;
		e->lt.coeff = 0.25;
	}
	ft_init_value_aff_data_sphere_fth(e, option, len);
}

void	ft_init_value_aff_data_sphere_sd(t_stuff *e, int option, int len)
{
	if (option == 3)
	{
		e->lt.posx = 250 - (len * 10);
		e->lt.posy = 55;
		e->lt.coeff = 0.30;
		e->lt.space = 40;
	}
	if (option == 4)
	{
		e->lt.posx = 230 - (len * 10);
		e->lt.posy = 78;
		e->lt.coeff = 0.25;
		e->lt.space = 40;
	}
	if (option == 5)
	{
		e->lt.posx = 250 - (len * 10);
		e->lt.posy = 80;
		e->lt.coeff = 0.30;
		e->lt.couleur = e->i.color.cobj.col3;
		e->lt.space = 40;
	}
	ft_init_value_aff_data_sphere_td(e, option, len);
}

void	ft_init_value_aff_data_sphere(t_stuff *e, int option, int len)
{
	if (len < 0)
		len = 0;
	if (option == 0)
	{
		e->lt.posx = 230 - (len * 10);
		e->lt.posy = 28;
		e->lt.coeff = 0.25;
		e->lt.couleur = e->i.color.cobj.col3;
		e->lt.space = 40;
	}
	if (option == 1)
	{
		e->lt.posx = 250 - (len * 10);
		e->lt.posy = 30;
		e->lt.coeff = 0.30;
		e->lt.space = 40;
	}
	if (option == 2)
	{
		e->lt.posx = 230 - (len * 10);
		e->lt.posy = 54;
		e->lt.coeff = 0.25;
		e->lt.space = 40;
	}
	ft_init_value_aff_data_sphere_sd(e, option, len);
}
