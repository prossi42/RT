/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <jgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 10:47:04 by jgaillar          #+#    #+#             */
/*   Updated: 2018/04/13 10:46:54 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	movement(int keycode, t_stuff *e)
{
	if (e->i.objet != -1)
		searchlist(e, e->i.each_obj, e->i.objet);
	if (e->i.objet == -1)
		move_objet(keycode, &e->poscam, e);
	else if (e->i.objet == SPHERE)
	{
		if (e->sph->nm >= e->i.mobj.start && e->sph->nm <= e->i.mobj.end)
			move_multiobj(e, keycode);
		else
			move_objet(keycode, &e->sph->pos, e);
	}
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
	multi_thread(e);
}

void	echap(int keycode, t_stuff *e)
{
	if (keycode == 53)
	{
		free(e->img.data);
		mlx_destroy_image(e->img.mlx_ptr, e->img.win_ptr);
		exit_interface(e);
		ntmleaks(e);
		ft_memdel((void **)&e);
		exit(0);
	}
}

void	cleanexit(t_stuff *e)
{
	free(e->img.data);
	mlx_destroy_image(e->img.mlx_ptr, e->img.win_ptr);
	ntmleaks(e);
	ft_memdel((void **)&e);
	exit(0);
}

void	hooks_sd(int keycode, t_stuff *e)
{
	e->pix += 6;
	if (keycode == 53)
		echap(keycode, e);
	else if (keycode == 36)
		movement_matrice(keycode, e);
	else if (keycode == 2 || keycode == 1 || keycode == 14 \
		|| keycode == 49 || keycode == 8 || keycode == 125 || \
		keycode == 126 || keycode == 124 || keycode == 123 || \
		keycode == 78 || keycode == 69 || keycode == 3 || \
		keycode == 126 || keycode == 116 || \
		keycode == 13 || keycode == 15)
		movement(keycode, e);
	e->pix -= 6;
}

int		hooks(int keycode, t_stuff *e)
{
	if (e->i.mat.act_angle == 0 && e->i.mat.act_value == 0 && \
		e->i.nobj.first == -1 && e->i.save.act_save == 0 && e->i.multi == 0 &&\
		(e->i.perlin == 0 || e->i.perlin == 3) && e->i.scr.act_scr == 0 &&\
		e->i.damier == -1)
		if (keycode)
			hooks_sd(keycode, e);
	if (e->i.mat.act_angle == 1 || e->i.mat.act_value == 1 || \
		e->i.nobj.first != -1 || e->i.save.act_save != 0 || e->i.multi != 0 ||\
		e->i.perlin != 0 || e->i.perlin != 3 || e->i.scr.act_scr != 0 ||\
		e->i.damier != -1)
		key_hook_interface(keycode, e);
	return (0);
}
