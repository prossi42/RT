/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <jgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 22:17:03 by jgaillar          #+#    #+#             */
/*   Updated: 2018/04/23 13:12:19 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		ft_affich(t_stuff *e, int option)
{
	(void)e;
	if (option == 0)
	{
		ft_putstr("usage : ./rt scene/camera scene/objets\n");
		ft_putstr("---> run ./rt scene/exemple_camera scene/exemple_objets");
		ft_putstr("  to know how to set values\n");
	}
	if (option == 1)
		ft_putstr("\nError in Open or Read functions (scene/Camera)\n\n");
	if (option == 2)
		ft_putstr("\nError in Parsing function (scene/camera)\n\n");
	if (option == 3)
		ft_putstr("\nError in Open or Read functions (scene/objets)\n\n");
	if (option == 4)
		ft_putstr("\nError in Parsing function (scene/objets)");
	ft_exit(option, e);
}

int			ft_open(t_stuff *e, char *argv)
{
	int size;

	if ((e->b.fd = open(argv, O_RDONLY)) < 0)
		return (-1);
	size = read(e->b.fd, e->b.buf, BUFF_SIZE);
	e->b.buf[size] = '\0';
	close(e->b.fd);
	return (0);
}

int			main_sd(t_stuff *e, char **argv)
{
	if (ft_open(e, argv[2]) == -1)
		ft_affich(e, 3);
	ft_init_struct(e, 1);
	if (ft_parsing_sd(e) == -1)
		ft_affich(e, 4);
	ft_init_struct(e, 2);
	return (0);
}

int			release(int keycode, t_stuff *e)
{
	if (keycode == 76)
	{
		multi_thread(e);
		apercu_courant(e);
	}
	return (0);
}

int			main(int ac, char **av)
{
	t_stuff *e;

	if (!(e = (t_stuff *)malloc(sizeof(t_stuff))))
		exit(0);
	if (ac != 3 || !av[1] || !av[2])
		ft_affich(e, 0);
	if (ft_open(e, av[1]) == -1)
		ft_affich(e, 1);
	ft_init_struct(e, 0);
	if (ft_parsing(e) == -1)
		ft_affich(e, 2);
	main_sd(e, av);
	e->img.mlx_ptr = mlx_init();
	e->img.win_ptr = mlx_new_window(e->img.mlx_ptr, WIN_X, WIN_Y,\
			"RT si t'es pas triste parce que etre triste c'est triste");
	parse_skybox(e);
	create_image(e);
	multi_thread(e);
	mlx_hook(e->img.win_ptr, 2, (1L << 0), hooks, e);
	mlx_hook(e->img.win_ptr, 17, (1L << 17), (int(*)())cleanexit, e);
	mlx_hook(e->img.win_ptr, 3, (1L << 1), release, e);
	mlx_hook(e->img.win_ptr, 4, (1L << 2), mouse_hook, e);
	mlx_hook(e->img.win_ptr, 6, (1L << 6), mouse_move, e);
	mlx_loop(e->img.mlx_ptr);
	return (0);
}
