/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objet_courant_fill_tab_data_camera.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Awk-LM <Awk-LM@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 21:26:24 by Awk-LM            #+#    #+#             */
/*   Updated: 2018/03/05 23:50:33 by Awk-LM           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	fill_tab_data_camera(t_stuff *e)
{
	ft_putendl("\n\nIn Case of segfault :");
	ft_putendl("1");
	sprintf(e->i.cobj.tab[0], "%.2f", e->i.mlx->data.pos.x);
	ft_putendl("2");
	sprintf(e->i.cobj.tab[1], "%.2f", e->i.mlx->data.pos.y);
	ft_putendl("3");
	sprintf(e->i.cobj.tab[2], "%.2f", e->i.mlx->data.pos.z);
	ft_putendl("4");
	sprintf(e->i.cobj.tab[3], "%.2f", e->i.mlx->data.dir.x);
	ft_putendl("5");
	sprintf(e->i.cobj.tab[4], "%.2f", e->i.mlx->data.dir.y);
	ft_putendl("6");
	sprintf(e->i.cobj.tab[5], "%.2f", e->i.mlx->data.dir.z);
	ft_putendl("7");
}
