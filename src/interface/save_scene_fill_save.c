/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_scene_fill_save.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:32:18 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 17:04:45 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	fill_save_cone_fh(t_stuff *e)
{
	e->i.save.tmp_buf = ft_mydtoa(e->cone->conscol, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n\nreflex = ");
	ft_strclr(e->i.save.tmp_buf);
	e->i.save.tmp_buf = ft_mydtoa(e->cone->reflex, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n------\n");
}

void	fill_save_cone_td(t_stuff *e)
{
	e->i.save.tmp_buf = ft_mydtoa(e->cone->color.b, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n\nnormX = ");
	ft_strclr(e->i.save.tmp_buf);
	e->i.save.tmp_buf = ft_mydtoa(e->cone->norm.x, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n\nnormY = ");
	ft_strclr(e->i.save.tmp_buf);
	e->i.save.tmp_buf = ft_mydtoa(e->cone->norm.y, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n\nnormZ = ");
	ft_strclr(e->i.save.tmp_buf);
	e->i.save.tmp_buf = ft_mydtoa(e->cone->norm.z, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n\nangle = ");
	ft_strclr(e->i.save.tmp_buf);
	e->i.save.tmp_buf = ft_mydtoa(e->cone->angle, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n\nrefrac = ");
	ft_strclr(e->i.save.tmp_buf);
	e->i.save.tmp_buf = ft_mydtoa(e->cone->refrac, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n\nconscol = ");
	ft_strclr(e->i.save.tmp_buf);
}

void	fill_save_cone_sd(t_stuff *e)
{
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, \
		"CONE\n------\nx = ");
	ft_strclr(e->i.save.tmp_buf);
	e->i.save.tmp_buf = ft_mydtoa(e->cone->pos.x, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n\ny = ");
	ft_strclr(e->i.save.tmp_buf);
	e->i.save.tmp_buf = ft_mydtoa(e->cone->pos.y, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n\nz = ");
	ft_strclr(e->i.save.tmp_buf);
	e->i.save.tmp_buf = ft_mydtoa(e->cone->pos.z, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n\nr = ");
	ft_strclr(e->i.save.tmp_buf);
	e->i.save.tmp_buf = ft_mydtoa(e->cone->color.r, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n\ng = ");
	ft_strclr(e->i.save.tmp_buf);
	e->i.save.tmp_buf = ft_mydtoa(e->cone->color.g, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, e->i.save.tmp_buf);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "\n\nb = ");
	ft_strclr(e->i.save.tmp_buf);
}

void	fill_save_cone(t_stuff *e)
{
	while (e->cone)
	{
		fill_save_cone_sd(e);
		fill_save_cone_td(e);
		fill_save_cone_fh(e);
		if (e->cone->next != NULL)
			e->cone = e->cone->next;
		else
			break ;
	}
}

int		save_scene_fill_save(t_stuff *e)
{
	if (!(e->i.save.save_buf = ft_strnew(300 * (e->d.nbmsph + \
		e->d.nbmcyl + e->d.nbmpla + e->d.nbmcone + e->d.nbmlight))))
		return (-1);
	if (!(e->i.save.tmp_buf = ft_strnew(300)))
		return (-1);
	e->i.save.save_buf = ft_strcat(e->i.save.save_buf, "------\n");
	reboot_list_loop(e, 3);
	if (e->d.nbmsph != 0)
		fill_save_sphere(e);
	if (e->d.nbmpla != 0)
		fill_save_plan(e);
	if (e->d.nbmlight != 0)
		fill_save_light(e);
	if (e->d.nbmcyl != 0)
		fill_save_cylindre(e);
	if (e->d.nbmcone != 0)
		fill_save_cone(e);
	ft_putstr_fd(e->i.save.save_buf, e->i.save.fd);
	ft_strdel(&e->i.save.save_buf);
	ft_strdel(&e->i.save.tmp_buf);
	return (0);
}
