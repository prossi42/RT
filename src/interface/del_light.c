/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 10:58:28 by prossi            #+#    #+#             */
/*   Updated: 2018/02/19 11:09:31 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	del_light_fh(t_stuff *e)
{
	e->light->pos.x = 0;
	e->light->pos.y = 0;
	e->light->pos.z = 0;
	e->light->color.r = 0;
	e->light->color.g = 0;
	e->light->color.b = 0;
	e->light->ray = 0;
	e->d.nbmlight = 0;
	e->light->nm = 0;
	e->i.each_obj = 0;
}

void	del_light_td(t_stuff *e)
{
	t_light	*tmp;
	t_light	*tmp2;

	tmp = e->light;
	e->light = e->light->prev;
	tmp2 = e->light;
	e->light = e->light->next;
	e->light = e->light->next;
	e->light->prev = tmp2;
	tmp2->next = e->light;
	free(tmp);
	e->i.each_obj = e->light->nm;
}

void	del_light_sd(t_stuff *e)
{
	t_light	*tmp;

	tmp = e->light;
	e->light = e->light->next;
	e->light->prev = NULL;
	free(tmp);
	e->i.each_obj = e->light->nm;
	e->tmplight = e->light;
}

void	del_light(t_stuff *e)
{
	t_light	*tmp;

	searchlist(e, e->i.each_obj, e->i.objet);
	if (e->light->next == NULL && e->light->prev != NULL)
	{
		tmp = e->light;
		e->light = e->light->prev;
		e->light->next = NULL;
		free(tmp);
		e->i.each_obj = e->light->nm;
	}
	else if (e->light->next != NULL && e->light->prev == NULL)
		del_light_sd(e);
	else if (e->light->next != NULL && e->light->prev != NULL)
		del_light_td(e);
	else if (e->light->next == NULL && e->light->prev == NULL)
		del_light_fh(e);
	aff(e);
}
