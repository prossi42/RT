/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiobj_create_pyrasphere.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:26:10 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 10:26:10 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	fill_value_pyrasphere(t_stuff *e)
{
	int		x;
	int		y;
	int		posx;
	int		posy;
	int		posz;

	x = -1;
	posx = e->i.mobj.pos.x;
	posz = e->i.mobj.pos.z;
	while (++x < e->i.mobj.len)
	{
		y = -1;
		posy = e->i.mobj.pos.y;
		while (++y < e->i.mobj.len)
		{
			e->sph->pos.x = posx;
			e->sph->pos.y = posy;
			e->sph->pos.z = posz;
			if (e->sph->next != NULL)
				e->sph = e->sph->next;
			posy -= e->i.mobj.ray * 2;
		}
		posx += e->i.mobj.ray * 2;
	}
}

void	create_pyrasphere_sd(t_stuff *e, int tot_sph, t_sphere *tmp2)
{
	e->sph = tmp2;
	if (e->d.nbmsph - tot_sph != 0)
		e->sph = e->sph->next;
	e->i.mobj.start = e->sph->nm;
	while (e->i.mobj.len > 0)
	{
		fill_value_pyrasphere(e);
		e->i.mobj.pos.z += e->i.mobj.ray;
		e->i.mobj.pos.x += e->i.mobj.ray;
		e->i.mobj.pos.y -= e->i.mobj.ray;
		e->i.mobj.len--;
	}
	e->i.mobj.end = e->sph->nm;
}

void	create_pyrasphere(t_stuff *e)
{
	int			i;
	t_sphere	*tmp;
	t_sphere	*tmp2;
	int			tot_sph;
	int			tmp_len;

	i = -1;
	tmp2 = e->sph;
	tot_sph = 0;
	tmp_len = e->i.mobj.len + 1;
	while (--tmp_len > 0)
		tot_sph += tmp_len * tmp_len;
	while (++i < tot_sph)
	{
		if (e->d.nbmsph != 0)
		{
			tmp = e->sph;
			init_list_sph(&e->sph->next);
			e->sph = e->sph->next;
			e->sph->prev = tmp;
		}
		set_to_value(e);
		e->d.nbmsph++;
	}
	create_pyrasphere_sd(e, tot_sph, tmp2);
}
