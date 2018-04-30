/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiobj_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 10:34:46 by prossi            #+#    #+#             */
/*   Updated: 2018/04/18 15:11:22 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	set_to_value(t_stuff *e)
{
	e->sph->pos.x = 0;
	e->sph->pos.y = 0;
	e->sph->pos.z = 0;
	e->sph->color.r = e->i.mobj.color.r;
	e->sph->color.g = e->i.mobj.color.g;
	e->sph->color.b = e->i.mobj.color.b;
	e->sph->ray = e->i.mobj.ray;
	e->sph->nm = e->d.nbmsph;
	e->sph->refrac = e->i.mobj.refrac;
	e->sph->conscol = e->i.mobj.conscol;
	e->sph->reflex = e->i.mobj.reflex;
}

void	last_mail_sphere(t_stuff *e)
{
	while (e->sph->next != NULL)
		e->sph = e->sph->next;
}

void	multiobj_create(t_stuff *e)
{
	if (e->i.mobj.len != 0 && e->i.mobj.ray != 0)
	{
		reboot_list_loop(e, 3);
		last_mail_sphere(e);
		if (e->i.multi == 1)
			create_cubesphere(e);
		else if (e->i.multi == 2)
			create_pyrasphere(e);
	}
	else
		reboot_multiobj_value(e, 0);
}
