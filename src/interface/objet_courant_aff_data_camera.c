/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objet_courant_aff_data_camera.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 15:09:15 by prossi            #+#    #+#             */
/*   Updated: 2018/04/18 15:07:16 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	aff_data_camera_sd(t_stuff *e, char *buf)
{
	awklm_string_put(buf, e);
	ft_strclr(buf);
	buf = ft_mydtoa(e->i.mlx->data.dir.x, buf);
	ft_init_value_aff_data_camera(e, 6, ft_strlen(buf) - 8);
	awklm_string_put("X:", e);
	ft_init_value_aff_data_camera(e, 7, ft_strlen(buf) - 8);
	awklm_string_put(buf, e);
	ft_strclr(buf);
	buf = ft_mydtoa(e->i.mlx->data.dir.y, buf);
	ft_init_value_aff_data_camera(e, 8, ft_strlen(buf) - 8);
	awklm_string_put("Y:", e);
	ft_init_value_aff_data_camera(e, 9, ft_strlen(buf) - 8);
	awklm_string_put(buf, e);
	ft_strclr(buf);
	buf = ft_mydtoa(e->i.mlx->data.dir.z, buf);
	ft_init_value_aff_data_camera(e, 10, ft_strlen(buf) - 8);
	awklm_string_put("Z:", e);
	ft_init_value_aff_data_camera(e, 11, ft_strlen(buf) - 8);
	awklm_string_put(buf, e);
	ft_strdel(&buf);
}

void	aff_data_camera(t_stuff *e)
{
	char		*buf;

	buf = NULL;
	if (!(buf = ft_strnew(25)))
	{
		ft_putendl("\nMalloc failed in (interface - obj.courant.aff.data.cam)");
		exit(0);
	}
	buf = ft_mydtoa(e->i.mlx->data.pos.x, buf);
	ft_init_value_aff_data_camera(e, 0, ft_strlen(buf) - 8);
	awklm_string_put("X:", e);
	ft_init_value_aff_data_camera(e, 1, ft_strlen(buf) - 8);
	awklm_string_put(buf, e);
	ft_strclr(buf);
	buf = ft_mydtoa(e->i.mlx->data.pos.y, buf);
	ft_init_value_aff_data_camera(e, 2, ft_strlen(buf) - 8);
	awklm_string_put("Y:", e);
	ft_init_value_aff_data_camera(e, 3, ft_strlen(buf) - 8);
	awklm_string_put(buf, e);
	ft_strclr(buf);
	buf = ft_mydtoa(e->i.mlx->data.pos.z, buf);
	ft_init_value_aff_data_camera(e, 4, ft_strlen(buf) - 8);
	awklm_string_put("Z:", e);
	ft_init_value_aff_data_camera(e, 5, ft_strlen(buf) - 8);
	aff_data_camera_sd(e, buf);
}
