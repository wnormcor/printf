/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_t5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnormcor <...@student.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 00:37:41 by wnormcor          #+#    #+#             */
/*   Updated: 2020/07/12 09:23:51 by wnormcor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_fill_x(char *x, t_flags flags, size_t len)
{
	int	done;

	done = 0;
	if (flags.dot >= 0)
		done += ft_fill_width(flags.dot - 1, len - 1, 1);
	done += ft_putstr(x, len);
	return (done);
}

static int	ft_put_x(char *x, t_flags flags)
{
	int				done;
	const size_t	len = ft_strlen(x);

	done = 0;
	if (flags.left_adj == 1)
		done += ft_fill_x(x, flags, len);
	if (flags.dot >= 0 && (size_t)flags.dot < len)
		flags.dot = len;
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		done += ft_fill_width(flags.width, 0, 0);
	}
	else
		done += ft_fill_width(flags.width, len, flags.zero_fill);
	if (flags.left_adj == 0)
		done += ft_fill_x(x, flags, len);
	return (done);
}

int			ft_print_x(unsigned int nbr, int lower, t_flags flags)
{
	int		done;
	char	*x;

	done = 0;
	if (flags.dot == 0 && nbr == 0)
	{
		done += ft_fill_width(flags.width, 0, 0);
		return (done);
	}
	x = ft_itoa_base((unsigned long long)nbr, 16);
	if (lower == 1)
		x = ft_s_tolower(x);
	done += ft_put_x(x, flags);
	free(x);
	return (done);
}

int			ft_print_prc(t_flags flags)
{
	int	done;

	done = 0;
	if (flags.left_adj == 1)
		ft_putchar('%');
	done = ft_fill_width(flags.width, 1, flags.zero_fill);
	if (flags.left_adj == 0)
		ft_putchar('%');
	return (done + 1);
}
