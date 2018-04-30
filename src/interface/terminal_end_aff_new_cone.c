/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_end_aff_new_cone.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 15:28:29 by prossi            #+#    #+#             */
/*   Updated: 2018/04/17 13:46:51 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

char	*end_aff_new_cone_fih(t_stuff *e, char *tmp)
{
	if (e->i.nobj.first == 9)
	{
		tmp = ft_strcpy(tmp, "Angle ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->cone->angle = ft_myatod(e->i.term.wbuf);
		if (e->cone->angle < 0)
			e->cone->angle *= -1;
	}
	else if (e->i.nobj.first == 10)
	{
		tmp = ft_strcpy(tmp, "Refrac ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->cone->refrac = ft_myatod(e->i.term.wbuf);
		if (e->cone->refrac > 2)
			e->cone->refrac = 2;
		else if (e->cone->refrac < 1 && e->cone->refrac > 0)
			e->cone->refrac = 1;
		else if (e->cone->refrac < 0)
			e->cone->refrac = 0;
	}
	return (tmp);
}

char	*end_aff_new_cone_fh(t_stuff *e, char *tmp)
{
	if (e->i.nobj.first == 7)
	{
		tmp = ft_strcpy(tmp, "Couleur G ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->cone->color.g = ft_atoi(e->i.term.wbuf);
		if (e->cone->color.g > 255)
			e->cone->color.g = 255;
		else if (e->cone->color.g < 0)
			e->cone->color.g = 0;
	}
	else if (e->i.nobj.first == 8)
	{
		tmp = ft_strcpy(tmp, "Couleur B ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->cone->color.b = ft_atoi(e->i.term.wbuf);
		if (e->cone->color.b > 255)
			e->cone->color.b = 255;
		else if (e->cone->color.b < 0)
			e->cone->color.b = 0;
	}
	return (tmp);
}

char	*end_aff_new_cone_td(t_stuff *e, char *tmp)
{
	if (e->i.nobj.first == 4)
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
		vecnorm(&e->cone->norm);
	}
	else if (e->i.nobj.first == 6)
	{
		tmp = ft_strcpy(tmp, "Couleur R ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->cone->color.r = ft_atoi(e->i.term.wbuf);
		if (e->cone->color.r > 255)
			e->cone->color.r = 255;
		else if (e->cone->color.r < 0)
			e->cone->color.r = 0;
	}
	return (tmp);
}

char	*end_aff_new_cone_sd(t_stuff *e, char *tmp)
{
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
	return (tmp);
}

void	end_aff_new_cone(t_stuff *e)
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
		tmp = end_aff_new_cone_sd(e, tmp);
		tmp = end_aff_new_cone_td(e, tmp);
		tmp = end_aff_new_cone_fh(e, tmp);
		tmp = end_aff_new_cone_fih(e, tmp);
		tmp = end_aff_new_cone_sh(e, tmp);
		end_aff_new_cone_seh(e, tmp);
	}
	else
		ft_putstr("\nMalloc error in end_aff - terminal (interface)\n");
}
