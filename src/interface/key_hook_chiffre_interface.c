/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_chiffre_interface.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:07:32 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 10:07:32 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	hook_chiffre_sd(int keycode, t_stuff *e)
{
	if (keycode == 82)
		e->i.term.wbuf[e->i.term.index] = '0';
	else if (keycode == 83)
		e->i.term.wbuf[e->i.term.index] = '1';
	else if (keycode == 84)
		e->i.term.wbuf[e->i.term.index] = '2';
	else if (keycode == 85)
		e->i.term.wbuf[e->i.term.index] = '3';
	else if (keycode == 86)
		e->i.term.wbuf[e->i.term.index] = '4';
	else if (keycode == 87)
		e->i.term.wbuf[e->i.term.index] = '5';
	else if (keycode == 88)
		e->i.term.wbuf[e->i.term.index] = '6';
	else if (keycode == 89)
		e->i.term.wbuf[e->i.term.index] = '7';
	else if (keycode == 91)
		e->i.term.wbuf[e->i.term.index] = '8';
	else if (keycode == 92)
		e->i.term.wbuf[e->i.term.index] = '9';
}

void	hook_chiffre(int keycode, t_stuff *e)
{
	if (keycode == 78 && e->i.term.index == 0)
		e->i.term.wbuf[e->i.term.index] = '-';
	if (((e->i.term.index < 4 && e->i.mat.act_angle == 1) || (e->i.term.index \
		< 5 && e->i.mat.act_value == 1) || (e->i.term.index < 6 && \
			e->i.nobj.first != -1) || (e->i.term.index < 6 && e->i.multi != 0) \
			|| (e->i.perlin == 2 && e->i.term.index < 4) || \
			(e->i.scr.act_scr == 1 && e->i.term.index < 10) || \
			(e->i.damier != -1 && e->i.term.index < 3)))
		hook_chiffre_sd(keycode, e);
	if ((e->i.term.index < 4 && e->i.mat.act_angle == 1) || \
	(e->i.term.index < 5 && e->i.mat.act_value == 1) || (e->i.term.index < 6 \
		&& e->i.nobj.first != -1) || (e->i.term.index < 6 && e->i.multi != 0) \
		|| (e->i.perlin == 2 && e->i.term.index < 4) || (e->i.scr.act_scr == 1 \
			&& e->i.term.index < 10) || (e->i.damier != -1 && \
				e->i.term.index < 3))
		e->i.term.index++;
}
