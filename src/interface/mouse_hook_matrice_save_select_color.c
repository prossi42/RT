/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook_matrice_save_select_color.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:15:24 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 10:15:25 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	mouse_hook_matrice_save_select_color_sd(t_stuff *e, int i, int j)
{
	if (e->i.mat.settings == 3)
		e->i.color.mat.col1 = e->i.color.tab[j][i];
	else if (e->i.mat.settings == 4)
		e->i.color.mat.col2 = e->i.color.tab[j][i];
	else if (e->i.mat.settings == 5)
		e->i.color.mat.col3 = e->i.color.tab[j][i];
	else if (e->i.save.settings == 3)
		e->i.color.saves.col1 = e->i.color.tab[j][i];
	else if (e->i.save.settings == 4)
		e->i.color.saves.col2 = e->i.color.tab[j][i];
	else if (e->i.save.settings == 5)
		e->i.color.saves.col3 = e->i.color.tab[j][i];
	e->i.mat.settings = 0;
	e->i.save.settings = 0;
	save_scene(e);
	matrice_interface(e);
}

void	mouse_hook_matrice_save_select_color(t_stuff *e, int x, int y)
{
	int		borderx;
	int		i;
	int		j;

	borderx = (WIN_X - WIDTH);
	j = -1;
	while (++j < 12)
	{
		i = -1;
		while (++i < 18)
		{
			if (x - borderx >= e->i.color.tabxd[j][i] && x - borderx <= \
				e->i.color.tabxf[j][i] \
			&& y >= e->i.color.tabyd[j][i] && y <= e->i.color.tabyf[j][i])
			{
				mouse_hook_matrice_save_select_color_sd(e, i, j);
			}
		}
	}
}
