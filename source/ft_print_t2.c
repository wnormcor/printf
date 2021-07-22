/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_t2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnormcor <...@student.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 19:06:01 by wnormcor          #+#    #+#             */
/*   Updated: 2020/07/12 09:25:55 by wnormcor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char		*ft_itoa_base(unsigned long long nbr, int base)
{
	size_t				len;
	unsigned long long	tmp;
	char				*str;

	len = 0;
	tmp = nbr;
	if (nbr == 0)
		return (ft_strdup("0"));
	while (tmp != 0)
	{
		tmp /= base;
		len++;
	}
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	while (nbr != 0)
	{
		str[len - 1] = (nbr % base) + (nbr % base > 9 ? '7' : '0');
		nbr /= base;
		len--;
	}
	return (str);
}

char		*ft_s_tolower(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		str[i] = ft_tolower(str[i]);
	return (str);
}

static int	ft_fill_p(char *str, t_flags flags, size_t len)
{
	int		done;

	done = 0;
	done += ft_putstr("0x", 2);
	if (flags.dot >= 0)
	{
		done += ft_fill_width(flags.dot, len, 1);
		done += ft_putstr(str, flags.dot);
	}
	else
		done += ft_putstr(str, len);
	return (done);
}

int			ft_print_p(unsigned long long nbr, t_flags flags)
{
	int		done;
	size_t	len;
	char	*str;

	done = 0;
	if (nbr == 0 && flags.dot == 0)
	{
		done += ft_putstr("0x", 2);
		return (done += ft_fill_width(flags.width, 0, 1));
	}
	if (nbr == 0 && flags.dot >= 0)
		flags.width -= 1;
	str = ft_itoa_base(nbr, 16);
	str = ft_s_tolower(str);
	len = ft_strlen(str);
	if ((size_t)flags.dot < len)
		flags.dot = len;
	if (flags.left_adj == 1)
		done += ft_fill_p(str, flags, len);
	done += ft_fill_width(flags.width, len + 2, 0);
	if (flags.left_adj == 0)
		done += ft_fill_p(str, flags, len);
	free(str);
	return (done);
}
