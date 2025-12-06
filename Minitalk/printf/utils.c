/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanis <yanis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 22:42:43 by yanis             #+#    #+#             */
/*   Updated: 2025/09/23 21:17:43 by yanis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	while (!*str)
		return (0);
	return (1 + ft_strlen(str + 1));
}

int	ft_putstr(char *str)
{
	if (!str)
		return (ft_putstr("(null)"));
	return (write(1, str, ft_strlen(str)));
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int nb, int *i)
{
	long long	n;

	n = nb;
	if (n < 0 && ((*i)++, write(1, "-", 1)))
		n = -n;
	if (n > 9)
		ft_putnbr(n / 10, i);
	(*i)++;
	return (write(1, &"0123456789"[n % 10], 1), *i);
}
