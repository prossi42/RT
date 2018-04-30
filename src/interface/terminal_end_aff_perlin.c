/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_end_aff_perlin.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 14:59:39 by prossi            #+#    #+#             */
/*   Updated: 2018/04/16 15:07:20 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

char	*end_aff_perlin_td(t_stuff *e, char *tmp)
{
	tmp = ft_strcpy(tmp, "Nouvelle valeur ? : ");
	tmp = ft_strcat(tmp, e->i.term.wbuf);
	e->i.term.wbuf[e->i.term.index] = '\0';
	e->i.perlin_stain = ft_myatod(e->i.term.wbuf);
	e->i.perlin = 3;
	multi_thread(e);
	apercu_courant(e);
	return (tmp);
}

char	*end_aff_perlin_sd(t_stuff *e, char *tmp)
{
	if (e->i.term.wbuf[0] == 'y')
		e->i.perlin = 2;
	if (e->i.term.wbuf[0] == 'n')
	{
		e->i.perlin = 3;
		multi_thread(e);
		apercu_courant(e);
	}
	tmp = ft_strcpy(tmp, "Changer la valeur ? : ");
	tmp = ft_strcat(tmp, e->i.term.wbuf);
	draw_terminal(e);
	return (tmp);
}

void	end_aff_perlin(t_stuff *e)
{
	char	*tmp;
	int		err;

	err = 0;
	if (!(tmp = ft_strnew(100)))
		err = 1;
	if (err == 0)
	{
		if (e->i.perlin == 1)
			tmp = end_aff_perlin_sd(e, tmp);
		else if (e->i.perlin == 2)
			tmp = end_aff_perlin_td(e, tmp);
		e->i.term.tab[e->i.term.indextab] = \
		ft_strcpy(e->i.term.tab[e->i.term.indextab], tmp);
		e->i.term.tabfill = 1;
		ft_strclr(e->i.term.wbuf);
		ft_strdel(&tmp);
		if (e->i.perlin == 1)
			terminal(e);
	}
	else
		ft_putstr("\nMalloc error in end_aff_perlin (terminal - interface)\n");
}
