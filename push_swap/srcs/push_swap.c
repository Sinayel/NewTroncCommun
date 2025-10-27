/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanis <yanis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 00:41:38 by yanis             #+#    #+#             */
/*   Updated: 2025/10/27 09:52:05 by yanis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_list(t_stack *stack)
{
	printf("Stack A :\n");
	while (stack)
	{
		printf("[%d]%d\n", stack->index, stack->value);
		stack = stack->next;
	}
}

int	main(int argc, char *argv[])
{
	if (argc >= 2)
	{
		t_stack *stackA;
		stackA = init_stack(argc, argv);
		print_list(stackA);
	}
	return (0);
}