/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CC.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 14:00:43 by prossi            #+#    #+#             */
/*   Updated: 2018/03/08 14:39:13 by Awk-LM           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/rt.h"

void	ft_init_segment_C(t_stuff *e, int option)
{
	if (option == 1)
	{
		e->bs.x_arc = e->lt.posx + (25 * e->lt.coeff);
		e->bs.y_arc = e->lt.posy - (25 * e->lt.coeff);
		e->bs.width = 25 * e->lt.coeff;
		e->bs.height = 25 * e->lt.coeff;
	}
}

void	C(t_stuff *e)
{
	ft_init_segment_C(e, 1);
	ft_ellipse(e, 2, 1);
	ft_ellipse(e, 1, 3);
	ft_ellipse(e, 1, 5);
	e->bs.width--;
	e->bs.height--;
	ft_ellipse(e, 2, 1);
	ft_ellipse(e, 1, 3);
	ft_ellipse(e, 1, 5);
	e->bs.width--;
	e->bs.height--;
	ft_ellipse(e, 2, 1);
	ft_ellipse(e, 1, 3);
	ft_ellipse(e, 1, 5);
}
