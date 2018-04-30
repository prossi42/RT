/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_plan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 09:36:38 by prossi            #+#    #+#             */
/*   Updated: 2018/04/13 15:40:09 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	del_plan_fh(t_stuff *e)
{
	e->pla->pos.x = 0;
	e->pla->pos.y = 0;
	e->pla->pos.z = 0;
	e->pla->norm.x = 0;
	e->pla->norm.y = 0;
	e->pla->norm.z = 0;
	e->pla->color.r = 0;
	e->pla->color.g = 0;
	e->pla->color.b = 0;
	e->pla->refrac = 0;
	e->pla->reflex = 0;
	e->pla->conscol = 0;
	e->d.nbmpla = 0;
	e->pla->nm = 0;
	e->i.each_obj = 0;
}

void	del_plan_td(t_stuff *e)
{
	t_plan	*tmp;
	t_plan	*tmp2;

	tmp = e->pla;
	e->pla = e->pla->prev;
	tmp2 = e->pla;
	e->pla = e->pla->next;
	e->pla = e->pla->next;
	e->pla->prev = tmp2;
	tmp2->next = e->pla;
	free(tmp);
	e->i.each_obj = e->pla->nm;
}

void	del_plan_sd(t_stuff *e)
{
	e->pla->pos.x = 0;
	e->pla->pos.y = 0;
	e->pla->pos.z = 0;
	e->pla->norm.x = 0;
	e->pla->norm.y = 0;
	e->pla->norm.z = 0;
	e->pla->color.r = 0;
	e->pla->color.g = 0;
	e->pla->color.b = 0;
	e->pla->refrac = 0;
	e->pla->reflex = 0;
	e->pla->conscol = 0;
}

void	del_plan(t_stuff *e)
{
	t_plan *tmp;

	searchlist(e, e->i.each_obj, e->i.objet);
	if (e->pla->next == NULL && e->pla->prev != NULL)
	{
		tmp = e->pla;
		e->pla = e->pla->prev;
		e->pla->next = NULL;
		free(tmp);
		e->i.each_obj = e->pla->nm;
	}
	else if (e->pla->next != NULL && e->pla->prev == NULL)
		del_plan_sd(e);
	else if (e->pla->next != NULL && e->pla->prev != NULL)
		del_plan_td(e);
	else if (e->pla->next == NULL && e->pla->prev == NULL)
		del_plan_fh(e);
	multi_thread(e);
	apercu_courant(e);
}
