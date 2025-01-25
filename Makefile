NAME = push_swap

LIBFT_DIR = ./ft_libft
lib = $(LIBFT_DIR)/libft.a

source = \
    push_swap.c \
	main.c \
    ft_isdouble.c \
    ft_isdayz.c

object = $(source:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(lib) $(NAME)

$(lib):
	make -C $(LIBFT_DIR)

$(NAME): $(object)
	$(CC) $(CFLAGS) $(object) $(lib) -o $(NAME)

clean:
	rm -rf $(object)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

s: re clean
	make clean -C $(LIBFT_DIR)
	rm -rf $(object)

.SECONDARY: $(object)
.PHONY: all clean fclean re somme
