/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc2d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Awk-LM <Awk-LM@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 21:32:51 by Awk-LM            #+#    #+#             */
/*   Updated: 2018/03/05 21:34:07 by Awk-LM           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	malloc2d(t_stuff *e)
{
	int		i;

	i = -1;
	if (!(e->i.term.tab = (char **)malloc(sizeof(char *) * 5)))
	{
		ft_putendl("\nLe malloc du tableau (interface - terminal) a echoué");
		exit (0);
	}
	while (++i < 5)
	{
		if (!(e->i.term.tab[i] = ft_strnew(100)))
		{
			ft_putendl("\nLe malloc du tableau (interface - terminal) a echoué");
			exit (0);
		}
	}
	e->i.term.tab[i] = NULL;
}
