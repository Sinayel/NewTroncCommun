/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylouvel <ylouvel@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 00:41:38 by yanis             #+#    #+#             */
/*   Updated: 2025/10/27 20:45:34 by ylouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_list(t_stack *stack, int i)
{
	if(i == 1)
		printf("Stack A :\n");
	else
		printf("Stack B :\n");
	while (stack)
	{
		printf("[%d]%d\n", stack->index, stack->value);
		stack = stack->next;
	}
	printf("\n");
}

// void	push_swap(t_stack **stack_a, t_stack **stack_b)
// {
	
// }

int	main(int argc, char *argv[])
{
	if (argc >= 2)
	{
		t_stack *stackA;
		t_stack *stackB;
		stackB = NULL;
		stackA = init_stack(argc, argv); //* Parsing fini
		print_list(stackA, 1);
		print_list(stackB, 0);
	}
	return (0);
}