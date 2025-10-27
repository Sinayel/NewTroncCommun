/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanis <yanis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 00:47:26 by yanis             #+#    #+#             */
/*   Updated: 2025/10/27 09:51:51 by yanis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*add_front(t_stack *stack, int nb, int index)
{
	t_stack	*new_node;
	t_stack	*tmp;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (stack);
	new_node->value = nb;
	new_node->index = index;
	new_node->next = NULL;
	if (!stack)
		return (new_node);
	tmp = stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
	return (stack);
}

t_stack	*init_stack(int argc, char *argv[])
{
	t_data	*data;
	t_stack	*stack;
	int		i;

	data = parsing(argc, argv);
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->value = ft_atoi(argv[1]);
	stack->index = 0;
	stack->next = NULL;
	i = 1;
	if (argc == 2)
		i = 0;
	while (++i < tabLen(data->args))
		stack = add_front(stack, ft_atoi(data->args[i]), i - 1);
	return (stack);
}
