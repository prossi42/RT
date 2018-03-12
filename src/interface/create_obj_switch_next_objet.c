/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_obj_switch_next_objet.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Awk-LM <Awk-LM@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 23:33:35 by Awk-LM            #+#    #+#             */
/*   Updated: 2018/02/22 23:50:52 by Awk-LM           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	switch_next_objet(t_stuff *e)
{
	if (e->i.objet == -1)
		ft_putendl("En construction...");
	else if (e->i.objet == SPHERE)
	{
		searchlist(e, e->i.each_obj, e->i.objet);
		if (e->sph->next != NULL)
		{
			e->sph = e->sph->next;
			e->i.each_obj = e->sph->nm;
		}
	}
	else if (e->i.objet == PLAN)
	{
		searchlist(e, e->i.each_obj, e->i.objet);
		if (e->pla->next != NULL)
		{
			e->pla = e->pla->next;
			e->i.each_obj = e->pla->nm;
		}
	}
	else if (e->i.objet == LIGHT)
	{
		searchlist(e, e->i.each_obj, e->i.objet);
		if (e->light->next != NULL)
		{
			e->light = e->light->next;
			e->i.each_obj = e->light->nm;
		}
	}
	else if (e->i.objet == CONE)
	{
		searchlist(e, e->i.each_obj, e->i.objet);
		if (e->cone->next != NULL)
		{
			e->cone = e->cone->next;
			e->i.each_obj = e->cone->nm;
		}
	}
	else
	{
		searchlist(e, e->i.each_obj, e->i.objet);
		if (e->cyl->next != NULL)
		{
			e->cyl = e->cyl->next;
			e->i.each_obj = e->cyl->nm;
		}
	}
}
