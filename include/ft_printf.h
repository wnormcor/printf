/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnormcor <...@student.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 19:05:31 by wnormcor          #+#    #+#             */
/*   Updated: 2020/07/12 16:40:38 by wnormcor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

typedef	struct		s_flags
{
	int				type;
	int				left_adj;
	int				zero_fill;
	int				width;
	int				star;
	int				dot;
}					t_flags;

int					ft_printf(const char *s_str, ...);
int					ft_read_str(const char *s, va_list av);
t_flags				ft_init_flags(void);
int					ft_read_flags(const char *s, int i, t_flags *f, va_list p);

t_flags				ft_flag_width(t_flags flags, va_list av);
t_flags				ft_flag_left_adj(t_flags flags);
t_flags				ft_flag_digit(char c, t_flags flags);
int					ft_flag_dot(const char *s, int st, t_flags *f, va_list p);

int					ft_translator(int c, t_flags flags, va_list av);
int					ft_type(int c);
int					ft_print_c(char c, t_flags flags);
int					ft_print_s(char *str, t_flags flags);
int					ft_print_p(unsigned long long nbr, t_flags flags);
int					ft_print_d(int nbr, t_flags flags);
int					ft_print_u(unsigned int nbr, t_flags flags);
int					ft_print_x(unsigned int nbr, int lower, t_flags flags);
int					ft_print_prc(t_flags flags);

int					ft_putchar(int c);
int					ft_putstr(char *str, int len);
int					ft_fill_width(int width, int fact_len, int zero_fill);

char				*ft_itoa_base(unsigned long long nbr, int base);
char				*ft_s_tolower(char *str);

#endif
