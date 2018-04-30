/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_end_aff_new_plan.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 10:55:15 by prossi            #+#    #+#             */
/*   Updated: 2018/04/17 13:25:04 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

char	*end_aff_new_plan_fih(t_stuff *e, char *tmp)
{
	if (e->i.nobj.first == 9)
	{
		tmp = ft_strcpy(tmp, "Refrac ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->pla->refrac = ft_myatod(e->i.term.wbuf);
		if (e->pla->refrac > 2)
			e->pla->refrac = 2;
		else if (e->pla->refrac < 1 && e->pla->refrac > 0)
			e->pla->refrac = 1;
		else if (e->pla->refrac < 0)
			e->pla->refrac = 0;
	}
	else if (e->i.nobj.first == 10)
	{
		tmp = ft_strcpy(tmp, "Conscol ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->pla->conscol = ft_myatod(e->i.term.wbuf);
		if (e->pla->conscol > 1)
			e->pla->conscol = 1;
		if (e->pla->conscol < 0)
			e->pla->conscol = 0;
	}
	return (tmp);
}

char	*end_aff_new_plan_fh(t_stuff *e, char *tmp)
{
	if (e->i.nobj.first == 7)
	{
		tmp = ft_strcpy(tmp, "Couleur G ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->pla->color.g = ft_atoi(e->i.term.wbuf);
		if (e->pla->color.g > 255)
			e->pla->color.g = 255;
		else if (e->pla->color.g < 0)
			e->pla->color.g = 0;
	}
	else if (e->i.nobj.first == 8)
	{
		tmp = ft_strcpy(tmp, "Couleur B ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->pla->color.b = ft_atoi(e->i.term.wbuf);
		if (e->pla->color.b > 255)
			e->pla->color.b = 255;
		else if (e->pla->color.b < 0)
			e->pla->color.b = 0;
	}
	return (tmp);
}

char	*end_aff_new_plan_td(t_stuff *e, char *tmp)
{
	if (e->i.nobj.first == 4)
	{
		tmp = ft_strcpy(tmp, "Direction en Y ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->pla->norm.y = ft_myatod(e->i.term.wbuf);
	}
	else if (e->i.nobj.first == 5)
	{
		tmp = ft_strcpy(tmp, "Direction en Z ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->pla->norm.z = ft_myatod(e->i.term.wbuf);
		vecnorm(&e->pla->norm);
	}
	else if (e->i.nobj.first == 6)
	{
		tmp = ft_strcpy(tmp, "Couleur R ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->pla->color.r = ft_atoi(e->i.term.wbuf);
		if (e->pla->color.r > 255)
			e->pla->color.r = 255;
		else if (e->pla->color.r < 0)
			e->pla->color.r = 0;
	}
	return (tmp);
}

char	*end_aff_new_plan_sd(t_stuff *e, char *tmp)
{
	if (e->i.nobj.first == 0)
	{
		tmp = ft_strcpy(tmp, "Position en X ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->pla->pos.x = ft_myatod(e->i.term.wbuf);
	}
	else if (e->i.nobj.first == 1)
	{
		tmp = ft_strcpy(tmp, "Position en Y ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->pla->pos.y = ft_myatod(e->i.term.wbuf);
	}
	else if (e->i.nobj.first == 2)
	{
		tmp = ft_strcpy(tmp, "Position en Z ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->pla->pos.z = ft_myatod(e->i.term.wbuf);
	}
	else if (e->i.nobj.first == 3)
	{
		tmp = ft_strcpy(tmp, "Direction en X ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->pla->norm.x = ft_myatod(e->i.term.wbuf);
	}
	return (tmp);
}

void	end_aff_new_plan(t_stuff *e)
{
	char	*tmp;
	int		err;

	err = 0;
	if (!(tmp = ft_strnew(100)))
		err = 1;
	if (err == 0)
	{
		searchlist(e, e->d.nbmpla - 1, PLAN);
		e->i.term.wbuf[e->i.term.index] = '\0';
		tmp = end_aff_new_plan_sd(e, tmp);
		tmp = end_aff_new_plan_td(e, tmp);
		tmp = end_aff_new_plan_fh(e, tmp);
		tmp = end_aff_new_plan_fih(e, tmp);
		tmp = end_aff_new_plan_sh(e, tmp);
		end_aff_new_plan_seh(e, tmp);
	}
	else
		ft_putstr("\nMalloc error in end_aff - terminal (interface)\n");
}
