/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_value_aff_data_camera.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Awk-LM <Awk-LM@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 16:31:05 by Awk-LM            #+#    #+#             */
/*   Updated: 2018/03/12 10:24:42 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_init_value_aff_data_camera(t_stuff *e, int option, int len)
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
	}
	if (option == 2)
	{
		e->lt.posx = 230 - (len * 10);
		e->lt.posy = 54;
		e->lt.coeff = 0.25;
	}
	if (option == 3)
	{
		e->lt.posx = 250 - (len * 10);
		e->lt.posy = 55;
		e->lt.coeff = 0.30;
	}
	if (option == 4)
	{
		e->lt.posx = 230 - (len * 10);
		e->lt.posy = 78;
		e->lt.coeff = 0.25;
	}
	if (option == 5)
	{
		e->lt.posx = 250 - (len * 10);
		e->lt.posy = 80;
		e->lt.coeff = 0.30;
	}
	if (option == 6)
	{
		e->lt.posx = 230 - (len * 10);
		e->lt.posy = 119;
		e->lt.coeff = 0.25;
	}
	if (option == 7)
	{
		e->lt.posx = 250 - (len * 10);
		e->lt.posy = 121;
		e->lt.coeff = 0.30;
	}
	if (option == 8)
	{
		e->lt.posx = 230 - (len * 10);
		e->lt.posy = 145;
		e->lt.coeff = 0.25;
	}
	if (option == 9)
	{
		e->lt.posx = 250 - (len * 10);
		e->lt.posy = 146;
		e->lt.coeff = 0.30;
	}
	if (option == 10)
	{
		e->lt.posx = 230 - (len * 10);
		e->lt.posy = 171;
		e->lt.coeff = 0.25;
	}
	if (option == 11)
	{
		e->lt.posx = 250 - (len * 10);
		e->lt.posy = 173;
		e->lt.coeff = 0.30;
	}
}
