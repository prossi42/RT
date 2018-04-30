/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 08:07:43 by prossi            #+#    #+#             */
/*   Updated: 2018/04/13 16:05:58 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	del_sphere_td(t_stuff *e, t_sphere *tmp)
{
	if (e->sph->next == NULL && e->sph->prev != NULL)
	{
		tmp = e->sph;
		e->sph = e->sph->prev;
		e->sph->next = NULL;
		free(tmp);
		e->i.each_obj = e->sph->nm;
	}
	else if (e->sph->next != NULL && e->sph->prev == NULL)
		del_sphere_tools_sd(e);
	else if (e->sph->next != NULL && e->sph->prev != NULL)
		del_sphere_tools_td(e);
	else if (e->sph->next == NULL && e->sph->prev == NULL)
		del_sphere_tools_fh(e);
}

void	del_sphere_sd(t_stuff *e, int option, t_sphere *tmp)
{
	if (e->sph->next != NULL)
	{
		option = 1;
		tmp = e->sph->next;
	}
	while (e->sph->nm != e->i.mobj.start)
	{
		e->sph = e->sph->prev;
		free(e->sph->next);
		e->sph->next = NULL;
		e->d.nbmsph--;
	}
	if (e->sph->prev != NULL)
	{
		e->sph = e->sph->prev;
		free(e->sph->next);
		e->sph->next = NULL;
		e->d.nbmsph--;
	}
	else
		del_sphere_tools_fh(e);
	if (option == 1)
		e->sph->next = tmp;
}

void	del_sphere(t_stuff *e)
{
	t_sphere	*tmp;
	int			i;
	int			option;

	i = 0;
	option = 0;
	tmp = NULL;
	searchlist(e, e->i.each_obj, e->i.objet);
	if (e->sph->nm >= e->i.mobj.start && e->sph->nm <= e->i.mobj.end && \
		e->i.mobj.end != 0)
	{
		searchlist(e, e->i.mobj.end, e->i.objet);
		del_sphere_sd(e, option, tmp);
		e->i.each_obj = 0;
		reboot_multiobj_value(e, 1);
	}
	else
		del_sphere_td(e, tmp);
	multi_thread(e);
	apercu_courant(e);
}
