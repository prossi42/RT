/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_end_aff_newobj.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 16:10:21 by prossi            #+#    #+#             */
/*   Updated: 2018/04/16 16:10:26 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	end_aff_newobj(t_stuff *e)
{
	if (e->i.objet == SPHERE)
		end_aff_new_sphere(e);
	else if (e->i.objet == PLAN)
		end_aff_new_plan(e);
	else if (e->i.objet == CYLINDRE)
		end_aff_new_cylindre(e);
	else if (e->i.objet == CONE)
		end_aff_new_cone(e);
	else if (e->i.objet == LIGHT)
		end_aff_new_light(e);
}
