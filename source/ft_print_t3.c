/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_t3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnormcor <...@student.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 19:06:03 by wnormcor          #+#    #+#             */
/*   Updated: 2020/07/13 22:35:06 by wnormcor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_fill_d(char *nbr_str, int tmp, t_flags flags, size_t len)
{
	int		done;

	done = 0;
	if (tmp < 0 && flags.dot >= 0)
		ft_putchar('-');
	if (flags.dot >= 0)
		done += ft_fill_width(flags.dot - 1, len - 1, 1);
	done += ft_putstr(nbr_str, len);
	return (done);
}

static int	ft_put_d(char *nbr_str, int tmp, t_flags flags)
{
	const size_t	len = ft_strlen(nbr_str);
	int				done;

	done = 0;
	if (flags.left_adj == 1)
		done += ft_fill_d(nbr_str, tmp, flags, len);
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
		done += ft_fill_d(nbr_str, tmp, flags, len);
	return (done);
}

static void	check_zero(t_flags *flags)
{
	if (flags->zero_fill == 1 && flags->dot == -1)
		ft_putchar('-');
	flags->zero_fill = 1;
	flags->width--;
}

int			ft_print_d(int nbr, t_flags flags)
{
	char	*nbr_str;
	int		tmp;
	int		done;
	long	nbl;

	done = 0;
	tmp = nbr;
	nbl = 0;
	if (flags.dot == 0 && nbr == 0)
		return (ft_fill_width(flags.width, 0, 0));
	if (nbr < 0 && (flags.dot >= 0 || flags.zero_fill == 1))
	{
		check_zero(&flags);
		nbr *= -1;
		nbr == -2147483648 ? nbl = 2147483648 : nbr;
		done++;
	}
	if (nbl)
		nbr_str = ft_itoa_base(nbl, 10);
	else
		nbr_str = ft_itoa(nbr);
	done += ft_put_d(nbr_str, tmp, flags);
	free(nbr_str);
	return (done);
}
