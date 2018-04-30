/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tab_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 08:05:23 by prossi            #+#    #+#             */
/*   Updated: 2018/03/15 08:19:18 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	fill_tab_colorssss(int **tab)
{
	tab[4][0] = 0x3300CC;
	tab[4][1] = 0x3333CC;
	tab[4][2] = 0x3366CC;
	tab[4][3] = 0x3399CC;
	tab[4][4] = 0x33CCCC;
	tab[4][5] = 0x33FFCC;
	tab[4][6] = 0x66FFCC;
	tab[4][7] = 0x66CCCC;
	tab[4][8] = 0x6699CC;
	tab[4][9] = 0x6666CC;
	tab[4][10] = 0x6633CC;
	tab[4][11] = 0x6600CC;
	tab[4][12] = 0xFF00CC;
	tab[4][13] = 0xFF33CC;
	tab[4][14] = 0xFF66CC;
	tab[4][15] = 0xFF99CC;
	tab[4][16] = 0xFFCCCC;
	tab[4][17] = 0xFFFFCC;
	fill_tab_color_sd(tab);
}

void	fill_tab_colorsss(int **tab)
{
	tab[3][0] = 0x330099;
	tab[3][1] = 0x333399;
	tab[3][2] = 0x336699;
	tab[3][3] = 0x339999;
	tab[3][4] = 0x33CC99;
	tab[3][5] = 0x33FF99;
	tab[3][6] = 0x66FF99;
	tab[3][7] = 0x66CC99;
	tab[3][8] = 0x669999;
	tab[3][9] = 0x666699;
	tab[3][10] = 0x663399;
	tab[3][11] = 0x660099;
	tab[3][12] = 0xFF0099;
	tab[3][13] = 0xFF3399;
	tab[3][14] = 0xFF6699;
	tab[3][15] = 0xFF9999;
	tab[3][16] = 0xFFCC99;
	tab[3][17] = 0xFFFF99;
	fill_tab_colorssss(tab);
}

void	fill_tab_colorss(int **tab)
{
	tab[2][0] = 0x330066;
	tab[2][1] = 0x333366;
	tab[2][2] = 0x336666;
	tab[2][3] = 0x339966;
	tab[2][4] = 0x33CC66;
	tab[2][5] = 0x33FF66;
	tab[2][6] = 0x66FF66;
	tab[2][7] = 0x66CC66;
	tab[2][8] = 0x669966;
	tab[2][9] = 0x666666;
	tab[2][10] = 0x663366;
	tab[2][11] = 0x660066;
	tab[2][12] = 0xFF0066;
	tab[2][13] = 0xFF3366;
	tab[2][14] = 0xFF6666;
	tab[2][15] = 0xFF9966;
	tab[2][16] = 0xFFCC66;
	tab[2][17] = 0xFFFF66;
	fill_tab_colorsss(tab);
}

void	fill_tab_colors(int **tab)
{
	tab[1][0] = 0x330033;
	tab[1][1] = 0x333333;
	tab[1][2] = 0x336633;
	tab[1][3] = 0x339933;
	tab[1][4] = 0x33CC33;
	tab[1][5] = 0x33FF33;
	tab[1][6] = 0x66FF33;
	tab[1][7] = 0x66CC33;
	tab[1][8] = 0x669933;
	tab[1][9] = 0x666633;
	tab[1][10] = 0x663333;
	tab[1][11] = 0x660033;
	tab[1][12] = 0xFF0033;
	tab[1][13] = 0xFF3333;
	tab[1][14] = 0xFF6633;
	tab[1][15] = 0xFF9933;
	tab[1][16] = 0xFFCC33;
	tab[1][17] = 0xFFFF33;
	fill_tab_colorss(tab);
}

void	fill_tab_color(int **tab)
{
	tab[0][0] = 0x330000;
	tab[0][1] = 0x333300;
	tab[0][2] = 0x336600;
	tab[0][3] = 0x339900;
	tab[0][4] = 0x33CC00;
	tab[0][5] = 0x33FF00;
	tab[0][6] = 0x66FF00;
	tab[0][7] = 0x66CC00;
	tab[0][8] = 0x669900;
	tab[0][9] = 0x666600;
	tab[0][10] = 0x663300;
	tab[0][11] = 0x660000;
	tab[0][12] = 0xFF0000;
	tab[0][13] = 0xFF3300;
	tab[0][14] = 0xFF6600;
	tab[0][15] = 0xFF9900;
	tab[0][16] = 0xFFCC00;
	tab[0][17] = 0xFFFF00;
	fill_tab_colors(tab);
}
