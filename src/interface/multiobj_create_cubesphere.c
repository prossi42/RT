/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiobj_create_cubesphere.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:24:39 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 10:25:54 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	fill_value_cubesphere_sd(t_stuff *e, t_pos pos)
{
	e->sph->pos.x = pos.x;
	e->sph->pos.y = pos.y;
	e->sph->pos.z = pos.z;
	if (e->sph->next != NULL)
		e->sph = e->sph->next;
}

void	fill_value_cubesphere(t_stuff *e)
{
	int		x;
	int		y;
	int		z;
	t_pos	pos;

	z = -1;
	pos.z = e->i.mobj.pos.z;
	while (++z < e->i.mobj.len)
	{
		y = -1;
		pos.x = e->i.mobj.pos.x;
		while (++y < e->i.mobj.len)
		{
			x = -1;
			pos.y = e->i.mobj.pos.y;
			while (++x < e->i.mobj.len)
			{
				fill_value_cubesphere_sd(e, pos);
				pos.y -= e->i.mobj.ray * 2;
			}
			pos.x += e->i.mobj.ray * 2;
		}
		pos.z += e->i.mobj.ray * 2;
	}
	e->i.mobj.end = e->sph->nm;
}

void	create_cubesphere_sd(t_stuff *e, int tot_sph)
{
	if (e->d.nbmsph - tot_sph != 0)
	{
		e->sph = e->sph->next;
	}
	e->i.mobj.start = e->sph->nm;
	fill_value_cubesphere(e);
}

void	create_cubesphere(t_stuff *e)
{
	int			i;
	t_sphere	*tmp;
	t_sphere	*tmp2;
	int			tot_sph;

	i = -1;
	tmp2 = e->sph;
	tot_sph = e->i.mobj.len * e->i.mobj.len * e->i.mobj.len;
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
	e->sph = tmp2;
	create_cubesphere_sd(e, tot_sph);
}
