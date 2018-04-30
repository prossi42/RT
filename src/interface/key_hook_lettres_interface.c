/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_lettres_interface.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:13:33 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 10:13:34 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	hook_letres_fh(int keycode, t_stuff *e)
{
	if (keycode == 16)
		e->i.term.wbuf[e->i.term.index] = 'y';
	else if (keycode == 6)
		e->i.term.wbuf[e->i.term.index] = 'z';
}

void	hook_letres_td(int keycode, t_stuff *e)
{
	if (keycode == 46)
		e->i.term.wbuf[e->i.term.index] = 'm';
	else if (keycode == 45)
		e->i.term.wbuf[e->i.term.index] = 'n';
	else if (keycode == 31)
		e->i.term.wbuf[e->i.term.index] = 'o';
	else if (keycode == 35)
		e->i.term.wbuf[e->i.term.index] = 'p';
	else if (keycode == 12)
		e->i.term.wbuf[e->i.term.index] = 'q';
	else if (keycode == 15)
		e->i.term.wbuf[e->i.term.index] = 'r';
	else if (keycode == 1)
		e->i.term.wbuf[e->i.term.index] = 's';
	else if (keycode == 17)
		e->i.term.wbuf[e->i.term.index] = 't';
	else if (keycode == 32)
		e->i.term.wbuf[e->i.term.index] = 'u';
	else if (keycode == 9)
		e->i.term.wbuf[e->i.term.index] = 'v';
	else if (keycode == 13)
		e->i.term.wbuf[e->i.term.index] = 'w';
	else if (keycode == 7)
		e->i.term.wbuf[e->i.term.index] = 'x';
}

void	hook_letres_sd(int keycode, t_stuff *e)
{
	if (keycode == 0)
		e->i.term.wbuf[e->i.term.index] = 'a';
	else if (keycode == 11)
		e->i.term.wbuf[e->i.term.index] = 'b';
	else if (keycode == 8)
		e->i.term.wbuf[e->i.term.index] = 'c';
	else if (keycode == 2)
		e->i.term.wbuf[e->i.term.index] = 'd';
	else if (keycode == 14)
		e->i.term.wbuf[e->i.term.index] = 'e';
	else if (keycode == 3)
		e->i.term.wbuf[e->i.term.index] = 'f';
	else if (keycode == 5)
		e->i.term.wbuf[e->i.term.index] = 'g';
	else if (keycode == 4)
		e->i.term.wbuf[e->i.term.index] = 'h';
	else if (keycode == 34)
		e->i.term.wbuf[e->i.term.index] = 'i';
	else if (keycode == 38)
		e->i.term.wbuf[e->i.term.index] = 'j';
	else if (keycode == 40)
		e->i.term.wbuf[e->i.term.index] = 'k';
	else if (keycode == 37)
		e->i.term.wbuf[e->i.term.index] = 'l';
}

void	hook_letres(int keycode, t_stuff *e)
{
	if (((e->i.save.act_save == 1 && e->i.term.index < 1) || \
	((e->i.save.act_save == 2 || e->i.save.act_save == 6 || \
		e->i.save.act_save == 7) && e->i.term.index < 10) || \
		(e->i.perlin == 1 && e->i.term.index < 1) || (e->i.scr.act_scr == 1 \
			&& e->i.term.index < 10)))
	{
		hook_letres_sd(keycode, e);
		hook_letres_td(keycode, e);
		hook_letres_fh(keycode, e);
	}
	if ((e->i.save.act_save == 1 && e->i.term.index < 1) || \
	((e->i.save.act_save == 2 || e->i.save.act_save == 6 || \
		e->i.save.act_save == 7) && e->i.term.index < 10) || (e->i.perlin == 1 \
			&& e->i.term.index < 1) || (e->i.scr.act_scr == 1 && \
				e->i.term.index < 10))
		e->i.term.index++;
}
