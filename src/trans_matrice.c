/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans_matrice.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luca <luca@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 14:24:00 by luca              #+#    #+#             */
/*   Updated: 2018/02/08 15:24:16 by lhermann         ###   ########.fr       */
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
