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
RM = rm -rf

LIBFT = libft.a
NAME = pipex
SRC = main.c pipe.c utils.c
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

OBJ_DIR = obj

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ) 
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) 
	@/bin/echo -ne "                                   \r"
	@echo "$(GREEN)> BUILDING PIPEX              [✓]$(END)"

$(LIBFT):
	@make -s -C libft/
	@cp libft/libft.a .

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@/bin/echo -ne "$(YELLOW)> BUILDING $<               \r$(END)"
	@$(CC) $(CCFLAGS) -c -o $@ $<

$(OBJ_DIR):
	@mkdir obj

clean:
	@make clean -s -C libft/
	@$(RM) $(OBJ)
	@$(RM) $(OBJ_DIR)

fclean: clean
	@make fclean -s -C libft
	@$(RM) $(LIBFT)
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re