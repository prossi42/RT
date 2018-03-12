/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   awklm_string_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 18:01:05 by prossi            #+#    #+#             */
/*   Updated: 2018/03/12 12:51:38 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/rt.h"

void	draw_high_letter_td(t_stuff *e)
{
	if (e->lt.charac == 'R' || e->lt.charac == 'r')
		R(e);
	else if (e->lt.charac == 'S' || e->lt.charac == 's')
		S(e);
	else if (e->lt.charac == 'T' || e->lt.charac == 't')
		T(e);
	else if (e->lt.charac == 'U' || e->lt.charac == 'u')
		U(e);
	else if (e->lt.charac == 'V' || e->lt.charac == 'v')
		V(e);
	else if (e->lt.charac == 'W' || e->lt.charac == 'w')
		W(e);
	else if (e->lt.charac == 'X' || e->lt.charac == 'x')
		X(e);
	else if (e->lt.charac == 'Y' || e->lt.charac == 'y')
		Y(e);
	else
		Z(e);
}

void	draw_high_letter_sd(t_stuff *e)
{
	if (e->lt.charac == 'K' || e->lt.charac == 'k')
		K(e);
	else if (e->lt.charac == 'L' || e->lt.charac == 'l')
		L(e);
	else if (e->lt.charac == 'M' || e->lt.charac == 'm')
		M(e);
	else if (e->lt.charac == 'N' || e->lt.charac == 'n')
		N(e);
	else if (e->lt.charac == 'O' || e->lt.charac == 'o')
		O(e);
	else if (e->lt.charac == 'P' || e->lt.charac == 'p')
		P(e);
	else if (e->lt.charac == 'Q' || e->lt.charac == 'q')
		Q(e);
	else
		draw_high_letter_td(e);
}

void	draw_high_letter(t_stuff *e)
{
	if (e->lt.charac == 'A' || e->lt.charac == 'a')
		A(e);
	else if (e->lt.charac == 'B' || e->lt.charac == 'b')
		B(e);
	else if (e->lt.charac == 'C' || e->lt.charac == 'c')
		C(e);
	else if (e->lt.charac == 'D' || e->lt.charac == 'd')
		D(e);
	else if (e->lt.charac == 'E' || e->lt.charac == 'e')
		E(e);
	else if (e->lt.charac == 'F' || e->lt.charac == 'f')
		F(e);
	else if (e->lt.charac == 'G' || e->lt.charac == 'g')
		G(e);
	else if (e->lt.charac == 'H' || e->lt.charac == 'h')
		H(e);
	else if (e->lt.charac == 'I' || e->lt.charac == 'i')
		I(e);
	else if (e->lt.charac == 'J' || e->lt.charac == 'j')
		J(e);
	else
		draw_high_letter_sd(e);
}

void	draw_numbers(t_stuff *e)
{
	if (e->lt.charac == '0')
		zero(e);
	else if (e->lt.charac == '1')
		one(e);
	else if (e->lt.charac == '2')
		two(e);
	else if (e->lt.charac == '3')
		three(e);
	else if (e->lt.charac == '4')
		four(e);
	else if (e->lt.charac == '5')
		five(e);
	else if (e->lt.charac == '6')
		six(e);
	else if (e->lt.charac == '7')
		seven(e);
	else if (e->lt.charac == '8')
		eight(e);
	else
		nine(e);
}

void	draw_sign(t_stuff *e)
{
	if (e->lt.charac == '.')
		dot(e);
	else if (e->lt.charac == '-')
		minus(e);
	else if (e->lt.charac == ':')
		colons(e);
	else if (e->lt.charac == '/')
		slash(e);
}

void	draw_letter(t_stuff *e)
{
	if ((e->lt.charac >= 65 && e->lt.charac <= 90) || (e->lt.charac >= 97 && e->lt.charac <= 122))
		draw_high_letter(e);
	if (e->lt.charac >= 48 && e->lt.charac <= 57)
		draw_numbers(e);
	if (e->lt.charac == '.' || e->lt.charac == '-' || e->lt.charac == ':' || e->lt.charac == '/')
		draw_sign(e);
}

void	awklm_string_put(char *str, t_stuff *e)
{
	int 	i;
	double	tmp_coeff;
	int		posx;
	int		posy;
	int		space;

	i = -1;
	posx = e->lt.posx;
	posy = e->lt.posy;
	space = e->lt.space;
	while (str[++i])
	{
		tmp_coeff = e->lt.coeff;
		// if (i == 0 && (str[i] < 48 || str[i] > 57))
		// 	e->lt.coeff *= 1.5;
		e->lt.charac = str[i];
		draw_letter(e);
		if (e->lt.charac == '.')
			e->lt.posx += (space / 2) * e->lt.coeff;
		else
			e->lt.posx += space * e->lt.coeff;
		e->lt.coeff = tmp_coeff;
	}
	e->lt.posx = posx;
	e->lt.posy = posy;
}
