/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <jgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 16:35:58 by jgaillar          #+#    #+#             */
/*   Updated: 2018/04/13 15:25:46 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	tree_set(t_stuff *e, t_tree **tmp, int option)
{
	if (option == 1)
	{
		*tmp = e->tree;
		if (init_tree(&e->tree->left) == -1)
			exit(-1);
		e->tree = e->tree->left;
		e->tree->prev = *tmp;
	}
	else if (option == 2)
	{
		*tmp = e->tree;
		if (init_tree(&e->tree->right) == -1)
			exit(-1);
		e->tree = e->tree->right;
		e->tree->prev = *tmp;
	}
}

void	fill_tree(t_stuff *e, int option)
{
	if (option == 1)
	{
		e->tree->tmpcolor = e->c.colorf;
		e->tree->tmpl = e->l;
		e->tree->tmptest = e->test;
		e->tree->tmpinter = e->c.inter;
		e->tree->tmpscolor = e->d.color;
		e->tree->objet = e->c.obj;
		e->tree->conscol = e->d.scol;
		e->tree->refrac = e->d.refrac;
	}
	else if (option == 2)
	{
		e->c.colorf = e->tree->tmpcolor;
		e->l = e->tree->tmpl;
		e->test = e->tree->tmptest;
		e->c.inter = e->tree->tmpinter;
		e->d.color = e->tree->tmpscolor;
		e->c.obj = e->tree->objet;
		e->d.scol = e->tree->conscol;
		e->d.refrac = e->tree->refrac;
	}
}

int		init_tree(t_tree **tree)
{
	if (!(*tree = (t_tree *)malloc(sizeof(t_tree))))
		return (-1);
	(*tree)->prev = NULL;
	(*tree)->tmpinter.x = 0;
	(*tree)->tmpinter.y = 0;
	(*tree)->tmpinter.z = 0;
	(*tree)->tmpsph = NULL;
	(*tree)->tmpplan = NULL;
	(*tree)->tmpcyl = NULL;
	(*tree)->tmpcone = NULL;
	(*tree)->tmplight = NULL;
	init_rgb(&(*tree)->tmpcolor, 0, 0, 0);
	init_rgb(&(*tree)->tmpscolor, 0, 0, 0);
	(*tree)->tmpnm = 0;
	(*tree)->tmpl = 0;
	(*tree)->tmptest = 0;
	(*tree)->objet = 0;
	(*tree)->left = NULL;
	(*tree)->right = NULL;
	(*tree)->conscol = 0;
	(*tree)->refrac = 0;
	return (0);
}
