/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objet_courant_aff_data_camera.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Awk-LM <Awk-LM@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 15:09:15 by Awk-LM            #+#    #+#             */
/*   Updated: 2018/03/06 17:12:08 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	aff_data_camera(t_stuff *e)
{
	if (e->i.cobj.ordre == 0)
	{
		e->lt.posx = 50;
		e->lt.posy = (WIN_Y - LENGTH) / 2;
		e->lt.coeff = 1;
		e->lt.couleur = 0xFFFFFF;
		e->lt.space = 40;
		awklm_string_put("012345678", e);
	}
}
