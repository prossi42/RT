/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newobj_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 10:56:19 by prossi            #+#    #+#             */
/*   Updated: 2018/02/22 23:51:26 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	new_light(t_stuff *e)
{
	t_light		*tmp;

	if (e->d.nbmlight != 0)
	{
		while (e->light->next != NULL)
			e->light = e->light->next;
		tmp = e->light;
		init_list_light(&e->light->next);
		e->light = e->light->next;
		e->light->prev = tmp;
		e->light->nm = e->d.nbmlight;
	}
	e->d.nbmlight++;
}
