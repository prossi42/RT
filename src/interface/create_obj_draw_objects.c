/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_obj_draw_objects.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 00:08:48 by prossi            #+#    #+#             */
/*   Updated: 2018/02/22 15:25:14 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	draw_cone(t_stuff *e)
{
	int		i;

	i = -1;
	ft_init_value_draw_cylindre_cone(e, 2);
	ft_ellipse(e, 0, 0);
	while (++i < 24)
	{
		if (i < 12)
		{
			ft_init_value_draw_cylindre_cone(e, 3);
			ft_ellipse(e, 0, 0);
		}
		else
		{
			ft_init_value_draw_cylindre_cone(e, 4);
			ft_ellipse(e, 0, 0);
		}
	}
}

void	draw_cylindre(t_stuff *e)
{
	int		i;

	i = -1;
	ft_init_value_draw_cylindre_cone(e, 0);
	ft_ellipse(e, 0, 0);
	while (++i < 20)
	{
		ft_init_value_draw_cylindre_cone(e, 1);
		ft_ellipse(e, 0, 0);
	}
}

void	draw_sphere(t_stuff *e)
{
	int		i;

	i = -1;
	ft_init_value_draw_sphere(e, 0);
	ft_ellipse(e, 0, 0);
	while (++i < 4)
	{
		ft_init_value_draw_sphere(e, 1);
		ft_ellipse(e, 0, 0);
	}
	ft_init_value_draw_sphere(e, 0);
	i = -1;
	while (++i < 4)
	{
		ft_init_value_draw_sphere(e, 2);
		ft_ellipse(e, 0, 0);
	}
}

void	draw_plan(t_stuff *e)
{
	int		i;

	i = 3;
	ft_init_value_draw_plan(e, 3);
	ft_segment_letter(e);
	while (++i < 14)
	{
		ft_init_value_draw_plan(e, i);
		ft_segment_letter(e);
	}
	ft_init_value_draw_plan(e, 14);
	ft_segment_letter(e);
	while (++i < 30)
	{
		ft_init_value_draw_plan(e, i);
		ft_segment_letter(e);
	}
}
