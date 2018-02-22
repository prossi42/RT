/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_obj_draw_camera.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Awk-LM <Awk-LM@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 17:25:13 by Awk-LM            #+#    #+#             */
/*   Updated: 2018/02/22 00:41:31 by Awk-LM           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	draw_camera_td(t_stuff *e)
{
	ft_init_value_draw_camera(e, 30);
	ft_segment_letter(e);
	ft_init_value_draw_camera(e, 31);
	ft_segment_letter(e);
	ft_init_value_draw_camera(e, 32);
	ft_segment_letter(e);
	ft_init_value_draw_camera(e, 33);
	ft_segment_letter(e);
	ft_init_value_draw_camera(e, 34);
	ft_arc(e, 4);
	ft_init_value_draw_camera(e, 35);
	ft_segment_letter(e);
	ft_init_value_draw_camera(e, 36);
	ft_segment_letter(e);
	ft_init_value_draw_camera(e, 37);
	ft_arc(e, 9);
	ft_init_value_draw_camera(e, 38);
	ft_segment_letter(e);
	ft_init_value_draw_camera(e, 39);
	ft_segment_letter(e);
	ft_init_value_draw_camera(e, 40);
	ft_segment_letter(e);
}

void	draw_camera_sd(t_stuff *e)
{
	ft_init_value_draw_camera(e, 18);
	ft_segment_letter(e);
	ft_init_value_draw_camera(e, 19);
	ft_segment_letter(e);
	ft_init_value_draw_camera(e, 20);
	ft_segment_letter(e);
	ft_init_value_draw_camera(e, 21);
	ft_segment_letter(e);
	ft_init_value_draw_camera(e, 22);
	ft_segment_letter(e);
	ft_init_value_draw_camera(e, 23);
	ft_segment_letter(e);
	ft_init_value_draw_camera(e, 24);
	ft_segment_letter(e);
	ft_init_value_draw_camera(e, 25);
	ft_segment_letter(e);
	ft_init_value_draw_camera(e, 26);
	ft_segment_letter(e);
	ft_init_value_draw_camera(e, 27);
	ft_segment_letter(e);
	ft_init_value_draw_camera(e, 28);
	ft_segment_letter(e);
	ft_init_value_draw_camera(e, 29);
	ft_segment_letter(e);
	draw_camera_td(e);
}

void	draw_camera(t_stuff *e)
{
	ft_init_value_draw_camera(e, 7);
	printf("Valeur en x : [%d]\n", e->bs.xi);
	printf("Valeur en y : [%d]\n", e->bs.yi);
	ft_segment_letter(e);
	ft_init_value_draw_camera(e, 8);
	ft_segment_letter(e);
	ft_init_value_draw_camera(e, 9);
	ft_segment_letter(e);
	ft_init_value_draw_camera(e, 10);
	ft_segment_letter(e);
	ft_init_value_draw_camera(e, 11);
	ft_arc(e, 9);
	ft_init_value_draw_camera(e, 12);
	ft_arc(e, 9);
	ft_init_value_draw_camera(e, 13);
	ft_arc(e, 9);
	ft_init_value_draw_camera(e, 12);
	ft_arc(e, 9);
	ft_init_value_draw_camera(e, 14);
	ft_segment_letter(e);
	ft_init_value_draw_camera(e, 15);
	ft_segment_letter(e);
	ft_init_value_draw_camera(e, 16);
	ft_arc(e, 2);
	ft_init_value_draw_camera(e, 17);
	ft_segment_letter(e);
	draw_camera_sd(e);
}
