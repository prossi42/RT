/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_value_aff_data_plan_sd.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 14:40:17 by prossi            #+#    #+#             */
/*   Updated: 2018/03/12 10:25:46 by mdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_init_value_aff_data_plan_svth(t_stuff *e, int option)
{
	if (option == 20)
	{
		e->lt.posx = WIN_X - WIDTH - 93;
		e->lt.posy = WIN_Y - LENGTH - 87;
		e->lt.coeff = 0.30;
	}
}

void	ft_init_value_aff_data_plan_sth(t_stuff *e, int option, int len)
{
	if (option == 17)
	{
		e->lt.couleur = 0x0000FF;
		e->lt.posx = 250 - (len * 10);
		e->lt.posy = 263;
		e->lt.coeff = 0.30;
	}
	if (option == 18)
	{
		e->lt.couleur = e->i.color.cobj.col3;
		e->lt.posx = 57 - (len * 6);
		e->lt.posy = WIN_Y - LENGTH - 87;
		e->lt.coeff = 0.30;
	}
	if (option == 19)
	{
		e->lt.posx = WIN_X - WIDTH - 93;
		e->lt.posy = 100;
		e->lt.coeff = 0.30;
	}
	ft_init_value_aff_data_plan_svth(e, option);
}
