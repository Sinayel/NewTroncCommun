# Nom de l'exécutable
NAME = push_swap

# Compilateur
CC = cc

# Options de compilation
CFLAGS = -Wall -Wextra -Werror

# Fichiers sources
SRC = push_swap.c

# Fichiers objets
OBJ = $(SRC:.c=.o)

# Couleurs (pour rendre le terminal plus joli)
GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
NC = \033[0m

# Règle par défaut
all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)✅ Compilation terminée avec succès !$(NC)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(YELLOW)Compilation de $< ...$(NC)"

clean:
	@rm -f $(OBJ)
	@echo "$(RED)🧹 Fichiers objets supprimés.$(NC)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)🧽 Exécutable supprimé.$(NC)"

re: fclean all

# Empêche Make d’interpréter ces noms comme des fichiers
.PHONY: all clean fclean re
