/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshots.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 13:52:21 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 10:52:39 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	screenshots_img(t_stuff *e)
{
	int		pos;

	if (!(e->i.scr.fd = open(e->i.scr.path, O_WRONLY | O_CREAT, 00755)))
		return ;
	ft_putstr_fd("P6 ", e->i.scr.fd);
	ft_putnbr_fd(1280, e->i.scr.fd);
	ft_putstr_fd(" ", e->i.scr.fd);
	ft_putnbr_fd(720, e->i.scr.fd);
	ft_putstr_fd(" 255\n", e->i.scr.fd);
	e->i.scr.height = -1;
	while (++e->i.scr.height < 720)
	{
		e->i.scr.width = -1;
		while (++e->i.scr.width < 1280)
		{
			pos = (e->i.scr.width * e->img.bits_per_pixel / 8 + e->i.scr.height\
				* e->img.size_line);
			write(e->i.scr.fd, &e->img.data[pos + 2], 1);
			write(e->i.scr.fd, &e->img.data[pos + 1], 1);
			write(e->i.scr.fd, &e->img.data[pos], 1);
		}
	}
	close(e->i.scr.fd);
}

int		screenshots_sd(t_stuff *e)
{
	char	*current_dir;

	current_dir = NULL;
	current_dir = getcwd(current_dir, 0);
	if (!(e->i.scr.path = ft_strnew(ft_strlen(current_dir) + 14)))
		return (-1);
	e->i.scr.path = ft_strcat(e->i.scr.path, current_dir);
	ft_strdel(&current_dir);
	e->i.scr.path = ft_strcat(e->i.scr.path, "/screenshots/");
	if (stat(e->i.scr.path, &e->i.scr.st) != 0)
	{
		if (mkdir(e->i.scr.path, 0755) == -1)
			return (-1);
	}
	e->i.scr.act_scr = 1;
	terminal(e);
	return (0);
}

int		screenshots(t_stuff *e)
{
	if (e->i.scr.act_scr == 0)
	{
		if (screenshots_sd(e) == -1)
			return (-1);
	}
	else
	{
		screenshots_img(e);
		e->i.scr.act_scr = 0;
		ft_strdel(&e->i.scr.path);
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, (WIN_Y - LENGTH) * \
		3 + 3 * 40, 0xFFFFFF, "Screenshot created");
	}
	return (0);
}
