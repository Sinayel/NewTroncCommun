/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylouvel <ylouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:48:47 by ylouvel           #+#    #+#             */
/*   Updated: 2025/09/21 14:58:23 by ylouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, unsigned long n)
{
	unsigned char	*pst;
	unsigned char	*prc;
	unsigned long	i;

	i = 0;
	pst = (unsigned char *)dst;
	prc = (unsigned char *)src;
	while (++i < n)
		*(pst)++ = *(prc)++;
	return (dst);
}

// #include <string.h>
// int main()
// {
//     unsigned char	pst[] = "hello";
//     unsigned char	prc[] = "worldodo";
//     printf("dst = %s\nsrc = %s\n\n", pst, prc);
//     ft_memcpy(pst, prc, 4);
//     memcpy(pst, prc, 4);
//     printf("dst = %s\nsrc = %s\n", pst, prc);

// }