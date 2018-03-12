/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <jgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 10:47:04 by jgaillar          #+#    #+#             */
/*   Updated: 2018/02/20 11:50:26 by Awk-LM           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	choose_sujet(t_stuff *e)
{
	reboot_list_loop(e, 3);
	e->c.obj = e->i.objet;
	if (e->c.obj == SPHERE && e->d.nbmsph != 0)
	{
		searchlist(e, e->i.each_obj, SPHERE);
		if (e->m.type_sujet == 1)
			matrice(e->m.type, e->m.axe, e, &e->sph->pos);
	}
	else if (e->c.obj == LIGHT && e->d.nbmlight != 0)
	{
		searchlist(e, e->i.each_obj, LIGHT);
		matrice(e->m.type, e->m.axe, e, &e->light->pos);
	}
	else if (e->c.obj == CYLINDRE && e->d.nbmcyl != 0)
	{
		searchlist(e, e->i.each_obj, CYLINDRE);
		if (e->m.type_sujet == 1)
			matrice(e->m.type, e->m.axe, e, &e->cyl->pos);
		else
			matrice(e->m.type, e->m.axe, e, &e->cyl->norm);
	}
	else if (e->c.obj == PLAN && e->d.nbmpla != 0)
	{
		searchlist(e, e->i.each_obj, PLAN);
		if (e->m.type_sujet == 1)
			matrice(e->m.type, e->m.axe, e, &e->pla->pos);
		else
			matrice(e->m.type, e->m.axe, e, &e->pla->norm);
	}
	else if (e->c.obj == CONE && e->d.nbmcone != 0)
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

void	move_objet(int keycode, t_vec *pos_obj, t_stuff *e)
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
	else if (keycode == 0)
		e->pr.y += 0.5;
	else if (keycode == 1)
		e->pr.z -= 0.5;
	else if (keycode == 2)
		e->pr.y -= 0.5;
	else if (keycode == 13)
		e->pr.z += 0.5;
	vectorcalc(e);
}

void	movement(int keycode, t_stuff *e)
{
	if (e->i.objet != -1)
		searchlist(e, e->i.each_obj, e->i.objet);
	if (e->i.objet == -1)
		move_objet(keycode, &e->poscam, e);
	else if (e->i.objet == SPHERE)
		move_objet(keycode, &e->sph->pos, e);
	else if (e->i.objet == PLAN)
		move_objet(keycode, &e->pla->pos, e);
	else if (e->i.objet == CONE)
		move_objet(keycode, &e->cone->pos, e);
	else if (e->i.objet == CYLINDRE)
		move_objet(keycode, &e->cyl->pos, e);
	else if (e->i.objet == LIGHT)
		move_objet(keycode, &e->light->pos, e);
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
	if (e->i.mat.act_angle == 0 && e->i.mat.act_value == 0 && e->i.nobj.first == -1)
	{
		if (keycode == 36)
			movement_matrice(keycode, e);
		else if (keycode == 53)
			echap(keycode, e);
		else if (keycode == 2 || keycode == 0 || keycode == 1 || keycode == 13 \
			|| keycode == 49 || keycode == 8 || keycode == 125 || \
			keycode == 126 || keycode == 124 || keycode == 123 || \
			keycode == 78 || keycode == 69)
			movement(keycode, e);
		else if (keycode == 43 || keycode == 47)
			pixel(keycode, e);
		aff(e);
	}
	if (e->i.mat.act_angle == 1 || e->i.mat.act_value == 1 || e->i.nobj.first != -1)
		key_hook_interface(keycode, e);
	return (0);
}
