/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reboot_multiobj_value.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 09:58:57 by prossi            #+#    #+#             */
/*   Updated: 2018/04/18 14:19:04 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	reboot_multiobj_value_sd(t_stuff *e)
{
	e->i.mobj.len = 0;
	e->i.mobj.ray = 0;
	e->i.mobj.pos.x = 0;
	e->i.mobj.pos.y = 0;
	e->i.mobj.pos.z = 0;
	e->i.mobj.color.r = 0;
	e->i.mobj.color.g = 0;
	e->i.mobj.color.b = 0;
	e->i.mobj.refrac = 0;
	e->i.mobj.reflex = 0;
	e->i.mobj.conscol = 0;
	e->i.mobj.start = 0;
	e->i.mobj.end = 0;
	e->i.multi = 0;
}

void	reboot_multiobj_value(t_stuff *e, int option)
{
	if (option == 0)
	{
		e->i.mobj.len = 0;
		e->i.mobj.ray = 0;
		e->i.mobj.pos.x = 0;
		e->i.mobj.pos.y = 0;
		e->i.mobj.pos.z = 0;
		e->i.mobj.color.r = 0;
		e->i.mobj.color.g = 0;
		e->i.mobj.color.b = 0;
		e->i.mobj.refrac = 0;
		e->i.mobj.reflex = 0;
		e->i.mobj.conscol = 0;
	}
	else
		reboot_multiobj_value_sd(e);
}
