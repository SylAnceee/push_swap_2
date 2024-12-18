# Compiler and flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I./libft

# Source files and Object files
SRC = ft_printf.c ft_printf_utils.c
OBJ = $(SRC:.c=.o)

# output library name
NAME = libftprintf.a

# Path to the libft library
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

# Rule to compile all source files and link with libft
all: $(LIBFT) $(NAME)

# Build libft first
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Create the static library from object files
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ) $(LIBFT)

# Rule to compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

# Clean object files and the library
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Recompile everything from scratch
re: fclean all
