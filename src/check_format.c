/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 13:20:24 by prossi            #+#    #+#             */
/*   Updated: 2018/02/05 11:22:19 by luca             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		check_check(t_stuff *e)
{
	if (ft_strcmp(e->b.tab[0], "------") != 0)
		return (-1);
	if (ft_strcmp(e->b.tab[e->d.nbl - 1], "------") != 0)
		return (-1);
	return (0);
}

int		check_format(t_stuff *e)
{
	int		y;

	y = -1;
	check_check(e);
	while (e->b.tab[++y])
	{
		if (ft_strcmp(e->b.tab[y], "SPHERE") == 0)
			if (sphere(e, y) == -1)
				return (-1);
		if (ft_strcmp(e->b.tab[y], "PLAN") == 0)
			if (plan(e, y) == -1)
				return (-1);
		if (ft_strcmp(e->b.tab[y], "LIGHT") == 0)
			if (light(e, y) == -1)
				return (-1);
		if (ft_strcmp(e->b.tab[y], "CYLINDRE") == 0)
			if (cylindre(e, y) == -1)
				return (-1);
		if (ft_strcmp(e->b.tab[y], "CONE") == 0)
			if (cone(e, y) == -1)
				return (-1);
		free(e->b.tab[y]);
	}
	free(e->b.tab);
	return (0);
}
