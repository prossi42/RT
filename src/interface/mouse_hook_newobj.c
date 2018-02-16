/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook_newobj.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Awk-LM <Awk-LM@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 19:37:19 by Awk-LM            #+#    #+#             */
/*   Updated: 2018/02/16 13:41:22 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	set_value_new_objet(t_stuff *e)
{
	e->i.nobj.first = 0;
	terminal(e);
}

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

void	new_plan(t_stuff *e)
{
	t_plan		*tmp;

	if (e->d.nbmpla != 0)
	{
		while (e->pla->next != NULL)
			e->pla = e->pla->next;
		tmp = e->pla;
		init_list_pla(&e->pla->next);
		e->pla = e->pla->next;
		e->pla->prev = tmp;
		e->pla->nm = e->d.nbmpla;
	}
	e->d.nbmpla++;
	set_value_new_objet(e);
}

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

void	new_cone(t_stuff *e)
{
	t_cone		*tmp;

	if (e->d.nbmcone != 0)
	{
		while (e->cone->next != NULL)
			e->cone = e->cone->next;
		tmp = e->cone;
		init_list_cone(&e->cone->next);
		e->cone = e->cone->next;
		e->cone->prev = tmp;
		e->cone->nm = e->d.nbmcone;
	}
	e->d.nbmcone++;
	set_value_new_objet(e);
}

void	new_light(t_stuff *e)
{
	t_light		*tmp;

	if (e->d.nbmlight != 0)
	{
		while (e->light->next != NULL)
			e->light = e->light->next;
		tmp = e->light;
		init_list_light(&e->light->next);
		e->light = e->light->next;
		e->light->prev = tmp;
		e->light->nm = e->d.nbmlight;
	}
	e->d.nbmlight++;
	set_value_new_objet(e);
}

void	newobj_sphere(t_stuff *e, int x)
{
	if (x >= ((WIN_X - WIDTH) / 4) && x <= ((WIN_X - WIDTH) / 4) * 3)
	{
		e->i.objet = SPHERE;
		e->i.nobj.act_obj = 1;
		e->i.each_obj = 0;
	}
	else if (x >= (((WIN_X - WIDTH) / 4) - 30) && x <= (((WIN_X - WIDTH) / 4) - 5) && e->i.nobj.act_obj == 1)
	{
		searchlist(e, e->i.each_obj, e->i.objet);
		if (e->sph->prev != NULL)
		{
			e->sph = e->sph->prev;
			e->i.each_obj = e->sph->nm;
		}
	}
	else if (x >= ((((WIN_X - WIDTH) / 4) * 3) + 5) && x <= ((((WIN_X - WIDTH) / 4) * 3) + 30)  && e->i.nobj.act_obj == 1)
	{
		searchlist(e, e->i.each_obj, e->i.objet);
		if (e->sph->next != NULL)
		{
			e->sph = e->sph->next;
			e->i.each_obj = e->sph->nm;
		}
	}
	else if (x >= (((WIN_X - WIDTH) / 4) * 3) + 70 && x <= (((WIN_X - WIDTH) / 4) * 3) + 95 && e->i.nobj.act_obj == 1)
		new_sphere(e);
}

void	newobj_plan(t_stuff *e, int x)
{
	if (x >= ((WIN_X - WIDTH) / 4) && x <= ((WIN_X - WIDTH) / 4) * 3)
	{
		e->i.objet = PLAN;
		e->i.nobj.act_obj = 2;
		e->i.each_obj = 0;
	}
	else if (x >= (((WIN_X - WIDTH) / 4) - 30) && x <= (((WIN_X - WIDTH) / 4) - 5) && e->i.nobj.act_obj == 2)
	{
		searchlist(e, e->i.each_obj, e->i.objet);
		if (e->pla->prev != NULL)
		{
			e->pla = e->pla->prev;
			e->i.each_obj = e->pla->nm;
		}
	}
	else if (x >= ((((WIN_X - WIDTH) / 4) * 3) + 5) && x <= ((((WIN_X - WIDTH) / 4) * 3) + 30)  && e->i.nobj.act_obj == 2)
	{
		searchlist(e, e->i.each_obj, e->i.objet);
		if (e->pla->next != NULL)
		{
			e->pla = e->pla->next;
			e->i.each_obj = e->pla->nm;
		}
	}
	else if (x >= (((WIN_X - WIDTH) / 4) * 3) + 70 && x <= (((WIN_X - WIDTH) / 4) * 3) + 95 && e->i.nobj.act_obj == 2)
		new_plan(e);
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
	{
		searchlist(e, e->i.each_obj, e->i.objet);
		if (e->cyl->prev != NULL)
		{
			e->cyl = e->cyl->prev;
			e->i.each_obj = e->cyl->nm;
		}
	}
	else if (x >= ((((WIN_X - WIDTH) / 4) * 3) + 5) && x <= ((((WIN_X - WIDTH) / 4) * 3) + 30)  && e->i.nobj.act_obj == 3)
	{
		searchlist(e, e->i.each_obj, e->i.objet);
		if (e->cyl->next != NULL)
		{
			e->cyl = e->cyl->next;
			e->i.each_obj = e->cyl->nm;
		}
	}
	else if (x >= (((WIN_X - WIDTH) / 4) * 3) + 70 && x <= (((WIN_X - WIDTH) / 4) * 3) + 95 && e->i.nobj.act_obj == 3)
		new_cylindre(e);
}

void	newobj_cone(t_stuff *e, int x)
{
	if (x >= ((WIN_X - WIDTH) / 4) && x <= ((WIN_X - WIDTH) / 4) * 3)
	{
		e->i.objet = CONE;
		e->i.nobj.act_obj = 4;
		e->i.each_obj = 0;
		printf("Valeur de nbmcone : [%d]\n\n", e->d.nbmcone);
	}
	else if (x >= (((WIN_X - WIDTH) / 4) - 30) && x <= (((WIN_X - WIDTH) / 4) - 5) && e->i.nobj.act_obj == 4)
	{
		searchlist(e, e->i.each_obj, e->i.objet);
		if (e->cone->prev != NULL)
		{
			e->cone = e->cone->prev;
			e->i.each_obj = e->cone->nm;
		}
	}
	else if (x >= ((((WIN_X - WIDTH) / 4) * 3) + 5) && x <= ((((WIN_X - WIDTH) / 4) * 3) + 30) && e->i.nobj.act_obj == 4)
	{
		searchlist(e, e->i.each_obj, e->i.objet);
		if (e->cone->next != NULL)
		{
			e->cone = e->cone->next;
			e->i.each_obj = e->cone->nm;
		}
	}
	else if (x >= (((WIN_X - WIDTH) / 4) * 3) + 70 && x <= (((WIN_X - WIDTH) / 4) * 3) + 95 && e->i.nobj.act_obj == 4)
		new_cone(e);
}

void	newobj_light(t_stuff *e, int x)
{
	if (x >= ((WIN_X - WIDTH) / 4) && x <= ((WIN_X - WIDTH) / 4) * 3)
	{
		e->i.objet = LIGHT;
		e->i.nobj.act_obj = 5;
		e->i.each_obj = 0;
	}
	else if (x >= (((WIN_X - WIDTH) / 4) - 30) && x <= (((WIN_X - WIDTH) / 4) - 5) && e->i.nobj.act_obj == 5)
	{
		searchlist(e, e->i.each_obj, e->i.objet);
		if (e->light->prev != NULL)
		{
			e->light = e->light->prev;
			e->i.each_obj = e->light->nm;
		}
	}
	else if (x >= ((((WIN_X - WIDTH) / 4) * 3) + 5) && x <= ((((WIN_X - WIDTH) / 4) * 3) + 30) && e->i.nobj.act_obj == 5)
	{
		searchlist(e, e->i.each_obj, e->i.objet);
		if (e->light->next != NULL)
		{
			e->light = e->light->next;
			e->i.each_obj = e->light->nm;
		}
	}
	else if (x >= (((WIN_X - WIDTH) / 4) * 3) + 70 && x <= (((WIN_X - WIDTH) / 4) * 3) + 95 && e->i.nobj.act_obj == 5)
		new_light(e);
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
// 	{
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
	int		bordery;

	bordery = (WIN_Y - LENGTH) * 2;
	if (y >= bordery + 5 && y <= bordery + 40)
		newobj_sphere(e, x);
	if (y >= bordery + 50 && y <= bordery + 85)
		newobj_plan(e, x);
	if (y >= bordery + 95 && y <= bordery + 130)
		newobj_cylindre(e, x);
	if (y >= bordery + 140 && y <= bordery + 175)
		newobj_cone(e, x);
	if (y >= bordery + 185 && y <= bordery + 220)
		newobj_light(e, x);
	if (y >= bordery + 230 && y <= bordery + 265)
		// newobj_camera(e, x);
		ft_putstr("En cours...\n");
}
