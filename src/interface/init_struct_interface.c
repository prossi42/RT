/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_interface.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 16:35:10 by prossi            #+#    #+#             */
/*   Updated: 2018/04/13 16:38:49 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	init_struct_fih(t_stuff *e, int option)
{
	if (option == 7 && e->i.first == 0)
	{
		if (!(e->i.color.tab = ft_tabint(18, 12)))
			exit(-1);
		fill_tab_color(e->i.color.tab);
		if (!(e->i.color.tabxd = ft_tabint(18, 12)))
			exit(-1);
		if (!(e->i.color.tabxf = ft_tabint(18, 12)))
			exit(-1);
		if (!(e->i.color.tabyd = ft_tabint(18, 12)))
			exit(-1);
		if (!(e->i.color.tabyf = ft_tabint(18, 12)))
			exit(-1);
	}
}

void	init_struct_fh(t_stuff *e, int option)
{
	if (option == 6 && e->i.first == 0)
	{
		e->i.load.index_load = 0;
		e->i.load.dir_stream = NULL;
		e->i.load.dir_list = NULL;
		e->i.load.nb_dir = 0;
		e->i.load.tab = NULL;
		e->i.load.index = 0;
		e->i.load.select = 0;
		e->i.load.first = 0;
		e->i.load.act_load = 0;
		e->i.load.act_erase = 0;
		e->i.load.nsph = 0;
		e->i.load.nlight = 0;
		e->i.load.npla = 0;
		e->i.load.ncyl = 0;
		e->i.load.ncone = 0;
	}
	init_struct_fih(e, option);
}

void	init_struct_td(t_stuff *e, int option)
{
	if (option == 4 && e->i.first == 0)
	{
		e->i.cobj.power = 0;
		e->i.color.cobj.col1 = 0x202020;
		e->i.color.cobj.col2 = 0x000000;
		e->i.color.cobj.col3 = 0xFFFFFF;
		e->i.cobj.settings = 0;
	}
	if (option == 5 && e->i.first == 0)
	{
		e->i.color.saves.col1 = 0x202020;
		e->i.color.saves.col2 = 0x000000;
		e->i.color.saves.col3 = 0xFFFFFF;
		e->i.save.select = 0;
		e->i.save.settings = 0;
		e->i.save.act_save = 0;
	}
	init_struct_fh(e, option);
}

void	init_struct_sd(t_stuff *e, int option)
{
	if (option == 2 && e->i.first == 0)
	{
		e->i.term.dot = 0;
		e->i.term.index = 0;
		e->i.term.first = 0;
		e->i.term.indextab = 0;
		e->i.term.tabfill = 0;
		malloc2d(e);
		if (!(e->i.term.wbuf = ft_strnew(100)))
			exit(-1);
	}
	if (option == 3 && e->i.first == 0)
	{
		e->i.nobj.first = -1;
		e->i.nobj.open = 0;
		e->i.nobj.power = 0;
		e->i.color.nobj.col1 = 0x202020;
		e->i.color.nobj.col2 = 0x000000;
		e->i.color.nobj.col3 = 0xFFFFFF;
		e->i.nobj.settings = 0;
	}
	init_struct_td(e, option);
}

void	init_struct(t_stuff *e, int option)
{
	if (option == 0 && e->i.first == 0)
	{
		e->i.nb_img = 0;
		e->i.objet = -1;
		e->i.each_obj = 0;
	}
	if (option == 1 && e->i.first == 0)
	{
		e->i.mat.act_trans = -1;
		e->i.mat.act_rot = -1;
		e->i.mat.dir_or_pos = 0;
		e->i.mat.act_xyz = 0;
		e->i.mat.act_angle = 0;
		e->i.mat.act_value = 0;
		e->i.color.mat.col1 = 0x202020;
		e->i.color.mat.col2 = 0x000000;
		e->i.color.mat.col3 = 0xFFFFFF;
		e->i.mat.settings = 0;
	}
	init_struct_sd(e, option);
}
