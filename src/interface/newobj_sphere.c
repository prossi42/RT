/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newobj_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 09:23:37 by prossi            #+#    #+#             */
/*   Updated: 2018/02/22 23:52:37 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	new_sphere(t_stuff *e)
{
	t_sphere	*tmp;

	if (e->d.nbmsph != 0)
	{
		while (e->sph->next != NULL)
			e->sph = e->sph->next;
		tmp = e->sph;
		init_list_sph(&e->sph->next);
		e->sph = e->sph->next;
		e->sph->prev = tmp;
		e->sph->nm = e->d.nbmsph;
	}
	e->d.nbmsph++;
}
