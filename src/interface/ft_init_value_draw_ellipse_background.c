/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_value_draw_ellipse_background.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Awk-LM <Awk-LM@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:37:22 by Awk-LM            #+#    #+#             */
/*   Updated: 2018/03/05 14:45:12 by Awk-LM           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_init_value_draw_ellipse_background(t_stuff *e, int option)
{
	if (option == 0)
	{
		e->lt.couleur = 0x000000;
		e->bs.x_arc = e->i.img_x / 2;
		e->bs.y_arc = e->i.img_y / 2;
		e->bs.height = 130;
		e->bs.width = 240;
	}
}
