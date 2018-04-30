/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newobj_cylindre.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 09:49:32 by prossi            #+#    #+#             */
/*   Updated: 2018/02/22 23:51:23 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	new_cylindre(t_stuff *e)
{
	t_cyl	*tmp;

	if (e->d.nbmcyl != 0)
	{
		while (e->cyl->next != NULL)
			e->cyl = e->cyl->next;
		tmp = e->cyl;
		init_list_cyl(&e->cyl->next);
		e->cyl = e->cyl->next;
		e->cyl->prev = tmp;
		e->cyl->nm = e->d.nbmcyl;
	}
	e->d.nbmcyl++;
}
