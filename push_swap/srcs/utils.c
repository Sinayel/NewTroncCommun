/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanis <yanis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 00:47:24 by yanis             #+#    #+#             */
/*   Updated: 2025/10/27 09:50:09 by yanis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*get_dataS(void)
{
	static t_stack stack;
	return (&stack);
}

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
