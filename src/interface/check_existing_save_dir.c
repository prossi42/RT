/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_existing_save_dir.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 11:44:32 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 17:06:32 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		check_existing_user_save_file(t_stuff *e)
{
	if (!(e->i.save.u_save_file = ft_strnew(ft_strlen(e->i.term.wbuf) + \
	ft_strlen(e->i.save.u_save_dir))))
		return (-1);
	e->i.save.u_save_file = ft_strcat(e->i.save.u_save_file, \
		e->i.save.u_save_dir);
	ft_strdel(&e->i.save.u_save_dir);
	e->i.save.u_save_file = ft_strcat(e->i.save.u_save_file, "/");
	e->i.save.u_save_file = ft_strncat(e->i.save.u_save_file, e->i.term.wbuf, \
		ft_strlen(e->i.term.wbuf) - 1);
	if (stat(e->i.save.u_save_file, &e->i.save.st) != 0)
	{
		e->i.save.fd = open(e->i.save.u_save_file, O_RDWR | O_CREAT, 0644);
		ft_strdel(&e->i.save.u_save_file);
	}
	else
	{
		ft_strdel(&e->i.save.u_save_file);
		return (-1);
	}
	return (0);
}

int		check_existing_save_file(t_stuff *e)
{
	char	*tmp;

	if (!(tmp = ft_strnew(100)))
		return (-1);
	tmp = ft_strcpy(tmp, e->i.save.save_dir);
	ft_strdel(&e->i.save.save_dir);
	tmp = ft_strncat(tmp, e->i.term.wbuf, ft_strlen(e->i.term.wbuf) - 1);
	if (stat(tmp, &e->i.save.st) != 0)
	{
		if ((e->i.save.fd = open(tmp, O_RDWR | O_CREAT, 0644)) == -1)
			return (-1);
	}
	else
		return (-1);
	ft_strdel(&tmp);
	return (0);
}

int		check_existing_user_save_dir(t_stuff *e)
{
	if (!(e->i.save.u_save_dir = ft_strnew(ft_strlen(e->i.term.wbuf) + \
	ft_strlen(e->i.save.save_dir))))
		return (-1);
	e->i.save.u_save_dir = ft_strcat(e->i.save.u_save_dir, e->i.save.save_dir);
	ft_strdel(&e->i.save.save_dir);
	e->i.save.u_save_dir = ft_strncat(e->i.save.u_save_dir, e->i.term.wbuf, \
		ft_strlen(e->i.term.wbuf) - 1);
	if (stat(e->i.save.u_save_dir, &e->i.save.st) != 0)
	{
		if (mkdir(e->i.save.u_save_dir, 0755) == -1)
		{
			ft_strdel(&e->i.save.u_save_dir);
			return (-1);
		}
	}
	else
	{
		ft_strdel(&e->i.save.u_save_dir);
		return (-1);
	}
	return (0);
}

int		check_existing_save_dir(t_stuff *e)
{
	char	*current_dir;

	current_dir = NULL;
	current_dir = getcwd(current_dir, 0);
	if (!(e->i.save.save_dir = ft_strnew(ft_strlen(current_dir) + 7)))
		return (-1);
	current_dir = ft_strcat(current_dir, "/save/");
	e->i.save.save_dir = ft_strcpy(e->i.save.save_dir, current_dir);
	ft_strdel(&current_dir);
	if (stat(e->i.save.save_dir, &e->i.save.st) != 0)
	{
		if (mkdir(e->i.save.save_dir, 0755) == -1)
			return (-1);
	}
	return (0);
}
