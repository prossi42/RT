/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_interface.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:25:42 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 22:25:36 by Awk-LM           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	free2d(t_stuff *e)
{
	int		i;

	i = -1;
	while (e->i.term.tab[++i])
		ft_strdel(&e->i.term.tab[i]);
	free(e->i.term.tab);
}

int		launch_interface(t_stuff *e)
{
	init_struct(e, 0);
	objet_courant(e);
	apercu_courant(e);
	create_obj(e);
	terminal(e);
	matrice_interface(e);
	save_scene(e);
	save_scene_load_save(e);
	settings_color(e);
	shortcuts(e);
	if (e->i.first == 0)
	{
		e->i.first = 1;
		reboot_list_interface(e, 0);
	}
	return (0);
}
