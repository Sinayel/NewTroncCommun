/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanis <yanis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 01:27:30 by yanis             #+#    #+#             */
/*   Updated: 2025/10/31 01:58:10 by yanis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stddef.h>

long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

void	print_error(void)
{
	t_data *data;
	data = get_data();
	if(data->args && data->split == 1)
		free_tabtab(data->args);
	printf("Error\n");
	exit(1);
}

void	check_argv(int argc, char *argv[], int input_verif)
{
	int		i;
	int		j;
	long	nb;

	i = 1;
	if(input_verif == 0)
		i = 0;
	while (i < argc)
	{
		if (!is_digit_tab(argv[i]))
			print_error();
		nb = ft_atol(argv[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			print_error();
		j = i;
		while (++j < argc)
			if (ft_atol(argv[j]) == nb)
				print_error();
		i++;
	}
	if(argc == 1)
		if(!is_digit_tab(argv[0]))
			print_error();
	// printf("All good\n");
}

t_data	*parsing(int argc, char *argv[])
{
	t_data *data;

	data = get_data();
	if (!data)
		return (NULL);
	if (argc == 2)
	{
		data->args = ft_split(argv[1], ' '); //! A free !!!
		data->split = 1;
		check_argv(tabLen(data->args), data->args, 0);
		return (data);
	}
	else if (argc > 2)
	{
		data->args = argv;
		data->split = 0;
		check_argv(argc, argv, 1);
		return (data);
	}
	return (NULL);
}
