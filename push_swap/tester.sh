#!/bin/bash

make libft
cc ./srcs/init_stack.c ./srcs/push_swap.c ./srcs/parsing.c ./srcs/commands.c ./srcs/utils.c ./srcs/test.c -Llibft -lft -o push_swap_tester

./push_swap_tester