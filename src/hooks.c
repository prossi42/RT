/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <jgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 10:47:04 by jgaillar          #+#    #+#             */
/*   Updated: 2018/02/12 11:17:37 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	choose_sujet(t_stuff *e)
{
	reboot_list_loop(e, 3);
	e->c.obj = e->i.objet;
	if (e->c.obj == SPHERE)
	{
		searchlist(e, e->i.each_obj, SPHERE);
		if (e->m.type_sujet == 1)
			matrice(e->m.type, e->m.axe, e, &e->sph->pos);
	}
	else if (e->c.obj == LIGHT)
	{
		searchlist(e, e->i.each_obj, LIGHT);
		matrice(e->m.type, e->m.axe, e, &e->light->pos);
	}
	else if (e->c.obj == CYLINDRE)
	{
		searchlist(e, e->i.each_obj, CYLINDRE);
		if (e->m.type_sujet == 1)
			matrice(e->m.type, e->m.axe, e, &e->cyl->pos);
		else
			matrice(e->m.type, e->m.axe, e, &e->cyl->norm);
	}
	else if (e->c.obj == PLAN)
	{
		searchlist(e, e->i.each_obj, PLAN);
		if (e->m.type_sujet == 1)
			matrice(e->m.type, e->m.axe, e, &e->pla->pos);
		else
			matrice(e->m.type, e->m.axe, e, &e->pla->norm);
	}
	else if (e->c.obj == CONE)
	{
		searchlist(e, e->i.each_obj, CONE);
		if (e->m.type_sujet == 1)
			matrice(e->m.type, e->m.axe, e, &e->cone->pos);
		else
			matrice(e->m.type, e->m.axe, e, &e->cone->norm);
	}
	else if (e->c.obj == -1)
	{
		if (e->m.type_sujet == 1)
			matrice(e->m.type, e->m.axe, e, &e->poscam);
		else
			matrice(e->m.type, e->m.axe, e, &e->pr);
		vectorcalc(e);
	}
}

void	movement_matrice(int keycode, t_stuff *e)
{
	if (keycode == 36 && e->m.type != '\0' && e->m.axe != '\0' && e->m.type_sujet != 0)
		choose_sujet(e);
	objet_courant(e);
	apercu_courant(e);
}

void	move_objet(int keycode, t_vec *pos_obj)
{
	if (keycode == 123)
		pos_obj->y += 0.5;
	else if (keycode == 124)
		pos_obj->y -= 0.5;
	else if (keycode == 126)
		pos_obj->x += 0.5;
	else if (keycode == 125)
		pos_obj->x -= 0.5;
	else if (keycode == 69)
		pos_obj->z += 0.5;
	else if (keycode == 78)
		pos_obj->z -= 0.5;
}

void	movement(int keycode, t_stuff *e)
{
	if (e->i.objet != -1)
		searchlist(e, e->i.each_obj, e->i.objet);
	if (e->i.objet == -1)
		move_objet(keycode, &e->poscam);
	else if (e->i.objet == SPHERE)
		move_objet(keycode, &e->sph->pos);
	else if (e->i.objet == PLAN)
		move_objet(keycode, &e->pla->pos);
	else if (e->i.objet == CONE)
		move_objet(keycode, &e->cone->pos);
	else if (e->i.objet == CYLINDRE)
		move_objet(keycode, &e->cyl->pos);
	else if (e->i.objet == LIGHT)
		move_objet(keycode, &e->light->pos);
	objet_courant(e);
	apercu_courant(e);
}

void	echap(int keycode, t_stuff *e)
{
	if (keycode == 53)
    {
		free(e->img.data);
		mlx_destroy_image(e->img.mlx_ptr, e->img.win_ptr);
		exit(0);
    }
}

void	cleanexit(t_stuff *e)
{
	free(e->img.data);
	mlx_destroy_image(e->img.mlx_ptr, e->img.win_ptr);
	exit(0);
}

void	pixel(int keycode, t_stuff *e)
{
	if (keycode == 43 && e->pix - 2 >= 0)
		e->pix -= 2;
	if (keycode == 47 && e->pix + 2 < 20)
		e->pix += 2;
}

int		hooks(int keycode, t_stuff *e)
{
	if (e->i.mat.act_angle == 0 && e->i.mat.act_value == 0)
	{
		if (keycode == 43 || keycode == 47)
			pixel(keycode, e);
		else if (keycode == 53)
			echap(keycode, e);
		// if (e->pix > 0)
		// {
			else if (keycode == 36)
				movement_matrice(keycode, e);
			else if (keycode == 2 || keycode == 0 || keycode == 1 || keycode == 13 \
				|| keycode == 49 || keycode == 8 || keycode == 125 || \
				keycode == 126 || keycode == 124 || keycode == 123 || \
				keycode == 78 || keycode == 69)
				movement(keycode, e);
			aff(e);
	//	}
	}
	if (e->i.mat.act_angle == 1 || e->i.mat.act_value == 1)
		key_hook_interface(keycode, e);
	return (0);
}
