/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_filtres.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 15:15:14 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 10:05:20 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		cartoon_sd(t_stuff *e, t_rgb *color)
{
	if (color->r >= 150 && color->r < 200)
		color->r = 175;
	if (color->g >= 150 && color->g < 200)
		color->g = 175;
	if (color->b >= 150 && color->b < 200)
		color->b = 175;
	if (color->r >= 200 && color->r <= 255)
		color->r = 225;
	if (color->g >= 200 && color->g <= 255)
		color->g = 225;
	if (color->b >= 200 && color->b <= 255)
		color->b = 225;
	if (e->c.obj == -1)
	{
		color->r = 0;
		color->g = 0;
		color->b = 0;
	}
}

void			cartoon(t_stuff *e, t_rgb *color)
{
	if (color->r >= 0 && color->r < 50)
		color->r = 25;
	if (color->g >= 0 && color->g < 50)
		color->g = 25;
	if (color->b >= 0 && color->b < 50)
		color->b = 25;
	if (color->r >= 50 && color->r < 100)
		color->r = 75;
	if (color->g >= 50 && color->g < 100)
		color->g = 75;
	if (color->b >= 50 && color->b < 100)
		color->b = 75;
	if (color->r >= 100 && color->r < 150)
		color->r = 125;
	if (color->g >= 100 && color->g < 150)
		color->g = 125;
	if (color->b >= 100 && color->b < 150)
		color->b = 125;
	cartoon_sd(e, color);
}

void			black_n_white(t_rgb *color)
{
	int		tmp;

	tmp = color->r + color->g + color->b;
	color->r = tmp / 3;
	color->g = tmp / 3;
	color->b = tmp / 3;
}

t_rgb			get_pixel(int x, int y, t_img *img)
{
	int			i;
	t_rgb		color;

	i = img->bits_per_pixel / 8;
	color.b = img->data[y * img->size_line + x * i];
	color.g = img->data[y * img->size_line + x * i + 1];
	color.r = img->data[y * img->size_line + x * i + 2];
	if (color.r < 0)
		color.r += 255;
	if (color.g < 0)
		color.g += 255;
	if (color.b < 0)
		color.b += 255;
	return (color);
}

void			interface_filtres(t_stuff *e)
{
	if (e->i.filtre == 1)
		black_n_white(&e->c.colorf);
	else if (e->i.filtre == 2)
		cartoon(e, &e->c.colorf);
	else if (e->i.filtre == 3)
		blur(e, 1);
	else if (e->i.filtre == 4)
		blur(e, 2);
}
