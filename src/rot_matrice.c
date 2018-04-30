/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_matrice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 12:40:47 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 12:40:48 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	rotation_z(t_vec *sujet, double radian)
{
	double	tmpx;
	double	tmpy;
	double	tmpz;
	double	sinus;
	double	cosinus;

	sinus = sin(radian);
	cosinus = cos(radian);
	tmpx = sujet->x;
	tmpy = sujet->y;
	tmpz = sujet->z;
	sujet->x = (cosinus * tmpx) + (-sinus * tmpy);
	sujet->y = (sinus * tmpx) + (cosinus * tmpy);
	sujet->z = tmpz;
}

void	rotation_y(t_vec *sujet, double radian)
{
	double	tmpx;
	double	tmpy;
	double	tmpz;
	double	sinus;
	double	cosinus;

	sinus = sin(radian);
	cosinus = cos(radian);
	tmpx = sujet->x;
	tmpy = sujet->y;
	tmpz = sujet->z;
	sujet->x = (cosinus * tmpx) + (sinus * tmpz);
	sujet->y = tmpy;
	sujet->z = (-sinus * tmpx) + (cosinus * tmpz);
}

void	rotation_x(t_vec *sujet, double radian)
{
	double	tmpx;
	double	tmpy;
	double	tmpz;
	double	sinus;
	double	cosinus;

	sinus = sin(radian);
	cosinus = cos(radian);
	tmpx = sujet->x;
	tmpy = sujet->y;
	tmpz = sujet->z;
	sujet->x = tmpx;
	sujet->y = (cosinus * tmpy) + (-sinus * tmpz);
	sujet->z = (sinus * tmpy) + (cosinus * tmpz);
}
