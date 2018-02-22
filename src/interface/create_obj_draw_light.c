/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_obj_draw_light.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 16:07:40 by prossi            #+#    #+#             */
/*   Updated: 2018/02/22 18:14:13 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	draw_light(t_stuff *e)
{
	ft_init_value_draw_light(e, 0);
	ft_ellipse(e, 1, 1);
	ft_ellipse(e, 2, 3);
	ft_ellipse(e, 2, 5);
	ft_init_value_draw_light(e, 1);
	ft_segment_letter(e);
	ft_init_value_draw_light(e, 2);
	ft_segment_letter(e);
	ft_init_value_draw_light(e, 3);
	ft_segment_letter(e);
	ft_init_value_draw_light(e, 4);
	ft_arc(e, 9);
	ft_init_value_draw_light(e, 5);
	ft_arc(e, 9);
	ft_init_value_draw_light(e, 6);
	ft_segment_letter(e);
	ft_init_value_draw_light(e, 7);
	ft_segment_letter(e);
	ft_init_value_draw_light(e, 8);
	ft_arc(e, 12);
	ft_arc(e, 10);
	ft_init_value_draw_light(e, 9);
	ft_ellipse(e, 2, 4);
	ft_init_value_draw_light(e, 10);
	ft_ellipse(e, 1, 4);
	// ft_init_value_draw_light(e, 11);
	ft_ellipse(e, 1, 3);
}
