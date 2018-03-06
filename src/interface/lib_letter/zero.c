/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Awk-LM <Awk-LM@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 00:06:07 by Awk-LM            #+#    #+#             */
/*   Updated: 2018/03/06 00:15:26 by Awk-LM           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_init_value_zero(t_stuff *e, int option)
{
	if (option == 0)
	{
		e->bs.x_arc = e->lt.posx + (12.5 * e->lt.coeff);
		e->bs.y_arc = e->lt.posy - (25 * e->lt.coeff);
		e->bs.width = 12.5 * e->lt.coeff;
		e->bs.height = 25 * e->lt.coeff;
	}
}

void	zero(t_stuff *e)
{
	ft_init_value_zero(e, 0);
	ft_ellipse(e, 0, 0);
	e->bs.width--;
	ft_ellipse(e, 0, 0);
	e->bs.width--;
	ft_ellipse(e, 0, 0);
}
