/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apercu_courant.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 18:10:46 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 12:00:49 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			raydir_apercu(t_stuff *e, int y, int z)
{
	t_vec		pixel;
	t_vec		tmp;

	pixel.y = (y + 0.9) / (WIN_X - WIDTH);
	pixel.z = (z + 0.5) / (WIN_Y - LENGTH);
	pixel.y = (2 * pixel.y) - 1;
	pixel.z = 1 - (2 * pixel.z);
	pixel.y *= tan(FOVCAMSD * 0.9 * M_PI / 180) * ((WIN_X - WIDTH)
		/ (WIN_Y - LENGTH));
	pixel.z *= tan(FOVCAMSD * 0.5 * M_PI / 180);
	pixel.x = 1;
	vecadd(&pixel, &pixel, &e->i.poscam);
	vecsous(&tmp, &pixel, &e->i.poscam);
	e->i.raydir = tmp;
	vecnorm(&e->i.raydir);
}

void			get_value_apercu(t_stuff *e)
{
	reboot_list_loop(e, 3);
	if (e->i.objet == SPHERE)
		searchlist(e, e->i.each_obj, SPHERE);
	else if (e->i.objet == LIGHT)
		searchlist(e, e->i.each_obj, LIGHT);
	else if (e->i.objet == CYLINDRE)
		searchlist(e, e->i.each_obj, CYLINDRE);
	else if (e->i.objet == PLAN)
		searchlist(e, e->i.each_obj, PLAN);
	else if (e->i.objet == CONE)
		searchlist(e, e->i.each_obj, CONE);
	fill_value_apercu(e);
}

void			multi_thread2(t_stuff *e)
{
	t_stuff		*tab;
	pthread_t	thread[MTI];

	if (!(tab = (t_stuff *)malloc(MT * sizeof(t_stuff))))
		exit(-1);
	e->jmt = -1;
	reboot_list_loop(e, 3);
	while (++e->jmt < MTI)
	{
		tab[e->jmt] = *e;
		tab[e->jmt].start2 = e->jmt * e->i.mlx->img_y / MTI;
		tab[e->jmt].end2 = tab[e->jmt].start2 + e->i.mlx->img_y / MTI;
		dedouble_list(&(tab[e->jmt]));
		pthread_create(&thread[e->jmt], NULL, aff_apercu, &tab[e->jmt]);
	}
	e->jmt = -1;
	while (++e->jmt < MTI)
		pthread_join(thread[e->jmt], NULL);
	e->img.img_ptri = e->i.mlx->img;
	mlx_put_image_to_window(e->img.mlx_ptr, e->img.win_ptr, e->i.mlx->img, 0,
		WIN_Y - LENGTH);
	e->jmt = -1;
	while (++e->jmt < MTI)
		ntmleaks(&tab[e->jmt]);
	free(tab);
}

void			apercu_courant(t_stuff *e)
{
	if (e->i.first == 0)
	{
		e->i.img_x = WIN_X - WIDTH;
		e->i.img_y = WIN_Y - LENGTH;
		new_img(e);
	}
	else
	{
		reboot_list_interface(e, 1);
		searchlist_interface(e, 1);
	}
	get_value_apercu(e);
	multi_thread2(e);
}
