/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylouvel <ylouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:31:36 by ylouvel           #+#    #+#             */
/*   Updated: 2025/09/21 15:09:41 by ylouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *b, int c, unsigned long len)
{
	unsigned char	*str;
	unsigned int	i;

	str = (unsigned char *)b;
	i = 0;
	while (i++ < len)
		*(str)++ = c;
	return (b);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
//     unsigned char str[6] = "Hello";
//     char c = 'b';
//     unsigned long len = 3;
//     printf("str = %s\n", str);
//     ft_memset(str, c, len);
//     memset(str, c, len);
//     printf("str = %s\n", str);
// }