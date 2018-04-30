/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newobj_cone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 10:25:11 by prossi            #+#    #+#             */
/*   Updated: 2018/02/22 23:50:19 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	new_cone(t_stuff *e)
{
	t_cone		*tmp;

	if (e->d.nbmcone != 0)
	{
		while (e->cone->next != NULL)
			e->cone = e->cone->next;
		tmp = e->cone;
		init_list_cone(&e->cone->next);
		e->cone = e->cone->next;
		e->cone->prev = tmp;
		e->cone->nm = e->d.nbmcone;
	}
	e->d.nbmcone++;
}
