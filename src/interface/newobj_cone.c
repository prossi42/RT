/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newobj_cone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 10:25:11 by prossi            #+#    #+#             */
/*   Updated: 2018/02/19 10:49:35 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	new_cone(t_stuff *e)
{
	t_cone		*tmp;

	if (e->d.nbmcone != 0)
	{
		while (e->cone->next != NULL)
			e->cone = e->cone->next;
		tmp = e->cone;
		init_list_cone(&e->cone->next);
		e->cone = e->cone->next;
		e->cone->prev = tmp;
		e->cone->nm = e->d.nbmcone;
	}
	e->d.nbmcone++;
	set_value_new_objet(e);
}

void	newobj_cone_td(t_stuff *e)
{
	searchlist(e, e->i.each_obj, e->i.objet);
	if (e->cone->next != NULL)
	{
		e->cone = e->cone->next;
		e->i.each_obj = e->cone->nm;
	}
}

void	newobj_cone_sd(t_stuff *e)
{
	searchlist(e, e->i.each_obj, e->i.objet);
	if (e->cone->prev != NULL)
	{
		e->cone = e->cone->prev;
		e->i.each_obj = e->cone->nm;
	}
}

void	newobj_cone(t_stuff *e, int x)
{
	if (x >= ((WIN_X - WIDTH) / 4) && x <= ((WIN_X - WIDTH) / 4) * 3)
	{
		e->i.objet = CONE;
		e->i.nobj.act_obj = 4;
		e->i.each_obj = 0;
	}
	else if (x >= (((WIN_X - WIDTH) / 4) - 30) && x <= (((WIN_X - WIDTH) / 4) - 5) && e->i.nobj.act_obj == 4)
		newobj_cone_sd(e);
	else if (x >= ((((WIN_X - WIDTH) / 4) * 3) + 5) && x <= ((((WIN_X - WIDTH) / 4) * 3) + 30) && e->i.nobj.act_obj == 4)
		newobj_cone_td(e);
	else if (x >= (((WIN_X - WIDTH) / 4) * 3) + 70 && x <= (((WIN_X - WIDTH) / 4) * 3) + 95 && e->i.nobj.act_obj == 4)
		new_cone(e);
	else if (x >= (e->i.mlx->img_x / 4) - 90 && x <= (e->i.mlx->img_x / 4) - 70 && e->i.nobj.act_obj == 4)
		del_cone(e);
}
