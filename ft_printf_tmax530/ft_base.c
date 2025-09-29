/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanis <yanis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 23:30:59 by yanis             #+#    #+#             */
/*   Updated: 2025/09/23 21:18:40 by yanis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int nb, char c)
{
	int	i;

	i = 0;
	if (c == 'X')
	{
		if (nb >= 16)
			i += ft_puthex(nb / 16, c);
		i += ft_putchar("0123456789ABCDEF"[nb % 16]);
	}
	else
	{
		if (nb >= 16)
			i += ft_puthex(nb / 16, c);
		i += ft_putchar("0123456789abcdef"[nb % 16]);
	}
	return (i);
}

int	ft_putptr(void *ptr)
{
	unsigned long	nb;
	int				i;

	nb = (unsigned long)ptr;
	i = 0;
	i += ft_putstr("0x");
	if (nb >= 16)
		i += ft_puthex(nb / 16, 0);
	i += ft_putchar("0123456789abcdef"[nb % 16]);
	return (i);
}

int	ft_putunbr(unsigned int nb)
{
	if (nb >= 10)
		return (ft_putunbr(nb / 10) + ft_putchar((nb % 10) + '0'));
	else
		return (ft_putchar(nb + '0'));
}
