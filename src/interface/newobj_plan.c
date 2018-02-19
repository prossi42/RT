/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newobj_plan.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 09:28:46 by prossi            #+#    #+#             */
/*   Updated: 2018/02/19 09:31:49 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	new_plan(t_stuff *e)
{
	t_plan		*tmp;

	if (e->d.nbmpla != 0)
	{
		while (e->pla->next != NULL)
			e->pla = e->pla->next;
		tmp = e->pla;
		init_list_pla(&e->pla->next);
		e->pla = e->pla->next;
		e->pla->prev = tmp;
		e->pla->nm = e->d.nbmpla;
	}
	e->d.nbmpla++;
	set_value_new_objet(e);
}

void	newobj_plan_td(t_stuff *e)
{
	searchlist(e, e->i.each_obj, e->i.objet);
	if (e->pla->next != NULL)
	{
		e->pla = e->pla->next;
		e->i.each_obj = e->pla->nm;
	}
}

void	newobj_plan_sd(t_stuff *e)
{
	searchlist(e, e->i.each_obj, e->i.objet);
	if (e->pla->prev != NULL)
	{
		e->pla = e->pla->prev;
		e->i.each_obj = e->pla->nm;
	}
}

void	newobj_plan(t_stuff *e, int x)
{
	if (x >= ((WIN_X - WIDTH) / 4) && x <= ((WIN_X - WIDTH) / 4) * 3)
	{
		e->i.objet = PLAN;
		e->i.nobj.act_obj = 2;
		e->i.each_obj = 0;
	}
	else if (x >= (((WIN_X - WIDTH) / 4) - 30) && x <= (((WIN_X - WIDTH) / 4) - 5) && e->i.nobj.act_obj == 2)
		newobj_plan_sd(e);
	else if (x >= ((((WIN_X - WIDTH) / 4) * 3) + 5) && x <= ((((WIN_X - WIDTH) / 4) * 3) + 30)  && e->i.nobj.act_obj == 2)
		newobj_plan_td(e);
	else if (x >= (((WIN_X - WIDTH) / 4) * 3) + 70 && x <= (((WIN_X - WIDTH) / 4) * 3) + 95 && e->i.nobj.act_obj == 2)
		new_plan(e);
	else if (x >= (e->i.mlx->img_x / 4) - 90 && x <= (e->i.mlx->img_x / 4) - 70 && e->i.nobj.act_obj == 2)
		del_plan(e);
}
