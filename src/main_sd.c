/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhermann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 11:25:59 by lhermann          #+#    #+#             */
/*   Updated: 2018/04/13 11:35:36 by lhermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		ft_exit_sd(int code, t_stuff *e)
{
	while (e->cyl)
	{
		free(e->cyl);
		e->cyl = e->cyl->next;
	}
	while (e->cone)
	{
		free(e->cone);
		e->cone = e->cone->next;
	}
	ft_putstr("Error happened: ");
	ft_putnbr(code);
	ft_putendl("\nExiting.");
	exit(code);
}

void		ft_exit(int code, t_stuff *e)
{
	if (e->img.data)
		free(e->img.data);
	while (e->sph)
	{
		free(e->sph);
		e->sph = e->sph->next;
	}
	while (e->pla)
	{
		free(e->pla);
		e->pla = e->pla->next;
	}
	while (e->light)
	{
		free(e->light);
		e->light = e->light->next;
	}
	ft_exit_sd(code, e);
}
