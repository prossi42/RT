/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_sd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <jgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 12:42:05 by jgaillar          #+#    #+#             */
/*   Updated: 2018/04/23 09:57:25 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		aff_td(t_stuff *e)
{
	init_rgb(&e->c.colorf, 0, 0, 0);
	e->ray = -1;
	reboot_list_loop(e, 3);
	raydir(e, e->c.posx, e->c.posy);
	e->c.colorf = raythingy(e, &e->raydir, &e->poscam);
}

static void		aff_sd(t_stuff *e)
{
	double		color;

	while (e->c.posx < WIDTH)
	{
		aff_td(e);
		if (e->i.filtre == 1 || e->i.filtre == 2)
			interface_filtres(e);
		else if (e->i.filtre == 6)
			init_rgb(&e->c.colorf, 255 - e->c.colorf.r, \
				255 - e->c.colorf.g, 255 - e->c.colorf.b);
		color = rgbtohexa(e->c.colorf.r, e->c.colorf.g, e->c.colorf.b);
		if (e->pix > 0)
			pixelisation(e, color);
		else
			mlx_pixel_put_to_image(e->img, e->c.posx,\
				e->c.posy, color);
		e->c.posx++;
	}
	e->c.posy++;
	if (e->pix > 0)
		e->c.posy += e->pix;
}

void			*aff(void *ev)
{
	int		i;
	int		j;
	t_stuff	*e;

	e = ((t_stuff *)ev);
	i = 0;
	j = 0;
	e->c.posy = e->start;
	while (e->c.posy <= e->end)
	{
		e->c.posx = 0;
		aff_sd(e);
	}
	reboot_list_loop(e, 3);
	pthread_exit(NULL);
}

void			dedouble_list(t_stuff *tmp)
{
	tmp->sph = copysphlist(tmp->sph);
	tmp->pla = copyplalist(tmp->pla);
	tmp->light = copylightlist(tmp->light);
	tmp->cyl = copycyllist(tmp->cyl);
	tmp->cone = copyconelist(tmp->cone);
}

void			multi_thread(t_stuff *e)
{
	t_stuff		*tab;
	pthread_t	thread[MT];

	if (!(tab = (t_stuff *)malloc(MT * sizeof(t_stuff))))
		exit(-1);
	e->imt = -1;
	reboot_list_loop(e, 3);
	while (++e->imt < MT)
	{
		tab[e->imt] = *e;
		tab[e->imt].start = e->imt * LENGTH / MT;
		tab[e->imt].end = tab[e->imt].start + LENGTH / MT;
		dedouble_list(&(tab[e->imt]));
		pthread_create(&thread[e->imt], NULL, aff, &tab[e->imt]);
	}
	e->imt = -1;
	while (++e->imt < MT)
		pthread_join(thread[e->imt], NULL);
	if (e->i.first == 0)
		launch_interface(e);
	mlx_put_image_to_window(e->img.mlx_ptr, e->img.win_ptr, \
		e->img.img_ptr, WIN_X - WIDTH, WIN_Y - LENGTH);
	freetabmt(e, tab);
}
