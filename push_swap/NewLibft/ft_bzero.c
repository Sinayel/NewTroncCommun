/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylouvel <ylouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:47:37 by ylouvel           #+#    #+#             */
/*   Updated: 2025/09/21 14:51:49 by ylouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, unsigned long n)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)s;
	while (n-- > 0)
		(*tmp++) = 0;
}

// int main()
// {
//     char str[] = "hello world";
//     printf("str = %s\n", str);
//     ft_bzero(str, 1);
//     printf("str = %s\n\n", str);

//     char str2[] = "hello world";
//     printf("str = %s\n", str2);
//     bzero(str2, 1);
//     printf("str = %s\n", str2);

// }