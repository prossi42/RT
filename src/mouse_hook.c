/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <jgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 16:14:48 by jgaillar          #+#    #+#             */
/*   Updated: 2018/02/12 10:15:16 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_rgb		getlightdebug(t_vec *norm, t_light **light, t_rgb *colorobj, t_stuff *e)
{
	t_rgb	rgb;
	double	angle;

	rgb.r = 0;
	rgb.g = 0;
	rgb.b = 0;
	angle = ((*light)->ray > 0.00001 ? (dot_product(norm, &(*light)->lightdir)) \
		: 0);
	if (e->ray == 1)
		ft_putendl("wsh alors");
	if ((*light)->ray > 0.00001 && angle > 0.00001)
	{
		e->test++;
		if (e->l == 1)
		{
			rgb.r = colorobj->r * (*light)->amb;
			rgb.g = colorobj->g * (*light)->amb;
			rgb.b = colorobj->b * (*light)->amb;
		}
		rgb.r += ((*light)->color.r * (*light)->diff) * angle;
		rgb.g += ((*light)->color.g * (*light)->diff) * angle;
		rgb.b += ((*light)->color.b * (*light)->diff) * angle;
		getspeclight(e, norm, &rgb, light);
		return (rgb);
	}
	if (e->l == 1)
		rgb_add(&rgb, rgb, (*colorobj), (*light)->amb);
	return (rgb);
}

t_rgb		reflectdebug(t_stuff *e, int obj, int nm)
{
	t_vec tmp;
	t_rgb tmp2;

	reboot_list_loop(e, 3);
	e->ref.tmpcolor = e->c.colorf;
	e->ref.tmpl = e->l;
	e->ref.tmpinter = e->c.inter;
	e->ref.tmpobj = e->c.obj;
	ft_putendl("ref");
	if (obj == SPHERE)
	{
		ft_putendl("SPHERE");
		searchlist(e, e->c.objsph, SPHERE);
		e->ref.tmpsph = e->sph;
		tmp = getrefray(e, &e->sph->norm, &e->poscam, &e->c.inter);
		reboot_list_loop(e, 3);
		tmp2 = raythingydebug(e, &tmp, &e->c.inter);
		e->sph = e->ref.tmpsph;
	}
	else if (obj == PLAN)
	{
		ft_putendl("PLAN");
		searchlist(e, e->c.objpla, PLAN);
		e->ref.tmpplan = e->pla;
		tmp = getrefray(e, &e->pla->norm, &e->poscam, &e->c.inter);
		reboot_list_loop(e, 3);
		tmp2 = raythingydebug(e, &tmp, &e->c.inter);
		e->pla = e->ref.tmpplan;
	}
	else if (obj == CYLINDRE)
	{
		ft_putendl("CYLINDRE");
		searchlist(e, e->c.objcyl, CYLINDRE);
		vecsous(&e->cyl->norml, &e->c.inter, &e->cyl->pos);
		vecnorm(&e->cyl->norml);
		e->cyl->norml.z = 0;
		e->ref.tmpcyl = e->cyl;
		tmp = getrefray(e, &e->cyl->norm, &e->poscam, &e->c.inter);
		reboot_list_loop(e, 3);
		tmp2 = raythingydebug(e, &tmp, &e->c.inter);
		e->cyl = e->ref.tmpcyl;
	}
	else if (obj == CONE)
	{
		ft_putendl("CONE");
		searchlist(e, e->c.objcone, CONE);
		vecsous(&e->cone->norml, &e->c.inter, &e->cone->pos);
		vecnorm(&e->cone->norml);
		e->cone->norml.z = 0;
		e->ref.tmpcone = e->cone;
		tmp = getrefray(e, &e->cone->norm, &e->poscam, &e->c.inter);
		reboot_list_loop(e, 3);
		tmp2 = raythingydebug(e, &tmp, &e->c.inter);
		e->cone = e->ref.tmpcone;
	}
	printf("tmpr : [%d] | tmpg : [%d] | tmpb : [%d]\n", tmp2.r, tmp2.g, tmp2.b);
	e->c.colorf = e->ref.tmpcolor;
	e->l = e->ref.tmpl;
	e->c.inter = e->ref.tmpinter;
	e->c.obj = e->ref.tmpobj;
	return (tmp2);
}

double		shadowsdebug(t_stuff *e, t_vec *inter, t_rgb color)
{
	t_rgb caca;

	caca.r = 0;
	caca.g = 0;
	caca.b = 0;

	reboot_list_loop(e, 2);
	while (e->light)
	{
		reboot_list_loop(e, 1);
		getlightdir(e, e->c.inter);
		checkdebug(e, &e->light->lightdir, &e->c.inter, 2);
		check_distdebug(e, 2);
		if (e->c.dist < e->light->t && e->c.dist > 0.00001 && e->c.obj != LIGHT)
			rgb_add(&e->c.colorf, caca, color, 0.8);
		e->light = e->light->next;
	}
	return (0);
}

void		check_distdebug(t_stuff *e, int option)
{
	if (e->c.distsph < e->c.dist && e->c.distsph > 0.00001)
	{
		if (option == 1)
		{
			e->c.obj = (e->c.distsph < e->c.dist ? SPHERE : -1);
			e->d.color.r = e->d.colsph.r;
			e->d.color.g = e->d.colsph.g;
			e->d.color.b = e->d.colsph.b;
		}
		e->c.dist = e->c.distsph;
	}
	if (e->c.distpla < e->c.dist && e->c.distpla > 0.00001)
	{
		if (option == 1)
		{
			e->c.obj = (e->c.distpla < e->c.dist ? PLAN : e->c.obj);
			e->d.color.r = e->d.colpla.r;
			e->d.color.g = e->d.colpla.g;
			e->d.color.b = e->d.colpla.b;
		}
		e->c.dist = e->c.distpla;
	}
	if (e->c.distcyl < e->c.dist && e->c.distcyl > 0.00001)
	{
		if (option == 1)
		{
			e->c.obj = (e->c.distcyl < e->c.dist ? CYLINDRE : e->c.obj);
			e->d.color.r = e->d.colcyl.r;
			e->d.color.g = e->d.colcyl.g;
			e->d.color.b = e->d.colcyl.b;
		}
		e->c.dist = e->c.distcyl;
	}
	if (e->c.distcone < e->c.dist && e->c.distcone > 0.00001)
	{
		if (option == 1)
		{
			e->c.obj = (e->c.distcone < e->c.dist ? CONE : e->c.obj);
			e->d.color.r = e->d.colcone.r;
			e->d.color.g = e->d.colcone.g;
			e->d.color.g = e->d.colcone.b;
		}
		e->c.dist = e->c.distcone;
	}
	if (e->c.distlight < e->c.dist && e->c.distlight > 0.00001 && option == 1)
	{
		e->c.obj = (e->c.distlight < e->c.dist ? LIGHT : e->c.obj);
		e->c.dist = e->c.distlight;
	}
}

void		checkdebug(t_stuff *e, t_vec *raydir, t_vec *pos, int option)
{
	e->c.dist = INFINITY;
	e->c.distsph = INFINITY;
	e->c.distpla = INFINITY;
	e->c.distcyl = INFINITY;
	e->c.distcone = INFINITY;
	e->c.distlight = INFINITY;
	if (option == 1)
		e->c.obj = -1;
	while (e->sph)
	{
		checksphere(e->sph, raydir, pos);
		if (e->sph->t < e->c.distsph && e->sph->t > 0.00001)
		{
			e->c.distsph = e->sph->t;
			if (option == 1)
			{
				e->c.objsph = e->sph->nm;
				e->c.obj = SPHERE;
				e->d.colsph.r = e->sph->color.r;
				e->d.colsph.g = e->sph->color.g;
				e->d.colsph.b = e->sph->color.b;
			}
		}
		e->sph = e->sph->next;
	}
	while (e->pla)
	{
		checkplan(e->pla, raydir, pos);
		if (e->pla->t < e->c.distpla && e->pla->t > 0.00001)
		{
			e->c.distpla = e->pla->t;
			if (option == 1)
			{
				e->c.objpla = e->pla->nm;
				e->c.obj = PLAN;
				e->d.colpla.r = e->pla->color.r;
				e->d.colpla.g = e->pla->color.g;
				e->d.colpla.b = e->pla->color.b;
			}
		}
		e->pla = e->pla->next;
	}
	while (e->cyl)
	{
		checkcyl(e->cyl, raydir, pos);
		if (e->cyl->t < e->c.distcyl && e->cyl->t > 0.00001)
		{
			e->c.distcyl = e->cyl->t;
			if (option == 1)
			{
				e->c.objcyl = e->cyl->nm;
				e->c.obj = CYLINDRE;
				e->d.colcyl.r = e->cyl->color.r;
				e->d.colcyl.g = e->cyl->color.g;
				e->d.colcyl.b = e->cyl->color.b;
			}
		}
		e->cyl = e->cyl->next;
	}
	while (e->cone)
	{
		checkcone(e->cone, raydir, pos);
		if (e->cone->t < e->c.distcone && e->cone->t > 0.00001)
		{
			e->c.distcone = e->cone->t;
			if (option == 1)
			{
				e->c.objcone = e->cone->nm;
				e->c.obj = CONE;
				e->d.colcone.r = e->cone->color.r;
				e->d.colcone.g = e->cone->color.g;
				e->d.colcone.b = e->cone->color.b;
			}
		}
		e->cone = e->cone->next;
	}
	while (e->light && option == 1)
	{
		checklight(e->light, raydir, pos);
		if (e->light->t < e->c.distlight && e->light->t > 0.00001)
		{
			e->c.distlight = e->light->t;
			e->c.objlight = e->light->nm;
			e->c.obj = LIGHT;
		}
		e->light = e->light->next;
	}
}

t_rgb		raythingydebug(t_stuff *e, t_vec *raydir, t_vec *pos)
{
	t_rgb	tmp2;
	e->l = 0;
	e->ray++;
	e->test = 0;
	e->c.colorf.r = 0;
	e->c.colorf.g = 0;
	e->c.colorf.b = 0;
	checkdebug(e, raydir, pos, 1);
	check_distdebug(e, 1);
	reboot_list_loop(e, 3);
	ft_putstr("ray : ");
	ft_putnbr(e->ray);
	ft_putchar('\n');
	if (e->c.obj >= 0 && e->c.obj <= 3)
	{
		getintersection(e, e->c.dist);
		while (e->light)
		{
			getlightdir(e, e->c.inter);
			reboot_list_loop(e, 1);
			checkdebug(e, &e->light->lightdir, &e->c.inter, 2);
			check_distdebug(e, 2);
			checklight(e->light, &e->light->lightdir, &e->c.inter);
			reboot_list_loop(e, 1);
			if (e->c.dist > e->light->t && e->c.dist > 0.00001 && e->light->t > 0.00001)
			{
				e->l++;
				if (e->c.obj == SPHERE)
				{
					if (e->ray == 1)
						ft_putendl("fdp");
					searchlist(e, e->c.objsph, SPHERE);
					vecsous(&e->sph->norm, &e->c.inter, &e->sph->pos);
					vecnorm(&e->sph->norm);
					rgb_add(&e->c.colorf, e->c.colorf, \
						getlightdebug(&e->sph->norm, &e->light, &e->sph->color, e), 1);
				}
				else if (e->c.obj == PLAN)
				{
					if (e->ray == 1)
						ft_putendl("ntm");
					searchlist(e, e->c.objpla, PLAN);
					if (dot_product(&e->raydir, &e->pla->norm) < 0)
						rgb_add(&e->c.colorf, e->c.colorf, \
							getlightdebug(&e->pla->norm, &e->light, &e->pla->color, e), 1);
					else
					{
						e->pla->norml.x = e->pla->norm.x * -1;
						e->pla->norml.y = e->pla->norm.y * -1;
						e->pla->norml.z = e->pla->norm.z * -1;
						rgb_add(&e->c.colorf, e->c.colorf, \
							getlightdebug(&e->pla->norml, &e->light, &e->pla->color, e), 1);
					}
				}
				else if (e->c.obj == CYLINDRE)
				{
					if (e->ray == 1)
						ft_putendl("ntr");
					searchlist(e, e->c.objcyl, CYLINDRE);
					vecsous(&e->cyl->norml, &e->c.inter, &e->cyl->pos);
					vecnorm(&e->cyl->norml);
					e->cyl->norml.z = 0;
					vecnorm(&e->cyl->norml);
					rgb_add(&e->c.colorf, e->c.colorf, \
							getlightdebug(&e->cyl->norml, &e->light, &e->cyl->color, e), 1);
				}
				else if (e->c.obj == CONE)
				{
					if (e->ray == 1)
						ft_putendl("pipi");
					searchlist(e, e->c.objcone, CONE);
					vecsous(&e->cone->norml, &e->c.inter, &e->cone->pos);
					vecnorm(&e->cone->norml);
					e->cone->norml.z = 0;
					vecnorm(&e->cone->norml);
					rgb_add(&e->c.colorf, e->c.colorf,\
					 	getlightdebug(&e->cone->norml, &e->light, &e->cone->color, e), 1);
			 	}
			}
			e->light = e->light->next;
		}
		if (e->l > 0)
		 	shadowsdebug(e, &e->c.inter, e->c.colorf);
		else
		{
			e->d.color.r *= 0.1;
			e->d.color.g *= 0.1;
			e->d.color.b *= 0.1;
			shadowsdebug(e, &e->c.inter, e->d.color);
		}
		if (e->ray == 0)
			printf("beforerefr : [%d] | beforerefg : [%d] | beforerefb : [%d]\n", e->c.colorf.r, e->c.colorf.g, e->c.colorf.b);
		if (e->ray < 1 && e->test > 0)
		{
			if (e->c.obj == SPHERE)
				rgb_add(&e->c.colorf, e->c.colorf, reflectdebug(e, SPHERE, e->c.objsph), 0.1);
			else if (e->c.obj == PLAN)
				rgb_add(&e->c.colorf, e->c.colorf, reflectdebug(e, PLAN, e->c.objpla), 1);
			else if (e->c.obj == CYLINDRE)
				rgb_add(&e->c.colorf, e->c.colorf, reflectdebug(e, CYLINDRE, e->c.objcyl), 0.1);
			else if (e->c.obj == CONE)
				rgb_add(&e->c.colorf, e->c.colorf, reflectdebug(e, CONE, e->c.objcone), 0.1);
			ft_putendl("ref");
		}
		ft_putendl("end ref");
		printf("afterrefr : [%d] | afterrefg : [%d] | afterrefb : [%d]\n", e->c.colorf.r, e->c.colorf.g, e->c.colorf.b);
	}
	else if (e->c.obj == LIGHT)
	{
		searchlist(e, e->c.objlight, LIGHT);
		rgb_add(&e->c.colorf, e->c.colorf, e->light->color, e->light->diff);
	}
	return (e->c.colorf);
}

int		mouse_hook(int button, int x, int y, t_stuff *e)
{
	double color;

	if (button == 1 && (x >= (WIN_X - WIDTH) && x <= WIN_X) && (y >= (WIN_Y - LENGTH) && y <= WIN_Y))
	{
		mlx_put_image_to_window(e->img.mlx_ptr, e->img.win_ptr, e->img.img_ptr, WIN_X - WIDTH, WIN_Y - LENGTH);
		reboot_list_loop(e, 3);
		raydir(e, x - (WIN_X - WIDTH), y - (WIN_Y - LENGTH));
		check(e, &e->raydir, &e->poscam, 1);
		check_dist(e, 1);
		if (e->c.obj == 0)
		{
			color = 0x6a74af;
			ft_putstr("SPHERE : ");
			ft_putnbr(e->c.objsph);
			e->i.each_obj = e->c.objsph;
			ft_putchar('\n');
		}
		else if (e->c.obj == 1)
		{
			color = 0xf3a1d1;
			ft_putstr("PLAN : ");
			ft_putnbr(e->c.objpla);
			e->i.each_obj = e->c.objpla;
			ft_putchar('\n');
		}
		else if (e->c.obj == 2)
		{
			color = 0xff5370;
			ft_putstr("CYLINDRE : ");
			ft_putnbr(e->c.objcyl);
			e->i.each_obj = e->c.objcyl;
			ft_putchar('\n');
		}
		else if (e->c.obj == 3)
		{
			color = 0x73d1c8;
			ft_putstr("CONE : ");
			ft_putnbr(e->c.objcone);
			e->i.each_obj = e->c.objcone;
			ft_putchar('\n');
		}
		else if (e->c.obj == 4)
		{
			color = 0xff9966;
			ft_putstr("LIGHT : ");
			ft_putnbr(e->c.objlight);
			e->i.each_obj = e->c.objlight;
			ft_putchar('\n');
		}
		if (e->c.obj > -1)
			ft_segment(e, x, y, color);
		e->i.objet = e->c.obj;
		objet_courant(e);
		apercu_courant(e);
	}
	else if (button == 1 && ((x > 0 && x <= WIN_X && y > 0 && y < WIN_Y - LENGTH) || (x > 0 && x < WIN_X - WIDTH && y > 0 && y < WIN_Y)))
	{
		mouse_hook_interface(e, x, y);
	}
	else if (button == 2 && (x >= (WIN_X - WIDTH) && x <= WIN_X) && (y >= (WIN_Y - LENGTH) && y <= WIN_Y))
	{
		reboot_list_loop(e, 3);
		raydir(e, x - (WIN_X - WIDTH), y - (WIN_Y - LENGTH));
		e->ray = -1;
		raythingydebug(e, &e->raydir, &e->poscam);
		ft_putchar('\n');
	}
	return (0);
}
