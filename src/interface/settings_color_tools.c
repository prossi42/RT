/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_color_tools.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 20:49:07 by prossi            #+#    #+#             */
/*   Updated: 2018/04/17 20:49:13 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	settings_color_bind(t_stuff *e, t_scouleur trio)
{
	ft_init_value_settings_color(e, 0, trio);
	awklm_string_put("Choix des couleurs", e);
	ft_init_value_settings_color(e, 1, trio);
	awklm_string_put("Fond", e);
	ft_init_value_settings_color(e, 2, trio);
	awklm_string_put("Forme", e);
	ft_init_value_settings_color(e, 3, trio);
	awklm_string_put("Police", e);
	ft_init_value_settings_color(e, 4, trio);
	empty_box(e);
	ft_init_value_settings_color(e, 5, trio);
	full_box(e);
	ft_init_value_settings_color(e, 6, trio);
	full_box(e);
}

void	draw_settings_color(t_stuff *e)
{
	int		x;
	int		y;
	int		color;

	y = -1;
	if (e->i.mat.settings == 2)
		color = e->i.color.mat.col1;
	if (e->i.save.settings == 2)
		color = e->i.color.saves.col1;
	while (++y < e->i.mlx->img_y)
	{
		x = -1;
		while (++x < e->i.mlx->img_x)
			pixel_put_to_img(&e->i.mlx, x, y, color);
	}
}
