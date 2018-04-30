/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_end_aff_screenshots.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 15:20:17 by prossi            #+#    #+#             */
/*   Updated: 2018/04/16 15:21:45 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	end_aff_screenshots(t_stuff *e)
{
	char	*tmp;
	int		err;

	err = 0;
	if (!(tmp = ft_strnew(100)))
		err = 1;
	if (err == 0)
	{
		tmp = ft_strcpy(tmp, "Nom du fichier ? : ");
		tmp = ft_strcat(tmp, e->i.term.wbuf);
		e->i.term.wbuf[e->i.term.index] = '\0';
		e->i.scr.path = ft_strcat(e->i.scr.path, e->i.term.wbuf);
		e->i.scr.path = ft_strcat(e->i.scr.path, ".ppm");
		e->i.term.tab[e->i.term.indextab] = \
		ft_strcpy(e->i.term.tab[e->i.term.indextab], tmp);
		e->i.term.tabfill = 1;
		ft_strclr(e->i.term.wbuf);
		ft_strdel(&tmp);
		draw_terminal(e);
		screenshots(e);
	}
	else
		ft_putstr("\nMalloc error in end_aff_screenshots \
		(terminal - interface)\n");
}
