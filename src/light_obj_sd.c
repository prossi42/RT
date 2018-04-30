/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_obj_sd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 13:00:06 by jgaillar          #+#    #+#             */
/*   Updated: 2018/04/13 13:00:11 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		light_plan_sd(t_stuff *e, t_vec *tmp)
{
	e->u = 1;
	e->pla->norml = revvec(e->pla->norm);
	*tmp = e->pla->norml;
	if (e->i.objet == PLAN && e->i.wave == 1)
		*tmp = wave(e->pla->norml, e->c.inter, e->m.axe, 0.5);
	vecnorm(tmp);
	if (e->pla->norm.x != 0)
	{
		*tmp = e->pla->norml;
		if (e->i.objet == PLAN && e->i.wave == 1)
			*tmp = wave(e->pla->norml, e->c.inter, e->m.axe, 0.5);
		vecnorm(tmp);
	}
	rgb_add(&e->c.colorf, e->c.colorf, \
		getlight(tmp, &e->light, &e->pla->color, e), 1);
}

void		light_plan(t_stuff *e, t_vec *raydir)
{
	t_vec	tmp;

	searchlist(e, e->c.objpla, PLAN);
	tmp = e->pla->norm;
	if (e->i.objet == PLAN && e->i.wave == 1)
		tmp = wave(e->pla->norm, e->c.inter, e->m.axe, 0.5);
	vecnorm(&e->pla->norm);
	if (dot_product(raydir, &e->pla->norm) < 0)
	{
		rgb_add(&e->c.colorf, e->c.colorf, \
			getlight(&tmp, &e->light, &e->pla->color, e), 1);
	}
	else
		light_plan_sd(e, &tmp);
}
