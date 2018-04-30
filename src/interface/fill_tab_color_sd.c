/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tab_color_sd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 08:11:33 by prossi            #+#    #+#             */
/*   Updated: 2018/03/15 08:20:17 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	fill_tab_color_sdssss(int **tab)
{
	tab[9][0] = 0x000066;
	tab[9][1] = 0x003366;
	tab[9][2] = 0x006666;
	tab[9][3] = 0x009966;
	tab[9][4] = 0x00CC66;
	tab[9][5] = 0x00FF66;
	tab[9][6] = 0x99FF66;
	tab[9][7] = 0x99CC66;
	tab[9][8] = 0x999966;
	tab[9][9] = 0x996666;
	tab[9][10] = 0x993366;
	tab[9][11] = 0x990066;
	tab[9][12] = 0xCC0066;
	tab[9][13] = 0xCC3366;
	tab[9][14] = 0xCC6666;
	tab[9][15] = 0xCC9966;
	tab[9][16] = 0xCCCC66;
	tab[9][17] = 0xCCFF66;
	fill_tab_color_td(tab);
}

void	fill_tab_color_sdsss(int **tab)
{
	tab[8][0] = 0x000099;
	tab[8][1] = 0x003399;
	tab[8][2] = 0x006699;
	tab[8][3] = 0x009999;
	tab[8][4] = 0x00CC99;
	tab[8][5] = 0x00FF99;
	tab[8][6] = 0x99FF99;
	tab[8][7] = 0x99CC99;
	tab[8][8] = 0x999999;
	tab[8][9] = 0x996699;
	tab[8][10] = 0x993399;
	tab[8][11] = 0x990099;
	tab[8][12] = 0xCC0099;
	tab[8][13] = 0xCC3399;
	tab[8][14] = 0xCC6699;
	tab[8][15] = 0xCC9999;
	tab[8][16] = 0xCCCC99;
	tab[8][17] = 0xCCFF99;
	fill_tab_color_sdssss(tab);
}

void	fill_tab_color_sdss(int **tab)
{
	tab[7][0] = 0x0000CC;
	tab[7][1] = 0x0033CC;
	tab[7][2] = 0x0066CC;
	tab[7][3] = 0x0099CC;
	tab[7][4] = 0x00CCCC;
	tab[7][5] = 0x00FFCC;
	tab[7][6] = 0x99FFCC;
	tab[7][7] = 0x99CCCC;
	tab[7][8] = 0x9999CC;
	tab[7][9] = 0x9966CC;
	tab[7][10] = 0x9933CC;
	tab[7][11] = 0x9900CC;
	tab[7][12] = 0xCC00CC;
	tab[7][13] = 0xCC33CC;
	tab[7][14] = 0xCC66CC;
	tab[7][15] = 0xCC99CC;
	tab[7][16] = 0xCCCCCC;
	tab[7][17] = 0xCCFFCC;
	fill_tab_color_sdsss(tab);
}

void	fill_tab_color_sds(int **tab)
{
	tab[6][0] = 0x0000FF;
	tab[6][1] = 0x0033FF;
	tab[6][2] = 0x0066FF;
	tab[6][3] = 0x0099FF;
	tab[6][4] = 0x00CCFF;
	tab[6][5] = 0x00FFFF;
	tab[6][6] = 0x99FFFF;
	tab[6][7] = 0x99CCFF;
	tab[6][8] = 0x9999FF;
	tab[6][9] = 0x9966FF;
	tab[6][10] = 0x9933FF;
	tab[6][11] = 0x9900FF;
	tab[6][12] = 0xCC00FF;
	tab[6][13] = 0xCC33FF;
	tab[6][14] = 0xCC66FF;
	tab[6][15] = 0xCC99FF;
	tab[6][16] = 0xCCCCFF;
	tab[6][17] = 0xCCFFFF;
	fill_tab_color_sdss(tab);
}

void	fill_tab_color_sd(int **tab)
{
	tab[5][0] = 0x3300FF;
	tab[5][1] = 0x3333FF;
	tab[5][2] = 0x3366FF;
	tab[5][3] = 0x3399FF;
	tab[5][4] = 0x33CCFF;
	tab[5][5] = 0x33FFFF;
	tab[5][6] = 0x66FFFF;
	tab[5][7] = 0x66CCFF;
	tab[5][8] = 0x6699FF;
	tab[5][9] = 0x6666FF;
	tab[5][10] = 0x6633FF;
	tab[5][11] = 0x6600FF;
	tab[5][12] = 0xFF00FF;
	tab[5][13] = 0xFF33FF;
	tab[5][14] = 0xFF66FF;
	tab[5][15] = 0xFF99FF;
	tab[5][16] = 0xFFCCFF;
	tab[5][17] = 0xFFFFFF;
	fill_tab_color_sds(tab);
}
