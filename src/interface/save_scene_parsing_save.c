/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_scene_parsing_save.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 12:10:22 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 14:02:07 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	del_excessed_mail(t_stuff *e)
{
	del_excessed_mail_sphere(e);
	del_excessed_mail_plan(e);
	del_excessed_mail_light(e);
	del_excessed_mail_cylindre(e);
	del_excessed_mail_cone(e);
}

void	empty_list(t_stuff *e)
{
	if (e->i.load.nsph == 0)
		set_to_zero_list_sph(e);
	if (e->i.load.npla == 0)
		set_to_zero_list_plan(e);
	if (e->i.load.nlight == 0)
		set_to_zero_list_light(e);
	if (e->i.load.ncyl == 0)
		set_to_zero_list_cylindre(e);
	if (e->i.load.ncone == 0)
		set_to_zero_list_cone(e);
}

void	free_tab_parsing(t_stuff *e)
{
	int		y;

	y = -1;
	while (++y < e->i.load.nbl)
	{
		ft_strdel(&e->i.load.tab_load[y]);
	}
	free(e->i.load.tab_load);
}

int		save_scene_parsing_save(t_stuff *e)
{
	char		*tmp;

	if (!(tmp = ft_strnew(100)))
		return (-1);
	tmp = ft_strncat(tmp, e->i.save.save_dir, \
		ft_strlen(e->i.save.save_dir) - 1);
	if ((e->i.save.fd = open(tmp, O_RDONLY)) < 0)
		return (-1);
	ft_strdel(&tmp);
	e->i.load.buf[read(e->i.save.fd, e->i.load.buf, BUFF_SIZE)] = '\0';
	reboot_list_loop(e, 3);
	if (parsing_format(e) == -1)
		return (-1);
	ft_strclr(e->i.load.buf);
	reboot_multiobj_value(e, 1);
	return (0);
}
