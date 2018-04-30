/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_interface.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 10:42:02 by prossi            #+#    #+#             */
/*   Updated: 2018/03/21 14:51:32 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	exit_interface(t_stuff *e)
{
	freetabint(e->i.color.tab, 12);
	freetabint(e->i.color.tabxd, 12);
	freetabint(e->i.color.tabxf, 12);
	freetabint(e->i.color.tabyd, 12);
	freetabint(e->i.color.tabyf, 12);
}
