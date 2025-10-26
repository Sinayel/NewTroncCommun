/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanis <yanis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 22:29:25 by yanis             #+#    #+#             */
/*   Updated: 2025/10/22 01:54:02 by yanis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_putnbr(int nb, int *i);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_puthex(unsigned long nb, char c);
int	ft_putptr(void *ptr);
int	ft_putunbr(unsigned int nb);
int	ft_printf(const char *str, ...);
int	ft_args(const char str, va_list *args);
int	ft_strlen(char *str);

#endif