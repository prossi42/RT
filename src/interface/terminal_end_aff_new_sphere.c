/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_end_aff_new_sphere.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 13:52:43 by prossi            #+#    #+#             */
/*   Updated: 2018/04/17 13:13:27 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

char	*end_aff_new_sphere_fih(t_stuff *e, char *tmp)
{
	if (e->i.nobj.first == 7)
	{
		tmp = ft_strcpy(tmp, "Refrac ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->sph->refrac = ft_myatod(e->i.term.wbuf);
		if (e->sph->refrac > 2)
			e->sph->refrac = 2;
		else if (e->sph->refrac < 1 && e->sph->refrac > 0)
			e->sph->refrac = 1;
		else if (e->sph->refrac < 0)
			e->sph->refrac = 0;
	}
	else if (e->i.nobj.first == 8)
	{
		tmp = ft_strcpy(tmp, "Conscol ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->sph->conscol = ft_myatod(e->i.term.wbuf);
		if (e->sph->conscol > 1)
			e->sph->conscol = 1;
		if (e->sph->conscol < 0)
			e->sph->conscol = 0;
	}
	return (tmp);
}

char	*end_aff_new_sphere_fh(t_stuff *e, char *tmp)
{
	if (e->i.nobj.first == 5)
	{
		tmp = ft_strcpy(tmp, "Couleur B ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->sph->color.b = ft_atoi(e->i.term.wbuf);
		if (e->sph->color.b > 255)
			e->sph->color.b = 255;
		else if (e->sph->color.b < 0)
			e->sph->color.b = 0;
	}
	else if (e->i.nobj.first == 6)
	{
		tmp = ft_strcpy(tmp, "Rayon ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->sph->ray = ft_myatod(e->i.term.wbuf);
		if (e->sph->ray < 0)
			e->sph->ray *= -1;
	}
	return (tmp);
}

char	*end_aff_new_sphere_td(t_stuff *e, char *tmp)
{
	if (e->i.nobj.first == 3)
	{
		tmp = ft_strcpy(tmp, "Couleur R ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->sph->color.r = ft_atoi(e->i.term.wbuf);
		if (e->sph->color.r > 255)
			e->sph->color.r = 255;
		else if (e->sph->color.r < 0)
			e->sph->color.r = 0;
	}
	else if (e->i.nobj.first == 4)
	{
		tmp = ft_strcpy(tmp, "Couleur G ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->sph->color.g = ft_atoi(e->i.term.wbuf);
		if (e->sph->color.g > 255)
			e->sph->color.g = 255;
		else if (e->sph->color.g < 0)
			e->sph->color.g = 0;
	}
	return (tmp);
}

char	*end_aff_new_sphere_sd(t_stuff *e, char *tmp)
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
	return (tmp);
}

void	end_aff_new_sphere(t_stuff *e)
{
	char	*tmp;
	int		err;

	err = 0;
	if (!(tmp = ft_strnew(100)))
		err = 1;
	if (err == 0)
	{
		searchlist(e, e->d.nbmsph - 1, SPHERE);
		e->i.term.wbuf[e->i.term.index] = '\0';
		tmp = end_aff_new_sphere_sd(e, tmp);
		tmp = end_aff_new_sphere_td(e, tmp);
		tmp = end_aff_new_sphere_fh(e, tmp);
		tmp = end_aff_new_sphere_fih(e, tmp);
		tmp = end_aff_new_sphere_sh(e, tmp);
		end_aff_new_sphere_seh(e, tmp);
	}
	else
		ft_putstr("\nMalloc error in end_aff - terminal (interface)\n");
}
