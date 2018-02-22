/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_interface.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:25:42 by prossi            #+#    #+#             */
/*   Updated: 2018/02/22 23:39:11 by Awk-LM           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	free2d(t_stuff *e)
{
	int		i;

	i = -1;
	while (e->i.term.tab[++i])
	{
		ft_strdel(&e->i.term.tab[i]);
	}
	free(e->i.term.tab);
}

void	malloc2d(t_stuff *e)
{
	int		i;
	int		err;

	if (!(e->i.term.tab = (char **)malloc(sizeof(char *) * 5)))
		err = 1;
	i = -1;
	if (err == 1)
	{
		ft_putstr("\nLe malloc du tableau (interface - terminal) a echoué\n");
		exit (0);
	}
	while (++i < 5)
	{
		if (!(e->i.term.tab[i] = ft_strnew(100)))
			err = 1;
		if (err == 1)
		{
			ft_putstr("\nLe malloc du tableau (interface - terminal) a echoué\n");
			exit (0);
		}
	}
	e->i.term.tab[i] = NULL;
}

void 	init_struct(t_stuff *e, int option)
{
	if (option == 0 && e->i.first == 0)
	{
		e->i.nb_img = 0;
		e->i.objet = -1;
		e->i.each_obj = 0;
	}
	if (option == 1 && e->i.first == 0)
	{
		e->i.mat.act_trans = 0;
		e->i.mat.act_rot = 0;
		e->i.mat.dir_or_pos = 0;
		e->i.mat.act_xyz = 0;
		e->i.mat.col_fond = 0x800000;
		e->i.mat.col_box = 0x6A455D;
		e->i.mat.act_angle = 0;
		e->i.mat.act_value = 0;
	}
	if (option == 2 && e->i.first == 0)
	{
		e->i.term.dot = 0;
		e->i.term.index = 0;
		e->i.term.first = 0;
		e->i.term.indextab = 0;
		e->i.term.tabfill = 0;
		malloc2d(e);
		e->i.term.wbuf = ft_strnew(100);
	}
	if (option == 3 && e->i.first == 0)
	{
		e->i.nobj.first = -1;
		e->i.nobj.open = 0;
		e->i.nobj.power = 0;
	}
}

int		launch_interface(t_stuff *e)
{
	init_struct(e, 0);
	objet_courant(e);
	apercu_courant(e);
	create_obj(e);
	terminal(e);
	matrice_interface(e);
	if (e->i.first == 0)
	{
		e->i.first = 1;
		reboot_list_interface(e, 0);
	}
	return (0);
}
