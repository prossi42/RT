/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_scene_fill_save_light.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:30:51 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 10:30:51 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	fill_save_light_td(t_stuff *e)
{
	e->i.save.tmp_buf = ft_mydtoa(e->light->color.g, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n\nb = ");
	ft_strclr(e->i.save.tmp_buf);
	e->i.save.tmp_buf = ft_mydtoa(e->light->color.b, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n\namb = ");
	ft_strclr(e->i.save.tmp_buf);
	e->i.save.tmp_buf = ft_mydtoa(e->light->amb, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n\ndiff = ");
	ft_strclr(e->i.save.tmp_buf);
	e->i.save.tmp_buf = ft_mydtoa(e->light->diff, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n------\n");
}

void	fill_save_light_sd(t_stuff *e)
{
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, \
		"LIGHT\n------\nx = ");
	ft_strclr(e->i.save.tmp_buf);
	e->i.save.tmp_buf = ft_mydtoa(e->light->pos.x, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n\ny = ");
	ft_strclr(e->i.save.tmp_buf);
	e->i.save.tmp_buf = ft_mydtoa(e->light->pos.y, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n\nz = ");
	ft_strclr(e->i.save.tmp_buf);
	e->i.save.tmp_buf = ft_mydtoa(e->light->pos.z, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n\nray = ");
	ft_strclr(e->i.save.tmp_buf);
	e->i.save.tmp_buf = ft_mydtoa(e->light->ray, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n\nr = ");
	ft_strclr(e->i.save.tmp_buf);
	e->i.save.tmp_buf = ft_mydtoa(e->light->color.r, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n\ng = ");
	ft_strclr(e->i.save.tmp_buf);
}

void	fill_save_light(t_stuff *e)
{
	while (e->light)
	{
		fill_save_light_sd(e);
		fill_save_light_td(e);
		if (e->light->next != NULL)
			e->light = e->light->next;
		else
			break ;
	}
}
