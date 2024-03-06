GREEN=\033[0;32m
RED=\033[0;31m
BLACK=\033[0;30m
YELLOW=\033[1;33m
BLUE=\033[0;34m
PURPLE=\033[1;95m
BG_PURPLE=\033[45m
END=\033[0m

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBS = -L libft -l:libft.a
RM = rm -rf

LIBFT = libft/libft.a
NAME = pipex
SRC = main.c pipe.c utils.c
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ) 
	@$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME) 
	@/bin/echo -ne "                                   \r"
	@echo "$(GREEN)> BUILDING PIPEX			[✓]$(END)"

$(LIBFT):
	@make -s -C libft/

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@/bin/echo -ne "$(YELLOW)> BUILDING $<               \r$(END)"
	@$(CC) $(CCFLAGS) -I $(INC_DIR) -c -o $@ $<

$(OBJ_DIR):
	@mkdir obj

clean:
	@make clean -s -C libft/
	@$(RM) $(OBJ_DIR)

fclean: clean
	@make fclean -s -C libft
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re