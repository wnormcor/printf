NAME = libft.a

SRC  = 	ft_memset_bzero.c ft_memfunc.c ft_strl.c ft_strchr.c ft_strn.c \
		ft_atoi.c ft_is.c ft_to.c ft_calloc_strdup.c \
		ft_sec_str.c ft_sec_put.c ft_sec_itoa.c ft_sec_split.c

OBJ  = 	ft_memset_bzero.o ft_memfunc.o ft_strl.o ft_strchr.o ft_strn.o \
		ft_atoi.o ft_is.o ft_to.o ft_calloc_strdup.o \
		ft_sec_str.o ft_sec_put.o ft_sec_itoa.o ft_sec_split.o

SRCBONUS = ft_bonus_one.c ft_bonus_two.c

OBJBONUS = ft_bonus_one.o ft_bonus_two.o

all: $(NAME)

$(OBJ):
	@gcc -Wall -Wextra -Werror -c $(SRC)

$(OBJBONUS):
	@gcc -Wall -Wextra -Werror -c $(SRCBONUS)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

bonus: $(OBJBONUS)
	@ar rcs $(NAME) $(OBJBONUS)

clean:
	@rm -f $(OBJ) $(OBJBONUS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re