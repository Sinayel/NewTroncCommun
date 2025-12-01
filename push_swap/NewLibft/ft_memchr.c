/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylouvel <ylouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 18:41:05 by ylouvel           #+#    #+#             */
/*   Updated: 2025/09/21 19:04:39 by ylouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp;
	unsigned char	tmpc;
	size_t			i;

	tmp = (unsigned char *)s;
	tmpc = (unsigned char)c;
	i = 0;
	if (!tmp)
		return (0);
	while (i < n)
	{
		if (tmp[i] == tmpc)
			return ((void *)&tmp[i]);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
//     char str[] = "Hello";
//     int c = 0;
//     printf("str = %s\n", str);
//     // ft_memchr(str, c, 4);
//     memchr(str, 195, 5);
//     printf("str = %s\n", str);
// }
