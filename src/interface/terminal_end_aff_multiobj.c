/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_end_aff_multiobj.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 15:56:33 by prossi            #+#    #+#             */
/*   Updated: 2018/04/16 15:56:42 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	end_aff_multiobj(t_stuff *e)
{
	if (e->i.multi != 0)
		end_aff_multiobj_cubesphere(e);
}
