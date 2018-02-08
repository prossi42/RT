/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compare_td.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luca <luca@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:03:15 by luca              #+#    #+#             */
/*   Updated: 2018/02/08 15:23:15 by lhermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		ft_compare_light_sd(char *str, int i)
{
	if (i == 6)
		if (ft_strcmp(str, "b =") == 0)
			return (0);
	if (i == 7)
		if (ft_strcmp(str, "amb =") == 0)
			return (0);
	if (i == 8)
		if (ft_strcmp(str, "diff =") == 0)
			return (0);
	return (-1);
}

int		ft_compare_light(char *str, int i)
{
	if (i == 0)
		if (ft_strcmp(str, "x =") == 0)
			return (0);
	if (i == 1)
		if (ft_strcmp(str, "y =") == 0)
			return (0);
	if (i == 2)
		if (ft_strcmp(str, "z =") == 0)
			return (0);
	if (i == 3)
		if (ft_strcmp(str, "ray =") == 0)
			return (0);
	if (i == 4)
		if (ft_strcmp(str, "r =") == 0)
			return (0);
	if (i == 5)
		if (ft_strcmp(str, "g =") == 0)
			return (0);
	if (ft_compare_light_sd(str, i) == 0)
		return (0);
	return (-1);
}
