/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_end_aff_multiobj_cubesphere.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 16:54:48 by prossi            #+#    #+#             */
/*   Updated: 2018/04/17 13:59:45 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

char	*end_aff_multiobj_cubesphere_fih(t_stuff *e, char *tmp)
{
	if (e->i.mobj.first == 7)
	{
		tmp = ft_strcpy(tmp, "Refrac ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->i.mobj.refrac = ft_myatod(e->i.term.wbuf);
		if (e->i.mobj.refrac > 2)
			e->i.mobj.refrac = 2;
		else if (e->i.mobj.refrac < 1 && e->i.mobj.refrac > 0)
			e->i.mobj.refrac = 1;
		else if (e->i.mobj.refrac < 0)
			e->i.mobj.refrac = 0;
	}
	else if (e->i.mobj.first == 8)
	{
		tmp = ft_strcpy(tmp, "Conscol ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->i.mobj.conscol = ft_myatod(e->i.term.wbuf);
		if (e->i.mobj.conscol > 1)
			e->i.mobj.conscol = 1;
		if (e->i.mobj.conscol < 0)
			e->i.mobj.conscol = 0;
	}
	return (tmp);
}

char	*end_aff_multiobj_cubesphere_fh(t_stuff *e, char *tmp)
{
	if (e->i.mobj.first == 5)
	{
		tmp = ft_strcpy(tmp, "Couleur B ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->i.mobj.color.b = ft_atoi(e->i.term.wbuf);
		if (e->i.mobj.color.b > 255)
			e->i.mobj.color.b = 255;
		else if (e->i.mobj.color.b < 0)
			e->i.mobj.color.b = 0;
	}
	else if (e->i.mobj.first == 6)
	{
		tmp = ft_strcpy(tmp, "Rayon ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->i.mobj.ray = ft_myatod(e->i.term.wbuf);
		if (e->i.mobj.ray < 0)
			e->i.mobj.ray *= -1;
	}
	return (tmp);
}

char	*end_aff_multiobj_cubesphere_td(t_stuff *e, char *tmp)
{
	if (e->i.mobj.first == 3)
	{
		tmp = ft_strcpy(tmp, "Couleur R ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->i.mobj.color.r = ft_atoi(e->i.term.wbuf);
		if (e->i.mobj.color.r > 255)
			e->i.mobj.color.r = 255;
		else if (e->i.mobj.color.r < 0)
			e->i.mobj.color.r = 0;
	}
	else if (e->i.mobj.first == 4)
	{
		tmp = ft_strcpy(tmp, "Couleur G ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->i.mobj.color.g = ft_atoi(e->i.term.wbuf);
		if (e->i.mobj.color.g > 255)
			e->i.mobj.color.g = 255;
		else if (e->i.mobj.color.g < 0)
			e->i.mobj.color.g = 0;
	}
	return (tmp);
}

char	*end_aff_multiobj_cubesphere_sd(t_stuff *e, char *tmp)
{
	if (e->i.mobj.first == 0)
	{
		tmp = ft_strcpy(tmp, "Position en X ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->i.mobj.pos.x = ft_myatod(e->i.term.wbuf);
	}
	else if (e->i.mobj.first == 1)
	{
		tmp = ft_strcpy(tmp, "Position en Y ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->i.mobj.pos.y = ft_myatod(e->i.term.wbuf);
	}
	else if (e->i.mobj.first == 2)
	{
		tmp = ft_strcpy(tmp, "Position en Z ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->i.mobj.pos.z = ft_myatod(e->i.term.wbuf);
	}
	return (tmp);
}

void	end_aff_multiobj_cubesphere(t_stuff *e)
{
	char	*tmp;
	int		err;

	err = 0;
	if (!(tmp = ft_strnew(100)))
		err = 1;
	if (err == 0)
	{
		e->i.term.wbuf[e->i.term.index] = '\0';
		tmp = end_aff_multiobj_cubesphere_sd(e, tmp);
		tmp = end_aff_multiobj_cubesphere_td(e, tmp);
		tmp = end_aff_multiobj_cubesphere_fh(e, tmp);
		tmp = end_aff_multiobj_cubesphere_fih(e, tmp);
		tmp = end_aff_multiobj_cubesphere_sh(e, tmp);
		end_aff_multiobj_cubesphere_seh(e, tmp);
	}
	else
		ft_putstr("\nMalloc error in end_aff - terminal (interface)\n");
}
