/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnormcor <...@student.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 14:58:08 by wnormcor          #+#    #+#             */
/*   Updated: 2020/07/12 08:43:51 by wnormcor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str, int len)
{
	int	i;

	i = 0;
	while (str[i] && i < len)
		ft_putchar(str[i++]);
	return (i);
}

int	ft_fill_width(int width, int fact_len, int zero_fill)
{
	int	i;

	i = 0;
	while (width - fact_len > 0)
	{
		if (zero_fill)
			ft_putchar('0');
		else
			ft_putchar(' ');
		width--;
		i++;
	}
	return (i);
}
