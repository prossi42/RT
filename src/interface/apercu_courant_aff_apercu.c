/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apercu_courant_aff_apercu.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 08:04:27 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 12:37:57 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		vectorcalc_apercu(t_stuff *e)
{
	e->i.poscam.x = e->i.mlx->data.pos.x - 10;
	e->i.poscam.y = e->i.mlx->data.pos.y;
	e->i.poscam.z = e->i.mlx->data.pos.z;
}

void		aff_apercu_set_value(t_stuff *e, double color)
{
	int		j;
	int		i;

	init_rgb(&e->c.colorf, 0, 0, 0);
	e->ray = -1;
	reboot_list_loop(e, 3);
	raydir_apercu(e, e->c.posx, e->c.posy);
	e->poscam = e->i.poscam;
	e->c.colorf = raythingy(e, &e->i.raydir, &e->poscam);
	color = rgbtohexa(e->c.colorf.r, e->c.colorf.g, e->c.colorf.b);
	if (e->pix > 0)
	{
		j = -1;
		while (++j <= e->pix)
		{
			i = -1;
			while (++i <= e->pix)
				pixel_put_to_img(&e->i.mlx, e->c.posx + i, e->c.posy + j,
					color);
		}
		e->c.posx += e->pix;
	}
	else
		pixel_put_to_img(&e->i.mlx, e->c.posx, e->c.posy, color);
}

void		*aff_apercu(void *ev)
{
	double	color;
	t_vec	tmp_poscam;
	t_stuff	*e;

	e = ((t_stuff *)ev);
	color = 0;
	vectorcalc_apercu(e);
	tmp_poscam = e->poscam;
	e->c.posy = e->start2 - 1;
	while (++e->c.posy < e->end2)
	{
		e->c.posx = -1;
		while (++e->c.posx < e->i.mlx->img_x)
			aff_apercu_set_value(e, color);
		if (e->pix > 0)
			e->c.posy += e->pix;
	}
	reboot_list_loop(e, 3);
	e->poscam = tmp_poscam;
	pthread_exit(NULL);
}
