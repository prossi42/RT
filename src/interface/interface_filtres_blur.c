/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_filtres_blur.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:02:23 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 10:02:55 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_rgb		blur_td_td(t_rgb alo, int i)
{
	alo.r = alo.r / i;
	alo.g = alo.g / i;
	alo.b = alo.b / i;
	return (alo);
}

t_rgb		blur_td_sd(t_rgb alo, t_rgb tmp)
{
	alo.r += tmp.r;
	alo.g += tmp.g;
	alo.b += tmp.b;
	return (alo);
}

t_rgb		blur_td(t_stuff *e, int x, int y, int coef)
{
	t_rgb		alo;
	t_rgb		tmp;
	t_xycoef	trio;

	e->i.i = 1;
	tmp.r = 0;
	tmp.g = 0;
	tmp.b = 0;
	trio.x = x;
	trio.y = y;
	trio.coef = coef;
	alo.r = 0;
	alo.g = 0;
	alo.b = 0;
	alo = blur_td_fh(e, trio, tmp, alo);
	alo = blur_td_fih(e, trio, tmp, alo);
	alo = blur_td_sh(e, trio, tmp, alo);
	return (alo);
}

void		blur_sd(t_stuff *e, int option, int x, int y)
{
	double		color;

	if (option == 1)
		e->c.colorf = blur_td(e, x, y, 10);
	else if (option == 2)
		e->c.colorf = blur_td(e, x, y, 1);
	if (e->c.colorf.r > 255)
		e->c.colorf.r = 255;
	else if (e->c.colorf.r < 0)
		e->c.colorf.r = 0;
	if (e->c.colorf.g > 255)
		e->c.colorf.g = 255;
	else if (e->c.colorf.g < 0)
		e->c.colorf.g = 0;
	if (e->c.colorf.b > 255)
		e->c.colorf.b = 255;
	else if (e->c.colorf.b < 0)
		e->c.colorf.b = 0;
	color = rgbtohexa(e->c.colorf.r, e->c.colorf.g, e->c.colorf.b);
	mlx_pixel_put_to_image(e->img, x, y, color);
}

void		blur(t_stuff *e, int option)
{
	int y;
	int x;

	y = -1;
	while (++y < LENGTH)
	{
		x = -1;
		while (++x < WIDTH)
		{
			blur_sd(e, option, x, y);
		}
	}
}
