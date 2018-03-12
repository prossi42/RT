/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newobj_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 09:23:37 by prossi            #+#    #+#             */
/*   Updated: 2018/02/22 23:52:37 by Awk-LM           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	new_sphere(t_stuff *e)
{
	t_sphere	*tmp;

	if (e->d.nbmsph != 0)
	{
		while (e->sph->next != NULL)
			e->sph = e->sph->next;
		tmp = e->sph;
		init_list_sph(&e->sph->next);
		e->sph = e->sph->next;
		e->sph->prev = tmp;
		e->sph->nm = e->d.nbmsph;
	}
	e->d.nbmsph++;
	set_value_new_objet(e);
}

void	newobj_sphere(t_stuff *e, int x)
{
	if (x == 0)
		ft_putstr("NTM");
	else if (x >= (((WIN_X - WIDTH) / 4) * 3) + 70 && x <= (((WIN_X - WIDTH) / 4) * 3) + 95 && e->i.nobj.act_obj == 1)
		new_sphere(e);
	else if (x >= (e->i.mlx->img_x / 4) - 90 && x <= (e->i.mlx->img_x / 4) - 70 && e->i.nobj.act_obj == 1)
		del_sphere(e);
}
