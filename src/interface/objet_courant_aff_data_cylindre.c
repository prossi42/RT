/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objet_courant_aff_data_cylindre.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Awk-LM <Awk-LM@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 14:25:43 by Awk-LM            #+#    #+#             */
/*   Updated: 2018/03/10 00:49:07 by Awk-LM           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	aff_data_cylindre(t_stuff *e)
{
	char		*buf;

	buf = NULL;
	if (!(buf = ft_strnew(25)))
	{
		ft_putendl("\nMalloc failed in (interface - obj.courant.aff.data.cyl)");
		exit(0);
	}
	sprintf(buf, "%.2f", e->i.mlx->data.pos.x);
	ft_init_value_aff_data_cylindre(e, 0, ft_strlen(buf) - 8);
	awklm_string_put("X:", e);
	ft_init_value_aff_data_cylindre(e, 1, ft_strlen(buf) - 8);
	awklm_string_put(buf, e);
	sprintf(buf, "%.2f", e->i.mlx->data.pos.y);
	ft_init_value_aff_data_cylindre(e, 2, ft_strlen(buf) - 8);
	awklm_string_put("Y:", e);
	ft_init_value_aff_data_cylindre(e, 3, ft_strlen(buf) - 8);
	awklm_string_put(buf, e);
	sprintf(buf, "%.2f", e->i.mlx->data.pos.z);
	ft_init_value_aff_data_cylindre(e, 4, ft_strlen(buf) - 8);
	awklm_string_put("Z:", e);
	ft_init_value_aff_data_cylindre(e, 5, ft_strlen(buf) - 8);
	awklm_string_put(buf, e);
	sprintf(buf, "%.2f", e->i.mlx->data.dir.x);
	ft_init_value_aff_data_cylindre(e, 6, ft_strlen(buf) - 8);
	awklm_string_put("X:", e);
	ft_init_value_aff_data_cylindre(e, 7, ft_strlen(buf) - 8);
	awklm_string_put(buf, e);
	sprintf(buf, "%.2f", e->i.mlx->data.dir.y);
	ft_init_value_aff_data_cylindre(e, 8, ft_strlen(buf) - 8);
	awklm_string_put("Y:", e);
	ft_init_value_aff_data_cylindre(e, 9, ft_strlen(buf) - 8);
	awklm_string_put(buf, e);
	sprintf(buf, "%.2f", e->i.mlx->data.dir.z);
	ft_init_value_aff_data_cylindre(e, 10, ft_strlen(buf) - 8);
	awklm_string_put("Z:", e);
	ft_init_value_aff_data_cylindre(e, 11, ft_strlen(buf) - 8);
	awklm_string_put(buf, e);
	sprintf(buf, "%d", e->i.mlx->data.color.r);
	ft_init_value_aff_data_cylindre(e, 12, ft_strlen(buf) - 8);
	awklm_string_put("R:", e);
	ft_init_value_aff_data_cylindre(e, 13, ft_strlen(buf) - 8);
	awklm_string_put(buf, e);
	sprintf(buf, "%d", e->i.mlx->data.color.g);
	ft_init_value_aff_data_cylindre(e, 14, ft_strlen(buf) - 8);
	awklm_string_put("G:", e);
	ft_init_value_aff_data_cylindre(e, 15, ft_strlen(buf) - 8);
	awklm_string_put(buf, e);
	sprintf(buf, "%d", e->i.mlx->data.color.b);
	ft_init_value_aff_data_cylindre(e, 16, ft_strlen(buf) - 8);
	awklm_string_put("B:", e);
	ft_init_value_aff_data_cylindre(e, 17, ft_strlen(buf) - 8);
	awklm_string_put(buf, e);
	sprintf(buf, "%.2f", e->i.mlx->data.ray);
	ft_init_value_aff_data_cylindre(e, 18, ft_strlen(buf) - 5);
	awklm_string_put(buf, e);
	sprintf(buf, "%.2f", e->i.mlx->data.refrac);
	ft_init_value_aff_data_cylindre(e, 19, ft_strlen(buf) - 5);
	awklm_string_put(buf, e);
	sprintf(buf, "%.2f", e->i.mlx->data.reflex);
	ft_init_value_aff_data_cylindre(e, 20, ft_strlen(buf) - 5);
	awklm_string_put(buf, e);
	sprintf(buf, "%.2f", e->i.mlx->data.conscol);
	ft_init_value_aff_data_cylindre(e, 21, ft_strlen(buf) - 5);
	awklm_string_put(buf, e);
	ft_strdel(&buf);
}
