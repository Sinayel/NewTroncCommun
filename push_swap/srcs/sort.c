/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylouvel <ylouvel@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 03:54:56 by ylouvel           #+#    #+#             */
/*   Updated: 2025/10/31 04:02:04 by ylouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sorted(t_stack *stackA)
{
	t_stack	*tmp;
	int		i;
	int		sorted;

	tmp = stackA;
	i = INT_MIN;
	sorted = 0;
	while (tmp)
	{
		if (i > tmp->value)
			sorted = 1;
		i = tmp->value;
		tmp = tmp->next;
	}
	if (sorted == 1)
		return (0);
	return (1);
}

void	push_swap(t_stack **stackA, t_stack **stackB)
{
	int	max_bits;
	int	size;
	int	i;
	int	j;

	max_bits = 0;
	size = strlen_stack(*stackA);
	while ((size - 1) >> max_bits)
		max_bits++;
	i = 0;
	while (i < max_bits && !is_sorted(*stackA))
	{
		j = 0;
		while (j < size)
		{
			if (((*stackA)->index >> i) & 1)
				ft_rotate(stackA, 'a');
			else
				ft_push(stackA, stackB, 'b');
			j++;
		}
		while (*stackB)
			ft_push(stackB, stackA, 'a');
		i++;
	}
}

void	sort_three(t_stack **a)
{
	if (!a || !*a || !(*a)->next || !(*a)->next->next)
		return ;
	if (is_sorted(*a))
		return ;
	if ((*a)->value > (*a)->next->value
		&& (*a)->value > (*a)->next->next->value)
	{
		ft_rotate(a, 'a');
		if ((*a)->value > (*a)->next->value)
			ft_swap(a, 'a');
	}
	else if ((*a)->next->value > (*a)->value
		&& (*a)->next->value > (*a)->next->next->value)
	{
		ft_reverse_rotate(a, 'a');
		if ((*a)->value > (*a)->next->value)
			ft_swap(a, 'a');
	}
	else if ((*a)->value > (*a)->next->value)
		ft_swap(a, 'a');
}

void	sort_four_to_five_elements(t_stack **a, t_stack **b)
{
	int	pushed;

	pushed = 0;
	while (pushed < 2)
	{
		if ((*a)->index == 0 || (*a)->index == 1)
		{
			ft_push(a, b, 'b');
			pushed++;
		}
		else
			ft_rotate(a, 'a');
	}
	if (*b && (*b)->index == 0 && (*b)->next && (*b)->next->index == 1)
		ft_swap(b, 'b');
	sort_three(a);
	ft_push(b, a, 'a');
	ft_push(b, a, 'a');
	if ((*a)->index > (*a)->next->index)
		ft_swap(a, 'a');
}
