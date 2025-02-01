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
	under5.c \
	main.c

source_b = \
    push_swap.c \
    ft_isdouble.c \
    ft_isdayz.c \
	ft_clear.c \
	rra_rrb.c \
	sorting.c \
	under5.c \
	checker.c \

object = $(source:.c=.o)
object_b = $(source_b:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(lib) $(NAME)

$(lib):
	make -C $(LIBFT_DIR)

$(NAME): $(object)
	$(CC) $(CFLAGS) $(object) $(lib) -o $(NAME)

bonus: $(lib) $(NAME1)

$(NAME1): $(object_b)
	$(CC) $(CFLAGS) $(object_b) $(lib) -o $(NAME1)

clean:
	rm -rf $(object)
	rm -rf $(object_b)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAME1)
	make fclean -C $(LIBFT_DIR)

re: fclean all

s: re clean
	make clean -C $(LIBFT_DIR)
	rm -rf $(object)
	rm -rf $(object_b)

f: $(object) $(object_b)
	$(CC) $(CFLAGS) $(object) $(lib) -o $(NAME)
	$(CC) $(CFLAGS) $(object_b) $(lib) -o $(NAME1)
	rm -rf $(object) $(object) && clear


.SECONDARY: $(object)
.PHONY: all clean fclean re somme
