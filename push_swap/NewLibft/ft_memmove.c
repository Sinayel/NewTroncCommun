/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylouvel <ylouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:58:59 by ylouvel           #+#    #+#             */
/*   Updated: 2025/09/21 15:08:40 by ylouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, unsigned long len)
{
	unsigned char	*pst;
	unsigned char	*rst;
	size_t			i;

	i = 0;
	if ((dst == NULL) && (src == NULL))
		return (NULL);
	pst = (unsigned char *)dst;
	rst = (unsigned char *)src;
	i = 1;
	if (rst < pst)
		while (i++ < len--)
			pst[len] = rst[len];
	else
		ft_memcpy(pst, rst, len);
	return (dst);
}

// #include <string.h>
// int main()
// {
//     unsigned char	pst[] = "hello";
//     unsigned char	prc[] = "worldodo";
//     printf("dst = %s\nsrc = %s\n\n", pst, prc);
//     ft_memmove(pst, prc, 4);
//     // memmove(pst, prc, 4);
//     printf("dst = %s\nsrc = %s\n", pst, prc);
// }
