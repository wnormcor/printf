/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_t1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnormcor <...@student.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 00:15:16 by wnormcor          #+#    #+#             */
/*   Updated: 2020/07/13 20:23:59 by wnormcor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int			ft_print_c(char c, t_flags flags)
{
	int	done;

	done = 0;
	if (flags.left_adj == 1)
		ft_putchar(c);
	done = ft_fill_width(flags.width, 1, 0);
	if (flags.left_adj == 0)
		ft_putchar(c);
	return (done + 1);
}

static int	ft_fill_s(char *s, t_flags flags, size_t len)
{
	int	done;

	done = 0;
	if (flags.dot >= 0)
	{
		done += ft_fill_width(flags.dot, len, 0);
		done += ft_putstr(s, flags.dot);
	}
	else
		done += ft_putstr(s, len);
	return (done);
}

int			ft_print_s(char *s, t_flags flags)
{
	int		done;
	char	*s_sub;
	size_t	len;

	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	if ((s_sub = ft_substr(s, 0, len)) == NULL)
		return (-1);
	if (flags.dot >= 0 && (size_t)flags.dot > len)
		flags.dot = len;
	done = 0;
	if (flags.left_adj == 1)
		done += ft_fill_s(s_sub, flags, len);
	if (flags.dot >= 0)
		done += ft_fill_width(flags.width, flags.dot, 0);
	else
		done += ft_fill_width(flags.width, len, 0);
	if (flags.left_adj == 0)
		done += ft_fill_s(s_sub, flags, len);
	free(s_sub);
	return (done);
}
