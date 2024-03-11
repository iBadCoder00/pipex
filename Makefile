# COLORS
GREEN		= \033[0;32m
RED			= \033[0;31m
BLACK		= \033[0;30m
YELLOW		= \033[1;33m
BLUE		= \033[0;34m
PURPLE		= \033[1;95m
BG_PURPLE	= \033[45m
END			= \033[0m

# BUILD FLAGS
CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror
LIBFT 		= libft/libft.a
LIBS 		= -L libft -l:libft.a
RM 			= rm -rf

# BIN CONFIG & SOURCE FILES
NAME 		= pipex
NAME_BONUS	= pipex_b
SRC 		= main.c pipe.c utils.c
BONUS_SRC 	= main_bonus.c pipe_bonus.c utils_bonus.c

OBJ			= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
BONUS_OBJ	= $(addprefix $(OBJ_DIR)/, $(BONUS_SRC:.c=.o))

# DIRECTORIES
SRC_DIR 	= src
OBJ_DIR 	= obj
INC_DIR 	= include

# RULES
all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(LIBFT) $(BONUS_OBJ)
			@$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBS) -o $(NAME_BONUS)
			@printf "                                   \r"
			@printf "$(GREEN)> BUILDING PIPEX_BONUS		[✓]\n$(END)"

$(NAME): $(LIBFT) $(OBJ) 
			@$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)
			@printf "                                   \r"
			@printf "$(GREEN)> BUILDING PIPEX		[✓]\n$(END)"

$(LIBFT):
			@make -s -C libft/

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
			@printf "$(YELLOW)> BUILDING $<               \r$(END)"
			@$(CC) $(CFLAGS) -I $(INC_DIR) -c -o $@ $<

$(OBJ_DIR):
			@mkdir obj

clean:
			@make clean -s -C libft/
			@$(RM) $(OBJ_DIR)

fclean: clean
			@make fclean -s -C libft
			@$(RM) $(NAME_BONUS)
			@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
