/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_sphere_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 15:57:06 by prossi            #+#    #+#             */
/*   Updated: 2018/04/13 15:57:38 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	del_sphere_tools_fh(t_stuff *e)
{
	e->sph->pos.x = 0;
	e->sph->pos.y = 0;
	e->sph->pos.z = 0;
	e->sph->color.r = 0;
	e->sph->color.g = 0;
	e->sph->color.b = 0;
	e->sph->ray = 0;
	e->sph->refrac = 0;
	e->sph->conscol = 0;
	e->sph->reflex = 0;
	e->d.nbmsph = 0;
	e->sph->nm = 0;
	e->i.each_obj = 0;
}

void	del_sphere_tools_td(t_stuff *e)
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

void	del_sphere_tools_sd(t_stuff *e)
{
	e->sph->pos.x = 0;
	e->sph->pos.y = 0;
	e->sph->pos.z = 0;
	e->sph->color.r = 0;
	e->sph->color.g = 0;
	e->sph->color.b = 0;
	e->sph->ray = 0;
	e->sph->refrac = 0;
	e->sph->conscol = 0;
	e->sph->reflex = 0;
}
