/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_end_aff_matrice.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 15:41:52 by prossi            #+#    #+#             */
/*   Updated: 2018/04/16 21:22:45 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

char	*end_aff_matrice_td(t_stuff *e, char *tmp)
{
	tmp = ft_strcpy(tmp, "Valeur de la translation ? : ");
	tmp = ft_strcat(tmp, e->i.term.wbuf);
	e->m.value = ft_atoi(e->i.term.wbuf);
	e->i.mat.act_trans = 1;
	return (tmp);
}

char	*end_aff_matrice_sd(t_stuff *e, char *tmp)
{
	tmp = ft_strcpy(tmp, "Valeur de l'angle en degre ? : ");
	tmp = ft_strcat(tmp, e->i.term.wbuf);
	e->m.angle = ft_atoi(e->i.term.wbuf);
	e->i.mat.act_rot = 1;
	return (tmp);
}

void	end_aff_matrice(t_stuff *e)
{
	char	*tmp;
	int		err;

	err = 0;
	if (!(tmp = ft_strnew(100)))
		err = 1;
	if (err == 0)
	{
		if (e->i.mat.act_rot == 0)
			tmp = end_aff_matrice_sd(e, tmp);
		if (e->i.mat.act_trans == 0)
			tmp = end_aff_matrice_td(e, tmp);
		e->i.term.tab[e->i.term.indextab] = \
		ft_strcpy(e->i.term.tab[e->i.term.indextab], tmp);
		e->i.term.tabfill = 1;
		ft_strclr(e->i.term.wbuf);
		ft_strdel(&tmp);
	}
	else
		ft_putstr("\nMalloc error in end_aff_matrice (terminal - interface)\n");
}
