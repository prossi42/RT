/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_aff_new_sphere.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Awk-LM <Awk-LM@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 13:31:38 by Awk-LM            #+#    #+#             */
/*   Updated: 2018/02/15 14:39:42 by Awk-LM           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void 	aff_new_sphere(t_stuff *e)
{
	if (e->i.nobj.first == 0)
	{
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, (WIN_Y - LENGTH) * 3 + 3 * 40, 0xFFFFFF, "Position en X ? : ");
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, WIN_X - WIDTH - 320, (WIN_Y - LENGTH) * 3 + 3 * 40, 0xFFFFFF, e->i.term.wbuf);
	}
	else if (e->i.nobj.first == 1)
	{
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, (WIN_Y - LENGTH) * 3 + 3 * 40, 0xFFFFFF, "Position en Y ? : ");
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, WIN_X - WIDTH - 320, (WIN_Y - LENGTH) * 3 + 3 * 40, 0xFFFFFF, e->i.term.wbuf);
	}
	else if (e->i.nobj.first == 2)
	{
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, (WIN_Y - LENGTH) * 3 + 3 * 40, 0xFFFFFF, "Position en Z ? : ");
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, WIN_X - WIDTH - 320, (WIN_Y - LENGTH) * 3 + 3 * 40, 0xFFFFFF, e->i.term.wbuf);
	}
	else if (e->i.nobj.first == 3)
	{
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, (WIN_Y - LENGTH) * 3 + 3 * 40, 0xFFFFFF, "Couleur R ? : ");
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, WIN_X - WIDTH - 360, (WIN_Y - LENGTH) * 3 + 3 * 40, 0xFFFFFF, e->i.term.wbuf);
	}
	else if (e->i.nobj.first == 4)
	{
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, (WIN_Y - LENGTH) * 3 + 3 * 40, 0xFFFFFF, "Couleur G ? : ");
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, WIN_X - WIDTH - 360, (WIN_Y - LENGTH) * 3 + 3 * 40, 0xFFFFFF, e->i.term.wbuf);
	}
	else if (e->i.nobj.first == 5)
	{
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, (WIN_Y - LENGTH) * 3 + 3 * 40, 0xFFFFFF, "Couleur B ? : ");
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, WIN_X - WIDTH - 360, (WIN_Y - LENGTH) * 3 + 3 * 40, 0xFFFFFF, e->i.term.wbuf);
	}
	else if (e->i.nobj.first == 6)
	{
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, (WIN_Y - LENGTH) * 3 + 3 * 40, 0xFFFFFF, "Rayon ? : ");
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, WIN_X - WIDTH - 400, (WIN_Y - LENGTH) * 3 + 3 * 40, 0xFFFFFF, e->i.term.wbuf);
	}
}
