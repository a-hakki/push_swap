NAME = push_swap
NAME1 = checker

LIBFT_DIR = ./ft_libft
lib = $(LIBFT_DIR)/libft.a

source = \
    push_swap.c \
    ft_isdouble.c \
    ft_isdayz.c \
	ft_clear.c \
	rra_rrb.c \
	sorting.c \
	under5.c

object = $(source:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(lib) $(NAME)

$(lib):
	make -C $(LIBFT_DIR)

$(NAME): $(object)
	$(CC) $(CFLAGS) $(object) main.c $(lib) -o $(NAME)

bonus: $(lib) $(NAME1)

$(NAME1): $(object)
	$(CC) $(CFLAGS) $(object) checker.c $(lib) -o $(NAME1)

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

f: $(object)
	$(CC) $(CFLAGS) $(object) main.c $(lib) -o $(NAME)
	$(CC) $(CFLAGS) $(object) checker.c $(lib) -o $(NAME1)
	rm -rf $(object) && clear


.SECONDARY: $(object)
.PHONY: all clean fclean re somme
