/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_scene_load_save.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:43:48 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 17:11:57 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	draw_save_scene_load_save(t_stuff *e)
{
	int		x;
	int		y;

	y = -1;
	while (++y < e->i.mlx->img_y)
	{
		x = -1;
		while (++x < e->i.mlx->img_x)
			pixel_put_to_img(&e->i.mlx, x, y, e->i.color.saves.col1);
	}
}

int		save_scene_open_load_save(t_stuff *e)
{
	e->i.load.nb_dir = 0;
	if (!(e->i.load.tab = (char **)malloc(sizeof(char *) * 15)))
		return (-1);
	if (!(e->i.load.dir_stream = opendir(e->i.save.save_dir)))
	{
		free(e->i.load.tab);
		return (-1);
	}
	while ((e->i.load.dir_list = readdir(e->i.load.dir_stream)) != NULL)
	{
		if (e->i.load.nb_dir >= 2)
		{
			if (!(e->i.load.tab[e->i.load.nb_dir - 2] = \
				ft_strdup(e->i.load.dir_list->d_name)))
				return (-1);
		}
		if (++e->i.load.nb_dir == 17)
			break ;
	}
	e->i.load.tab[e->i.load.nb_dir - 2] = NULL;
	if (closedir(e->i.load.dir_stream) == -1)
		return (-1);
	e->i.load.nb_dir -= 2;
	e->i.load.first = 1;
	return (0);
}

int		save_scene_load_save_select_dir(t_stuff *e)
{
	char	*tmp;

	if (!(tmp = ft_strnew(100)))
	{
		e->i.load.index = 0;
		return (-1);
	}
	tmp = ft_strcpy(tmp, e->i.save.save_dir);
	tmp = ft_strcat(tmp, e->i.load.tab[e->i.load.index + \
		(e->i.load.index_load * 5)]);
	tmp = ft_strcat(tmp, "/");
	ft_strdel(&e->i.save.save_dir);
	if (!(e->i.save.save_dir = ft_strdup(tmp)))
	{
		e->i.load.index = 0;
		ft_strdel(&tmp);
		return (-1);
	}
	e->i.load.index = 0;
	ft_strdel(&tmp);
	if (e->i.save.act_save != 0)
		e->i.save.act_save = 6;
	return (0);
}

void	free_tab(t_stuff *e)
{
	int		y;

	y = -1;
	while (e->i.load.tab[++y])
	{
		ft_strdel(&e->i.load.tab[y]);
	}
	ft_strdel(&e->i.load.tab[y]);
	free(e->i.load.tab);
}

void	save_scene_load_save(t_stuff *e)
{
	if (e->i.first == 0)
	{
		e->i.img_x = (WIN_X - WIDTH) / 2;
		e->i.img_y = WIN_Y - LENGTH;
		new_img(e);
		init_struct(e, 6);
	}
	else
	{
		reboot_list_interface(e, 1);
		searchlist_interface(e, 6);
		if (e->i.save.act_save == 3)
			e->i.save.act_save = 4;
		draw_save_scene_load_save(e);
		save_scene_load_save_elh(e);
		save_scene_load_save_twh(e);
		save_scene_load_save_thh(e);
		save_scene_load_save_draw_ellipse_background(e);
		save_scene_load_save_draw_title_background(e);
		mlx_put_image_to_window(e->img.mlx_ptr, e->img.win_ptr, e->i.mlx->img,\
			(WIN_X - WIDTH) + ((WIN_X - WIDTH) / 2), 0);
		save_scene_load_save_fhh(e);
		shortcuts(e);
	}
}
