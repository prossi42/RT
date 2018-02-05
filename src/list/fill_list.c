/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luca <luca@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 12:52:39 by luca              #+#    #+#             */
/*   Updated: 2018/02/05 13:26:27 by luca             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	fill_list_sph(t_sphere **sph, double *tabd, int nbm)
{
	(*sph)->pos.x = tabd[0];
	(*sph)->pos.y = tabd[1];
	(*sph)->pos.z = tabd[2];
	(*sph)->ray = tabd[3];
	(*sph)->color.r = tabd[4];
	(*sph)->color.g = tabd[5];
	(*sph)->color.b = tabd[6];
	(*sph)->nm = nbm;
	free(tabd);
}

void	fill_list_pla(t_plan **pla, double *tabdpla, int nbmpla)
{
	(*pla)->pos.x = tabdpla[0];
	(*pla)->pos.y = tabdpla[1];
	(*pla)->pos.z = tabdpla[2];
	(*pla)->color.r = tabdpla[3];
	(*pla)->color.g = tabdpla[4];
	(*pla)->color.b = tabdpla[5];
	(*pla)->norm.x = tabdpla[6];
	(*pla)->norm.y = tabdpla[7];
	(*pla)->norm.z = tabdpla[8];
	(*pla)->nm = nbmpla;
	free(tabdpla);
}

void	fill_list_light(t_light **light, double *tabdlight, int nbmlight)
{
	(*light)->pos.x = tabdlight[0];
	(*light)->pos.y = tabdlight[1];
	(*light)->pos.z = tabdlight[2];
	(*light)->ray = tabdlight[3];
	(*light)->color.r = tabdlight[4];
	(*light)->color.g = tabdlight[5];
	(*light)->color.b = tabdlight[6];
	(*light)->amb = tabdlight[7];
	(*light)->diff = tabdlight[8];
	(*light)->nm = nbmlight;
	free(tabdlight);
}

void	fill_list_cyl(t_cyl **cyl, double *tabdcyl, int nbmcyl)
{
	(*cyl)->pos.x = tabdcyl[0];
	(*cyl)->pos.y = tabdcyl[1];
	(*cyl)->pos.z = tabdcyl[2];
	(*cyl)->norm.x = tabdcyl[3];
	(*cyl)->norm.y = tabdcyl[4];
	(*cyl)->norm.z = tabdcyl[5];
	(*cyl)->ray = tabdcyl[6];
	(*cyl)->color.r = tabdcyl[7];
	(*cyl)->color.g = tabdcyl[8];
	(*cyl)->color.b = tabdcyl[9];
	(*cyl)->nm = nbmcyl;
	free(tabdcyl);
}

void	fill_list_cone(t_cone **cone, double *tabdcone, int nbmcone)
{
	(*cone)->pos.x = tabdcone[0];
	(*cone)->pos.y = tabdcone[1];
	(*cone)->pos.z = tabdcone[2];
	(*cone)->color.r = tabdcone[3];
	(*cone)->color.g = tabdcone[4];
	(*cone)->color.b = tabdcone[5];
	(*cone)->norm.x = tabdcone[6];
	(*cone)->norm.y = tabdcone[7];
	(*cone)->norm.z = tabdcone[8];
	(*cone)->angle = tabdcone[9];
	(*cone)->nm = nbmcone;
	free(tabdcone);
}
