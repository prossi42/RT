/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook_matrice_sd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:14:28 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 10:14:48 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	mouse_hook_matrice_hh(t_stuff *e)
{
	if (e->i.mat.act_xyz != 3)
	{
		e->i.mat.act_xyz = 3;
		e->m.axe = 'z';
	}
	else
	{
		e->i.mat.act_xyz = 0;
		e->m.axe = '\0';
	}
}

void	mouse_hook_matrice_seh(t_stuff *e)
{
	if (e->i.mat.act_xyz != 2)
	{
		e->i.mat.act_xyz = 2;
		e->m.axe = 'y';
	}
	else
	{
		e->i.mat.act_xyz = 0;
		e->m.axe = '\0';
	}
}

void	mouse_hook_matrice_sh(t_stuff *e)
{
	if (e->i.mat.act_xyz != 1)
	{
		e->i.mat.act_xyz = 1;
		e->m.axe = 'x';
	}
	else
	{
		e->i.mat.act_xyz = 0;
		e->m.axe = '\0';
	}
}

void	mouse_hook_matrice_fih(t_stuff *e)
{
	if (e->i.mat.dir_or_pos != 2)
	{
		e->i.mat.dir_or_pos = 2;
		e->m.type_sujet = 1;
	}
	else
	{
		e->m.type_sujet = 0;
		e->i.mat.dir_or_pos = 0;
	}
}
