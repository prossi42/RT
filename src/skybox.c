/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skybox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 12:33:45 by prossi            #+#    #+#             */
/*   Updated: 2018/04/13 14:59:08 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

char			color_is_black(t_rgb *color)
{
	int		nbr;

	nbr = color->r + color->b + color->g;
	if (!nbr)
		init_rgb(color, 1, 1, 1);
	return ((!nbr) ? 1 : 0);
}

t_rgb			skybox(t_stuff *e, t_rgb color, t_vec *raydir)
{
	t_rgb		color_sky;
	t_uv		uv;
	int			i;
	double		intensity;

	i = -1;
	intensity = 0;
	init_rgb(&color_sky, 0, 0, 0);
	uv.x = atan2(raydir->x, raydir->y) / (2 * M_PI) + 0.5;
	uv.y = raydir->z * 0.5 + 0.5;
	uv.x = e->tex.width * (1 - uv.x);
	uv.y = e->tex.height * (1 - uv.y);
	color_sky = get_sky_rgb((int)uv.x, (int)uv.y, e->tex);
	intensity *= (color_is_black(&color_sky)) ? 100 : 5;
	rgb_add(&color, color_sky, color, intensity);
	return (color);
}

void			parse_skybox(t_stuff *e)
{
	if ((e->tex.ptr = mlx_xpm_file_to_image(e->img.mlx_ptr,
		"pics/dths.xpm", &e->tex.width,
		&e->tex.height)))
	{
		if (!(e->tex.data = mlx_get_data_addr(e->tex.ptr,
			&e->tex.bpp, &e->tex.sizl,
			&e->tex.endian)))
			ft_putstr("skybox can't be loaded");
		else
			e->tex.is_init = 1;
	}
	else
		ft_putstr("skybox can't be loaded");
}

t_rgb			get_sky_rgb(int x, int y, t_skybox tex)
{
	int			c;
	t_rgb		color;
	int			pos;

	color.r = 0;
	color.g = 0;
	color.b = 0;
	if (x < tex.width && y < tex.height && x >= 0 && y >= 0)
	{
		pos = (x * tex.bpp / 8) + (y * tex.sizl);
		c = *(int *)&(tex.data[pos]);
		color.r = c / 65536 % 256;
		color.g = c / 256 % 256;
		color.b = c % 256;
		return (color);
	}
	return (color);
}
