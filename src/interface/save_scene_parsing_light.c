/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_scene_parsing_light.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 22:14:16 by prossi            #+#    #+#             */
/*   Updated: 2018/03/28 12:10:47 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		parsing_data_light_fh(t_stuff *e, char *nb)
{
	double		d;

	if ((d = ft_myatod(nb)) == 2147483647)
		return (-1);
	e->i.load.tabdlight[++e->d.i] = d;
	return (0);
}

int		parsing_data_light_td(t_stuff *e, char *str)
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
	if (parsing_data_light_fh(e, nb) == -1)
		return (-1);
	ft_strdel(&nb);
	return (0);
}

int		parsing_data_light_sd(t_stuff *e, char *str)
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

int		parsing_data_light(t_stuff *e, int y)
{
	int		tmp;
	char	*str;
	int		i;

	tmp = y - 1;
	i = 0;
	while (++tmp < y + 9)
	{
		if (parsing_data_light_sd(e, e->i.load.tab_load[tmp]) == -1)
			return (-1);
		if (!(str = ft_strsub(e->i.load.tab_load[tmp], 0, e->d.equal + 1)))
			return (-1);
		if (ft_compare_light(str, i) == -1)
			return (-1);
		ft_strdel(&str);
		if (!(str = ft_strsub(e->i.load.tab_load[tmp], e->d.equal + 1, \
			ft_strlen(e->i.load.tab_load[tmp]) - e->d.equal)))
			return (-1);
		if (parsing_data_light_td(e, str) == -1)
			return (-1);
		i++;
		ft_strdel(&str);
	}
	e->d.i = -1;
	return (0);
}

int		parsing_light(t_stuff *e, int y)
{
	t_light		*tmp;

	if (ft_strcmp(e->i.load.tab_load[y - 1], "------") != 0)
		return (-1);
	if (ft_strcmp(e->i.load.tab_load[y + 1], "------") != 0)
		return (-1);
	y += 2;
	if (!(e->i.load.tabdlight = (double *)malloc(sizeof(double) * 9)))
		return (-1);
	if (parsing_data_light(e, y) == -1)
		return (-1);
	if (e->light->next == NULL && e->i.load.nlight != 0)
	{
		tmp = e->light;
		init_list_light(&e->light->next);
		e->light = e->light->next;
		e->light->prev = tmp;
	}
	if (e->light->next != NULL && e->i.load.nlight != 0)
		e->light = e->light->next;
	save_scene_fill_list_light(e);
	e->i.load.nlight++;
	return (0);
}
