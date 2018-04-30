/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_interface.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 22:57:37 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 10:08:39 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	key_hook_interface_sd(t_stuff *e)
{
	if (e->i.term.index != 0)
	{
		if (e->i.term.dot == 0 && (e->i.perlin == 1 || \
			e->i.scr.act_scr != 0 || e->i.save.act_save != 0 || \
			e->i.load.act_load != 0 || e->i.damier != -1 || \
			e->i.mat.act_rot == 0 || e->i.mat.act_trans == 0))
			e->i.term.wbuf[e->i.term.index] = '\n';
		else if (e->i.term.dot == 1 && e->i.term.wbuf[0] != '.' && \
		(e->i.nobj.first != -1 || e->i.multi != 0 || e->i.perlin == 2 ||\
			e->i.mat.act_rot == 0 || e->i.mat.act_trans == 0))
			e->i.term.wbuf[e->i.term.index] = '\n';
	}
}

void	key_hook_interface(int keycode, t_stuff *e)
{
	if ((keycode >= 82 && keycode <= 89) || (keycode >= 91 && keycode <= 92) \
	|| keycode == 78)
		hook_chiffre(keycode, e);
	else if (((keycode >= 0 && keycode <= 9) || (keycode >= 11 && \
		keycode <= 17) || keycode == 31 || keycode == 32 || keycode == 34 \
		|| keycode == 35 || keycode == 37 || keycode == 38 || keycode == 40 || \
		keycode == 45 || keycode == 46) && e->i.mat.act_angle == 0 && \
		e->i.mat.act_value == 0 && e->i.nobj.first == -1)
		hook_letres(keycode, e);
	if (keycode == 36)
		key_hook_interface_sd(e);
	if (keycode == 51 && e->i.term.index != 0)
	{
		if (e->i.term.wbuf[e->i.term.index - 1] == '.')
			e->i.term.dot = 0;
		e->i.term.wbuf[--e->i.term.index] = '\0';
	}
	if (keycode == 65 && e->i.term.dot == 0)
	{
		e->i.term.wbuf[e->i.term.index] = '.';
		e->i.term.index++;
		e->i.term.dot++;
	}
	terminal(e);
}
