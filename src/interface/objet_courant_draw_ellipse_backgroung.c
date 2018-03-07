/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objet_courant_draw_ellipse_backgroung.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Awk-LM <Awk-LM@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:36:47 by Awk-LM            #+#    #+#             */
/*   Updated: 2018/03/05 14:15:18 by Awk-LM           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	draw_ellipse_background(t_stuff *e)
{
	ft_init_value_draw_ellipse_background(e, 0);
	ft_ellipse(e, 0, 0);
	while (e->bs.height > 0)
	{
		e->bs.height--;
		ft_ellipse(e, 0, 0);
	}
	while (e->bs.width > 1)
	{
		e->bs.width--;
		ft_ellipse(e, 0, 0);
	}
}
