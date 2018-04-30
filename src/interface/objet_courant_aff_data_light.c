/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objet_courant_aff_data_light.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 14:28:33 by prossi            #+#    #+#             */
/*   Updated: 2018/04/18 14:58:35 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	aff_data_light_td(t_stuff *e, char *buf)
{
	buf = ft_mydtoa(e->i.mlx->data.amb, buf);
	ft_init_value_aff_data_light(e, 13, ft_strlen(buf) - 5);
	awklm_string_put(buf, e);
	ft_strclr(buf);
	buf = ft_mydtoa(e->i.mlx->data.diff, buf);
	ft_init_value_aff_data_light(e, 14, ft_strlen(buf) - 5);
	awklm_string_put(buf, e);
	ft_strdel(&buf);
}

void	aff_data_light_sd(t_stuff *e, char *buf)
{
	awklm_string_put(buf, e);
	ft_strclr(buf);
	buf = ft_mydtoa(e->i.mlx->data.color.r, buf);
	ft_init_value_aff_data_light(e, 6, ft_strlen(buf) - 8);
	awklm_string_put("R:", e);
	ft_init_value_aff_data_light(e, 7, ft_strlen(buf) - 8);
	awklm_string_put(buf, e);
	ft_strclr(buf);
	buf = ft_mydtoa(e->i.mlx->data.color.g, buf);
	ft_init_value_aff_data_light(e, 8, ft_strlen(buf) - 8);
	awklm_string_put("G:", e);
	ft_init_value_aff_data_light(e, 9, ft_strlen(buf) - 8);
	awklm_string_put(buf, e);
	ft_strclr(buf);
	buf = ft_mydtoa(e->i.mlx->data.color.b, buf);
	ft_init_value_aff_data_light(e, 10, ft_strlen(buf) - 8);
	awklm_string_put("B:", e);
	ft_init_value_aff_data_light(e, 11, ft_strlen(buf) - 8);
	awklm_string_put(buf, e);
	ft_strclr(buf);
	buf = ft_mydtoa(e->i.mlx->data.ray, buf);
	ft_init_value_aff_data_light(e, 12, ft_strlen(buf) - 5);
	awklm_string_put(buf, e);
	ft_strclr(buf);
	aff_data_light_td(e, buf);
}

void	aff_data_light(t_stuff *e)
{
	char		*buf;

	buf = NULL;
	if (!(buf = ft_strnew(25)))
	{
		ft_putendl("\nMalloc failed in (interface - obj.courant.aff.data.lig)");
		exit(0);
	}
	buf = ft_mydtoa(e->i.mlx->data.pos.x, buf);
	ft_init_value_aff_data_light(e, 0, ft_strlen(buf) - 8);
	awklm_string_put("X:", e);
	ft_init_value_aff_data_light(e, 1, ft_strlen(buf) - 8);
	awklm_string_put(buf, e);
	ft_strclr(buf);
	buf = ft_mydtoa(e->i.mlx->data.pos.y, buf);
	ft_init_value_aff_data_light(e, 2, ft_strlen(buf) - 8);
	awklm_string_put("Y:", e);
	ft_init_value_aff_data_light(e, 3, ft_strlen(buf) - 8);
	awklm_string_put(buf, e);
	ft_strclr(buf);
	buf = ft_mydtoa(e->i.mlx->data.pos.z, buf);
	ft_init_value_aff_data_light(e, 4, ft_strlen(buf) - 8);
	awklm_string_put("Z:", e);
	ft_init_value_aff_data_light(e, 5, ft_strlen(buf) - 8);
	aff_data_light_sd(e, buf);
}
