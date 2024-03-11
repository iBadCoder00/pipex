#	COLORS
GREEN		= \033[0;32m
RED			= \033[0;31m
BLACK		= \033[0;30m
YELLOW		= \033[1;33m
BLUE		= \033[0;34m
PURPLE		= \033[1;95m
BG_PURPLE	= \033[45m
END			= \033[0m

#	COMPILATION AND BUILD FLAGS
CC			= gcc
CCFLAGS 	= -Wall -Wextra -Werror
LIB 		= ar rcs
RM 			= rm -rf

#	SRC & OBJ FILES
NAME		= libft.a
LEGACY_SRC	= ft_memset.c ft_bzero.c ft_strlen.c\
			  ft_atoi.c ft_isdigit.c ft_isalpha.c\
			  ft_isprint.c ft_isascii.c ft_isalnum.c ft_memchr.c ft_memcpy.c\
			  ft_memcmp.c ft_memmove.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c\
			  ft_strncmp.c ft_toupper.c ft_tolower.c ft_strnstr.c ft_strrchr.c ft_calloc.c\
			  ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c ft_substr.c\
			  ft_strjoin.c ft_strtrim.c ft_strmapi.c ft_itoa.c ft_split.c ft_striteri.c\
			  ft_lstnew.c ft_lstadd_front.c ft_lstsize.c\
			  ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c\
			  ft_lstclear.c ft_lstiter.c ft_lstmap.c 
PRINTF_SRC  = exlibft.c format_utils.c ft_printaddr.c\
			  ft_printchar.c ft_printf.c ft_printhex.c ft_printint.c ft_printstr.c ft_printuint.c utils.c
GNL_SRC		= get_next_line.c get_next_line_utils.c
SRC_FILE	= $(addprefix $(LEGACY_DIR)/, $(LEGACY_SRC)) $(addprefix $(PRINTF_DIR)/, $(PRINTF_SRC))\
			  $(addprefix $(GNL_DIR)/, $(GNL_SRC))
SRC			= $(addprefix $(SRC_DIR)/, $(SRC_FILE))
OBJ			= $(addprefix $(OBJ_DIR)/, $(SRC_FILE:.c=.o))

#	DIRECTORIES
SRC_DIR 	= src
PRINTF_DIR 	= ft_printf
LEGACY_DIR	= legacy
GNL_DIR		= gnl
OBJ_DIR		= obj
INC_DIR		= ./include
# DEPENDENCIES

DEPS 		= $(addprefix $(INC_DIR)/, libft.h ft_printf.h get_next_line.h)
#	BUILD

all: $(NAME)

$(NAME): $(OBJ) $(DEPS)
			@$(LIB) $(NAME) $(OBJ)
			@ranlib $(NAME)
			@printf "                                                     \r"
			@printf "$(GREEN)> BUILDING LIBFT		[✓]\n$(END)"




$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
			@printf "$(YELLOW)> BUILDING $<                      \r$(END)"
			@$(CC) -I $(INC_DIR) $(CCFLAGS) -c -o $@ $<


$(OBJ_DIR): 
			@printf '\033c'
			@mkdir -p $(OBJ_DIR)/$(PRINTF_DIR)
			@mkdir -p $(OBJ_DIR)/$(LEGACY_DIR)
				@mkdir -p $(OBJ_DIR)/$(GNL_DIR)
clean:
			@$(RM) $(OBJ_DIR)

fclean: clean
			@$(RM) $(NAME)

re: fclean all

rebonus: fclean bonus
