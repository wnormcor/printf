/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnormcor <...@student.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 19:06:24 by wnormcor          #+#    #+#             */
/*   Updated: 2020/07/13 20:45:15 by wnormcor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int				ft_read_str(const char *s, va_list av)
{
	t_flags		flags;
	int			done;
	int			ret_t;
	int			i;

	done = 0;
	i = -1;
	while (s[++i])
		if (s[i] != '%')
			done += ft_putchar(s[i]);
		else if (s[i] == '%' && s[i + 1])
		{
			i++;
			flags = ft_init_flags();
			i = ft_read_flags(s, i, &flags, av);
			if (ft_type(s[i]))
			{
				if ((ret_t = ft_translator((char)flags.type, flags, av)) == -1)
					return (-1);
				done += ret_t;
			}
			else if (s[i])
				done += ft_putchar(s[i]);
		}
	return (done);
}

int				ft_printf(const char *s, ...)
{
	va_list		av;
	int			done;

	if (s == NULL)
		return (-1);
	va_start(av, s);
	done = ft_read_str(s, av);
	va_end(av);
	return (done);
}
