/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_matrice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luca <luca@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 14:22:59 by luca              #+#    #+#             */
/*   Updated: 2018/02/06 12:19:57 by luca             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

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
