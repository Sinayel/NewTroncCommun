/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanis <yanis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 22:31:02 by yanis             #+#    #+#             */
/*   Updated: 2025/09/23 21:36:47 by yanis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_args(const char str, va_list *args)
{
	int	i;

	i = 0;
	if (str == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (str == 'd' || str == 'i')
		return (ft_putnbr(va_arg(*args, int), &i));
	else if (str == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (str == 'x' || str == 'X')
		return (ft_puthex(va_arg(*args, unsigned int), str));
	else if (str == 'p')
		return (ft_putptr(va_arg(*args, void *)));
	else if (str == 'u')
		return (ft_putunbr(va_arg(*args, unsigned int)));
	else if (str == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		wc;
	va_list	args;

	i = -1;
	wc = 0;
	va_start(args, str);
	while (str[++i])
	{
		if (str[i] == '%')
			wc += ft_args(str[++i], &args);
		else
			wc += ft_putchar(str[i]);
	}
	va_end(args);
	return (wc);
}

// #include <limits.h>
// int	main(void)
// {
// 	int	i;

// 	i = printf("i = %%d %d\n", INT_MAX);
// 	i = printf("%%s = %s\n", NULL);
// 	i = printf("%%s = %s\n", "Hello World");
// 	i = ft_printf("%d\n", 42);
// 	i = ft_printf("hex = %x\nhex maj = %X\n", 31, 31);
// 	i = printf("hex = %x\nhex maj = %X\n", 31, 31);
// 	i = printf("i = %%d %d\n", 65);
// 	printf("\n%d\n", i);
// }
