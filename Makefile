# Variables
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c push.c swap.c reverse_rotate.c rotate.c ft_split_diff.c commands.c handle_errors.c init_a_to_b.c init_b_to_a.c sort_stacks.c sort_three.c stack_utils.c stack_init.c
OBJS = $(SRCS:.c=.o)
NAME = push_swap

# Paths to libraries
FT_PRINTF_DIR = ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

# Rules
all: $(FT_PRINTF) $(NAME)

$(FT_PRINTF): $(LIBFT)
	$(MAKE) -C $(FT_PRINTF_DIR)

$(NAME): $(OBJS) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(FT_PRINTF)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re