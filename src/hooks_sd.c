/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_sd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 12:35:13 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 12:35:20 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	matrice_multiobj_sd(t_stuff *e)
{
	searchlist(e, e->i.mobj.start, SPHERE);
	while (e->sph->nm != e->i.mobj.end)
	{
		matrice(e->m.type, e->m.axe, e, &e->sph->pos);
		e->sph = e->sph->next;
	}
	matrice(e->m.type, e->m.axe, e, &e->sph->pos);
	searchlist(e, e->i.mobj.start, SPHERE);
	while (e->sph->nm != e->i.mobj.end)
	{
		e->sph->pos.x -= e->m.tmp_pos.x;
		e->sph->pos.y -= e->m.tmp_pos.y;
		e->sph->pos.z -= e->m.tmp_pos.z;
		e->sph = e->sph->next;
	}
	e->sph->pos.x -= e->m.tmp_pos.x;
	e->sph->pos.y -= e->m.tmp_pos.y;
	e->sph->pos.z -= e->m.tmp_pos.z;
}

void	matrice_multiobj(t_stuff *e)
{
	searchlist(e, e->i.mobj.start, SPHERE);
	e->m.tmp_pos.x = 0 - e->sph->pos.x;
	e->m.tmp_pos.y = 0 - e->sph->pos.y;
	e->m.tmp_pos.z = 0 - e->sph->pos.z;
	while (e->sph->nm != e->i.mobj.end)
	{
		e->sph->pos.x += e->m.tmp_pos.x;
		e->sph->pos.y += e->m.tmp_pos.y;
		e->sph->pos.z += e->m.tmp_pos.z;
		e->sph = e->sph->next;
	}
	e->sph->pos.x += e->m.tmp_pos.x;
	e->sph->pos.y += e->m.tmp_pos.y;
	e->sph->pos.z += e->m.tmp_pos.z;
	matrice_multiobj_sd(e);
}

void	choose_sujet_td(t_stuff *e)
{
	if (e->c.obj == -1)
	{
		if (e->m.type_sujet == 1)
			matrice(e->m.type, e->m.axe, e, &e->poscam);
		else
			matrice(e->m.type, e->m.axe, e, &e->pr);
	}
}

void	choose_sujet_sd(t_stuff *e)
{
	if (e->c.obj == CYLINDRE && e->d.nbmcyl != 0)
	{
		searchlist(e, e->i.each_obj, CYLINDRE);
		if (e->m.type_sujet == 1)
			matrice(e->m.type, e->m.axe, e, &e->cyl->pos);
		else
			matrice(e->m.type, e->m.axe, e, &e->cyl->norm);
	}
	else if (e->c.obj == PLAN && e->d.nbmpla != 0)
	{
		searchlist(e, e->i.each_obj, PLAN);
		if (e->m.type_sujet == 1)
			matrice(e->m.type, e->m.axe, e, &e->pla->pos);
		else
			matrice(e->m.type, e->m.axe, e, &e->pla->norm);
	}
	else if (e->c.obj == CONE && e->d.nbmcone != 0)
	{
		searchlist(e, e->i.each_obj, CONE);
		if (e->m.type_sujet == 1)
			matrice(e->m.type, e->m.axe, e, &e->cone->pos);
		else
			matrice(e->m.type, e->m.axe, e, &e->cone->norm);
	}
}

void	choose_sujet(t_stuff *e)
{
	reboot_list_loop(e, 3);
	e->c.obj = e->i.objet;
	if (e->c.obj == SPHERE && e->d.nbmsph != 0)
	{
		searchlist(e, e->i.each_obj, SPHERE);
		if (e->m.type_sujet == 1)
		{
			if (e->i.mobj.end != 0 && e->sph->nm >= e->i.mobj.start \
				&& e->sph->nm <= e->i.mobj.end)
				matrice_multiobj(e);
			else
				matrice(e->m.type, e->m.axe, e, &e->sph->pos);
		}
	}
	else if (e->c.obj == LIGHT && e->d.nbmlight != 0)
	{
		searchlist(e, e->i.each_obj, LIGHT);
		matrice(e->m.type, e->m.axe, e, &e->light->pos);
	}
	choose_sujet_sd(e);
	choose_sujet_td(e);
}
