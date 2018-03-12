/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook_newobj.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Awk-LM <Awk-LM@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 19:37:19 by Awk-LM            #+#    #+#             */
/*   Updated: 2018/03/12 11:08:46 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	set_value_new_objet(t_stuff *e)
{
	e->i.nobj.first = 0;
	terminal(e);
}

void	set_del_objet(t_stuff *e)
{
	if (e->i.objet == SPHERE)
		del_sphere(e);
	else if (e->i.objet == PLAN)
		del_plan(e);
	else if (e->i.objet == LIGHT)
		del_light(e);
	else if (e->i.objet == CYLINDRE)
		del_cylindre(e);
	else if (e->i.objet == CONE)
		del_cone(e);
}

// void	newobj_camera(t_stuff *e, int x)
// {
// 	if (x >= ((WIN_X - WIDTH) / 4) && x <= ((WIN_X - WIDTH) / 4) * 3)
// 	{
// 		e->i.objet = -1;
// 		e->i.nobj.act_obj = 6;
		// e->i.each_obj = 0;
// 	}
// 	else if (x >= (((WIN_X - WIDTH) / 4) - 30) && x <= (((WIN_X - WIDTH) / 4) - 5) && e->i.nobj.act_obj == 6)
// 		searchlist(e, e->i.each_obj, e->i.objet);
// 		if (e->camera->prev != NULL)
// 		{
// 			e->camera = e->camera->prev;
// 			e->i.each_obj = e->camera->nm;
// 		}
// 	}
// 	else if (x >= ((((WIN_X - WIDTH) / 4) * 3) + 5) && x <= ((((WIN_X - WIDTH) / 4) * 3) + 30)  && e->i.nobj.act_obj == 6)
// 	{
// 		searchlist(e, e->i.each_obj, e->i.objet);
// 		if (e->camera->next != NULL)
// 		{
// 			e->camera = e->camera->next;
// 			e->i.each_obj = e->camera->nm;
// 		}
// 	}
// 	else if (x >= (((WIN_X - WIDTH) / 4) * 3) + 70 && x <= (((WIN_X - WIDTH) / 4) * 3) + 95)
// 		ft_putstr("En cours...\n");
// }

void	mouse_hook_newobj(t_stuff *e, int x, int y)
{
	int		centery;
	int		centerx;
	int		bordery;

	bordery = (WIN_Y - LENGTH) * 2;
	centery = bordery + ((((WIN_Y - LENGTH) * 3) - ((WIN_Y - LENGTH) * 2)) / 2);
	centerx = (WIN_X - WIDTH) / 2;
	if (y >= centery - 100 && y <= centery + 100 && x > centerx - 100 && x <= centerx + 100)
	{
		if (e->i.nobj.power == 0)
			e->i.nobj.power = 1;
		else
			e->i.nobj.power = 0;
	}
	else if (e->i.nobj.power == 1 && y > bordery && y < centery - 100 && x > centerx - 100 && x < centerx + 100)
	{
		if (e->i.objet < LIGHT)
		{
			e->i.objet++;
			e->i.each_obj = 0;
		}
	}
	else if (e->i.nobj.power == 1 && y > centery + 100 && y < (WIN_Y - LENGTH) * 3 && x > centerx - 100 && x < centerx + 100)
	{
		if (e->i.objet > -1)
		{
			e->i.objet--;
			e->i.each_obj = 0;
		}
	}
	else if (e->i.nobj.power == 1 && y > centery - 100 && y < centery + 100 && x > centerx + 100 && x < 402)
		switch_next_objet(e);
	else if (e->i.nobj.power == 1 && y > centery - 100 && y < centery + 100 && x < centerx - 100 && x > 123)
		switch_prev_objet(e);
	else if (e->i.nobj.power == 1 && y > centery - 100 && y < centery + 100 && x > WIN_X - WIDTH -  100 && x < WIN_X - WIDTH)
		set_value_new_objet(e);
	else if (e->i.nobj.power == 1 && y > centery - 100 && y < centery + 100 && x > 0 && x < 100)
		set_del_objet(e);
	else if (y > bordery && y < bordery + 20 && x > WIN_X - WIDTH - 20 && x < WIN_X - WIDTH)
		ft_putendl("NTM JULS");
	create_obj(e);
}
