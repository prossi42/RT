/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_end_aff_new_light.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 13:54:07 by prossi            #+#    #+#             */
/*   Updated: 2018/04/17 13:33:01 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

char	*end_aff_new_light_fih(t_stuff *e, char *tmp)
{
	if (e->i.nobj.first == 7)
	{
		tmp = ft_strcpy(tmp, "Coeff. Amb. ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->light->amb = ft_myatod(e->i.term.wbuf);
		if (e->light->amb < 0)
			e->light->amb *= -1;
		if (e->light->amb > 1)
			e->light->amb = 1;
	}
	else if (e->i.nobj.first == 8)
	{
		tmp = ft_strcpy(tmp, "Coeff. Diff. ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->light->diff = ft_myatod(e->i.term.wbuf);
		if (e->light->diff < 0)
			e->light->diff *= -1;
		if (e->light->diff > 1)
			e->light->diff = 1;
	}
	return (tmp);
}

char	*end_aff_new_light_fh(t_stuff *e, char *tmp)
{
	if (e->i.nobj.first == 5)
	{
		tmp = ft_strcpy(tmp, "Couleur B ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->light->color.b = ft_atoi(e->i.term.wbuf);
		if (e->light->color.b > 255)
			e->light->color.b = 255;
		else if (e->light->color.b < 0)
			e->light->color.b = 0;
	}
	else if (e->i.nobj.first == 6)
	{
		tmp = ft_strcpy(tmp, "Rayon ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->light->ray = ft_myatod(e->i.term.wbuf);
		if (e->light->ray < 0)
			e->light->ray *= -1;
	}
	return (tmp);
}

char	*end_aff_new_light_td(t_stuff *e, char *tmp)
{
	if (e->i.nobj.first == 3)
	{
		tmp = ft_strcpy(tmp, "Couleur R ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->light->color.r = ft_atoi(e->i.term.wbuf);
		if (e->light->color.r > 255)
			e->light->color.r = 255;
		else if (e->light->color.r < 0)
			e->light->color.r = 0;
	}
	else if (e->i.nobj.first == 4)
	{
		tmp = ft_strcpy(tmp, "Couleur G ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->light->color.g = ft_atoi(e->i.term.wbuf);
		if (e->light->color.g > 255)
			e->light->color.g = 255;
		else if (e->light->color.g < 0)
			e->light->color.g = 0;
	}
	return (tmp);
}

char	*end_aff_new_light_sd(t_stuff *e, char *tmp)
{
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
	return (tmp);
}

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
		tmp = end_aff_new_light_sd(e, tmp);
		tmp = end_aff_new_light_td(e, tmp);
		tmp = end_aff_new_light_fh(e, tmp);
		tmp = end_aff_new_light_fih(e, tmp);
		end_aff_new_light_sh(e, tmp);
	}
	else
		ft_putstr("\nMalloc error in end_aff - terminal (interface)\n");
}
