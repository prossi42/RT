/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objet_courant_aff_data_camera.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Awk-LM <Awk-LM@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 15:09:15 by Awk-LM            #+#    #+#             */
/*   Updated: 2018/03/09 21:58:38 by Awk-LM           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	aff_data_camera(t_stuff *e)
{
	char		*buf;

	buf = NULL;
	if (!(buf = ft_strnew(25)))
	{
		ft_putendl("\nMalloc failed in (interface - obj.courant.aff.data.cam)");
		exit(0);
	}
	sprintf(buf, "%.2f", e->i.mlx->data.pos.x);
	ft_init_value_aff_data_camera(e, 0, ft_strlen(buf) - 8);
	awklm_string_put("X:", e);
	ft_init_value_aff_data_camera(e, 1, ft_strlen(buf) - 8);
	awklm_string_put(buf, e);
	sprintf(buf, "%.2f", e->i.mlx->data.pos.y);
	ft_init_value_aff_data_camera(e, 2, ft_strlen(buf) - 8);
	awklm_string_put("Y:", e);
	ft_init_value_aff_data_camera(e, 3, ft_strlen(buf) - 8);
	awklm_string_put(buf, e);
	sprintf(buf, "%.2f", e->i.mlx->data.pos.z);
	ft_init_value_aff_data_camera(e, 4, ft_strlen(buf) - 8);
	awklm_string_put("Z:", e);
	ft_init_value_aff_data_camera(e, 5, ft_strlen(buf) - 8);
	awklm_string_put(buf, e);
	sprintf(buf, "%.2f", e->i.mlx->data.dir.x);
	ft_init_value_aff_data_camera(e, 6, ft_strlen(buf) - 8);
	awklm_string_put("X:", e);
	ft_init_value_aff_data_camera(e, 7, ft_strlen(buf) - 8);
	awklm_string_put(buf, e);
	sprintf(buf, "%.2f", e->i.mlx->data.dir.y);
	ft_init_value_aff_data_camera(e, 8, ft_strlen(buf) - 8);
	awklm_string_put("Y:", e);
	ft_init_value_aff_data_camera(e, 9, ft_strlen(buf) - 8);
	awklm_string_put(buf, e);
	sprintf(buf, "%.2f", e->i.mlx->data.dir.z);
	ft_init_value_aff_data_camera(e, 10, ft_strlen(buf) - 8);
	awklm_string_put("Z:", e);
	ft_init_value_aff_data_camera(e, 11, ft_strlen(buf) - 8);
	awklm_string_put(buf, e);
	ft_strdel(&buf);
}
