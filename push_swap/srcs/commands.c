/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylouvel <ylouvel@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 19:21:46 by ylouvel           #+#    #+#             */
/*   Updated: 2025/10/27 20:37:58 by ylouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_push(t_stack **from, t_stack **to, char name)
{
	t_stack	*tmp;

	if (!*from)
		return;
	tmp = *from;
	*from = (*from)->next;
	tmp->next = *to;
	*to = tmp;
    printf("p%c\n", name);
}

void	ft_rotate(t_stack **stack, char name)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return;
	first = *stack;
	*stack = (*stack)->next;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	printf("r%c\n", name);
}


