CC = cc
CFLAGS = -Wall -Wextra -Werror -Iminilibx-linux -INewLibft -INewGetNextLi -g3
RM = rm -rf

NAME = so_long

SRCS = srcs/so_long.c srcs/map.c srcs/parsing.c srcs/utils.c srcs/mlx.c
OBJ_DIR = obj
OBJS = $(OBJ_DIR)/so_long.o $(OBJ_DIR)/map.o $(OBJ_DIR)/parsing.o $(OBJ_DIR)/utils.o $(OBJ_DIR)/mlx.o

MLX_DIR = minilibx-linux
LIBFT_DIR = NewLibft
GNL_DIR = NewGetNextLine

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/so_long.o: srcs/so_long.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c srcs/so_long.c -o $(OBJ_DIR)/so_long.o

$(OBJ_DIR)/map.o: srcs/map.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c srcs/map.c -o $(OBJ_DIR)/map.o

$(OBJ_DIR)/parsing.o: srcs/parsing.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c srcs/parsing.c -o $(OBJ_DIR)/parsing.o

$(OBJ_DIR)/utils.o: srcs/utils.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c srcs/utils.c -o $(OBJ_DIR)/utils.o

$(OBJ_DIR)/mlx.o: srcs/mlx.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c srcs/mlx.c -o $(OBJ_DIR)/mlx.o

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(GNL_DIR)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(OBJS) -L$(GNL_DIR) -lgnl -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz -o $(NAME)

clean:
	$(RM) $(OBJ_DIR)
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
