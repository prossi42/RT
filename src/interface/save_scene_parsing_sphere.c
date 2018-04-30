/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_scene_parsing_sphere.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:48:56 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 10:48:57 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		parsing_data_sphere_fh(t_stuff *e, char *nb)
{
	double		d;

	if ((d = ft_myatod(nb)) == 2147483647)
		return (-1);
	e->i.load.tabdsph[++e->d.i] = d;
	return (0);
}

int		parsing_data_sphere_td(t_stuff *e, char *str)
{
	int		i;
	char	*nb;

	i = -1;
	if (str[0] != ' ')
		return (-1);
	while (str[++i])
	{
		if (str[i] == ' ' && i != 0)
			return (-1);
		if ((str[i] < 48 || str[i] > 57) && str[i] != '.' && str[i] != ' ' \
		&& str[i] != '-')
			return (-1);
		if (str[i] == '-' && i != 1)
			return (-1);
	}
	if (!(nb = ft_strsub(str, 1, ft_strlen(str) - 1)))
		return (-1);
	if (parsing_data_sphere_fh(e, nb) == -1)
		return (-1);
	ft_strdel(&nb);
	return (0);
}

int		parsing_data_sphere_sd(t_stuff *e, char *str)
{
	int		i;
	int		nbequal;
	int		nbdot;

	i = -1;
	nbequal = 0;
	nbdot = 0;
	e->d.equal = 0;
	if (!str)
		return (-1);
	while (str[++i])
	{
		if (str[i] == '=')
		{
			e->d.equal = i;
			nbequal++;
		}
		if (str[i] == '.')
			nbdot++;
	}
	if (nbequal != 1)
		return (-1);
	if (nbdot != 1)
		return (-1);
	return (0);
}

int		parsing_data_sphere(t_stuff *e, int y)
{
	int		tmp;
	char	*str;
	int		i;

	tmp = y - 1;
	i = 0;
	while (++tmp < y + 10)
	{
		if (parsing_data_sphere_sd(e, e->i.load.tab_load[tmp]) == -1)
			return (-1);
		if (!(str = ft_strsub(e->i.load.tab_load[tmp], 0, e->d.equal + 1)))
			return (-1);
		if (ft_compare_sphere(str, i) == -1)
			return (-1);
		ft_strdel(&str);
		if (!(str = ft_strsub(e->i.load.tab_load[tmp], e->d.equal + 1, \
			ft_strlen(e->i.load.tab_load[tmp]) - e->d.equal)))
			return (-1);
		if (parsing_data_sphere_td(e, str) == -1)
			return (-1);
		i++;
		ft_strdel(&str);
	}
	e->d.i = -1;
	return (0);
}

int		parsing_sphere(t_stuff *e, int y)
{
	t_sphere	*tmp;

	if (ft_strcmp(e->i.load.tab_load[y - 1], "------") != 0)
		return (-1);
	if (ft_strcmp(e->i.load.tab_load[y + 1], "------") != 0)
		return (-1);
	y += 2;
	if (!(e->i.load.tabdsph = (double *)malloc(sizeof(double) * 10)))
		return (-1);
	if (parsing_data_sphere(e, y) == -1)
		return (-1);
	if (e->sph->next == NULL && e->i.load.nsph != 0)
	{
		tmp = e->sph;
		init_list_sph(&e->sph->next);
		e->sph = e->sph->next;
		e->sph->prev = tmp;
	}
	if (e->sph->next != NULL && e->i.load.nsph != 0)
		e->sph = e->sph->next;
	save_scene_fill_list_sph(e);
	e->i.load.nsph++;
	return (0);
}
