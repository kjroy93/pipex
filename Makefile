###########################################
#             VARIABLES                   #
###########################################

NAME        = pipex
NAME_BONUS  = pipex_bonus

# Directories
SRC_DIR     = src
OBJ_DIR     = obj
LIBFT_DIR   = libft
INCLUDE_DIR = include
LIBFT_INCLUDE = $(LIBFT_DIR)/include

# Source files listed manually
SRC         = src/parse/get_argv.c src/parse/ft_new_split.c src/utils/utils.c				\
              src/utils/redirect_functions.c src/utils/error_free.c src/execution.c pipex.c
SRC_BONUS   = src_bonus/execution_bonus.c src_bonus/pipex_bonus.c src_bonus/status_bonus.c

# Object files
OBJ         = $(SRC:.c=.o)
OBJ_FILES   = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))
OBJ_BONUS   = $(patsubst src_bonus/%.c,$(OBJ_DIR)/bonus_%.o,$(SRC_BONUS))

# Compiler and flags
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g -I$(INCLUDE_DIR) -I$(LIBFT_INCLUDE)

# Static libft library
LIBFT       = $(LIBFT_DIR)/libft.a

###########################################
#                RULES                    #
###########################################

all: $(LIBFT) $(NAME)

# Compile libft if not compiled or outdated
$(LIBFT):
	@echo "⚙️ 📘 Compiling libft..."
	@$(MAKE) -C $(LIBFT_DIR) > /dev/null 2>&1

# Compile mandatory pipex
$(NAME): $(OBJ_FILES)
	@echo "(|) 42: Compiling pipex..."
	@$(CC) $(CFLAGS) $^ $(LIBFT) -o $@

# Compile bonus pipex
bonus: $(LIBFT) $(OBJ_BONUS) $(OBJ_FILES)
	@echo "(|) 42: Compiling pipex bonus..."
	@$(CC) $(CFLAGS) $^ $(LIBFT) -o $(NAME_BONUS)

# Compile each .c to .o inside obj directory
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/bonus_%.o: src_bonus/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

###########################################
#               CLEANING                  #
###########################################

clean:
	@echo "🧹 Swoosh swoosh... Removing object files..."
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean > /dev/null 2>&1

fclean: clean
	@echo "🧹🧹 Swoosh swoosh... Removing everything..."
	@rm -f $(NAME) $(NAME_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) fclean > /dev/null 2>&1

re: fclean all

.PHONY: all clean fclean re bonus
