/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <jgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 10:47:04 by jgaillar          #+#    #+#             */
/*   Updated: 2018/02/12 11:17:37 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_sphere	*copysphlist(t_sphere *sph)
{
	t_sphere *begin;
	t_sphere *new;
	t_sphere *last;

	if (sph == NULL)
		return (NULL);
	new = malloc(sizeof(t_sphere));
	*new = *sph;
	sph = sph->next;
	begin = new;
	while (sph)
	{
		last = new;
		new->next = malloc(sizeof(t_sphere));
		new = new->next;
		*new = *sph;
		new->prev = last;
		sph = sph->next;
	}
	return (begin);
}

t_cone	*copyconelist(t_cone *cone)
{
	t_cone *begin;
	t_cone *new;
	t_cone *last;

	if (cone == NULL)
		return (NULL);
	new = malloc(sizeof(t_cone));
	*new = *cone;
	cone = cone->next;
	begin = new;
	while (cone)
	{
		last = new;
		new->next = malloc(sizeof(t_cone));
		new = new->next;
		*new = *cone;
		new->prev = last;
		cone = cone->next;
	}
	return (begin);
}

t_plan	*copyplalist(t_plan *pla)
{
	t_plan *begin;
	t_plan *new;
	t_plan *last;

	if (pla == NULL)
		return (NULL);
	new = malloc(sizeof(t_plan));
	*new = *pla;
	pla = pla->next;
	begin = new;
	while (pla)
	{
		last = new;
		new->next = malloc(sizeof(t_plan));
		new = new->next;
		*new = *pla;
		new->prev = last;
		pla = pla->next;
	}
	return (begin);
}

t_light	*copylightlist(t_light *light)
{
	t_light *begin;
	t_light *new;
	t_light *last;

	if (light == NULL)
		return (NULL);
	new = malloc(sizeof(t_light));
	*new = *light;
	light = light->next;
	begin = new;
	while (light)
	{
		last = new;
		new->next = malloc(sizeof(t_light));
		new = new->next;
		*new = *light;
		new->prev = last;
		light = light->next;
	}
	return (begin);
}

t_cyl	*copycyllist(t_cyl *cyl)
{
	t_cyl *begin;
	t_cyl *new;
	t_cyl *last;

	if (cyl == NULL)
		return (NULL);
	new = malloc(sizeof(t_cyl));
	*new = *cyl;
	cyl = cyl->next;
	begin = new;
	while (cyl)
	{
		last = new;
		new->next = malloc(sizeof(t_cyl));
		new = new->next;
		*new = *cyl;
		new->prev = last;
		cyl = cyl->next;
	}
	return (begin);
}