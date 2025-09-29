CC = 			cc
CFLAGS = 		-Wall -Wextra -Werror
RM = 			rm -f

NAME = libftprintf.a

SRCS = 	ft_printf.c \
		ft_base.c \
		utils.c

OBJS = 		$(SRCS:.c=.o)

$(NAME) :	$(OBJS)
				ar -rc $(NAME) $(OBJS)

all : $(NAME) banner

banner:
	@echo "\033[1;32m✅ libftprintf successfully built!\033[0m"
	@echo ""
	@echo "\033[1;36m ██▓     ██▓ ▄▄▄▄     █████▒▄▄▄█████▓\033[0m"
	@echo "\033[1;36m▓██▒    ▓██▒▓█████▄ ▓██   ▒ ▓  ██▒ ▓▒\033[0m"
	@echo "\033[1;36m▒██░    ▒██▒▒██▒ ▄██▒████ ░ ▒ ▓██░ ▒░\033[0m"
	@echo "\033[1;36m▒██░    ░██░▒██░█▀  ░▓█▒  ░ ░ ▓██▓ ░ \033[0m"
	@echo "\033[1;36m░██████▒░██░░▓█  ▀█▓░▒█░      ▒██▒ ░ \033[0m"
	@echo "\033[1;36m░ ▒░▓  ░░▓  ░▒▓███▀▒ ▒ ░      ▒ ░░   \033[0m"
	@echo "\033[1;36m░ ░ ▒  ░ ▒ ░▒░▒   ░  ░          ░    \033[0m"
	@echo "\033[1;36m  ░ ░    ▒ ░ ░    ░  ░ ░      ░      \033[0m"
	@echo "\033[1;36m    ░  ░ ░   ░                       \033[0m"
	@echo "\033[1;36m                  ░                \033[0m"
	@echo ""



so:
				$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
				gcc -nostartfiles -shared -o libftprintf.so $(OBJS)

.c.o:
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}


$(MSOURCES) :
				$(CC) $(CFLAGS) $(SRCS) -c
				ar -rc $(NAME) $(OBJS)

re : 		fclean all


clean:
				$(RM) $(OBJS)
				@echo "\033[0;31mlibftprintf cleaned!\033[0m"


fclean: 	clean
				$(RM) $(NAME)
				$(RM) libftprintf.so

.PHONY: 	fclean clean re all