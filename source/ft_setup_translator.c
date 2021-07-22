/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup_translator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnormcor <...@student.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 15:19:26 by wnormcor          #+#    #+#             */
/*   Updated: 2020/07/13 20:27:21 by wnormcor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

t_flags	ft_init_flags(void)
{
	t_flags		flags;

	flags.type = 0;
	flags.left_adj = 0;
	flags.zero_fill = 0;
	flags.width = 0;
	flags.star = 0;
	flags.dot = -1;
	return (flags);
}

int		ft_type(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
			|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

int		ft_read_flags(const char *s, int i, t_flags *flags, va_list av)
{
	while (s[i])
	{
		if (!ft_isdigit(s[i]) && !ft_type(s[i]) && (s[i] != '-')
			&& (s[i] != '0') && (s[i] != '.') && (s[i] != '*'))
			break ;
		if (s[i] == '-')
			*flags = ft_flag_left_adj(*flags);
		if (s[i] == '0' && flags->width == 0 && flags->left_adj == 0)
			flags->zero_fill = 1;
		if (s[i] == '.')
			i = ft_flag_dot(s, i, flags, av);
		if (s[i] == '*')
			*flags = ft_flag_width(*flags, av);
		if (ft_isdigit(s[i]))
			*flags = ft_flag_digit(s[i], *flags);
		if (ft_type(s[i]))
		{
			flags->type = s[i];
			break ;
		}
		i++;
	}
	return (i);
}

int		ft_translator(int c, t_flags flags, va_list av)
{
	int	done;

	done = 0;
	if (c == 'c')
		done += ft_print_c(va_arg(av, int), flags);
	else if (c == 's')
		done += ft_print_s(va_arg(av, char *), flags);
	else if (c == 'p')
		done += ft_print_p(va_arg(av, unsigned long long), flags);
	else if (c == 'd' || c == 'i')
		done += ft_print_d(va_arg(av, int), flags);
	else if (c == 'u')
		done += ft_print_u(va_arg(av, unsigned int), flags);
	else if (c == 'x')
		done += ft_print_x(va_arg(av, unsigned int), 1, flags);
	else if (c == 'X')
		done += ft_print_x(va_arg(av, unsigned int), 0, flags);
	else if (c == '%')
		done += ft_print_prc(flags);
	return (done);
}
