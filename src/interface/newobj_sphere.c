/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newobj_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 09:23:37 by prossi            #+#    #+#             */
/*   Updated: 2018/02/19 09:25:44 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	new_sphere(t_stuff *e)
{
	t_sphere	*tmp;

	if (e->d.nbmsph != 0)
	{
		while (e->sph->next != NULL)
			e->sph = e->sph->next;
		tmp = e->sph;
		init_list_sph(&e->sph->next);
		e->sph = e->sph->next;
		e->sph->prev = tmp;
		e->sph->nm = e->d.nbmsph;
	}
	e->d.nbmsph++;
	set_value_new_objet(e);
}

void	newobj_sphere_td(t_stuff *e)
{
	searchlist(e, e->i.each_obj, e->i.objet);
	if (e->sph->next != NULL)
	{
		e->sph = e->sph->next;
		e->i.each_obj = e->sph->nm;
	}
}

void	newobj_sphere_sd(t_stuff *e)
{
	searchlist(e, e->i.each_obj, e->i.objet);
	if (e->sph->prev != NULL)
	{
		e->sph = e->sph->prev;
		e->i.each_obj = e->sph->nm;
	}
}

void	newobj_sphere(t_stuff *e, int x)
{
	if (x >= ((WIN_X - WIDTH) / 4) && x <= ((WIN_X - WIDTH) / 4) * 3)
	{
		e->i.objet = SPHERE;
		e->i.nobj.act_obj = 1;
		e->i.each_obj = 0;
	}
	else if (x >= (((WIN_X - WIDTH) / 4) - 30) && x <= (((WIN_X - WIDTH) / 4) - 5) && e->i.nobj.act_obj == 1)
		newobj_sphere_sd(e);
	else if (x >= ((((WIN_X - WIDTH) / 4) * 3) + 5) && x <= ((((WIN_X - WIDTH) / 4) * 3) + 30)  && e->i.nobj.act_obj == 1)
		newobj_sphere_td(e);
	else if (x >= (((WIN_X - WIDTH) / 4) * 3) + 70 && x <= (((WIN_X - WIDTH) / 4) * 3) + 95 && e->i.nobj.act_obj == 1)
		new_sphere(e);
	else if (x >= (e->i.mlx->img_x / 4) - 90 && x <= (e->i.mlx->img_x / 4) - 70 && e->i.nobj.act_obj == 1)
		del_sphere(e);
}
