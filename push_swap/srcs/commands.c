/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylouvel <ylouvel@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 19:21:46 by ylouvel           #+#    #+#             */
/*   Updated: 2025/10/30 22:44:58 by ylouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_push(t_stack **from, t_stack **to, char name)
{
	t_stack	*tmp;
	t_data *data;
	data = get_data();

	if (!*from)
		return;
	tmp = *from;
	*from = (*from)->next;
	tmp->next = *to;
	*to = tmp;
	data->count++;
    printf("p%c\n", name);
}

void	ft_rotate(t_stack **stack, char name)
{
	t_stack	*first;
	t_stack	*last;
	t_data *data;
	data = get_data();

	if (!*stack || !(*stack)->next)
		return;
	first = *stack;
	*stack = (*stack)->next;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	data->count++;
	printf("r%c\n", name);
}

void	ft_swap(t_stack **stack, char name)
{
	t_stack *first;
	t_stack *second;
	t_data *data;

	data = get_data();
	if (!*stack || !(*stack)->next)
		return;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	data->count++;
	printf("s%c\n", name);
}

void	ft_reverse_rotate(t_stack **stack, char name)
{
	t_stack *prev;
	t_stack *last;
	t_stack *head;
	t_data *data;

	data = get_data();
	if (!*stack || !(*stack)->next)
		return;
	head = *stack;
	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = head;
	*stack = last;
	data->count++;
	printf("rr%c\n", name);
}
