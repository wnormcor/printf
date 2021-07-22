# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wnormcor <...@student.21-school.ru>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/16 10:18:16 by wnormcor          #+#    #+#              #
#    Updated: 2020/07/12 00:41:34 by wnormcor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
HEAD = include/ft_printf.h

SRC =	source/ft_printf.c \
		source/ft_print_t1.c \
		source/ft_print_t2.c \
		source/ft_print_t3.c \
		source/ft_print_t4.c \
		source/ft_print_t5.c \
		source/ft_putchars.c \
		source/ft_setup_flags.c \
		source/ft_setup_translator.c \

%.o: %.c $(HEAD)
	gcc $(FLAGS) -c $< -o $@

OBJ = $(SRC:%.c=%.o)

$(NAME): $(OBJ)
	@$(MAKE) all -C ./libft
	@$(MAKE) bonus -C ./libft
	@cp ./libft/libft.a $(NAME)
	@ar rcs $(NAME) $(OBJ)
	@echo LIBNAME: Library $(NAME) with LIBFT for LIBFTPRINTF has been created with object-file index

all: $(NAME)

clean:
	@$(MAKE) clean -C ./libft
	@rm -f $(OBJ)
	@echo CLEAN: Objects with LIBFT files .o had been cleaned

fclean: clean
	@$(MAKE) fclean -C ./libft
	@rm -f $(NAME)
	@echo FCLEAN: Library $(NAME) has been cleaned

re: fclean all
	@echo RE: fclean and make all completed

bonus: 
	$(MAKE) all

.PHONY: all clean fclean re bonus
