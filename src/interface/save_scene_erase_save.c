/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_scene_erase_save.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 16:44:48 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 14:04:21 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		save_scene_erase_save(t_stuff *e)
{
	char	*tmp;

	if (!(tmp = ft_strnew(100)))
		return (-1);
	tmp = ft_strncat(tmp, e->i.save.save_dir, \
		ft_strlen(e->i.save.save_dir) - 1);
	if (remove(tmp) == -1)
		return (-1);
	ft_strdel(&tmp);
	return (0);
}
