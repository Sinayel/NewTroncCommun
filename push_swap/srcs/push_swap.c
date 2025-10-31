/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylouvel <ylouvel@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 00:41:38 by yanis             #+#    #+#             */
/*   Updated: 2025/10/31 04:22:58 by ylouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_list(t_stack *stack, int i)
{
	if (i == 1)
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

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc >= 2)
	{
		stack_b = NULL;
		stack_a = init_stack(argc, argv);
		if (!is_sorted(stack_a) && strlen_stack(stack_a) == 2)
			ft_swap(&stack_a, 'a');
		else if (strlen_stack(stack_a) == 3 && !is_sorted(stack_a))
			sort_three(&stack_a);
		else if (strlen_stack(stack_a) == 5 || strlen_stack(stack_a) == 4)
			sort_four_to_five_elements(&stack_a, &stack_b);
		else if (strlen_stack(stack_a) > 5)
			push_swap(&stack_a, &stack_b);
		// print_list(stack_a, 1);
		// print_list(stack_b, 0);
		free_stack(&stack_a);
		free_stack(&stack_b);
	}
	return (0);
}
