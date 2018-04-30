/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objet_courant_aff_data_plan.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 14:29:14 by prossi            #+#    #+#             */
/*   Updated: 2018/04/18 14:55:35 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	aff_data_plan_fh(t_stuff *e, char *buf)
{
	buf = ft_mydtoa(e->i.mlx->data.conscol, buf);
	ft_init_value_aff_data_plan(e, 20, ft_strlen(buf) - 5);
	awklm_string_put(buf, e);
	ft_strdel(&buf);
}

void	aff_data_plan_td(t_stuff *e, char *buf)
{
	awklm_string_put(buf, e);
	ft_strclr(buf);
	buf = ft_mydtoa(e->i.mlx->data.color.g, buf);
	ft_init_value_aff_data_plan(e, 14, ft_strlen(buf) - 8);
	awklm_string_put("G:", e);
	ft_init_value_aff_data_plan(e, 15, ft_strlen(buf) - 8);
	awklm_string_put(buf, e);
	ft_strclr(buf);
	buf = ft_mydtoa(e->i.mlx->data.color.b, buf);
	ft_init_value_aff_data_plan(e, 16, ft_strlen(buf) - 8);
	awklm_string_put("B:", e);
	ft_init_value_aff_data_plan(e, 17, ft_strlen(buf) - 8);
	awklm_string_put(buf, e);
	ft_strclr(buf);
	buf = ft_mydtoa(e->i.mlx->data.refrac, buf);
	ft_init_value_aff_data_plan(e, 18, ft_strlen(buf) - 5);
	awklm_string_put(buf, e);
	ft_strclr(buf);
	buf = ft_mydtoa(e->i.mlx->data.reflex, buf);
	ft_init_value_aff_data_plan(e, 19, ft_strlen(buf) - 5);
	awklm_string_put(buf, e);
	ft_strclr(buf);
	aff_data_plan_fh(e, buf);
}

void	aff_data_plan_sd(t_stuff *e, char *buf)
{
	awklm_string_put(buf, e);
	ft_strclr(buf);
	buf = ft_mydtoa(e->i.mlx->data.dir.x, buf);
	ft_init_value_aff_data_plan(e, 6, ft_strlen(buf) - 8);
	awklm_string_put("X:", e);
	ft_init_value_aff_data_plan(e, 7, ft_strlen(buf) - 8);
	awklm_string_put(buf, e);
	ft_strclr(buf);
	buf = ft_mydtoa(e->i.mlx->data.dir.y, buf);
	ft_init_value_aff_data_plan(e, 8, ft_strlen(buf) - 8);
	awklm_string_put("Y:", e);
	ft_init_value_aff_data_plan(e, 9, ft_strlen(buf) - 8);
	awklm_string_put(buf, e);
	ft_strclr(buf);
	buf = ft_mydtoa(e->i.mlx->data.dir.z, buf);
	ft_init_value_aff_data_plan(e, 10, ft_strlen(buf) - 8);
	awklm_string_put("Z:", e);
	ft_init_value_aff_data_plan(e, 11, ft_strlen(buf) - 8);
	awklm_string_put(buf, e);
	ft_strclr(buf);
	buf = ft_mydtoa(e->i.mlx->data.color.r, buf);
	ft_init_value_aff_data_plan(e, 12, ft_strlen(buf) - 8);
	awklm_string_put("R:", e);
	ft_init_value_aff_data_plan(e, 13, ft_strlen(buf) - 8);
	aff_data_plan_td(e, buf);
}

void	aff_data_plan(t_stuff *e)
{
	char		*buf;

	buf = NULL;
	if (!(buf = ft_strnew(25)))
	{
		ft_putendl("\nMalloc failed in (interface - obj.courant.aff.data.pla)");
		exit(0);
	}
	buf = ft_mydtoa(e->i.mlx->data.pos.x, buf);
	ft_init_value_aff_data_plan(e, 0, ft_strlen(buf) - 8);
	awklm_string_put("X:", e);
	ft_init_value_aff_data_plan(e, 1, ft_strlen(buf) - 8);
	awklm_string_put(buf, e);
	ft_strclr(buf);
	buf = ft_mydtoa(e->i.mlx->data.pos.y, buf);
	ft_init_value_aff_data_plan(e, 2, ft_strlen(buf) - 8);
	awklm_string_put("Y:", e);
	ft_init_value_aff_data_plan(e, 3, ft_strlen(buf) - 8);
	awklm_string_put(buf, e);
	ft_strclr(buf);
	buf = ft_mydtoa(e->i.mlx->data.pos.z, buf);
	ft_init_value_aff_data_plan(e, 4, ft_strlen(buf) - 8);
	awklm_string_put("Z:", e);
	ft_init_value_aff_data_plan(e, 5, ft_strlen(buf) - 8);
	aff_data_plan_sd(e, buf);
}
