/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacement_matriciel_camera.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 14:15:06 by prossi            #+#    #+#             */
/*   Updated: 2018/04/13 15:39:48 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	up_vec_create(t_vec *vec)
{
	vec->x = 0;
	vec->y = 1;
	vec->z = 0;
}

void	right_vec_create(t_vec *vec)
{
	vec->x = 1;
	vec->y = 0;
	vec->z = 0;
}

void	forward_vec_create(t_vec *vec)
{
	vec->x = 1;
	vec->y = 0;
	vec->z = 0;
}

void	angle_increase(t_stuff *e, double z, double y, double x)
{
	e->rotz += z;
	e->roty += y;
	e->rotx += x;
	if (e->rotz >= 360)
		e->rotz -= 360;
	if (e->roty >= 360)
		e->roty -= 360;
	if (e->rotx >= 360)
		e->rotx -= 360;
}
