/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 12:37:26 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 12:37:27 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		init_list_cone(t_cone **cone)
{
	if (!(*cone = (t_cone *)malloc(sizeof(t_cone))))
		exit(-1);
	(*cone)->prev = NULL;
	(*cone)->pos.x = 0;
	(*cone)->pos.y = 0;
	(*cone)->pos.z = 0;
	(*cone)->color.r = 0;
	(*cone)->color.g = 0;
	(*cone)->color.b = 0;
	(*cone)->norm.x = 0;
	(*cone)->norm.y = 0;
	(*cone)->norm.z = 0;
	(*cone)->angle = 0;
	(*cone)->nm = 0;
	(*cone)->refrac = 0;
	(*cone)->conscol = 0;
	(*cone)->reflex = 0;
	(*cone)->next = NULL;
	return (0);
}

int		init_list_cyl(t_cyl **cyl)
{
	if (!(*cyl = (t_cyl *)malloc(sizeof(t_cyl))))
		exit(-1);
	(*cyl)->prev = NULL;
	(*cyl)->pos.x = 0;
	(*cyl)->pos.y = 0;
	(*cyl)->pos.z = 0;
	(*cyl)->color.r = 0;
	(*cyl)->color.g = 0;
	(*cyl)->color.b = 0;
	(*cyl)->norm.x = 0;
	(*cyl)->norm.y = 0;
	(*cyl)->norm.z = 0;
	(*cyl)->ray = 0;
	(*cyl)->nm = 0;
	(*cyl)->refrac = 0;
	(*cyl)->reflex = 0;
	(*cyl)->conscol = 0;
	(*cyl)->next = NULL;
	return (0);
}

int		init_list_light(t_light **light)
{
	if (!(*light = (t_light *)malloc(sizeof(t_light))))
		exit(-1);
	(*light)->prev = NULL;
	(*light)->pos.x = 0;
	(*light)->pos.y = 0;
	(*light)->pos.z = 0;
	(*light)->color.r = 0;
	(*light)->color.g = 0;
	(*light)->color.b = 0;
	(*light)->ray = 0;
	(*light)->amb = 0;
	(*light)->diff = 0;
	(*light)->nm = 0;
	(*light)->next = NULL;
	return (0);
}

int		init_list_sph(t_sphere **sph)
{
	if (!(*sph = (t_sphere *)malloc(sizeof(t_sphere))))
		exit(-1);
	(*sph)->prev = NULL;
	(*sph)->pos.x = 0;
	(*sph)->pos.y = 0;
	(*sph)->pos.z = 0;
	(*sph)->color.r = 0;
	(*sph)->color.g = 0;
	(*sph)->color.b = 0;
	(*sph)->ray = 0;
	(*sph)->nm = 0;
	(*sph)->refrac = 0;
	(*sph)->conscol = 0;
	(*sph)->reflex = 0;
	(*sph)->next = NULL;
	return (0);
}

int		init_list_pla(t_plan **pla)
{
	if (!(*pla = (t_plan *)malloc(sizeof(t_plan))))
		exit(-1);
	(*pla)->prev = NULL;
	(*pla)->pos.x = 0;
	(*pla)->pos.y = 0;
	(*pla)->pos.z = 0;
	(*pla)->color.r = 0;
	(*pla)->color.g = 0;
	(*pla)->color.b = 0;
	(*pla)->norm.x = 0;
	(*pla)->norm.y = 0;
	(*pla)->norm.z = 0;
	(*pla)->nm = 0;
	(*pla)->refrac = 0;
	(*pla)->reflex = 0;
	(*pla)->conscol = 0;
	(*pla)->ray = 0;
	(*pla)->next = NULL;
	return (0);
}
