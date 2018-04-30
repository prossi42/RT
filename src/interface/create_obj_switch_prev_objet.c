/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_obj_switch_prev_objet.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 23:45:37 by prossi            #+#    #+#             */
/*   Updated: 2018/04/10 08:30:31 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	switch_prev_objet_td(t_stuff *e)
{
	searchlist(e, e->i.each_obj, e->i.objet);
	if (e->cyl->prev != NULL)
	{
		e->cyl = e->cyl->prev;
		e->i.each_obj = e->cyl->nm;
	}
}

void	switch_prev_objet_sd(t_stuff *e)
{
	if (e->i.objet == LIGHT)
	{
		searchlist(e, e->i.each_obj, e->i.objet);
		if (e->light->prev != NULL)
		{
			e->light = e->light->prev;
			e->i.each_obj = e->light->nm;
		}
	}
	else if (e->i.objet == CONE)
	{
		searchlist(e, e->i.each_obj, e->i.objet);
		if (e->cone->prev != NULL)
		{
			e->cone = e->cone->prev;
			e->i.each_obj = e->cone->nm;
		}
	}
}

void	switch_prev_objet(t_stuff *e)
{
	if (e->i.objet == -1)
		ft_putendl("En construction...");
	else if (e->i.objet == SPHERE)
	{
		searchlist(e, e->i.each_obj, e->i.objet);
		if (e->sph->prev != NULL)
		{
			e->sph = e->sph->prev;
			e->i.each_obj = e->sph->nm;
		}
	}
	else if (e->i.objet == PLAN)
	{
		searchlist(e, e->i.each_obj, e->i.objet);
		if (e->pla->prev != NULL)
		{
			e->pla = e->pla->prev;
			e->i.each_obj = e->pla->nm;
		}
	}
	else if (e->i.objet == LIGHT || e->i.objet == CONE)
		switch_prev_objet_sd(e);
	else
		switch_prev_objet_td(e);
}
