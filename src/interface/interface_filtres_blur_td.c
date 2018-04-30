/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_filtres_blur_td.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:05:47 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 10:06:46 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_rgb		blur_td_sh(t_stuff *e, t_xycoef trio, t_rgb tmp, t_rgb alo)
{
	if (trio.x < WIDTH - trio.coef && trio.x >= trio.coef)
	{
		e->i.i++;
		tmp = get_pixel(trio.x + trio.coef, trio.y, &e->img);
		alo = blur_td_sd(alo, tmp);
	}
	if (trio.y < LENGTH - trio.coef && trio.y >= trio.coef)
	{
		e->i.i++;
		tmp = get_pixel(trio.x, trio.y + trio.coef, &e->img);
		alo = blur_td_sd(alo, tmp);
	}
	alo = blur_td_td(alo, e->i.i);
	return (alo);
}

t_rgb		blur_td_fih(t_stuff *e, t_xycoef trio, t_rgb tmp, t_rgb alo)
{
	if (trio.x >= trio.coef && trio.x < WIDTH - trio.coef && trio.y > \
		trio.coef && trio.y <= LENGTH - trio.coef)
	{
		e->i.i++;
		tmp = get_pixel(trio.x + trio.coef, trio.y - trio.coef, &e->img);
		alo = blur_td_sd(alo, tmp);
	}
	if (trio.x > trio.coef && trio.x <= WIDTH - trio.coef && trio.y >= \
		trio.coef && trio.y < LENGTH - trio.coef)
	{
		e->i.i++;
		tmp = get_pixel(trio.x - trio.coef, trio.y + trio.coef, &e->img);
		alo = blur_td_sd(alo, tmp);
	}
	if (trio.y > trio.coef && trio.y <= LENGTH - trio.coef)
	{
		e->i.i++;
		tmp = get_pixel(trio.x, trio.y - trio.coef, &e->img);
		alo = blur_td_sd(alo, tmp);
	}
	return (alo);
}

t_rgb		blur_td_fh(t_stuff *e, t_xycoef trio, t_rgb tmp, t_rgb alo)
{
	alo = get_pixel(trio.x, trio.y, &e->img);
	if (trio.x > trio.coef && trio.x <= WIDTH - trio.coef)
	{
		e->i.i++;
		tmp = get_pixel(trio.x - trio.coef, trio.y, &e->img);
		alo = blur_td_sd(alo, tmp);
	}
	if (trio.x > trio.coef && trio.x <= WIDTH - trio.coef && trio.y > \
		trio.coef && trio.y <= LENGTH - trio.coef)
	{
		e->i.i++;
		tmp = get_pixel(trio.x - trio.coef, trio.y - trio.coef, &e->img);
		alo = blur_td_sd(alo, tmp);
	}
	if (trio.x >= trio.coef && trio.x < WIDTH - trio.coef && trio.y >= \
		trio.coef && trio.y < LENGTH - trio.coef)
	{
		e->i.i++;
		tmp = get_pixel(trio.x + trio.coef, trio.y + trio.coef, &e->img);
		alo = blur_td_sd(alo, tmp);
	}
	return (alo);
}
