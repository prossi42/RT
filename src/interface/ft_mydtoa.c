/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mydtoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 22:36:39 by prossi            #+#    #+#             */
/*   Updated: 2018/04/09 12:24:06 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

char	*ifzero(char *str)
{
	str[0] = '0';
	str[1] = '.';
	str[2] = '0';
	str[3] = '0';
	return (str);
}

char	*betweenzerotonine(double nb, char *str, int i)
{
	if (i == 1)
		str[0] = '-';
	str[i] = '0' + (int)nb;
	str[++i] = '.';
	nb -= (int)nb;
	nb *= 10;
	str[++i] = '0' + (int)nb;
	nb -= (int)nb;
	nb *= 10;
	str[++i] = '0' + (int)nb;
	return (str);
}

char	*my_itoa(int nb, char *str, int i)
{
	int		len;

	len = ft_lenint(nb);
	if (i == 1)
		len++;
	while (len > 0)
	{
		str[len - 1] = '0' + nb % 10;
		nb /= 10;
		len--;
	}
	if (i == 1)
		str[0] = '-';
	return (str);
}

char	*other_value(double nb, char *str, int i)
{
	str = my_itoa((int)nb, str, i);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	str[i] = '.';
	nb -= (int)nb;
	nb *= 10;
	str[++i] = '0' + (int)nb;
	nb -= (int)nb;
	nb *= 10;
	str[++i] = '0' + (int)nb;
	return (str);
}

char	*ft_mydtoa(double nb, char *str)
{
	int		i;

	if (nb < 0)
	{
		i = 1;
		nb *= -1;
	}
	else
		i = 0;
	if (nb == 0)
		return (str = ifzero(str));
	else if (nb > 0 && nb < 10)
		return (str = betweenzerotonine(nb, str, i));
	else
		return (str = other_value(nb, str, i));
	return (str);
}
