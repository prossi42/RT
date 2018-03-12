/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newobj_plan.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 09:28:46 by prossi            #+#    #+#             */
/*   Updated: 2018/02/22 23:51:29 by Awk-LM           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	new_plan(t_stuff *e)
{
	t_plan		*tmp;

	if (e->d.nbmpla != 0)
	{
		while (e->pla->next != NULL)
			e->pla = e->pla->next;
		tmp = e->pla;
		init_list_pla(&e->pla->next);
		e->pla = e->pla->next;
		e->pla->prev = tmp;
		e->pla->nm = e->d.nbmpla;
	}
	e->d.nbmpla++;
}
