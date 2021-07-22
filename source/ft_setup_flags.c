/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnormcor <...@student.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 19:05:59 by wnormcor          #+#    #+#             */
/*   Updated: 2020/07/12 16:37:40 by wnormcor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

t_flags	ft_flag_left_adj(t_flags flags)
{
	flags.left_adj = 1;
	flags.zero_fill = 0;
	return (flags);
}

t_flags	ft_flag_width(t_flags flags, va_list av)
{
	flags.star = 1;
	flags.width = va_arg(av, int);
	if (flags.width < 0)
	{
		flags.left_adj = 1;
		flags.width *= -1;
	}
	return (flags);
}

int		ft_flag_dot(const char *s, int i, t_flags *flags, va_list av)
{
	if (s[++i] == '*')
	{
		flags->dot = va_arg(av, int);
		i++;
	}
	else
	{
		flags->dot = 0;
		while (ft_isdigit(s[i]))
			flags->dot = (flags->dot * 10) + (s[i++] - 48);
	}
	return (i);
}

t_flags	ft_flag_digit(char c, t_flags flags)
{
	if (flags.star == 1)
		flags.width = 0;
	flags.width = (flags.width * 10) + (c - 48);
	return (flags);
}
