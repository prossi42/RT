/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 10:42:49 by prossi            #+#    #+#             */
/*   Updated: 2018/04/13 15:37:40 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	del_cone_fh(t_stuff *e)
{
	e->cone->pos.x = 0;
	e->cone->pos.y = 0;
	e->cone->pos.z = 0;
	e->cone->norm.x = 0;
	e->cone->norm.y = 0;
	e->cone->norm.z = 0;
	e->cone->color.r = 0;
	e->cone->color.g = 0;
	e->cone->color.b = 0;
	e->cone->angle = 0;
	e->cone->refrac = 0;
	e->cone->reflex = 0;
	e->cone->conscol = 0;
	e->d.nbmcone = 0;
	e->cone->nm = 0;
	e->i.each_obj = 0;
}

void	del_cone_td(t_stuff *e)
{
	t_cone	*tmp;
	t_cone	*tmp2;

	tmp = e->cone;
	e->cone = e->cone->prev;
	tmp2 = e->cone;
	e->cone = e->cone->next;
	e->cone = e->cone->next;
	e->cone->prev = tmp2;
	tmp2->next = e->cone;
	free(tmp);
	e->i.each_obj = e->cone->nm;
}

void	del_cone_sd(t_stuff *e)
{
	e->cone->pos.x = 0;
	e->cone->pos.y = 0;
	e->cone->pos.z = 0;
	e->cone->norm.x = 0;
	e->cone->norm.y = 0;
	e->cone->norm.z = 0;
	e->cone->color.r = 0;
	e->cone->color.g = 0;
	e->cone->color.b = 0;
	e->cone->angle = 0;
	e->cone->refrac = 0;
	e->cone->reflex = 0;
	e->cone->conscol = 0;
}

void	del_cone(t_stuff *e)
{
	t_cone	*tmp;

	searchlist(e, e->i.each_obj, e->i.objet);
	if (e->cone->next == NULL && e->cone->prev != NULL)
	{
		tmp = e->cone;
		e->cone = e->cone->prev;
		e->cone->next = NULL;
		free(tmp);
		e->i.each_obj = e->cone->nm;
	}
	else if (e->cone->next != NULL && e->cone->prev == NULL)
		del_cone_sd(e);
	else if (e->cone->next != NULL && e->cone->prev != NULL)
		del_cone_td(e);
	else if (e->cone->next == NULL && e->cone->prev == NULL)
		del_cone_fh(e);
	multi_thread(e);
	apercu_courant(e);
}
