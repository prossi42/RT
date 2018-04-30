/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_scene_fill_save_plan.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:30:56 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 10:30:56 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	fill_save_plan_fh(t_stuff *e)
{
	e->i.save.tmp_buf = ft_mydtoa(e->pla->reflex, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n\nray = ");
	ft_strclr(e->i.save.tmp_buf);
	e->i.save.tmp_buf = ft_mydtoa(e->pla->ray, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n------\n");
}

void	fill_save_plan_td(t_stuff *e)
{
	e->i.save.tmp_buf = ft_mydtoa(e->pla->color.b, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n\nnormX = ");
	ft_strclr(e->i.save.tmp_buf);
	e->i.save.tmp_buf = ft_mydtoa(e->pla->norm.x, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n\nnormY = ");
	ft_strclr(e->i.save.tmp_buf);
	e->i.save.tmp_buf = ft_mydtoa(e->pla->norm.y, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n\nnormZ = ");
	ft_strclr(e->i.save.tmp_buf);
	e->i.save.tmp_buf = ft_mydtoa(e->pla->norm.z, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n\nrefrac = ");
	ft_strclr(e->i.save.tmp_buf);
	e->i.save.tmp_buf = ft_mydtoa(e->pla->refrac, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n\nconscol = ");
	ft_strclr(e->i.save.tmp_buf);
	e->i.save.tmp_buf = ft_mydtoa(e->pla->conscol, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n\nreflex = ");
	ft_strclr(e->i.save.tmp_buf);
}

void	fill_save_plan_sd(t_stuff *e)
{
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, \
		"PLAN\n------\nx = ");
	ft_strclr(e->i.save.tmp_buf);
	e->i.save.tmp_buf = ft_mydtoa(e->pla->pos.x, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n\ny = ");
	ft_strclr(e->i.save.tmp_buf);
	e->i.save.tmp_buf = ft_mydtoa(e->pla->pos.y, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n\nz = ");
	ft_strclr(e->i.save.tmp_buf);
	e->i.save.tmp_buf = ft_mydtoa(e->pla->pos.z, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n\nr = ");
	ft_strclr(e->i.save.tmp_buf);
	e->i.save.tmp_buf = ft_mydtoa(e->pla->color.r, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n\ng = ");
	ft_strclr(e->i.save.tmp_buf);
	e->i.save.tmp_buf = ft_mydtoa(e->pla->color.g, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n\nb = ");
	ft_strclr(e->i.save.tmp_buf);
}

void	fill_save_plan(t_stuff *e)
{
	while (e->pla)
	{
		fill_save_plan_sd(e);
		fill_save_plan_td(e);
		fill_save_plan_fh(e);
		if (e->pla->next != NULL)
			e->pla = e->pla->next;
		else
			break ;
	}
}
