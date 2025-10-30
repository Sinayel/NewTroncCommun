/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylouvel <ylouvel@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 00:47:24 by yanis             #+#    #+#             */
/*   Updated: 2025/10/30 22:46:49 by ylouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_data *get_data(void)
{
	static t_data data;
	return (&data);
}

void	free_tabtab(char **argv)
{
	int	i;

	i = 0;
	if (!argv)
		return ;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

int strlenStack(t_stack *stack)
{
	t_stack	*tmp;
	int i;
	i = 0;
	tmp = stack;
	while(tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return i;
}

int tabLen(char **argv)
{
    int i = 0;
    while(argv[i])
        i++;
    return i;
}

int	is_digit_tab(char *argv)
{
	int	i;

	i = -1;
	while (argv[++i])
	{
		if(argv[i] == '-' && i == 0)
		{
			i++;
			if (!ft_isdigit(argv[i]) || argv[i] == '0')
				return (0);
		}
		else if(!ft_isdigit(argv[i]))
			return (0);
	}
	return (1);
}

int	find_min(t_stack *stack)
{
	int min;

	if (!stack)
		return (0);
	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

int	index_of(t_stack *stack, int value)
{
	int i = 0;
	while (stack)
	{
		if (stack->value == value)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}
