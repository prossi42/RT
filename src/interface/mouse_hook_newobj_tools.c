/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook_newobj_tools.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:18:21 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 10:18:22 by prossi           ###   ########.fr       */
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

void	set_new_obj(t_stuff *e)
{
	if (e->i.objet == SPHERE)
		new_sphere(e);
	else if (e->i.objet == PLAN)
		new_plan(e);
	else if (e->i.objet == LIGHT)
		new_light(e);
	else if (e->i.objet == CYLINDRE)
		new_cylindre(e);
	else if (e->i.objet == CONE)
		new_cone(e);
	if (e->i.objet != -1)
		set_value_new_objet(e);
}

void	mouse_hook_newobj_select_color(t_stuff *e, int x, int y)
{
	int		bordery;
	int		i;
	int		j;

	bordery = (WIN_Y - LENGTH) * 2;
	j = -1;
	while (++j < 12)
	{
		i = -1;
		while (++i < 18)
		{
			if (x >= e->i.color.tabxd[j][i] && x <= e->i.color.tabxf[j][i] \
			&& y - bordery >= e->i.color.tabyd[j][i] && y - bordery <= \
			e->i.color.tabyf[j][i])
			{
				if (e->i.nobj.settings == 3)
					e->i.color.nobj.col1 = e->i.color.tab[j][i];
				else if (e->i.nobj.settings == 4)
					e->i.color.nobj.col2 = e->i.color.tab[j][i];
				else if (e->i.nobj.settings == 5)
					e->i.color.nobj.col3 = e->i.color.tab[j][i];
				e->i.nobj.settings = 0;
			}
		}
	}
}

void	mouse_hook_new_obj_color(t_stuff *e, int x, int y)
{
	int		bordery;

	bordery = (WIN_Y - LENGTH) * 2;
	if (e->i.nobj.settings == 2)
	{
		if (x > 250 && x < 320 && y < bordery + 110 && y > bordery + 70)
			e->i.nobj.settings = 3;
		if (x > 250 && x < 320 && y < bordery + 180 && y > bordery + 140)
			e->i.nobj.settings = 4;
		if (x > 250 && x < 320 && y < bordery + 250 && y > bordery + 210)
			e->i.nobj.settings = 5;
		settings_color(e);
	}
	else
	{
		mouse_hook_newobj_select_color(e, x, y);
		create_obj(e);
	}
}
