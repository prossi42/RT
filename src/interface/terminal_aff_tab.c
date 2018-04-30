/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_aff_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 16:18:38 by prossi            #+#    #+#             */
/*   Updated: 2018/04/16 16:20:03 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	aff_tab(t_stuff *e)
{
	if (e->i.term.tabfill == 1)
	{
		if (e->i.term.indextab == 4)
		{
			ft_strclr(e->i.term.tab[0]);
			e->i.term.tab[0] = ft_strcpy(e->i.term.tab[0], e->i.term.tab[1]);
			ft_strclr(e->i.term.tab[1]);
			e->i.term.tab[1] = ft_strcpy(e->i.term.tab[1], e->i.term.tab[2]);
			ft_strclr(e->i.term.tab[2]);
			e->i.term.tab[2] = ft_strcpy(e->i.term.tab[2], e->i.term.tab[3]);
			e->i.term.indextab -= 1;
			redraw_tab(e);
		}
		if (e->i.term.indextab >= 0)
			mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, \
				(WIN_Y - LENGTH) * 3 + (0 * 40), 0xFFFFFF, e->i.term.tab[0]);
		if (e->i.term.indextab > 1)
			mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, \
				(WIN_Y - LENGTH) * 3 + (1 * 40), 0xFFFFFF, e->i.term.tab[1]);
		if (e->i.term.indextab > 2)
			mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, \
				(WIN_Y - LENGTH) * 3 + (2 * 40), 0xFFFFFF, e->i.term.tab[2]);
	}
}
