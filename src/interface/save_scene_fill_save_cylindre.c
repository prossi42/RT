/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_scene_fill_save_cylindre.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:30:42 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 10:30:43 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	fill_save_cylindre_fh(t_stuff *e)
{
	e->i.save.tmp_buf = ft_mydtoa(e->cyl->conscol, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n\nreflex = ");
	ft_strclr(e->i.save.tmp_buf);
	e->i.save.tmp_buf = ft_mydtoa(e->cyl->reflex, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n------\n");
}

void	fill_save_cylindre_td(t_stuff *e)
{
	e->i.save.tmp_buf = ft_mydtoa(e->cyl->norm.z, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n\nray = ");
	ft_strclr(e->i.save.tmp_buf);
	e->i.save.tmp_buf = ft_mydtoa(e->cyl->ray, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n\nr = ");
	ft_strclr(e->i.save.tmp_buf);
	e->i.save.tmp_buf = ft_mydtoa(e->cyl->color.r, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n\ng = ");
	ft_strclr(e->i.save.tmp_buf);
	e->i.save.tmp_buf = ft_mydtoa(e->cyl->color.g, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n\nb = ");
	ft_strclr(e->i.save.tmp_buf);
	e->i.save.tmp_buf = ft_mydtoa(e->cyl->color.b, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n\nrefrac = ");
	ft_strclr(e->i.save.tmp_buf);
	e->i.save.tmp_buf = ft_mydtoa(e->cyl->refrac, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n\nconscol = ");
	ft_strclr(e->i.save.tmp_buf);
}

void	fill_save_cylindre_sd(t_stuff *e)
{
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, \
		"CYLINDRE\n------\nx = ");
	ft_strclr(e->i.save.tmp_buf);
	e->i.save.tmp_buf = ft_mydtoa(e->cyl->pos.x, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n\ny = ");
	ft_strclr(e->i.save.tmp_buf);
	e->i.save.tmp_buf = ft_mydtoa(e->cyl->pos.y, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n\nz = ");
	ft_strclr(e->i.save.tmp_buf);
	e->i.save.tmp_buf = ft_mydtoa(e->cyl->pos.z, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n\nnormX = ");
	ft_strclr(e->i.save.tmp_buf);
	e->i.save.tmp_buf = ft_mydtoa(e->cyl->norm.x, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n\nnormY = ");
	ft_strclr(e->i.save.tmp_buf);
	e->i.save.tmp_buf = ft_mydtoa(e->cyl->norm.y, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n\nnormZ = ");
	ft_strclr(e->i.save.tmp_buf);
}

void	fill_save_cylindre(t_stuff *e)
{
	while (e->cyl)
	{
		fill_save_cylindre_sd(e);
		fill_save_cylindre_td(e);
		fill_save_cylindre_fh(e);
		if (e->cyl->next != NULL)
			e->cyl = e->cyl->next;
		else
			break ;
	}
}
