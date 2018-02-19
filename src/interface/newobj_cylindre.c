/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newobj_cylindre.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 09:49:32 by prossi            #+#    #+#             */
/*   Updated: 2018/02/19 09:56:44 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	new_cylindre(t_stuff *e)
{
	t_cyl	*tmp;

	if (e->d.nbmcyl != 0)
	{
		while (e->cyl->next != NULL)
			e->cyl = e->cyl->next;
		tmp = e->cyl;
		init_list_cyl(&e->cyl->next);
		e->cyl = e->cyl->next;
		e->cyl->prev = tmp;
		e->cyl->nm = e->d.nbmcyl;
	}
	e->d.nbmcyl++;
	set_value_new_objet(e);
}

void	newobj_cylindre_td(t_stuff *e)
{
	searchlist(e, e->i.each_obj, e->i.objet);
	if (e->cyl->next != NULL)
	{
		e->cyl = e->cyl->next;
		e->i.each_obj = e->cyl->nm;
	}
}

void	newobj_cylindre_sd(t_stuff *e)
{
	searchlist(e, e->i.each_obj, e->i.objet);
	if (e->cyl->prev != NULL)
	{
		e->cyl = e->cyl->prev;
		e->i.each_obj = e->cyl->nm;
	}
}

void	newobj_cylindre(t_stuff *e, int x)
{
	if (x >= ((WIN_X - WIDTH) / 4) && x <= ((WIN_X - WIDTH) / 4) * 3)
	{
		e->i.objet = CYLINDRE;
		e->i.nobj.act_obj = 3;
		e->i.each_obj = 0;
	}
	else if (x >= (((WIN_X - WIDTH) / 4) - 30) && x <= (((WIN_X - WIDTH) / 4) - 5) && e->i.nobj.act_obj == 3)
		newobj_cylindre_sd(e);
	else if (x >= ((((WIN_X - WIDTH) / 4) * 3) + 5) && x <= ((((WIN_X - WIDTH) / 4) * 3) + 30)  && e->i.nobj.act_obj == 3)
		newobj_cylindre_td(e);
	else if (x >= (((WIN_X - WIDTH) / 4) * 3) + 70 && x <= (((WIN_X - WIDTH) / 4) * 3) + 95 && e->i.nobj.act_obj == 3)
		new_cylindre(e);
	else if (x >= (e->i.mlx->img_x / 4) - 90 && x <= (e->i.mlx->img_x / 4) - 70 && e->i.nobj.act_obj == 3)
		del_cylindre(e);
}
