# Terminal colors
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
RESET = \033[0m

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

# Directories
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj

# Source files
SRC_FILES = ft_printf.c ft_printf_utils.c
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

# Library name
NAME = libftprintf.a

# Printf for ASCII art display
PRINTF = printf

# Rules
all: $(NAME)

# Create directories
dirs:
	@mkdir -p $(OBJ_DIR)

# Compile library
$(NAME): dirs $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@$(PRINTF) "$(GREEN)[SUCCESS]$(RESET) Compiled $(BLUE)$(NAME)$(RESET)\n"
	@$(PRINTF) "$(CYAN)"
	@$(PRINTF) "  _____ _______   _____  _____  _____ _   _ _______ ______ \n"
	@$(PRINTF) " |  __ \__   __| |  __ \|  __ \|_   _| \ | |__   __|  ____|\n"
	@$(PRINTF) " | |__) | | |    | |__) | |__) | | | |  \| |  | |  | |__   \n"
	@$(PRINTF) " |  ___/  | |    |  ___/|  _  /  | | | . \` |  | |  |  __|  \n"
	@$(PRINTF) " | |      | |    | |    | | \ \ _| |_| |\  |  | |  | |     \n"
	@$(PRINTF) " |_|      |_|    |_|    |_|  \_\_____|_| \_|  |_|  |_|     \n"
	@$(PRINTF) "$(RESET)\n"

# Compile objects
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | dirs
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@
	@$(PRINTF) "$(GREEN)[OK]$(RESET) Compiled $(notdir $<)\n"

# Clean objects
clean:
	@$(RM) $(OBJS)
	@rm -rf $(OBJ_DIR)
	@$(PRINTF) "$(YELLOW)[CLEAN]$(RESET) Removed object files\n"

# Clean all
fclean: clean
	@$(RM) $(NAME)
	@$(PRINTF) "$(YELLOW)[CLEAN]$(RESET) Removed $(BLUE)$(NAME)$(RESET)\n"

# Rebuild
re: fclean all

# For testing purposes - create a simple test program
test: $(NAME)
	@$(CC) $(CFLAGS) -I$(INC_DIR) tests/test.c -L. -lftprintf -o test_printf
	@$(PRINTF) "$(GREEN)[SUCCESS]$(RESET) Test program created! Run with ./test_printf\n"

.PHONY: all clean fclean re dirs test

.PHONY:			all clean fclean re bonus
