CC = cc
CFLAGS = -Wall -Wextra -Werror 

NAME = libftprintf.a

SRC = \
	ft_putnbr_unsigned.c \
	ft_putchar.c  \
	ft_putnbr_base.c \
	ft_putstr.c \
	ft_putnbr.c \
	ft_printf.c\
	ft_putptr.c
	
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I .

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re 