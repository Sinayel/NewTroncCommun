CFLAGS = -Wall -Wextra -Werror -Iminilibx-linux -INewLibft -INewGetNextLine -g3

RM = rm -rf

OBJ_DIR = obj
SRC_DIR = srcs
LIBFT_DIR = NewLibft
GNL_DIR = NewGetNextLine
MLX_DIR = minilibx-linux
HEADER = include/so_long.h

NAME = so_long
SRCS = init_map.c render_map.c parsing.c so_long.c utils.c handle.c checking.c

SRCS_FILES = $(addprefix $(SRC_DIR)/, $(SRCS))
OBJS = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCS))

all: $(NAME)

mlx:
	git clone https://github.com/42Paris/minilibx-linux.git minilibx-linux

vgcore:
	@$(RM) vgcore.*

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
	@$(MAKE) -C $(MLX_DIR)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(GNL_DIR)
	@cc $(CFLAGS) $(OBJS) -L$(GNL_DIR) -lgnl -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER) | $(OBJ_DIR)
	@cc $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning objects..."
	@$(RM) $(OBJ_DIR)
	@$(MAKE) -C $(MLX_DIR) clean
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(GNL_DIR) clean

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(GNL_DIR) fclean
	@$(RM) vgcore.*

re: fclean all

.PHONY: all clean fclean re mlx