/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_interface.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 22:57:37 by prossi            #+#    #+#             */
/*   Updated: 2018/02/14 08:16:33 by Awk-LM           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	hook_letres(int keycode, t_stuff *e)
{
	if (keycode == 0 && e->i.mat.act_angle == 0 && e->i.mat.act_value == 0 && e->i.nobj.first == -1)
		e->i.term.wbuf[e->i.term.index] = 'a';
	else if (keycode == 11 && e->i.mat.act_angle == 0 && e->i.mat.act_value == 0 && e->i.nobj.first == -1)
		e->i.term.wbuf[e->i.term.index] = 'b';
	else if (keycode == 8 && e->i.mat.act_angle == 0 && e->i.mat.act_value == 0 && e->i.nobj.first == -1)
		e->i.term.wbuf[e->i.term.index] = 'c';
	else if (keycode == 2 && e->i.mat.act_angle == 0 && e->i.mat.act_value == 0 && e->i.nobj.first == -1)
		e->i.term.wbuf[e->i.term.index] = 'd';
	else if (keycode == 14 && e->i.mat.act_angle == 0 && e->i.mat.act_value == 0 && e->i.nobj.first == -1)
		e->i.term.wbuf[e->i.term.index] = 'e';
	else if (keycode == 3 && e->i.mat.act_angle == 0 && e->i.mat.act_value == 0 && e->i.nobj.first == -1)
		e->i.term.wbuf[e->i.term.index] = 'f';
	else if (keycode == 5 && e->i.mat.act_angle == 0 && e->i.mat.act_value == 0 && e->i.nobj.first == -1)
		e->i.term.wbuf[e->i.term.index] = 'g';
	else if (keycode == 4 && e->i.mat.act_angle == 0 && e->i.mat.act_value == 0 && e->i.nobj.first == -1)
		e->i.term.wbuf[e->i.term.index] = 'h';
	else if (keycode == 34 && e->i.mat.act_angle == 0 && e->i.mat.act_value == 0 && e->i.nobj.first == -1)
		e->i.term.wbuf[e->i.term.index] = 'i';
	else if (keycode == 38 && e->i.mat.act_angle == 0 && e->i.mat.act_value == 0 && e->i.nobj.first == -1)
		e->i.term.wbuf[e->i.term.index] = 'j';
	else if (keycode == 40 && e->i.mat.act_angle == 0 && e->i.mat.act_value == 0 && e->i.nobj.first == -1)
		e->i.term.wbuf[e->i.term.index] = 'k';
	else if (keycode == 37 && e->i.mat.act_angle == 0 && e->i.mat.act_value == 0 && e->i.nobj.first == -1)
		e->i.term.wbuf[e->i.term.index] = 'l';
	else if (keycode == 46 && e->i.mat.act_angle == 0 && e->i.mat.act_value == 0 && e->i.nobj.first == -1)
		e->i.term.wbuf[e->i.term.index] = 'm';
	else if (keycode == 45 && e->i.mat.act_angle == 0 && e->i.mat.act_value == 0 && e->i.nobj.first == -1)
		e->i.term.wbuf[e->i.term.index] = 'n';
	else if (keycode == 31 && e->i.mat.act_angle == 0 && e->i.mat.act_value == 0 && e->i.nobj.first == -1)
		e->i.term.wbuf[e->i.term.index] = 'o';
	else if (keycode == 35 && e->i.mat.act_angle == 0 && e->i.mat.act_value == 0 && e->i.nobj.first == -1)
		e->i.term.wbuf[e->i.term.index] = 'p';
	else if (keycode == 12 && e->i.mat.act_angle == 0 && e->i.mat.act_value == 0 && e->i.nobj.first == -1)
		e->i.term.wbuf[e->i.term.index] = 'q';
	else if (keycode == 15 && e->i.mat.act_angle == 0 && e->i.mat.act_value == 0 && e->i.nobj.first == -1)
		e->i.term.wbuf[e->i.term.index] = 'r';
	else if (keycode == 1 && e->i.mat.act_angle == 0 && e->i.mat.act_value == 0 && e->i.nobj.first == -1)
		e->i.term.wbuf[e->i.term.index] = 's';
	else if (keycode == 17 && e->i.mat.act_angle == 0 && e->i.mat.act_value == 0 && e->i.nobj.first == -1)
		e->i.term.wbuf[e->i.term.index] = 't';
	else if (keycode == 32 && e->i.mat.act_angle == 0 && e->i.mat.act_value == 0 && e->i.nobj.first == -1)
		e->i.term.wbuf[e->i.term.index] = 'u';
	else if (keycode == 9 && e->i.mat.act_angle == 0 && e->i.mat.act_value == 0 && e->i.nobj.first == -1)
		e->i.term.wbuf[e->i.term.index] = 'v';
	else if (keycode == 13 && e->i.mat.act_angle == 0 && e->i.mat.act_value == 0 && e->i.nobj.first == -1)
		e->i.term.wbuf[e->i.term.index] = 'w';
	else if (keycode == 7 && e->i.mat.act_angle == 0 && e->i.mat.act_value == 0 && e->i.nobj.first == -1)
		e->i.term.wbuf[e->i.term.index] = 'x';
	else if (keycode == 16 && e->i.mat.act_angle == 0 && e->i.mat.act_value == 0 && e->i.nobj.first == -1)
		e->i.term.wbuf[e->i.term.index] = 'y';
	else if (keycode == 6 && e->i.mat.act_angle == 0 && e->i.mat.act_value == 0 && e->i.nobj.first == -1)
		e->i.term.wbuf[e->i.term.index] = 'z';
}

void	hook_chiffre(int keycode, t_stuff *e)
{
	if (keycode == 78 && e->i.term.index == 0)
		e->i.term.wbuf[e->i.term.index] = '-';
	if (keycode == 82 && ((e->i.term.index < 4 && e->i.mat.act_angle == 1) || (e->i.term.index < 5 && e->i.mat.act_value == 1) || (e->i.term.index < 6 && e->i.nobj.first != -1)))
		e->i.term.wbuf[e->i.term.index] = '0';
	else if (keycode == 83 && ((e->i.term.index < 4 && e->i.mat.act_angle == 1) || (e->i.term.index < 5 && e->i.mat.act_value == 1) || (e->i.term.index < 6 && e->i.nobj.first != -1)))
		e->i.term.wbuf[e->i.term.index] = '1';
	else if (keycode == 84 && ((e->i.term.index < 4 && e->i.mat.act_angle == 1) || (e->i.term.index < 5 && e->i.mat.act_value == 1) || (e->i.term.index < 6 && e->i.nobj.first != -1)))
		e->i.term.wbuf[e->i.term.index] = '2';
	else if (keycode == 85 && ((e->i.term.index < 4 && e->i.mat.act_angle == 1) || (e->i.term.index < 5 && e->i.mat.act_value == 1) || (e->i.term.index < 6 && e->i.nobj.first != -1)))
		e->i.term.wbuf[e->i.term.index] = '3';
	else if (keycode == 86 && ((e->i.term.index < 4 && e->i.mat.act_angle == 1) || (e->i.term.index < 5 && e->i.mat.act_value == 1) || (e->i.term.index < 6 && e->i.nobj.first != -1)))
		e->i.term.wbuf[e->i.term.index] = '4';
	else if (keycode == 87 && ((e->i.term.index < 4 && e->i.mat.act_angle == 1) || (e->i.term.index < 5 && e->i.mat.act_value == 1) || (e->i.term.index < 6 && e->i.nobj.first != -1)))
		e->i.term.wbuf[e->i.term.index] = '5';
	else if (keycode == 88 && ((e->i.term.index < 4 && e->i.mat.act_angle == 1) || (e->i.term.index < 5 && e->i.mat.act_value == 1) || (e->i.term.index < 6 && e->i.nobj.first != -1)))
		e->i.term.wbuf[e->i.term.index] = '6';
	else if (keycode == 89 && ((e->i.term.index < 4 && e->i.mat.act_angle == 1) || (e->i.term.index < 5 && e->i.mat.act_value == 1) || (e->i.term.index < 6 && e->i.nobj.first != -1)))
		e->i.term.wbuf[e->i.term.index] = '7';
	else if (keycode == 91 && ((e->i.term.index < 4 && e->i.mat.act_angle == 1) || (e->i.term.index < 5 && e->i.mat.act_value == 1) || (e->i.term.index < 6 && e->i.nobj.first != -1)))
		e->i.term.wbuf[e->i.term.index] = '8';
	else if (keycode == 92 && ((e->i.term.index < 4 && e->i.mat.act_angle == 1) || (e->i.term.index < 5 && e->i.mat.act_value == 1) || (e->i.term.index < 6 && e->i.nobj.first != -1)))
		e->i.term.wbuf[e->i.term.index] = '9';
	if ((e->i.term.index < 4 && e->i.mat.act_angle == 1) || (e->i.term.index < 5 && e->i.mat.act_value == 1) || (e->i.term.index < 6 && e->i.nobj.first != -1))
		e->i.term.index++;
}

void	key_hook_interface(int keycode, t_stuff *e)
{
	if ((keycode >= 82 && keycode <= 89) || (keycode >= 91 && keycode <= 92) || keycode == 78)
		hook_chiffre(keycode, e);
	else if ((keycode >= 0 && keycode <= 9) || (keycode >= 11 && keycode <= 17)\
	 || keycode == 31 || keycode == 32 || keycode == 34 || keycode == 35 \
	 || keycode == 37 || keycode == 38 || keycode == 40 || keycode == 45 \
	 || keycode == 46)
	 	hook_letres(keycode, e);
	if (keycode == 36 && ((e->i.term.dot == 0 && e->i.nobj.first == -1) || (e->i.term.dot == 1 && e->i.nobj.first != -1 && e->i.term.wbuf[0] != '.')))
	{
		e->i.term.wbuf[e->i.term.index] = '\n';
	}
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
