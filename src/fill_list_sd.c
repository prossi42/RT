/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list_sd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 12:55:08 by jgaillar          #+#    #+#             */
/*   Updated: 2018/04/13 12:55:13 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	fill_list_sph_sd(t_sphere **sph, double *tabd)
{
	(*sph)->color.b = tabd[6];
	if ((*sph)->color.b > 255)
		(*sph)->color.b = 255;
	if ((*sph)->color.b < 0)
		(*sph)->color.b = 0;
	(*sph)->refrac = tabd[7];
	if ((*sph)->refrac > 2)
		(*sph)->refrac = 2;
	else if ((*sph)->refrac < 1 && (*sph)->refrac > 0)
		(*sph)->refrac = 1;
	else if ((*sph)->refrac < 0)
		(*sph)->refrac = 0;
	(*sph)->conscol = tabd[8];
	if ((*sph)->conscol > 1)
		(*sph)->conscol = 1;
	if ((*sph)->conscol < 0)
		(*sph)->conscol = 0;
	(*sph)->reflex = tabd[9];
	if ((*sph)->reflex > 1)
		(*sph)->reflex = 1;
	if ((*sph)->reflex < 0)
		(*sph)->reflex = 0;
}

void	fill_list_sph(t_sphere **sph, double *tabd, int nbm)
{
	(*sph)->pos.x = tabd[0];
	(*sph)->pos.y = tabd[1];
	(*sph)->pos.z = tabd[2];
	(*sph)->ray = tabd[3];
	if ((*sph)->ray < 0)
		(*sph)->ray *= -1;
	(*sph)->color.r = tabd[4];
	if ((*sph)->color.r > 255)
		(*sph)->color.r = 255;
	if ((*sph)->color.r < 0)
		(*sph)->color.r = 0;
	(*sph)->color.g = tabd[5];
	if ((*sph)->color.g > 255)
		(*sph)->color.g = 255;
	if ((*sph)->color.g < 0)
		(*sph)->color.g = 0;
	fill_list_sph_sd(sph, tabd);
	(*sph)->nm = nbm;
	free(tabd);
}

void	fill_list_pla_sd(t_plan **pla, double *tabdpla)
{
	(*pla)->norm.x = tabdpla[6];
	(*pla)->norm.y = tabdpla[7];
	(*pla)->norm.z = tabdpla[8];
	vecnorm(&(*pla)->norm);
	(*pla)->refrac = tabdpla[9];
	if ((*pla)->refrac > 2)
		(*pla)->refrac = 2;
	else if ((*pla)->refrac < 1 && (*pla)->refrac > 0)
		(*pla)->refrac = 1;
	else if ((*pla)->refrac < 0)
		(*pla)->refrac = 0;
	(*pla)->conscol = tabdpla[10];
	if ((*pla)->conscol > 1)
		(*pla)->conscol = 1;
	if ((*pla)->conscol < 0)
		(*pla)->conscol = 0;
	(*pla)->reflex = tabdpla[11];
	if ((*pla)->reflex > 1)
		(*pla)->reflex = 1;
	if ((*pla)->reflex < 0)
		(*pla)->reflex = 0;
	(*pla)->ray = tabdpla[12];
	if ((*pla)->ray < 0)
		(*pla)->ray *= -1;
}

void	fill_list_pla(t_plan **pla, double *tabdpla, int nbmpla)
{
	(*pla)->pos.x = tabdpla[0];
	(*pla)->pos.y = tabdpla[1];
	(*pla)->pos.z = tabdpla[2];
	(*pla)->color.r = tabdpla[3];
	if ((*pla)->color.r > 255)
		(*pla)->color.r = 255;
	if ((*pla)->color.r < 0)
		(*pla)->color.r = 0;
	(*pla)->color.g = tabdpla[4];
	if ((*pla)->color.g > 255)
		(*pla)->color.g = 255;
	if ((*pla)->color.g < 0)
		(*pla)->color.g = 0;
	(*pla)->color.b = tabdpla[5];
	if ((*pla)->color.b > 255)
		(*pla)->color.b = 255;
	if ((*pla)->color.b < 0)
		(*pla)->color.b = 0;
	fill_list_pla_sd(pla, tabdpla);
	(*pla)->nm = nbmpla;
	free(tabdpla);
}

void	fill_list_light_sd(t_light **light, double *tabdlight)
{
	(*light)->color.b = tabdlight[6];
	if ((*light)->color.b > 255)
		(*light)->color.b = 255;
	if ((*light)->color.b < 0)
		(*light)->color.b = 0;
	(*light)->amb = tabdlight[7];
	if ((*light)->amb < 0)
		(*light)->amb *= -1;
	if ((*light)->amb > 1)
		(*light)->amb = 1;
	(*light)->diff = tabdlight[8];
	if ((*light)->diff < 0)
		(*light)->diff *= -1;
	if ((*light)->diff > 1)
		(*light)->diff = 1;
}
