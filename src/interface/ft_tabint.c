/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 07:58:05 by prossi            #+#    #+#             */
/*   Updated: 2018/03/15 07:58:14 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		**ft_tabint(int x, int y)
{
	int		**tabi;
	int		i;

	i = 0;
	tabi = 0;
	if (!(tabi = (int **)malloc(sizeof(int *) * y)))
		return (NULL);
	while (i < y)
	{
		if (!(tabi[i] = (int *)malloc(sizeof(int) * x)))
			return (NULL);
		i++;
	}
	return (tabi);
}
