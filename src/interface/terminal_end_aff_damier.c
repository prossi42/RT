/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_end_aff_damier.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 15:22:17 by prossi            #+#    #+#             */
/*   Updated: 2018/04/16 16:03:39 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	end_aff_damier_fh(t_stuff *e)
{
	if (e->i.damier < 5)
	{
		e->i.damier++;
		terminal(e);
	}
	else if (e->i.damier == 5)
	{
		e->i.damier = -1;
		multi_thread(e);
	}
}

char	*end_aff_damier_td(t_stuff *e, char *tmp, int color)
{
	if (e->i.damier == 4)
	{
		tmp = ft_strcpy(tmp, "Seconde couleur G ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->i.col_dam2.g = color;
	}
	else if (e->i.damier == 5)
	{
		tmp = ft_strcpy(tmp, "Seconde couleur B ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->i.col_dam2.b = color;
	}
	return (tmp);
}

char	*end_aff_damier_sd(t_stuff *e, char *tmp, int color)
{
	if (e->i.damier == 0)
	{
		tmp = ft_strcpy(tmp, "Premiere couleur R ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->i.col_dam1.r = color;
	}
	else if (e->i.damier == 1)
	{
		tmp = ft_strcpy(tmp, "Premiere couleur G ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->i.col_dam1.g = color;
	}
	else if (e->i.damier == 2)
	{
		tmp = ft_strcpy(tmp, "Premiere couleur B ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->i.col_dam1.b = color;
	}
	else if (e->i.damier == 3)
	{
		tmp = ft_strcpy(tmp, "Seconde couleur R ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->i.col_dam2.r = color;
	}
	return (tmp);
}

void	end_aff_damier(t_stuff *e)
{
	char	*tmp;
	int		err;
	int		color;

	err = 0;
	if (!(tmp = ft_strnew(100)))
		err = 1;
	if (err == 0)
	{
		color = ft_atoi(e->i.term.wbuf);
		if (color > 255)
			color = 255;
		if (color < 0)
			color = 0;
		tmp = end_aff_damier_sd(e, tmp, color);
		tmp = end_aff_damier_td(e, tmp, color);
		e->i.term.tab[e->i.term.indextab] = \
		ft_strcpy(e->i.term.tab[e->i.term.indextab], tmp);
		e->i.term.tabfill = 1;
		ft_strclr(e->i.term.wbuf);
		ft_strdel(&tmp);
		end_aff_damier_fh(e);
	}
	else
		ft_putendl("\nMalloc error in end_aff_damier (terminal - interface)");
}
