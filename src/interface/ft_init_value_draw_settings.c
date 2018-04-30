/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_value_draw_settings.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 10:35:30 by prossi            #+#    #+#             */
/*   Updated: 2018/03/14 10:36:15 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_init_value_draw_settings(t_stuff *e, int option)
{
	if (option == 0)
	{
		e->lt.posx = e->i.mlx->img_x - 20;
		e->lt.posy = 20;
		e->lt.couleur = 0xFFFFFF;
		e->lt.coeff = 1;
	}
}
