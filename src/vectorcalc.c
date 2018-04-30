/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorcalc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <jgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 10:07:54 by jgaillar          #+#    #+#             */
/*   Updated: 2018/04/13 09:54:43 by lhermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		raydir(t_stuff *e, int y, int z)
{
	t_vec	pixel;
	t_vec	tmp;

	pixel.y = (y + 0.5) / WIDTH;
	pixel.z = (z + 0.5) / LENGTH;
	pixel.y = (2 * pixel.y) - 1;
	pixel.z = 1 - (2 * pixel.z);
	pixel.y *= tan(FOV * 0.5 * M_PI / 180) * RATIO;
	pixel.z *= tan(FOV * 0.5 * M_PI / 180);
	pixel.x = 1;
	vecadd(&pixel, &pixel, &e->poscam);
	vecsous(&tmp, &pixel, &e->poscam);
	e->raydir = tmp;
	vecnorm(&e->raydir);
	rotation_apply(e, &e->raydir);
}
