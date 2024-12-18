# Mandatory and bonus source files
SRC_MAND = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
           ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
           ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
           ft_strrchr.c ft_tolower.c ft_toupper.c ft_calloc.c ft_strdup.c ft_substr.c \
           ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
           ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SRC_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
            ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
            ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

# Compiler and flags
CFLAGS = -Wall -Wextra -Werror
CC = cc

# Output library name
NAME = libft.a

# Object files for mandatory and bonus
OBJ_MAND = $(SRC_MAND:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

# Rule to build the library from mandatory object files
$(NAME): $(OBJ_MAND)
	$(AR) rcs $(NAME) $(OBJ_MAND)

# Default rule
all: $(NAME)

# Rule to include bonus files in the library
bonus: $(OBJ_MAND) $(OBJ_BONUS)
	$(AR) rcs $(NAME) $(OBJ_MAND) $(OBJ_BONUS)

# Rule for compiling .c files into .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files
clean:
	rm -f $(OBJ_MAND) $(OBJ_BONUS)

# Clean up all files, including the library
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all
