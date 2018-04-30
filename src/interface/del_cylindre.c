/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_cylindre.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 09:58:52 by prossi            #+#    #+#             */
/*   Updated: 2018/04/13 15:35:53 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	del_cylindre_fh(t_stuff *e)
{
	e->cyl->pos.x = 0;
	e->cyl->pos.y = 0;
	e->cyl->pos.z = 0;
	e->cyl->norm.x = 0;
	e->cyl->norm.y = 0;
	e->cyl->norm.z = 0;
	e->cyl->color.r = 0;
	e->cyl->color.g = 0;
	e->cyl->color.b = 0;
	e->cyl->refrac = 0;
	e->cyl->reflex = 0;
	e->cyl->conscol = 0;
	e->cyl->ray = 0;
	e->d.nbmcyl = 0;
	e->cyl->nm = 0;
	e->i.each_obj = 0;
}

void	del_cylindre_td(t_stuff *e)
{
	t_cyl	*tmp;
	t_cyl	*tmp2;

	tmp = e->cyl;
	e->cyl = e->cyl->prev;
	tmp2 = e->cyl;
	e->cyl = e->cyl->next;
	e->cyl = e->cyl->next;
	e->cyl->prev = tmp2;
	tmp2->next = e->cyl;
	free(tmp);
	e->i.each_obj = e->cyl->nm;
}

void	del_cylindre_sd(t_stuff *e)
{
	e->cyl->pos.x = 0;
	e->cyl->pos.y = 0;
	e->cyl->pos.z = 0;
	e->cyl->norm.x = 0;
	e->cyl->norm.y = 0;
	e->cyl->norm.z = 0;
	e->cyl->color.r = 0;
	e->cyl->color.g = 0;
	e->cyl->color.b = 0;
	e->cyl->refrac = 0;
	e->cyl->reflex = 0;
	e->cyl->conscol = 0;
	e->cyl->ray = 0;
}

void	del_cylindre(t_stuff *e)
{
	t_cyl	*tmp;

	searchlist(e, e->i.each_obj, e->i.objet);
	if (e->cyl->next == NULL && e->cyl->prev != NULL)
	{
		tmp = e->cyl;
		e->cyl = e->cyl->prev;
		e->cyl->next = NULL;
		free(tmp);
		e->i.each_obj = e->cyl->nm;
	}
	else if (e->cyl->next != NULL && e->cyl->prev == NULL)
		del_cylindre_sd(e);
	else if (e->cyl->next != NULL && e->cyl->prev != NULL)
		del_cylindre_td(e);
	else if (e->cyl->next == NULL && e->cyl->prev == NULL)
		del_cylindre_fh(e);
	multi_thread(e);
	apercu_courant(e);
}
