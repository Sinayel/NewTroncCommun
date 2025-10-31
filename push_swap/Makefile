CFLAGS = -Wall -Wextra -Werror -Ilibft -g3

RM = rm -rf

OBJ_DIR = obj
SRC_DIR = srcs
LIBFT_DIR = libft
HEADER = include/push_swap.h

NAME = push_swap
SRCS = init_stack.c push_swap.c parsing.c commands.c utils.c

SRCS_FILES = $(addprefix $(SRC_DIR)/, $(SRCS))
OBJS = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCS))

all: $(NAME)

vgcore:
	@$(RM) vgcore.*

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
	@echo "\n\033[1;32m✅ Push_swap successfully built!\033[0m"
	@$(MAKE) -C $(LIBFT_DIR)
	@cc $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER) | $(OBJ_DIR)
	@echo -ne "\r\033[1;34m⏳ Compiling $<...\033[0m"
	@cc $(CFLAGS) -c $< -o $@

libft:
	git clone git@github.com:Sinayel/libft.git

clean:
	@echo "\033[0;31m🚮 Cleaning objects...\033[0m"
	@$(RM) $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean:
	@echo "\033[0;31m🚮 Cleaning objects...\033[0m"
	@$(RM) $(NAME)
	@$(RM) $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(RM) vgcore.*

re: fclean all

.PHONY: all clean fclean re libft