/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanis <yanis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:11:23 by ylouvel           #+#    #+#             */
/*   Updated: 2025/10/19 23:36:13 by yanis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	sign;

	sign = 1;
	i = 0;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && qstr[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

#include <stdio.h>
#include <stdlib.h>
int main()
{
	int result;
	result = ft_atoi("98778978978789789890989890890890898908908989089");
	printf("%d\n", result);
	result = atoi("98778978978789789890989890890890898908908989089");
	printf("%d\n", result);
	return 0;
}