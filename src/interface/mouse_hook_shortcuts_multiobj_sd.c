/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook_shortcuts_multiobj_sd.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:19:53 by prossi            #+#    #+#             */
/*   Updated: 2018/04/23 10:19:55 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	mouse_hook_shortcuts_multiobj_sh(t_stuff *e)
{
	if (e->i.wave == 0)
	{
		e->i.wave = 1;
		multi_thread(e);
		apercu_courant(e);
	}
	else
	{
		e->i.wave = 0;
		multi_thread(e);
		apercu_courant(e);
	}
}
