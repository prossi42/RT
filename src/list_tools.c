/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 13:32:49 by prossi            #+#    #+#             */
/*   Updated: 2018/04/13 11:44:35 by lhermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	reboot_list(t_stuff *e)
{
	while (e->sph->prev != NULL)
		e->sph = e->sph->prev;
	while (e->pla->prev != NULL)
		e->pla = e->pla->prev;
	while (e->light->prev != NULL)
		e->light = e->light->prev;
	while (e->cyl->prev != NULL)
		e->cyl = e->cyl->prev;
	while (e->cone->prev != NULL)
		e->cone = e->cone->prev;
}

void	reboot_list_loop(t_stuff *e, int option)
{
	if (option == 1 || option == 3)
	{
		while (e->sph && e->sph->nm > 0)
			e->sph = e->sph->prev;
		while (e->pla && e->pla->nm > 0)
			e->pla = e->pla->prev;
		while (e->cyl && e->cyl->nm > 0)
			e->cyl = e->cyl->prev;
		while (e->cone && e->cone->nm > 0)
			e->cone = e->cone->prev;
	}
	if (option == 2 || option == 3)
	{
		while (e->light && e->light->nm > 0)
		{
			e->light = e->light->prev;
		}
	}
}

void	ntmleaks(t_stuff *e)
{
	while (e->sph)
	{
		free(e->sph);
		e->sph = e->sph->next;
	}
	while (e->pla)
	{
		free(e->pla);
		e->pla = e->pla->next;
	}
	while (e->light)
	{
		free(e->light);
		e->light = e->light->next;
	}
	while (e->cyl)
	{
		free(e->cyl);
		e->cyl = e->cyl->next;
	}
	while (e->cone)
	{
		free(e->cone);
		e->cone = e->cone->next;
	}
}

void	searchlist_sd(t_stuff *e, int nmail, int nlist)
{
	if (nlist == LIGHT)
	{
		while (e->light->nm != nmail)
			e->light = e->light->next;
	}
}

void	searchlist(t_stuff *e, int nmail, int nlist)
{
	reboot_list_loop(e, 1);
	if (nlist == SPHERE)
	{
		while (e->sph->nm != nmail)
			e->sph = e->sph->next;
	}
	if (nlist == PLAN)
	{
		while (e->pla->nm != nmail)
			e->pla = e->pla->next;
	}
	if (nlist == CYLINDRE)
	{
		while (e->cyl->nm != nmail)
			e->cyl = e->cyl->next;
	}
	if (nlist == CONE)
	{
		while (e->cone->nm != nmail)
			e->cone = e->cone->next;
	}
	searchlist_sd(e, nmail, nlist);
}
