CC = cc
CFLAGS = -Wall -Wextra -Werror -Iminilibx-linux -INewLibft -INewGetNextLi -g3
RM = rm -f

NAME = so_long
SRCS = so_long.c
OBJS = $(SRCS:.c=.o)

MLX_DIR = minilibx-linux
LIBFT_DIR = NewLibft
GNL_DIR = NewGetNextLine

all: $(NAME)

$(NAME): $(OBJS)
	@# Compiler libft
	$(MAKE) -C $(LIBFT_DIR)
	@# Compiler gnl
	$(MAKE) -C $(GNL_DIR)
	@# Compiler minilibx
	$(MAKE) -C $(MLX_DIR)
	@# Link final
	$(CC) $(OBJS) -L$(GNL_DIR) -lgnl -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(GNL_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	@echo "\033[0;31mCleaned objects!\033[0m"

fclean: clean
	$(RM) $(NAME)
	$(RM) vgcore.*
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(GNL_DIR) fclean
	@echo "\033[0;31mFull clean!\033[0m"

re: fclean all

.PHONY: all clean fclean re
