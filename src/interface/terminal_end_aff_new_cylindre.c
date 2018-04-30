/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_end_aff_new_cylindre.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 14:42:30 by prossi            #+#    #+#             */
/*   Updated: 2018/04/17 13:40:14 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

char	*end_aff_new_cylindre_fih(t_stuff *e, char *tmp)
{
	if (e->i.nobj.first == 9)
	{
		tmp = ft_strcpy(tmp, "Rayon ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->cyl->ray = ft_myatod(e->i.term.wbuf);
		if (e->cyl->ray < 0)
			e->cyl->ray *= -1;
	}
	else if (e->i.nobj.first == 10)
	{
		tmp = ft_strcpy(tmp, "Refrac ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->cyl->refrac = ft_myatod(e->i.term.wbuf);
		if (e->cyl->refrac > 2)
			e->cyl->refrac = 2;
		else if (e->cyl->refrac < 1 && e->cyl->refrac > 0)
			e->cyl->refrac = 1;
		else if (e->cyl->refrac < 0)
			e->cyl->refrac = 0;
	}
	return (tmp);
}

char	*end_aff_new_cylindre_fh(t_stuff *e, char *tmp)
{
	if (e->i.nobj.first == 7)
	{
		tmp = ft_strcpy(tmp, "Couleur G ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->cyl->color.g = ft_atoi(e->i.term.wbuf);
		if (e->cyl->color.g > 255)
			e->cyl->color.g = 255;
		else if (e->cyl->color.g < 0)
			e->cyl->color.g = 0;
	}
	else if (e->i.nobj.first == 8)
	{
		tmp = ft_strcpy(tmp, "Couleur B ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->cyl->color.b = ft_atoi(e->i.term.wbuf);
		if (e->cyl->color.b > 255)
			e->cyl->color.b = 255;
		else if (e->cyl->color.b < 0)
			e->cyl->color.b = 0;
	}
	return (tmp);
}

char	*end_aff_new_cylindre_td(t_stuff *e, char *tmp)
{
	if (e->i.nobj.first == 4)
	{
		tmp = ft_strcpy(tmp, "Direction en Y ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->cyl->norm.y = ft_myatod(e->i.term.wbuf);
	}
	else if (e->i.nobj.first == 5)
	{
		tmp = ft_strcpy(tmp, "Direction en Z ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->cyl->norm.z = ft_myatod(e->i.term.wbuf);
		vecnorm(&e->cyl->norm);
	}
	else if (e->i.nobj.first == 6)
	{
		tmp = ft_strcpy(tmp, "Couleur R ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->cyl->color.r = ft_atoi(e->i.term.wbuf);
		if (e->cyl->color.r > 255)
			e->cyl->color.r = 255;
		else if (e->cyl->color.r < 0)
			e->cyl->color.r = 0;
	}
	return (tmp);
}

char	*end_aff_new_cylindre_sd(t_stuff *e, char *tmp)
{
	if (e->i.nobj.first == 0)
	{
		tmp = ft_strcpy(tmp, "Position en X ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->cyl->pos.x = ft_myatod(e->i.term.wbuf);
	}
	else if (e->i.nobj.first == 1)
	{
		tmp = ft_strcpy(tmp, "Position en Y ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->cyl->pos.y = ft_myatod(e->i.term.wbuf);
	}
	else if (e->i.nobj.first == 2)
	{
		tmp = ft_strcpy(tmp, "Position en Z ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->cyl->pos.z = ft_myatod(e->i.term.wbuf);
	}
	else if (e->i.nobj.first == 3)
	{
		tmp = ft_strcpy(tmp, "Direction en X ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->cyl->norm.x = ft_myatod(e->i.term.wbuf);
	}
	return (tmp);
}

void	end_aff_new_cylindre(t_stuff *e)
{
	char	*tmp;
	int		err;

	err = 0;
	if (!(tmp = ft_strnew(100)))
		err = 1;
	if (err == 0)
	{
		searchlist(e, e->d.nbmcyl - 1, CYLINDRE);
		e->i.term.wbuf[e->i.term.index] = '\0';
		tmp = end_aff_new_cylindre_sd(e, tmp);
		tmp = end_aff_new_cylindre_td(e, tmp);
		tmp = end_aff_new_cylindre_fh(e, tmp);
		tmp = end_aff_new_cylindre_fih(e, tmp);
		tmp = end_aff_new_cylindre_sh(e, tmp);
		end_aff_new_cylindre_seh(e, tmp);
	}
	else
		ft_putstr("\nMalloc error in end_aff - terminal (interface)\n");
}
