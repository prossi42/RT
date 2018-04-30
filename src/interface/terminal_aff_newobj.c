/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_aff_newobj.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 16:12:57 by prossi            #+#    #+#             */
/*   Updated: 2018/04/16 16:13:10 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	aff_new_obj(t_stuff *e)
{
	if (e->i.objet == SPHERE)
		aff_new_sphere(e);
	else if (e->i.objet == PLAN)
		aff_new_plan(e);
	else if (e->i.objet == CYLINDRE)
		aff_new_cylindre(e);
	else if (e->i.objet == CONE)
		aff_new_cone(e);
	else if (e->i.objet == LIGHT)
		aff_new_light(e);
}
