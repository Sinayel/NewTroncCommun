NAME_CLIENT    = client
NAME_SERVER    = server
SRCS_CLIENT    = client.c ft_atoi.c
SRCS_SERVER    = server.c
SRCS           = $(SRCS_CLIENT) $(SRCS_SERVER)
OBJ_DIR        = obj
OBJS_CLIENT    = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCS_CLIENT))
OBJS_SERVER    = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCS_SERVER))
OBJS           = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCS))
PRINTF_DIR     = ./printf
PRINTF_LIB     = $(PRINTF_DIR)/libftprintf.a
HEADER         = includes/minitalk.h
CC             = cc
CFLAGS         = -Wall -Wextra -Werror -I ./includes
RM             = rm -f

all: $(PRINTF_LIB) $(NAME_CLIENT) $(NAME_SERVER)

$(PRINTF_LIB):
	@$(MAKE) -sC $(PRINTF_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME_CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(PRINTF_LIB) -o $(NAME_CLIENT)

$(NAME_SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(PRINTF_LIB) -o $(NAME_SERVER)

$(OBJ_DIR)/%.o: %.c $(HEADER) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -sC $(PRINTF_DIR)
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -sC $(PRINTF_DIR)
	$(RM) $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all

.PHONY: all clean fclean re
