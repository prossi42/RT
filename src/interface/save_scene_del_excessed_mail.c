/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_scene_del_excessed_mail.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 21:01:21 by prossi            #+#    #+#             */
/*   Updated: 2018/04/17 21:01:30 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	del_excessed_mail_cone(t_stuff *e)
{
	int		tmp_nmail;

	tmp_nmail = e->cone->nm;
	while (e->cone->next != NULL)
		e->cone = e->cone->next;
	while (e->cone->nm != tmp_nmail)
	{
		e->cone = e->cone->prev;
		free(e->cone->next);
		e->cone->next = NULL;
	}
}

void	del_excessed_mail_cylindre(t_stuff *e)
{
	int		tmp_nmail;

	tmp_nmail = e->cyl->nm;
	while (e->cyl->next != NULL)
		e->cyl = e->cyl->next;
	while (e->cyl->nm != tmp_nmail)
	{
		e->cyl = e->cyl->prev;
		free(e->cyl->next);
		e->cyl->next = NULL;
	}
}

void	del_excessed_mail_light(t_stuff *e)
{
	int			tmp_nmail;

	tmp_nmail = e->light->nm;
	while (e->light->next != NULL)
		e->light = e->light->next;
	while (e->light->nm != tmp_nmail)
	{
		e->light = e->light->prev;
		free(e->light->next);
		e->light->next = NULL;
	}
}

void	del_excessed_mail_plan(t_stuff *e)
{
	int		tmp_nmail;

	tmp_nmail = e->pla->nm;
	while (e->pla->next != NULL)
		e->pla = e->pla->next;
	while (e->pla->nm != tmp_nmail)
	{
		e->pla = e->pla->prev;
		free(e->pla->next);
		e->pla->next = NULL;
	}
}

void	del_excessed_mail_sphere(t_stuff *e)
{
	int		tmp_nmail;

	tmp_nmail = e->sph->nm;
	while (e->sph->next != NULL)
		e->sph = e->sph->next;
	while (e->sph->nm != tmp_nmail)
	{
		e->sph = e->sph->prev;
		free(e->sph->next);
		e->sph->next = NULL;
	}
}
