/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook_shortcuts.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 15:22:04 by prossi            #+#    #+#             */
/*   Updated: 2018/04/19 13:38:13 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	mouse_hook_shortcuts(t_stuff *e, int x, int y)
{
	if (y > 0 && y < (WIN_Y - LENGTH) / 3)
		mouse_hook_shortcuts_filtres(e, x);
	else if (y > (WIN_Y - LENGTH) / 3 && y < ((WIN_Y - LENGTH) / 3) * 2)
		mouse_hook_shortcuts_multiobj(e, x);
	else if (y > ((WIN_Y - LENGTH) / 3) * 2 && y < WIN_Y - LENGTH)
		mouse_hook_shortcuts_divers(e, x);
}
