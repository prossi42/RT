/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_end_aff_new_cone_sd.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 13:45:52 by prossi            #+#    #+#             */
/*   Updated: 2018/04/17 13:47:09 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	end_aff_new_cone_seh(t_stuff *e, char *tmp)
{
	e->i.term.tab[e->i.term.indextab] = \
	ft_strcpy(e->i.term.tab[e->i.term.indextab], tmp);
	e->i.term.tabfill = 1;
	ft_strclr(e->i.term.wbuf);
	ft_strdel(&tmp);
	if (e->i.nobj.first == 12)
	{
		e->i.nobj.first = -1;
		multi_thread(e);
		apercu_courant(e);
	}
	else
	{
		e->i.nobj.first++;
		terminal(e);
	}
}

char	*end_aff_new_cone_sh(t_stuff *e, char *tmp)
{
	if (e->i.nobj.first == 11)
	{
		tmp = ft_strcpy(tmp, "Conscol ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->cone->conscol = ft_myatod(e->i.term.wbuf);
		if (e->cone->conscol > 1)
			e->cone->conscol = 1;
		if (e->cone->conscol < 0)
			e->cone->conscol = 0;
	}
	else if (e->i.nobj.first == 12)
	{
		tmp = ft_strcpy(tmp, "Reflex ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->cone->reflex = ft_myatod(e->i.term.wbuf);
		if (e->cone->reflex > 1)
			e->cone->reflex = 1;
		if (e->cone->reflex < 0)
			e->cone->reflex = 0;
	}
	return (tmp);
}
