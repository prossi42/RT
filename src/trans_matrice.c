/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans_matrice.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 12:40:56 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 12:40:57 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	translation_x(t_vec *sujet, double value)
{
	sujet->x += value;
}

void	translation_y(t_vec *sujet, double value)
{
	sujet->y += value;
}

void	translation_z(t_vec *sujet, double value)
{
	sujet->z += value;
}

void	convert_deg_in_rad(int angle_degre, t_stuff *e)
{
	e->m.radian = angle_degre * (M_PI / 180);
}
