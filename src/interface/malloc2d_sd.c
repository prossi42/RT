/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc2d_sd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Awk-LM <Awk-LM@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 21:36:03 by Awk-LM            #+#    #+#             */
/*   Updated: 2018/03/05 21:36:25 by Awk-LM           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	malloc2d_sd(t_stuff *e)
{
	int		i;

	i = -1;
	if (!(e->i.cobj.tab = (char **)malloc(sizeof(char *) * 20)))
	{
		ft_putendl("\nMalloc failed (interface - obj. courant)");
		exit (0);
	}
	while (++i < 20)
	{
		if (!(e->i.cobj.tab[i] = ft_strnew(100)))
		{
			ft_putendl("\nMalloc failed (interface - obj. courant)");
			exit (0);
		}
	}
	e->i.cobj.tab[i] = NULL;
}
