/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 14:08:00 by prossi            #+#    #+#             */
/*   Updated: 2018/02/16 15:26:24 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	matrice(char type, char axe, t_stuff *e, t_vec *sujet)
{
	if (type == 'r')
	{
		convert_deg_in_rad(e->m.angle, e);
		if (axe == 'x')
		{
			rotation_x(sujet, e->m.radian);
		}
		else if (axe == 'y')
		{
			rotation_y(sujet, e->m.radian);
		}
		else if (axe == 'z')
		{
			rotation_z(sujet, e->m.radian);
		}
	}
	else if (type == 't')
	{
		if (axe == 'x')
		{
			translation_x(sujet, e->m.value);
		}
		else if (axe == 'y')
		{
			translation_y(sujet, e->m.value);
		}
		else if (axe == 'z')
		{
			translation_z(sujet, e->m.value);
		}
	}
}
