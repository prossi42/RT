/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newobj_plan.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 09:28:46 by prossi            #+#    #+#             */
/*   Updated: 2018/02/22 23:51:29 by Awk-LM           ###   ########.fr       */
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

void	newobj_plan(t_stuff *e, int x)
{
	if (x >= ((WIN_X - WIDTH) / 4) && x <= ((WIN_X - WIDTH) / 4) * 3)
	{
		e->i.objet = PLAN;
		e->i.each_obj = 0;
	}
	else if (x >= (((WIN_X - WIDTH) / 4) * 3) + 70 && x <= (((WIN_X - WIDTH) / 4) * 3) + 95 && e->i.nobj.act_obj == 2)
		new_plan(e);
	else if (x >= (e->i.mlx->img_x / 4) - 90 && x <= (e->i.mlx->img_x / 4) - 70 && e->i.nobj.act_obj == 2)
		del_plan(e);
}
