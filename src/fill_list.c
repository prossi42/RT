/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 12:40:25 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 12:40:26 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	fill_list_light(t_light **light, double *tabdlight, int nbmlight)
{
	(*light)->pos.x = tabdlight[0];
	(*light)->pos.y = tabdlight[1];
	(*light)->pos.z = tabdlight[2];
	(*light)->ray = tabdlight[3];
	if ((*light)->ray < 0)
		(*light)->ray *= -1;
	(*light)->color.r = tabdlight[4];
	if ((*light)->color.r > 255)
		(*light)->color.r = 255;
	if ((*light)->color.r < 0)
		(*light)->color.r = 0;
	(*light)->color.g = tabdlight[5];
	if ((*light)->color.g > 255)
		(*light)->color.g = 255;
	if ((*light)->color.g < 0)
		(*light)->color.g = 0;
	fill_list_light_sd(light, tabdlight);
	(*light)->nm = nbmlight;
	free(tabdlight);
}

void	fill_list_cyl_sd(t_cyl **cyl, double *tabdcyl)
{
	(*cyl)->color.b = tabdcyl[9];
	if ((*cyl)->color.b > 255)
		(*cyl)->color.b = 255;
	if ((*cyl)->color.b < 0)
		(*cyl)->color.b = 0;
	(*cyl)->refrac = tabdcyl[10];
	if ((*cyl)->refrac > 2)
		(*cyl)->refrac = 2;
	else if ((*cyl)->refrac < 1 && (*cyl)->refrac > 0)
		(*cyl)->refrac = 1;
	else if ((*cyl)->refrac < 0)
		(*cyl)->refrac = 0;
	(*cyl)->conscol = tabdcyl[11];
	if ((*cyl)->conscol > 1)
		(*cyl)->conscol = 1;
	if ((*cyl)->conscol < 0)
		(*cyl)->conscol = 0;
	(*cyl)->reflex = tabdcyl[12];
	if ((*cyl)->reflex > 1)
		(*cyl)->reflex = 1;
	if ((*cyl)->reflex < 0)
		(*cyl)->reflex = 0;
}

void	fill_list_cyl(t_cyl **cyl, double *tabdcyl, int nbmcyl)
{
	(*cyl)->pos.x = tabdcyl[0];
	(*cyl)->pos.y = tabdcyl[1];
	(*cyl)->pos.z = tabdcyl[2];
	(*cyl)->norm.x = tabdcyl[3];
	(*cyl)->norm.y = tabdcyl[4];
	(*cyl)->norm.z = tabdcyl[5];
	vecnorm(&(*cyl)->norm);
	(*cyl)->ray = tabdcyl[6];
	if ((*cyl)->ray < 0)
		(*cyl)->ray *= -1;
	(*cyl)->color.r = tabdcyl[7];
	if ((*cyl)->color.r > 255)
		(*cyl)->color.r = 255;
	if ((*cyl)->color.r < 0)
		(*cyl)->color.r = 0;
	(*cyl)->color.g = tabdcyl[8];
	if ((*cyl)->color.g > 255)
		(*cyl)->color.g = 255;
	if ((*cyl)->color.g < 0)
		(*cyl)->color.g = 0;
	fill_list_cyl_sd(cyl, tabdcyl);
	(*cyl)->nm = nbmcyl;
	free(tabdcyl);
}

void	fill_list_cone_sd(t_cone **cone, double *tabdcone)
{
	(*cone)->norm.x = tabdcone[6];
	(*cone)->norm.y = tabdcone[7];
	(*cone)->norm.z = tabdcone[8];
	vecnorm(&(*cone)->norm);
	(*cone)->angle = tabdcone[9];
	if ((*cone)->angle < 0)
		(*cone)->angle *= -1;
	(*cone)->refrac = tabdcone[10];
	if ((*cone)->refrac > 2)
		(*cone)->refrac = 2;
	else if ((*cone)->refrac < 1 && (*cone)->refrac > 0)
		(*cone)->refrac = 1;
	else if ((*cone)->refrac < 0)
		(*cone)->refrac = 0;
	(*cone)->conscol = tabdcone[11];
	if ((*cone)->conscol > 1)
		(*cone)->conscol = 1;
	if ((*cone)->conscol < 0)
		(*cone)->conscol = 0;
	(*cone)->reflex = tabdcone[12];
	if ((*cone)->reflex > 1)
		(*cone)->reflex = 1;
	if ((*cone)->reflex < 0)
		(*cone)->reflex = 0;
}

void	fill_list_cone(t_cone **cone, double *tabdcone, int nbmcone)
{
	(*cone)->pos.x = tabdcone[0];
	(*cone)->pos.y = tabdcone[1];
	(*cone)->pos.z = tabdcone[2];
	(*cone)->color.r = tabdcone[3];
	if ((*cone)->color.r > 255)
		(*cone)->color.r = 255;
	if ((*cone)->color.r < 0)
		(*cone)->color.r = 0;
	(*cone)->color.g = tabdcone[4];
	if ((*cone)->color.g > 255)
		(*cone)->color.g = 255;
	if ((*cone)->color.g < 0)
		(*cone)->color.g = 0;
	(*cone)->color.b = tabdcone[5];
	if ((*cone)->color.b > 255)
		(*cone)->color.b = 255;
	if ((*cone)->color.b < 0)
		(*cone)->color.b = 0;
	fill_list_cone_sd(cone, tabdcone);
	(*cone)->nm = nbmcone;
	free(tabdcone);
}
