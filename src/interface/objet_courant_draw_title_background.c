/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objet_courant_draw_title_background.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Awk-LM <Awk-LM@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 13:51:09 by Awk-LM            #+#    #+#             */
/*   Updated: 2018/03/09 13:55:23 by Awk-LM           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	draw_title_background(t_stuff *e)
{
		ft_init_value_draw_title_background(e, 0);
		awklm_string_put("POSITION", e);
		if (e->i.objet != SPHERE && e->i.objet != LIGHT)
		{
			ft_init_value_draw_title_background(e, 1);
			awklm_string_put("DIRECTION", e);
		}
		if (e->i.objet != -1)
		{
			ft_init_value_draw_title_background(e, 2);
			awklm_string_put("COULEUR", e);
		}
		if (e->i.objet == SPHERE || e->i.objet == LIGHT || e->i.objet == CYLINDRE)
		{
			ft_init_value_draw_title_background(e, 3);
			awklm_string_put("RAYON", e);
		}
		if (e->i.objet == CONE)
		{
			ft_init_value_draw_title_background(e, 3);
			awklm_string_put("ANGLE", e);
		}
		if (e->i.objet == LIGHT)
		{
			ft_init_value_draw_title_background(e, 4);
			awklm_string_put("COEFF. AMB.", e);
			ft_init_value_draw_title_background(e, 5);
			awklm_string_put("COEFF. DIF.", e);
		}
		if (e->i.objet != LIGHT && e->i.objet != -1)
		{
			ft_init_value_draw_title_background(e, 4);
			awklm_string_put("COEF. REFR.", e);
			ft_init_value_draw_title_background(e, 5);
			awklm_string_put("COEF. REFL.", e);
			ft_init_value_draw_title_background(e, 6);
			awklm_string_put("CONS. COUL.", e);
		}
}
