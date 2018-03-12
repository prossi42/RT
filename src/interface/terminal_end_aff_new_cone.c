/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_end_aff_new_cone.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Awk-LM <Awk-LM@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 15:28:29 by Awk-LM            #+#    #+#             */
/*   Updated: 2018/02/16 13:23:06 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void 	end_aff_new_cone(t_stuff *e)
{
	char	*tmp;
	int		err;

	err = 0;
	if (!(tmp = ft_strnew(100)))
		err = 1;
	if (err == 0)
	{
		searchlist(e, e->d.nbmcone - 1, CONE);
		e->i.term.wbuf[e->i.term.index] = '\0';
		if (e->i.nobj.first == 0)
		{
			tmp = ft_strcpy(tmp, "Position en X ? : ");
			tmp = ft_strcat(tmp, e->i.term.wbuf);
			e->cone->pos.x = ft_myatod(e->i.term.wbuf);
		}
		else if (e->i.nobj.first == 1)
		{
			tmp = ft_strcpy(tmp, "Position en Y ? : ");
			tmp = ft_strcat(tmp, e->i.term.wbuf);
			e->cone->pos.y = ft_myatod(e->i.term.wbuf);
		}
		else if (e->i.nobj.first == 2)
		{
			tmp = ft_strcpy(tmp, "Position en Z ? : ");
			tmp = ft_strcat(tmp, e->i.term.wbuf);
			e->cone->pos.z = ft_myatod(e->i.term.wbuf);
		}
		else if (e->i.nobj.first == 3)
		{
			tmp = ft_strcpy(tmp, "Direction en X ? : ");
			tmp = ft_strcat(tmp, e->i.term.wbuf);
			e->cone->norm.x = ft_myatod(e->i.term.wbuf);
		}
		else if (e->i.nobj.first == 4)
		{
			tmp = ft_strcpy(tmp, "Direction en Y ? : ");
			tmp = ft_strcat(tmp, e->i.term.wbuf);
			e->cone->norm.y = ft_myatod(e->i.term.wbuf);
		}
		else if (e->i.nobj.first == 5)
		{
			tmp = ft_strcpy(tmp, "Direction en Z ? : ");
			tmp = ft_strcat(tmp, e->i.term.wbuf);
			e->cone->norm.z = ft_myatod(e->i.term.wbuf);
		}
		else if (e->i.nobj.first == 6)
		{
			tmp = ft_strcpy(tmp, "Couleur R ? : ");
			tmp = ft_strcat(tmp, e->i.term.wbuf);
			e->cone->color.r = ft_atoi(e->i.term.wbuf);
		}
		else if (e->i.nobj.first == 7)
		{
			tmp = ft_strcpy(tmp, "Couleur G ? : ");
			tmp = ft_strcat(tmp, e->i.term.wbuf);
			e->cone->color.g = ft_atoi(e->i.term.wbuf);
		}
		else if (e->i.nobj.first == 8)
		{
			tmp = ft_strcpy(tmp, "Couleur B ? : ");
			tmp = ft_strcat(tmp, e->i.term.wbuf);
			e->cone->color.b = ft_atoi(e->i.term.wbuf);
		}
		else if (e->i.nobj.first == 9)
		{
			tmp = ft_strcpy(tmp, "Angle ? : ");
			tmp = ft_strcat(tmp, e->i.term.wbuf);
			e->cone->angle = ft_myatod(e->i.term.wbuf);
		}
		e->i.term.tab[e->i.term.indextab] = ft_strcpy(e->i.term.tab[e->i.term.indextab], tmp);
		e->i.term.tabfill = 1;
		ft_strclr(e->i.term.wbuf);
		ft_strdel(&tmp);
		if (e->i.nobj.first == 9)
		{
			e->i.nobj.first = -1;
			multi_thread(e);
			multi_thread2(e);
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
