###########################################
#             VARIABLES                   #
###########################################

NAME        = pipex
NAME_BONUS  = pipex_bonus

# Directories
SRC_DIR     = src
OBJ_DIR     = obj
SRC_BONUS_DIR = src_bonus
LIBFT_DIR   = libft
INCLUDE_DIR = include
LIBFT_INCLUDE = $(LIBFT_DIR)/include

# Source files mandatory
SRC         = $(SRC_DIR)/parse/get_argv.c \
              $(SRC_DIR)/parse/ft_new_split.c \
              $(SRC_DIR)/utils/utils.c \
              $(SRC_DIR)/utils/redirect_functions.c \
              $(SRC_DIR)/utils/error_free.c \
              $(SRC_DIR)/parse/execution.c \
              $(SRC_DIR)/pipex.c

# Source files bonus
SRC_BONUS   = $(SRC_DIR)/parse/get_argv.c \
              $(SRC_DIR)/parse/ft_new_split.c \
              $(SRC_DIR)/utils/utils.c \
              $(SRC_DIR)/utils/redirect_functions.c \
              $(SRC_DIR)/utils/error_free.c \
			  $(SRC_BONUS_DIR)/childs_bonus.c \
			  $(SRC_BONUS_DIR)/execution_bonus.c \
              $(SRC_BONUS_DIR)/pipex_bonus.c \
              $(SRC_BONUS_DIR)/status_bonus.c \
			  $(SRC_BONUS_DIR)/here_doc_bonus.c 

# Object files
OBJ         = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC))
OBJ_BONUS   = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC_BONUS))

# Compiler and flags
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g3 -I$(INCLUDE_DIR) -I$(LIBFT_INCLUDE)

# Static libft library
LIBFT       = $(LIBFT_DIR)/libft.a

###########################################
#                RULES                    #
###########################################

all: $(LIBFT) $(NAME)

bonus: $(LIBFT) $(NAME_BONUS)

# Compile libft if not compiled or outdated
$(LIBFT):
	@echo "⚙️ 📘 Compiling libft..."
	@$(MAKE) -C $(LIBFT_DIR) > /dev/null 2>&1

# Compile mandatory pipex
$(NAME): $(OBJ)
	@echo "(|) 42: Compiling pipex..."
	@$(CC) $(CFLAGS) $^ $(LIBFT) -o $@

# Compile bonus pipex
$(NAME_BONUS): $(OBJ_BONUS)
	@echo "(|) 42: Compiling pipex bonus..."
	@$(CC) $(CFLAGS) $^ $(LIBFT) -o $@

# Compile each .c to .o inside obj directory
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

###########################################
#               CLEANING                  #
###########################################

clean:
	@echo "🧹 Removing object files..."
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean > /dev/null 2>&1

fclean: clean
	@echo "🧹 Removing executables..."
	@rm -f $(NAME) $(NAME_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) fclean > /dev/null 2>&1

re: fclean all

.PHONY: all clean fclean re bonus
