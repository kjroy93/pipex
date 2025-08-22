###########################################
#             VARIABLES                   #
###########################################

NAME    = libft.a

# Directories
SRC_DIR = src
OBJ_DIR = obj
INT_DIR = include

SRC     = ft_atoi.c ft_isalpha.c ft_itoa.c ft_memcpy.c ft_putendl_fd.c ft_strchr.c				\
          ft_strlcat.c ft_strncmp.c ft_substr.c ft_bzero.c ft_isascii.c ft_memmove.c 			\
          ft_putnbr_fd.c ft_strdup.c ft_strlcpy.c ft_strnstr.c ft_tolower.c ft_calloc.c 		\
          ft_isdigit.c ft_memchr.c ft_memset.c ft_putstr_fd.c ft_striteri.c ft_strlen.c			\
          ft_strrchr.c ft_toupper.c ft_isalnum.c ft_isprint.c ft_memcmp.c ft_putchar_fd.c		\
          ft_split.c ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_lstnew.c ft_lstsize.c			\
          ft_lstmap.c ft_lstlast.c ft_lstiter.c ft_lstdelone.c ft_lstclear.c ft_lstadd_front.c	\
          ft_lstadd_back.c ft_printf.c print_char.c print_hex.c print_int.c print_pointer.c		\
          print_string.c print_unsigned.c get_next_line.c 										\

# Source files with full path
SRC_FILES = $(addprefix $(SRC_DIR)/, $(SRC))

# Object files with full path and .o extension
OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# Compiler and flags
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -I$(INT_DIR)
AR      = ar rcs

###########################################
#              RULES                      #
###########################################

# Default target
all: $(NAME)

# Create static library from object files
$(NAME): $(OBJ_FILES)
	$(AR) $@ $^

# Compile .c files to .o files, create obj directory if needed
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

###########################################
#               CLEANING                  #
###########################################

# Remove object files and obj directory
clean:
	@rm -rf $(OBJ_DIR)

# Remove library and object files
fclean: clean
	@rm -rf $(NAME)

# Clean and recompile everything
re: fclean all

###########################################
#            SPECIAL RULES                #
###########################################

.PHONY: all clean fclean re
