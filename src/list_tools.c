/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 13:32:49 by prossi            #+#    #+#             */
/*   Updated: 2018/02/05 13:26:37 by luca             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	reboot_list(t_stuff *e)
{
	while (e->sph->prev != NULL)
		e->sph = e->sph->prev;
	while (e->pla->prev != NULL)
		e->pla = e->pla->prev;
	while (e->light->prev != NULL)
		e->light = e->light->prev;
	while (e->cyl->prev != NULL)
		e->cyl = e->cyl->prev;
	while (e->cone->prev != NULL)
		e->cone = e->cone->prev;
	e->tmp = e->sph;
	e->tmppla = e->pla;
	e->tmplight = e->light;
	e->tmpcyl = e->cyl;
	e->tmpcone = e->cone;
}

void	reboot_list_loop(t_stuff *e, int option)
{
	if (option == 1 || option == 3)
	{
		e->sph = e->tmp;
		e->pla = e->tmppla;
		e->cyl = e->tmpcyl;
		e->cone = e->tmpcone;
	}
	if (option == 2 || option == 3)
		e->light = e->tmplight;
}

void	searchlist(t_stuff *e, int nmail, int nlist)
{
	reboot_list_loop(e, 1);
	if (nlist == SPHERE)
	{
		while (e->sph->nm != nmail)
			e->sph = e->sph->next;
	}
	if (nlist == PLAN)
	{
		while (e->pla->nm != nmail)
		e->pla = e->pla->next;
	}
	if (nlist == CYLINDRE)
	{
		while (e->cyl->nm != nmail)
			e->cyl = e->cyl->next;
	}
	if (nlist == CONE)
	{
		while (e->cone->nm != nmail)
			e->cone = e->cone->next;
	}
	if (nlist == LIGHT)
	{
	while (e->light->nm != nmail)
		e->light = e->light->next;
	}
}

void	print_list(t_stuff *e)
{
	printf("\n------\nDEBUT DES SPHERES\n------\n\n");
	while (e->sph)
	{
		printf("PosX : [%f]\n", e->sph->pos.x);
		printf("PosY : [%f]\n", e->sph->pos.y);
		printf("PosZ : [%f]\n", e->sph->pos.z);
		printf("Rayon : [%f]\n", e->sph->ray);
		printf("ColorR : [%d]\n", e->sph->color.r);
		printf("ColorG : [%d]\n", e->sph->color.g);
		printf("ColorB : [%d]\n", e->sph->color.b);
		printf("Numero du maillon : [%d]\n", e->sph->nm);
		e->sph = e->sph->next;
		ft_putchar('\n');
	}
	printf("\n\n------\nDEBUT DES PLANS\n------\n\n");
	while (e->pla)
	{
		printf("PosX : [%f]\n", e->pla->pos.x);
		printf("PosY : [%f]\n", e->pla->pos.y);
		printf("PosZ : [%f]\n", e->pla->pos.z);
		printf("ColorR : [%d]\n", e->pla->color.r);
		printf("ColorG : [%d]\n", e->pla->color.g);
		printf("ColorB : [%d]\n", e->pla->color.b);
		printf("NormX : [%f]\n", e->pla->norm.x);
		printf("NormY : [%f]\n", e->pla->norm.y);
		printf("NormZ : [%f]\n", e->pla->norm.z);
		printf("Numero du maillon : [%d]\n", e->pla->nm);
		e->pla = e->pla->next;
		ft_putchar('\n');
	}
	printf("\n\n------\nDEBUT DES LIGHT\n------\n\n");
	while (e->light)
	{
		printf("PosX : [%f]\n", e->light->pos.x);
		printf("PosY : [%f]\n", e->light->pos.y);
		printf("PosZ : [%f]\n", e->light->pos.z);
		printf("Rayon : [%f]\n", e->light->ray);
		printf("ColorR : [%d]\n", e->light->color.r);
		printf("ColorG : [%d]\n", e->light->color.g);
		printf("ColorB : [%d]\n", e->light->color.b);
		printf("Lum. Amb : [%f]\n", e->light->amb);
		printf("Lum. Diff : [%f]\n", e->light->diff);
		printf("Numero du maillon : [%d]\n", e->light->nm);
		e->light = e->light->next;
		ft_putchar('\n');
	}
	printf("\n------\nDEBUT DES CYLINDRES\n------\n\n");
	while (e->cyl)
	{
		printf("posX : [%f]\n", e->cyl->pos.x);
		printf("posY : [%f]\n", e->cyl->pos.y);
		printf("posZ : [%f]\n", e->cyl->pos.z);
		printf("NormX : [%f]\n", e->cyl->norm.x);
		printf("NormY : [%f]\n", e->cyl->norm.y);
		printf("NormZ : [%f]\n", e->cyl->norm.z);
		printf("Rayon : [%f]\n", e->cyl->ray);
		printf("ColorR : [%d]\n", e->cyl->color.r);
		printf("ColorG : [%d]\n", e->cyl->color.g);
		printf("ColorB : [%d]\n", e->cyl->color.b);
		printf("Numero du maillon : [%d]\n", e->cyl->nm);
		e->cyl = e->cyl->next;
		ft_putchar('\n');
	}
	printf("\n------\nDEBUT DES CONES\n------\n\n");
	while (e->cone)
	{
		printf("PosX : [%f]\n", e->cone->pos.x);
		printf("PosY : [%f]\n", e->cone->pos.y);
		printf("PosZ : [%f]\n", e->cone->pos.z);
		printf("ColorR : [%d]\n", e->cone->color.r);
		printf("ColorG : [%d]\n", e->cone->color.g);
		printf("ColorB : [%d]\n", e->cone->color.b);
		printf("Numero du maillon : [%d]\n", e->cone->nm);
		e->cone = e->cone->next;
		ft_putchar('\n');
	}
}
