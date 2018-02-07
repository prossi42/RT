/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 14:08:00 by prossi            #+#    #+#             */
/*   Updated: 2018/02/05 14:48:27 by luca             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

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
		printf("\nUne rotation en [%c] d'un angle de [%.0fº] vient d'etre effectuée\n", axe, e->m.angle);
		printf("\nNouvelle valeur du sujet : x : [%.2f] y : [%.2f] z : [%.2f]\n", sujet->x, sujet->y, sujet->z);
	}
	else if (type == 't')
	{
		if (axe == 'x')
		{
			translation_x(sujet, e->m.value);
		}
		else if (axe == 'y')
		{
			translation_x(sujet, e->m.value);
		}
		else if (axe == 'z')
		{
			translation_x(sujet, e->m.value);
		}
		printf("\nUne translation en [%c] d'une valeur de [%.0f] vient d'etre effectuée\n", axe, e->m.value);
	}
}