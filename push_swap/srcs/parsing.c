/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanis <yanis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 01:27:30 by yanis             #+#    #+#             */
/*   Updated: 2025/10/27 09:44:12 by yanis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	check_argv(int argc, char *argv[])
{
	int	i;
	int	j;
	int	nb;

	i = 1;
	j = 1;
	while (i <= argc - 1)
	{
		nb = ft_atoi(argv[i]);
		j = 1;
		while (j <= argc - 1)
		{
			if ((nb == ft_atoi(argv[j]) && j != i) || !is_digit_tab(argv[i]))
			{
				printf("Error\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
	printf("All good\n");
}

t_data	*parsing(int argc, char *argv[])
{
    t_data *data;
    data = malloc(sizeof(t_data));
    if(!data)
        return NULL;
    if(argc == 2)
    {
        data->args = ft_split(argv[1], ' '); //! A free !!!
        check_argv(tabLen(data->args), data->args);
        return data;
    }
	else if (argc > 2)
    {
        data->args = argv;
		check_argv(argc, data->args);
        return (data);
    }
    return NULL;
}