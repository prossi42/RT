/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_obj_draw_objects.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Awk-LM <Awk-LM@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 00:08:48 by Awk-LM            #+#    #+#             */
/*   Updated: 2018/02/22 08:39:39 by Awk-LM           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	draw_sphere(t_stuff *e)
{
	int		i;
	int		option;  //A SUPRIMER PRESENT JUSTE POUR LES TESTS

	i = -1;
	option = 1; //A SUPPRIMER PRESENT JUSTE POUR LES TESTS
	ft_init_value_draw_objects(e, 0);
	if (e->i.objet == SPHERE)
	{
		if (option == 0)
		{
			ft_arc(e, 9);
			while (++i < 10)
			{
				if (i <= 6)
				{
					ft_init_value_draw_objects(e, 1);
					ft_arc(e, 2);
				}
				if (i > 6)
				{
					ft_init_value_draw_objects(e, 2);
					ft_arc(e, 2);
				}
			}
			i = -1;
			ft_init_value_draw_objects(e, 0);
			while (++i < 10)
			{
				if (i <= 6)
				{
					ft_init_value_draw_objects(e, 3);
					ft_arc(e, 1);
				}
				if (i > 6)
				{
					ft_init_value_draw_objects(e, 4);
					ft_arc(e, 1);
				}
			}
		}
		else
			ft_ellipse(e);
	}
}

void	draw_objects(t_stuff *e)
{
	if (e->i.objet == SPHERE || e->i.objet == LIGHT)
		draw_sphere(e);
	// else if (e->i.objet == PLAN)
	// 	draw_plan(e);
	// else if (e->i.objet == CYLINDRE)
	// 	draw_cylindre(e);
	// else if (e->i.objet == CONE)
	// 	draw_cone(e);
}
