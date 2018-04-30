/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objet_courant.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 22:13:22 by prossi            #+#    #+#             */
/*   Updated: 2018/04/18 14:33:22 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	objet_courant_color(t_stuff *e)
{
	ft_init_value_objet_courant_color(e, 0);
	awklm_string_put("Choix des couleurs", e);
	ft_init_value_objet_courant_color(e, 1);
	awklm_string_put("Fond", e);
	ft_init_value_objet_courant_color(e, 2);
	awklm_string_put("Forme", e);
	ft_init_value_objet_courant_color(e, 3);
	awklm_string_put("Police", e);
	ft_init_value_objet_courant_color(e, 4);
	empty_box(e);
	ft_init_value_objet_courant_color(e, 5);
	full_box(e);
	ft_init_value_objet_courant_color(e, 6);
	full_box(e);
}

void	get_value_current(t_stuff *e)
{
	reboot_list_loop(e, 3);
	if (e->i.objet == SPHERE)
		searchlist(e, e->i.each_obj, SPHERE);
	else if (e->i.objet == LIGHT)
		searchlist(e, e->i.each_obj, LIGHT);
	else if (e->i.objet == CYLINDRE)
		searchlist(e, e->i.each_obj, CYLINDRE);
	else if (e->i.objet == PLAN)
		searchlist(e, e->i.each_obj, PLAN);
	else if (e->i.objet == CONE)
		searchlist(e, e->i.each_obj, CONE);
	fill_value_current(e);
}

void	aff_data(t_stuff *e)
{
	if (e->i.objet == -1)
		aff_data_camera(e);
	else if (e->i.objet == SPHERE)
		aff_data_sphere(e);
	else if (e->i.objet == LIGHT)
		aff_data_light(e);
	else if (e->i.objet == CYLINDRE)
		aff_data_cylindre(e);
	else if (e->i.objet == PLAN)
		aff_data_plan(e);
	else if (e->i.objet == CONE)
		aff_data_cone(e);
}

void	objet_courant_sd(t_stuff *e)
{
	if (e->i.cobj.settings == 0 || e->i.cobj.settings == 1)
	{
		get_value_current(e);
		draw_ellipse_background(e);
		if (e->i.cobj.power == 0)
			draw_title_background(e);
		if (e->i.cobj.power == 1)
			aff_data(e);
	}
	if (e->i.cobj.settings == 1)
	{
		ft_init_value_draw_settings(e, 0);
		settings(e);
	}
	if (e->i.cobj.settings == 2)
		objet_courant_color(e);
	mlx_put_image_to_window(e->img.mlx_ptr, e->img.win_ptr, \
		e->i.mlx->img, 0, 0);
}

void	objet_courant(t_stuff *e)
{
	if (e->i.first == 0)
	{
		e->i.img_x = WIN_X - WIDTH;
		e->i.img_y = WIN_Y - LENGTH;
		new_img(e);
		init_struct(e, 4);
	}
	else
	{
		reboot_list_interface(e, 1);
		searchlist_interface(e, 0);
	}
	draw_objet_courant(e);
	objet_courant_sd(e);
}
