/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook_newobj.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Awk-LM <Awk-LM@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 19:37:19 by Awk-LM            #+#    #+#             */
/*   Updated: 2018/02/22 23:44:29 by Awk-LM           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	set_value_new_objet(t_stuff *e)
{
	e->i.nobj.first = 0;
	terminal(e);
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
	{
		switch_next_objet(e);
	}
	create_obj(e);
	// if (y >= bordery + 5 && y <= bordery + 40)
	// 	newobj_sphere(e, x);
	// if (y >= bordery + 50 && y <= bordery + 85)
	// 	newobj_plan(e, x);
	// if (y >= bordery + 95 && y <= bordery + 130)
	// 	newobj_cylindre(e, x);
	// if (y >= bordery + 140 && y <= bordery + 175)
	// 	newobj_cone(e, x);
	// if (y >= bordery + 185 && y <= bordery + 220)
	// 	newobj_light(e, x);
	// if (y >= bordery + 230 && y <= bordery + 265)
	// 	// newobj_camera(e, x);
	// 	ft_putstr("En cours...\n");
}
