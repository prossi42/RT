/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin_tab_td.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <jgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 11:53:00 by jgaillar          #+#    #+#             */
/*   Updated: 2018/04/12 10:40:12 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	perlin_tab_thd(t_perlin *p)
{
	p->perm[287] = 72;
	p->perm[288] = 243;
	p->perm[289] = 141;
	p->perm[290] = 128;
	p->perm[291] = 195;
	p->perm[292] = 78;
	p->perm[293] = 66;
	p->perm[294] = 215;
	p->perm[295] = 61;
	p->perm[296] = 156;
	p->perm[297] = 180;
}

void	perlin_tab_twd(t_perlin *p)
{
	p->perm[264] = 13;
	p->perm[265] = 201;
	p->perm[266] = 95;
	p->perm[267] = 96;
	p->perm[268] = 53;
	p->perm[269] = 194;
	p->perm[270] = 233;
	p->perm[271] = 7;
	p->perm[272] = 225;
	p->perm[273] = 140;
	p->perm[274] = 127;
	p->perm[275] = 4;
	p->perm[276] = 150;
	p->perm[277] = 254;
	p->perm[278] = 138;
	p->perm[279] = 236;
	p->perm[280] = 205;
	p->perm[281] = 93;
	p->perm[282] = 222;
	p->perm[283] = 114;
	p->perm[284] = 67;
	p->perm[285] = 29;
	p->perm[286] = 24;
	perlin_tab_thd(p);
}

void	perlin_tab_eld(t_perlin *p)
{
	p->perm[240] = 222;
	p->perm[241] = 114;
	p->perm[242] = 67;
	p->perm[243] = 29;
	p->perm[244] = 24;
	p->perm[245] = 72;
	p->perm[246] = 243;
	p->perm[247] = 141;
	p->perm[248] = 128;
	p->perm[249] = 195;
	p->perm[250] = 78;
	p->perm[251] = 66;
	p->perm[252] = 215;
	p->perm[253] = 61;
	p->perm[255] = 156;
	p->perm[256] = 180;
	p->perm[257] = 151;
	p->perm[258] = 160;
	p->perm[259] = 137;
	p->perm[260] = 91;
	p->perm[261] = 90;
	p->perm[262] = 15;
	p->perm[263] = 131;
	perlin_tab_twd(p);
}

double	smooth_noise_3d_sd(t_perlin *p)
{
	p->g111 = fast_dot(get_grad(p->x1 + 1, p->y1 + 1, \
		p->z1 + 1, p), p->x - 1, p->y - 1, p->z - 1.);
	p->u = quintic_poly(p->x);
	p->v = quintic_poly(p->y);
	p->w = quintic_poly(p->z);
	p->x00 = linear_interpolate(p->g000, p->g100, p->u);
	p->x10 = linear_interpolate(p->g010, p->g110, p->u);
	p->x01 = linear_interpolate(p->g001, p->g101, p->u);
	p->x11 = linear_interpolate(p->g011, p->g111, p->u);
	p->xy0 = linear_interpolate(p->x00, p->x10, p->v);
	p->xy1 = linear_interpolate(p->x01, p->x11, p->v);
	p->xyz = linear_interpolate(p->xy0, p->xy1, p->w);
	return (p->xyz);
}

double	smooth_noise_3d(double x_pos, double y_pos, double z_pos, t_stuff *e)
{
	x_pos = fabs(x_pos) / e->i.perlin_stain;
	y_pos = fabs(y_pos) / e->i.perlin_stain;
	z_pos = fabs(z_pos) / e->i.perlin_stain;
	int_and_frac(x_pos, &e->p.x1, &e->p.x);
	int_and_frac(y_pos, &e->p.y1, &e->p.y);
	int_and_frac(z_pos, &e->p.z1, &e->p.z);
	e->p.x1 &= 255;
	e->p.y1 &= 255;
	e->p.z1 &= 255;
	e->p.g000 = fast_dot(get_grad(e->p.x1, e->p.y1, e->p.z1, \
		&e->p), e->p.x, e->p.y, e->p.z);
	e->p.g001 = fast_dot(get_grad(e->p.x1, e->p.y1, e->p.z1 + 1, &e->p), \
		e->p.x, e->p.y, e->p.z - 1);
	e->p.g010 = fast_dot(get_grad(e->p.x1, e->p.y1 + 1, e->p.z1, &e->p),\
		e->p.x, e->p.y - 1, e->p.z);
	e->p.g011 = fast_dot(get_grad(e->p.x1, e->p.y1 + 1, \
		e->p.z1 + 1, &e->p), e->p.x, e->p.y - 1, e->p.z - 1);
	e->p.g100 = fast_dot(get_grad(e->p.x1 + 1, e->p.y1, e->p.z1, &e->p), \
		e->p.x - 1, e->p.y, e->p.z);
	e->p.g101 = fast_dot(get_grad(e->p.x1 + 1, e->p.y1, e->p.z1 + 1, &e->p),\
		e->p.x - 1, e->p.y, e->p.z - 1);
	e->p.g110 = fast_dot(get_grad(e->p.x1 + 1, e->p.y1 + 1, e->p.z1, &e->p),\
		e->p.x - 1, e->p.y - 1, e->p.z);
	return (smooth_noise_3d_sd(&e->p));
}
