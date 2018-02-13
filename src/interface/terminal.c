/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 22:26:52 by prossi            #+#    #+#             */
/*   Updated: 2018/02/13 08:36:44 by Awk-LM           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	draw_terminal(t_stuff *e)
{
	int		x;
	int		y;

	y = -1;
	while (++y < e->i.img_y)
	{
		x = -1;
		while (++x < e->i.img_x)
		{
			pixel_put_to_img(&e->i.mlx, x, y, 0x000000);
		}
	}
	mlx_put_image_to_window(e->img.mlx_ptr, e->img.win_ptr, e->i.mlx->img, 0, (WIN_Y - LENGTH) * 3);
}

void	aff_angle(t_stuff *e)
{
	mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, (WIN_Y - LENGTH) * 3 + 3 * 40, 0xFFFFFF, "Valeur de l'angle en degre ? : ");
	mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, WIN_X - WIDTH - 200, (WIN_Y - LENGTH) * 3 + 3 * 40, 0xFFFFFF, e->i.term.wbuf);
}

void	aff_value(t_stuff *e)
{
	mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, (WIN_Y - LENGTH) * 3 + 3 * 40, 0xFFFFFF, "Valeur de la translation ? : ");
	mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, WIN_X - WIDTH - 200, (WIN_Y - LENGTH) * 3 + 3 * 40, 0xFFFFFF, e->i.term.wbuf);
}

void	aff_tab(t_stuff *e)
{
	if (e->i.term.tabfill == 1)
	{
		if (e->i.term.indextab >= 0)
			mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, (WIN_Y - LENGTH) * 3 + (0 * 40), 0xFFFFFF, e->i.term.tab[0]);
		if (e->i.term.indextab >= 1)
			mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, (WIN_Y - LENGTH) * 3 + (1 * 40), 0xFFFFFF, e->i.term.tab[1]);
		if (e->i.term.indextab > 2)
		{
			mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, (WIN_Y - LENGTH) * 3 + (2 * 40), 0xFFFFFF, e->i.term.tab[2]);
			free2d(e);
			e->i.term.indextab = 0;
			e->i.term.tabfill = 0;
			e->i.term.first = 0;
		}
	}
}

void	end_aff_matrice(t_stuff *e)
{
	char	*tmp;
	int		err;

	err = 0;
	if (!(tmp = ft_strnew(100)))
		err = 1;
	if (err == 0)
	{
		if (e->i.mat.act_angle == 1)
		{
			tmp = ft_strcpy(tmp, "Valeur de l'angle en degre ? : ");
			tmp = ft_strcat(tmp, e->i.term.wbuf);
			e->m.angle = ft_atoi(e->i.term.wbuf);
		}
		if (e->i.mat.act_value == 1)
		{
			tmp = ft_strcpy(tmp, "Valeur de la translation ? : ");
			tmp = ft_strcat(tmp, e->i.term.wbuf);
			e->m.value = ft_atoi(e->i.term.wbuf);
		}
		e->i.term.tab[e->i.term.indextab] = ft_strcpy(e->i.term.tab[e->i.term.indextab], tmp);
		e->i.term.tabfill = 1;
		ft_strdel(&e->i.term.wbuf);
		ft_strdel(&tmp);
	}
	else
		ft_putstr("\nMalloc error in end_aff - terminal (interface)\n");
}

void	end_aff_newobj(t_stuff *e)
{
	char	*tmp;
	int		err;

	err = 0;
	if (!(tmp = ft_strnew(100)))
		err = 1;
	if (err == 0)
	{
		if (e->i.nobj.first == 0)
		{
			tmp = ft_strcpy(tmp, "Position en X ? : ");
			tmp = ft_strcat(tmp, e->i.term.wbuf);
			e->sph->pos.x = ft_myatod(e->i.term.wbuf);
		}
		else if (e->i.nobj.first == 1)
		{
			tmp = ft_strcpy(tmp, "Position en Y ? : ");
			tmp = ft_strcat(tmp, e->i.term.wbuf);
			e->sph->pos.y = ft_myatod(e->i.term.wbuf);
		}
		else if (e->i.nobj.first == 2)
		{
			tmp = ft_strcpy(tmp, "Position en Z ? : ");
			tmp = ft_strcat(tmp, e->i.term.wbuf);
			e->sph->pos.z = ft_myatod(e->i.term.wbuf);
		}
		// else if (e->i.nobj.first == 3)
		// {
		// 	tmp = ft_strcpy(tmp, "Vecteur Dir. en X ? : ");
		// 	tmp = ft_strcat(tmp, e->i.term.wbuf);
		// 	e->sph->pos.z = ft_myatod(e->i.term.wbuf);
		// }
		// else if (e->i.nobj.first == 4)
		// {
		// 	tmp = ft_strcpy(tmp, "Vecteur Dir. en Y ? : ");
		// 	tmp = ft_strcat(tmp, e->i.term.wbuf);
		// 	e->sph->pos.z = ft_myatod(e->i.term.wbuf);
		// }
		// else if (e->i.nobj.first == 5)
		// {
		// 	tmp = ft_strcpy(tmp, "Vecteur Dir. en Z ? : ");
		// 	tmp = ft_strcat(tmp, e->i.term.wbuf);
		// 	e->sph->pos.z = ft_myatod(e->i.term.wbuf);
		// }
		else if (e->i.nobj.first == 6)
		{
			tmp = ft_strcpy(tmp, "Couleur R ? : ");
			tmp = ft_strcat(tmp, e->i.term.wbuf);
			e->sph->color.r = ft_myatod(e->i.term.wbuf);
		}
		else if (e->i.nobj.first == 7)
		{
			tmp = ft_strcpy(tmp, "Couleur G ? : ");
			tmp = ft_strcat(tmp, e->i.term.wbuf);
			e->sph->color.g = ft_myatod(e->i.term.wbuf);
		}
		else if (e->i.nobj.first == 8)
		{
			tmp = ft_strcpy(tmp, "Couleur B ? : ");
			tmp = ft_strcat(tmp, e->i.term.wbuf);
			e->sph->color.b = ft_myatod(e->i.term.wbuf);
		}
		else if (e->i.nobj.first == 9)
		{
			tmp = ft_strcpy(tmp, "Rayon ? : ");
			tmp = ft_strcat(tmp, e->i.term.wbuf);
			e->sph->color.b = ft_myatod(e->i.term.wbuf);
		}
		e->i.term.tab[e->i.trm.indextab] = ft_strcpy(e->i.term.tab[e->i.term.indextab], tmp);
		e->i.term.tabfill = 1;
		ft_strdel(&e->i.term.wbuf);
		ft_strdel(&tmp);
	}
	else
		ft_putstr("\nMalloc error in end_aff - terminal (interface)\n");
}

void	aff_new_obj(t_stuff *e)
{
	if (e->i.nobj.first == 0)
	{
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, (WIN_Y - LENGTH) * 3 + 3 * 40, 0xFFFFFF, "Position en X ? : ");
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, WIN_X - WIDTH - 200, (WIN_Y - LENGTH) * 3 + 3 * 40, 0xFFFFFF, e->i.term.wbuf);
	}
	else if (e->i.nobj.first == 1)
	{
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, (WIN_Y - LENGTH) * 3 + 3 * 40, 0xFFFFFF, "Position en Y ? : ");
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, WIN_X - WIDTH - 200, (WIN_Y - LENGTH) * 3 + 3 * 40, 0xFFFFFF, e->i.term.wbuf);
	}
	else if (e->i.nobj.first == 2)
	{
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, (WIN_Y - LENGTH) * 3 + 3 * 40, 0xFFFFFF, "Position en Z ? : ");
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, WIN_X - WIDTH - 200, (WIN_Y - LENGTH) * 3 + 3 * 40, 0xFFFFFF, e->i.term.wbuf);
	}
	else if (e->i.nobj.first == 3 && e->i.objet != SPHERE && e->i.objet != LIGHT && e->i.objet -1)
	{
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, (WIN_Y - LENGTH) * 3 + 3 * 40, 0xFFFFFF, "Vecteur Dir. en X ? : ");
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, WIN_X - WIDTH - 200, (WIN_Y - LENGTH) * 3 + 3 * 40, 0xFFFFFF, e->i.term.wbuf);
	}
	else if (e->i.nobj.first == 4 && e->i.objet != SPHERE && e->i.objet != LIGHT && e->i.objet -1)
	{
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, (WIN_Y - LENGTH) * 3 + 3 * 40, 0xFFFFFF, "Vecteur Dir. en Y ? : ");
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, WIN_X - WIDTH - 200, (WIN_Y - LENGTH) * 3 + 3 * 40, 0xFFFFFF, e->i.term.wbuf);
	}
	else if (e->i.nobj.first == 5 && e->i.objet != SPHERE && e->i.objet != LIGHT && e->i.objet -1)
	{
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, (WIN_Y - LENGTH) * 3 + 3 * 40, 0xFFFFFF, "Vecteur Dir. en Z ? : ");
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, WIN_X - WIDTH - 200, (WIN_Y - LENGTH) * 3 + 3 * 40, 0xFFFFFF, e->i.term.wbuf);
	}
	else if (e->i.nobj.first == 6 && e->i.objet != -1)
	{
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, (WIN_Y - LENGTH) * 3 + 3 * 40, 0xFFFFFF, "Couleur R ? : ");
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, WIN_X - WIDTH - 200, (WIN_Y - LENGTH) * 3 + 3 * 40, 0xFFFFFF, e->i.term.wbuf);
	}
	else if (e->i.nobj.first == 7 && e->i.objet != -1)
	{
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, (WIN_Y - LENGTH) * 3 + 3 * 40, 0xFFFFFF, "Couleur G ? : ");
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, WIN_X - WIDTH - 200, (WIN_Y - LENGTH) * 3 + 3 * 40, 0xFFFFFF, e->i.term.wbuf);
	}
	else if (e->i.nobj.first == 8 && e->i.objet != -1)
	{
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, (WIN_Y - LENGTH) * 3 + 3 * 40, 0xFFFFFF, "Couleur B ? : ");
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, WIN_X - WIDTH - 200, (WIN_Y - LENGTH) * 3 + 3 * 40, 0xFFFFFF, e->i.term.wbuf);
	}
	else if (e->i.nobj.first == 9 && (e->i.objet == SPHERE || e->i.objet == CYLINDRE || e->i.objet == LIGHT))
	{
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, (WIN_Y - LENGTH) * 3 + 3 * 40, 0xFFFFFF, "Rayon ? : ");
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, WIN_X - WIDTH - 200, (WIN_Y - LENGTH) * 3 + 3 * 40, 0xFFFFFF, e->i.term.wbuf);
	}
	else if (e->i.nobj.first == 9 && e->i.objet == CONE)
	{
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, 15, (WIN_Y - LENGTH) * 3 + 3 * 40, 0xFFFFFF, "Angle ? : ");
		mlx_string_put(e->img.mlx_ptr, e->img.win_ptr, WIN_X - WIDTH - 200, (WIN_Y - LENGTH) * 3 + 3 * 40, 0xFFFFFF, e->i.term.wbuf);
	}
}

void	terminal(t_stuff *e)
{
	if (e->i.first == 0)
	{
		e->i.img_x = WIN_X - WIDTH;
		e->i.img_y = WIN_Y - ((WIN_Y - LENGTH) * 3);
		new_img(e);
		init_struct(e, 2);
		draw_terminal(e);
	}
	else
	{
		reboot_list_interface(e, 1);
		searchlist_interface(e, 3);
		draw_terminal(e);
		if (e->i.mat.act_angle == 1 && e->i.term.wbuf[e->i.term.index] != '\n')
			aff_angle(e);
		if (e->i.mat.act_value == 1 && e->i.term.wbuf[e->i.term.index] != '\n')
			aff_value(e);
		if (e->i.nobj.first != -1 && e->i.term.wbuf[e->i.term.index] != '\n')
			aff_new_obj(e);
		if (e->i.term.wbuf[e->i.term.index] == '\n')
		{
			if (e->i.mat.act_angle != 0 || e->i.mat.act_value != 0)
			{
				end_aff_matrice(e);
				e->i.mat.act_angle = 0;
				e->i.mat.act_value = 0;
			}
			else if (e->i.nobj.first != -1)
			{
				end_aff_newobj(e);
				if ((e->i.nobj.first >= 0 && e->i.nobj.first < 2) || (e->i.nobj.first >= 6 && e->i.nobj.first < 8))
					e->i.nobj.first++;
				else if (e->i.nobj.first == 2)
					e->i.nobj.first += 4;
				terminal(e);  // A verifier et continuer

			}
			e->i.term.index = 0;
			e->i.term.indextab++;
		}
		aff_tab(e);
	}
}
