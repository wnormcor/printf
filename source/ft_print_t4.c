/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_t4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnormcor <...@student.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 19:06:15 by wnormcor          #+#    #+#             */
/*   Updated: 2020/07/12 09:54:37 by wnormcor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_fill_u(char *nbr_str, t_flags flags, size_t len)
{
	int	done;

	done = 0;
	if (flags.dot >= 0)
		done += ft_fill_width(flags.dot - 1, len - 1, 1);
	done += ft_putstr(nbr_str, len);
	return (done);
}

static int	ft_put_u(char *nbr_str, t_flags flags)
{
	const size_t	len = ft_strlen(nbr_str);
	int				done;

	done = 0;
	if (flags.left_adj == 1)
		done += ft_fill_u(nbr_str, flags, len);
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
		done += ft_fill_u(nbr_str, flags, len);
	return (done);
}

int			ft_print_u(unsigned int nbr, t_flags flags)
{
	char	*nbr_str;
	int		done;

	done = 0;
	if (flags.dot == 0 && nbr == 0)
	{
		done += ft_fill_width(flags.width, 0, 0);
		return (done);
	}
	nbr_str = ft_itoa_base(nbr, 10);
	done += ft_put_u(nbr_str, flags);
	free(nbr_str);
	return (done);
}
