/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_end_aff_multiobj_cubesphere_sd.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 13:57:13 by prossi            #+#    #+#             */
/*   Updated: 2018/04/17 14:01:02 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	end_aff_multiobj_cubesphere_seh(t_stuff *e, char *tmp)
{
	e->i.term.tab[e->i.term.indextab] = \
	ft_strcpy(e->i.term.tab[e->i.term.indextab], tmp);
	e->i.term.tabfill = 1;
	ft_strclr(e->i.term.wbuf);
	ft_strdel(&tmp);
	if ((e->i.multi == 1 && e->i.mobj.first == 10) || \
	(e->i.multi == 2 && e->i.mobj.first == 9))
	{
		if (e->i.multi == 2)
			e->i.mobj.len = 4;
		e->i.mobj.first = 0;
		multiobj_create(e);
		e->i.multi = 0;
		multi_thread(e);
		terminal(e);
	}
	else
	{
		e->i.mobj.first++;
		terminal(e);
	}
}

char	*end_aff_multiobj_cubesphere_sh(t_stuff *e, char *tmp)
{
	if (e->i.mobj.first == 9)
	{
		tmp = ft_strcpy(tmp, "Reflex ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->i.mobj.reflex = ft_myatod(e->i.term.wbuf);
		if (e->i.mobj.reflex > 1)
			e->i.mobj.reflex = 1;
		if (e->i.mobj.reflex < 0)
			e->i.mobj.reflex = 0;
	}
	else if (e->i.mobj.first == 10)
	{
		tmp = ft_strcpy(tmp, "Taille du cube ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->i.mobj.len = ft_atoi(e->i.term.wbuf);
		if (e->i.mobj.len > 5)
			e->i.mobj.len = 5;
		else if (e->i.mobj.len < 0)
			e->i.mobj.len = 0;
	}
	return (tmp);
}
