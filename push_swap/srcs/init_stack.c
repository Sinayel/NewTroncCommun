/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylouvel <ylouvel@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 00:47:26 by yanis             #+#    #+#             */
/*   Updated: 2025/10/30 22:52:36 by ylouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*to_free;

	if (!stack || !*stack)
		return ;
	tmp = *stack;
	while (tmp)
	{
		to_free = tmp;
		tmp = tmp->next;
		free(to_free);
	}
	*stack = NULL;
}

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

void assign_index(t_stack *stack)
{
    t_stack *ptr;
    t_stack *min;
    int i = 0;
    int size = strlenStack(stack);
    long current_min;

    while (i < size)
    {
        ptr = stack;
        min = NULL;
        current_min = LONG_MAX;

        while (ptr)
        {
            if (ptr->value < current_min && ptr->index == -1)
            {
                current_min = ptr->value;
                min = ptr;
            }
            ptr = ptr->next;
        }
        if (min)
            min->index = i;
        i++;
    }
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
	stack->data.count = 0;
	stack->index = -1;
	stack->next = NULL;
	i = 1;
	if (argc == 2)
		i = 0;
	while (++i < tabLen(data->args))
		stack = add_front(stack, ft_atoi(data->args[i]), -1);
	// if(data->args)
	// 	free_tabtab(data->args);
	assign_index(stack);
	return (stack);
}
