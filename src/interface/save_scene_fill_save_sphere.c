/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_scene_fill_save_sphere.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:31:02 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 17:07:13 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	fill_save_sphere_td(t_stuff *e)
{
	e->i.save.tmp_buf = ft_mydtoa(e->sph->color.g, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n\nb = ");
	ft_strclr(e->i.save.tmp_buf);
	e->i.save.tmp_buf = ft_mydtoa(e->sph->color.b, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n\nrefrac = ");
	ft_strclr(e->i.save.tmp_buf);
	e->i.save.tmp_buf = ft_mydtoa(e->sph->refrac, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n\nconscol = ");
	ft_strclr(e->i.save.tmp_buf);
	e->i.save.tmp_buf = ft_mydtoa(e->sph->conscol, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n\nreflex = ");
	ft_strclr(e->i.save.tmp_buf);
	e->i.save.tmp_buf = ft_mydtoa(e->sph->reflex, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n------\n");
}

void	fill_save_sphere_sd(t_stuff *e)
{
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, \
		"SPHERE\n------\nx = ");
	ft_strclr(e->i.save.tmp_buf);
	e->i.save.tmp_buf = ft_mydtoa(e->sph->pos.x, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n\ny = ");
	ft_strclr(e->i.save.tmp_buf);
	e->i.save.tmp_buf = ft_mydtoa(e->sph->pos.y, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n\nz = ");
	ft_strclr(e->i.save.tmp_buf);
	e->i.save.tmp_buf = ft_mydtoa(e->sph->pos.z, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n\nray = ");
	ft_strclr(e->i.save.tmp_buf);
	e->i.save.tmp_buf = ft_mydtoa(e->sph->ray, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n\nr = ");
	ft_strclr(e->i.save.tmp_buf);
	e->i.save.tmp_buf = ft_mydtoa(e->sph->color.r, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n\ng = ");
	ft_strclr(e->i.save.tmp_buf);
}

void	fill_save_sphere(t_stuff *e)
{
	while (e->sph)
	{
		fill_save_sphere_sd(e);
		fill_save_sphere_td(e);
		if (e->sph->next != NULL)
			e->sph = e->sph->next;
		else
			break ;
	}
}
