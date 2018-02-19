/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newobj_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 10:56:19 by prossi            #+#    #+#             */
/*   Updated: 2018/02/19 10:58:22 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	new_light(t_stuff *e)
{
	t_light		*tmp;

	if (e->d.nbmlight != 0)
	{
		while (e->light->next != NULL)
			e->light = e->light->next;
		tmp = e->light;
		init_list_light(&e->light->next);
		e->light = e->light->next;
		e->light->prev = tmp;
		e->light->nm = e->d.nbmlight;
	}
	e->d.nbmlight++;
	set_value_new_objet(e);
}

void	newobj_light_td(t_stuff *e)
{
	searchlist(e, e->i.each_obj, e->i.objet);
	if (e->light->next != NULL)
	{
		e->light = e->light->next;
		e->i.each_obj = e->light->nm;
	}
}

void	newobj_light_sd(t_stuff *e)
{
	searchlist(e, e->i.each_obj, e->i.objet);
	if (e->light->prev != NULL)
	{
		e->light = e->light->prev;
		e->i.each_obj = e->light->nm;
	}
}

void	newobj_light(t_stuff *e, int x)
{
	if (x >= ((WIN_X - WIDTH) / 4) && x <= ((WIN_X - WIDTH) / 4) * 3)
	{
		e->i.objet = LIGHT;
		e->i.nobj.act_obj = 5;
		e->i.each_obj = 0;
	}
	else if (x >= (((WIN_X - WIDTH) / 4) - 30) && x <= (((WIN_X - WIDTH) / 4) - 5) && e->i.nobj.act_obj == 5)
		newobj_light_sd(e);
	else if (x >= ((((WIN_X - WIDTH) / 4) * 3) + 5) && x <= ((((WIN_X - WIDTH) / 4) * 3) + 30) && e->i.nobj.act_obj == 5)
		newobj_light_td(e);
	else if (x >= (((WIN_X - WIDTH) / 4) * 3) + 70 && x <= (((WIN_X - WIDTH) / 4) * 3) + 95 && e->i.nobj.act_obj == 5)
		new_light(e);
	else if (x >= (e->i.mlx->img_x / 4) - 90 && x <= (e->i.mlx->img_x / 4) - 70 && e->i.nobj.act_obj == 5)
		del_light(e);
}
