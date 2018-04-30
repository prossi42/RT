/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacement_matriciel_camera_sd.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 14:17:38 by prossi            #+#    #+#             */
/*   Updated: 2018/04/13 15:42:58 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec	y_rotation(t_vec vec, double angle)
{
	t_vec	new;
	double	ang;

	ang = angle * M_PI / 180;
	new.y = vec.y * cos(ang) + vec.x * sin(ang);
	new.z = vec.z;
	new.x = vec.x * cos(ang) - vec.y * sin(ang);
	return (new);
}

t_vec	z_rotation(t_vec vec, double angle)
{
	t_vec	new;
	double	ang;

	ang = angle * M_PI / 180;
	new.y = vec.y;
	new.z = vec.z * cos(ang) - vec.x * sin(ang);
	new.x = vec.z * sin(ang) + vec.x * cos(ang);
	return (new);
}

t_vec	x_rotation(t_vec vec, double angle)
{
	t_vec	new;
	double	ang;

	ang = angle * M_PI / 180;
	new.x = vec.x;
	new.y = vec.y * cos(ang) - vec.z * sin(ang);
	new.z = vec.y * sin(ang) + vec.z * cos(ang);
	return (new);
}

void	rotation_apply(t_stuff *e, t_vec *dir)
{
	*dir = z_rotation(*dir, e->rotz);
	*dir = y_rotation(*dir, e->roty);
	*dir = x_rotation(*dir, e->rotx);
	vecnorm(dir);
}

void	rotation_apply2(t_stuff *e, t_vec *dir)
{
	*dir = x_rotation(*dir, e->rotx2);
	vecnorm(dir);
}
