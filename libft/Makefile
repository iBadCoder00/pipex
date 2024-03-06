GREEN=\033[0;32m
RED=\033[0;31m
BLACK=\033[0;30m
YELLOW=\033[1;33m
BLUE=\033[0;34m
PURPLE=\033[1;95m
BG_PURPLE=\033[45m
END=\033[0m

LIB = ar rcs
RM = rm -rf

CC = gcc
CCFLAGS = -Wall -Wextra -Werror

NAME = libft.a
SRC =	ft_memset.c ft_bzero.c ft_strlen.c ft_atoi.c ft_isdigit.c ft_isalpha.c\
ft_isprint.c ft_isascii.c ft_isalnum.c ft_memchr.c ft_memcpy.c\
ft_memcmp.c ft_memmove.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c\
ft_strncmp.c ft_toupper.c ft_tolower.c ft_strnstr.c ft_strrchr.c ft_calloc.c\
ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c ft_substr.c\
ft_strjoin.c ft_strtrim.c ft_strmapi.c ft_itoa.c ft_split.c ft_striteri.c \
ft_lstnew.c ft_lstadd_front.c ft_lstsize.c\
ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c\
ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	@$(LIB) $(NAME) $(OBJ)
	@echo "$(GREEN)COMPILING LIBFT	 		 [✓]$(END)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@/bin/echo -ne "$(YELLOW)COMPILING LIBFT			 [\\]\r$(END)"
	@sleep 0.05
	@/bin/echo -ne "$(YELLOW)COMPILING LIBFT			 [|]\r$(END)"
	@sleep 0.05
	@/bin/echo -ne "$(YELLOW)COMPILING LIBFT			 [/]\r$(END)"
	@sleep 0.05
	@/bin/echo -ne "$(YELLOW)COMPILING LIBFT			 [-]\r$(END)"
	@$(CC) $(CCFLAGS) -I $(INC_DIR) -c -o $@ $<
	

$(OBJ_DIR):
	@mkdir obj
clean:
	@$(RM) $(OBJ)
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all bonus re comp_msg clean fclean
