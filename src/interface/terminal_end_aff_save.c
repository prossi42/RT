/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_end_aff_save.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 15:09:17 by prossi            #+#    #+#             */
/*   Updated: 2018/04/16 16:21:07 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

char	*end_aff_save_fih(t_stuff *e, char *tmp)
{
	tmp = ft_strcpy(tmp, "Nom du fichier de sauvegarde ? : ");
	tmp = ft_strcat(tmp, e->i.term.wbuf);
	save_scene_create_save(e);
	return (tmp);
}

char	*end_aff_save_fh(t_stuff *e, char *tmp)
{
	tmp = ft_strcpy(tmp, "Nom du fichier de sauvegarde ? : ");
	tmp = ft_strcat(tmp, e->i.term.wbuf);
	save_scene_create_save(e);
	return (tmp);
}

char	*end_aff_save_td(t_stuff *e, char *tmp)
{
	tmp = ft_strcpy(tmp, "Nom du dossier de sauvegarde ? : ");
	tmp = ft_strcat(tmp, e->i.term.wbuf);
	save_scene_create_save(e);
	return (tmp);
}

char	*end_aff_save_sd(t_stuff *e, char *tmp)
{
	if (e->i.term.wbuf[0] == 'y')
		e->i.save.act_save = 2;
	if (e->i.term.wbuf[0] == 'n')
		e->i.save.act_save = 3;
	tmp = ft_strcpy(tmp, "Creer un nouveau dossier de sauvegarde ? (y/n): ");
	tmp = ft_strcat(tmp, e->i.term.wbuf);
	return (tmp);
}

void	end_aff_save(t_stuff *e)
{
	char	*tmp;
	int		err;

	err = 0;
	if (!(tmp = ft_strnew(100)))
		err = 1;
	if (err == 0)
	{
		if (e->i.save.act_save == 1)
			tmp = end_aff_save_sd(e, tmp);
		else if (e->i.save.act_save == 2)
			tmp = end_aff_save_td(e, tmp);
		else if (e->i.save.act_save == 6)
			tmp = end_aff_save_fh(e, tmp);
		else if (e->i.save.act_save == 7)
			tmp = end_aff_save_fih(e, tmp);
		e->i.term.tab[e->i.term.indextab] = \
		ft_strcpy(e->i.term.tab[e->i.term.indextab], tmp);
		e->i.term.tabfill = 1;
		ft_strclr(e->i.term.wbuf);
		ft_strdel(&tmp);
	}
	else
		ft_putstr("\nMalloc error in end_aff_save (terminal - interface)\n");
}
