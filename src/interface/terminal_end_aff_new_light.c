/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_end_aff_new_light.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 13:54:07 by prossi            #+#    #+#             */
/*   Updated: 2018/02/16 15:39:50 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	end_aff_new_light(t_stuff *e)
{
	char	*tmp;
	int		err;

	err = 0;
	if (!(tmp = ft_strnew(100)))
		err = 1;
	if (err == 0)
	{
		searchlist(e, e->d.nbmlight - 1, LIGHT);
		e->i.term.wbuf[e->i.term.index] = '\0';
		if (e->i.nobj.first == 0)
		{
			tmp = ft_strcpy(tmp, "Position en X ? : ");
			tmp = ft_strcat(tmp, e->i.term.wbuf);
			e->light->pos.x = ft_myatod(e->i.term.wbuf);
		}
		else if (e->i.nobj.first == 1)
		{
			tmp = ft_strcpy(tmp, "Position en Y ? : ");
			tmp = ft_strcat(tmp, e->i.term.wbuf);
			e->light->pos.y = ft_myatod(e->i.term.wbuf);
		}
		else if (e->i.nobj.first == 2)
		{
			tmp = ft_strcpy(tmp, "Position en Z ? : ");
			tmp = ft_strcat(tmp, e->i.term.wbuf);
			e->light->pos.z = ft_myatod(e->i.term.wbuf);
		}
		else if (e->i.nobj.first == 3)
		{
			tmp = ft_strcpy(tmp, "Couleur R ? : ");
			tmp = ft_strcat(tmp, e->i.term.wbuf);
			e->light->color.r = ft_atoi(e->i.term.wbuf);
		}
		else if (e->i.nobj.first == 4)
		{
			tmp = ft_strcpy(tmp, "Couleur G ? : ");
			tmp = ft_strcat(tmp, e->i.term.wbuf);
			e->light->color.g = ft_atoi(e->i.term.wbuf);
		}
		else if (e->i.nobj.first == 5)
		{
			tmp = ft_strcpy(tmp, "Couleur B ? : ");
			tmp = ft_strcat(tmp, e->i.term.wbuf);
			e->light->color.b = ft_atoi(e->i.term.wbuf);
		}
		else if (e->i.nobj.first == 6)
		{
			tmp = ft_strcpy(tmp, "Rayon ? : ");
			tmp = ft_strcat(tmp, e->i.term.wbuf);
			e->light->ray = ft_myatod(e->i.term.wbuf);
		}
		else if (e->i.nobj.first == 7)
		{
			tmp = ft_strcpy(tmp, "Coeff. Amb. ? : ");
			tmp = ft_strcat(tmp, e->i.term.wbuf);
			e->light->amb = ft_myatod(e->i.term.wbuf);
		}
		else if (e->i.nobj.first == 8)
		{
			tmp = ft_strcpy(tmp, "Coeff. Diff. ? : ");
			tmp = ft_strcat(tmp, e->i.term.wbuf);
			e->light->diff = ft_myatod(e->i.term.wbuf);
		}
		e->i.term.tab[e->i.term.indextab] = ft_strcpy(e->i.term.tab[e->i.term.indextab], tmp);
		e->i.term.tabfill = 1;
		ft_strclr(e->i.term.wbuf);
		ft_strdel(&tmp);
		if (e->i.nobj.first == 8)
		{
			e->i.nobj.first = -1;
			aff(e);
		}
		else
		{
			e->i.nobj.first++;
			terminal(e);
		}
	}
	else
		ft_putstr("\nMalloc error in end_aff - terminal (interface)\n");
}
