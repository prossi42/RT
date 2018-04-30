/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_interface_sd.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 16:36:10 by prossi            #+#    #+#             */
/*   Updated: 2018/04/13 16:37:32 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	init_struct_sh(t_stuff *e, int option)
{
	if (option == 8 && e->i.first == 0)
	{
		e->i.filtre = 0;
		e->i.multi = 0;
		e->i.mobj.len = 0;
		e->i.mobj.ray = 0;
		e->i.mobj.pos.x = 0;
		e->i.mobj.pos.y = 0;
		e->i.mobj.pos.z = 0;
		e->i.mobj.refrac = 0;
		e->i.mobj.reflex = 0;
		e->i.mobj.conscol = 0;
		e->i.mobj.first = 0;
		e->i.mobj.start = 0;
		e->i.mobj.end = 0;
		e->i.scr.act_scr = 0;
	}
}
