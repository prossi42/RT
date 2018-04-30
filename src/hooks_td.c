/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_td.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <jgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 14:03:42 by jgaillar          #+#    #+#             */
/*   Updated: 2018/04/13 17:21:45 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	movement_matrice(int keycode, t_stuff *e)
{
	if (keycode == 36 && e->m.type != '\0' && e->m.axe != '\0' \
		&& e->m.type_sujet != 0)
	{
		choose_sujet(e);
		objet_courant(e);
		apercu_courant(e);
		multi_thread(e);
	}
}

void	move_objet_td(t_vec *pos_obj, int keycode)
{
	if (keycode == 124)
		pos_obj->y += 1.0;
	else if (keycode == 123)
		pos_obj->y -= 1.0;
	else if (keycode == 126)
		pos_obj->x += 1.0;
	else if (keycode == 125)
		pos_obj->x -= 1.0;
	else if (keycode == 69)
		pos_obj->z += 1.0;
	else if (keycode == 78)
		pos_obj->z -= 1.0;
}

void	move_objet_sd(t_stuff *e, int keycode)
{
	if (keycode == 14)
		angle_increase(e, -4, 0, 0);
	if (keycode == 3)
		angle_increase(e, 0, 4, 0);
	if (keycode == 1)
		angle_increase(e, 0, -4, 0);
	if (keycode == 2)
		angle_increase(e, 4, 0, 0);
	if (keycode == 13)
		angle_increase(e, 0, 0, 4);
	if (keycode == 15)
		angle_increase(e, 0, 0, -4);
}

void	move_objet(int keycode, t_vec *pos_obj, t_stuff *e)
{
	t_vec	forward;
	t_vec	up;

	if (e->i.objet == -1 && (keycode == 123 || keycode == 124 \
		|| keycode == 126 || keycode == 125 || keycode == 69 || \
		keycode == 78 || keycode == 1 || keycode == 2 || keycode == 3 ||\
		keycode == 14 || keycode == 13 || keycode == 15))
	{
		forward_vec_create(&forward);
		rotation_apply(e, &forward);
		up_vec_create(&up);
		rotation_apply(e, &up);
		if (keycode == 123)
			vecsous(pos_obj, pos_obj, &up);
		if (keycode == 125)
			vecsous(pos_obj, pos_obj, &forward);
		if (keycode == 124)
			vecadd(pos_obj, pos_obj, &up);
		if (keycode == 126)
			vecadd(pos_obj, pos_obj, &forward);
		move_objet_sd(e, keycode);
	}
	else if (keycode == 123 || keycode == 124 || keycode == 126 || \
		keycode == 125 || keycode == 69 || keycode == 78)
		move_objet_td(pos_obj, keycode);
}

void	move_multiobj(t_stuff *e, int keycode)
{
	searchlist(e, e->i.mobj.start, SPHERE);
	while (e->sph->nm != e->i.mobj.end)
	{
		move_objet(keycode, &e->sph->pos, e);
		e->sph = e->sph->next;
	}
	move_objet(keycode, &e->sph->pos, e);
}
