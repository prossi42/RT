/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_obj_draw_plus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Awk-LM <Awk-LM@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 11:59:06 by Awk-LM            #+#    #+#             */
/*   Updated: 2018/03/12 10:29:06 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	draw_plus_td(t_stuff *e)
{
	int		i;

	i = -1;
	ft_init_value_draw_plus(e, 4);
	ft_segment_letter(e);
	while (++i < 10)
	{
		ft_init_value_draw_plus(e, 5);
		ft_segment_letter(e);
	}
	ft_init_value_draw_plus(e, 6);
	ft_segment_letter(e);
	i = -1;
	while (++i < 10)
	{
		ft_init_value_draw_plus(e, 7);
		ft_segment_letter(e);
	}
}

void	draw_plus_sd(t_stuff *e)
{
	int		i;

	i = -1;
	ft_init_value_draw_plus(e, 0);
	e->lt.couleur = e->i.color.nobj.col1;
	ft_segment_letter(e);
	while (++i < 10)
	{
		ft_init_value_draw_plus(e, 1);
		ft_segment_letter(e);
	}
	ft_init_value_draw_plus(e, 2);
	ft_segment_letter(e);
	i = -1;
	while (++i < 10)
	{
		ft_init_value_draw_plus(e, 3);
		ft_segment_letter(e);
	}
	draw_plus_td(e);
}

void	draw_plus(t_stuff *e)
{
	int		i;

	i = -1;
	if (e->i.nobj.open != 2)
	{
		ft_init_value_draw_plus(e, 0);
		ft_segment_letter(e);
		while (++i < 10)
		{
			ft_init_value_draw_plus(e, 1);
			ft_segment_letter(e);
		}
		ft_init_value_draw_plus(e, 2);
		ft_segment_letter(e);
		i = -1;
		while (++i < 10)
		{
			ft_init_value_draw_plus(e, 3);
			ft_segment_letter(e);
		}
	}
	else if (e->i.nobj.open == 2)
		draw_plus_sd(e);
}
