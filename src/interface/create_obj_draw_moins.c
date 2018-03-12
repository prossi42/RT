/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_obj_draw_moins.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Awk-LM <Awk-LM@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 10:22:49 by Awk-LM            #+#    #+#             */
/*   Updated: 2018/03/12 10:27:52 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	draw_moins_sd(t_stuff *e)
{
	int		i;

	i = -1;
	ft_init_value_draw_moins(e, 0);
	e->lt.couleur = e->i.color.nobj.col1;
	ft_segment_letter(e);
	while (++i < 10)
	{
		ft_init_value_draw_moins(e, 1);
		ft_segment_letter(e);
	}
	ft_init_value_draw_moins(e, 2);
	ft_segment_letter(e);
	i = -1;
	while (++i < 10)
	{
		ft_init_value_draw_moins(e, 3);
		ft_segment_letter(e);
	}
}

void	draw_moins(t_stuff *e)
{
	int		i;

	i = -1;
	if (e->i.nobj.open != 1)
	{
		ft_init_value_draw_moins(e, 0);
		ft_segment_letter(e);
		while (++i < 10)
		{
			ft_init_value_draw_moins(e, 1);
			ft_segment_letter(e);
		}
	}
	else if (e->i.nobj.open == 1)
		draw_moins_sd(e);
}
