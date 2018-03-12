/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Awk-LM <Awk-LM@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 08:07:43 by Awk-LM            #+#    #+#             */
/*   Updated: 2018/02/19 08:15:00 by Awk-LM           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	del_sphere_fh(t_stuff *e)
{
	e->sph->pos.x = 0;
	e->sph->pos.y = 0;
	e->sph->pos.z = 0;
	e->sph->color.r = 0;
	e->sph->color.g = 0;
	e->sph->color.b = 0;
	e->sph->ray = 0;
	e->d.nbmsph = 0;
	e->sph->nm = 0;
	e->i.each_obj = 0;
}

void	del_sphere_td(t_stuff *e)
{
	t_sphere	*tmp;
	t_sphere	*tmp2;

	tmp = e->sph;
	e->sph = e->sph->prev;
	tmp2 = e->sph;
	e->sph = e->sph->next;
	e->sph = e->sph->next;
	e->sph->prev = tmp2;
	tmp2->next = e->sph;
	free(tmp);
	e->i.each_obj = e->sph->nm;
}

void	del_sphere_sd(t_stuff *e)
{
	t_sphere	*tmp;

	tmp = e->sph;
	e->sph = e->sph->next;
	e->sph->prev = NULL;
	free(tmp);
	e->i.each_obj = e->sph->nm;
	e->tmp = e->sph;
}

void	del_sphere(t_stuff *e)
{
	t_sphere	*tmp;

	searchlist(e, e->i.each_obj, e->i.objet);
	if (e->sph->next == NULL && e->sph->prev != NULL)
	{
		tmp = e->sph;
		e->sph = e->sph->prev;
		e->sph->next = NULL;
		free(tmp);
		e->i.each_obj = e->sph->nm;
	}
	else if (e->sph->next != NULL && e->sph->prev == NULL)
		del_sphere_sd(e);
	else if (e->sph->next != NULL && e->sph->prev != NULL)
		del_sphere_td(e);
	else if (e->sph->next == NULL && e->sph->prev == NULL)
		del_sphere_fh(e);
	multi_thread(e);
	multi_thread2(e);
}
