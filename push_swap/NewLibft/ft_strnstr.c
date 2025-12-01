/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylouvel <ylouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 18:40:29 by ylouvel           #+#    #+#             */
/*   Updated: 2025/09/21 18:57:55 by ylouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if ((!haystack || !needle) && (len == 0))
		return (0);
	if (needle[0] == 0)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		while (haystack[i + j] == needle[j] && haystack[i + j] && i + j < len)
		{
			j++;
			if (needle[j] == '\0')
				return ((char *)&haystack[i]);
		}
		i++;
		j = 0;
	}
	return (0);
}

// int main()
// {
//     char *str = "Hello World";
//     char *to_find = "";
//     size_t len = 15;
//     printf("str = %s\nfind = [%s]\n", str, to_find);
//     ft_strnstr(str, to_find, len);
//     printf("chaine trouver : [%s]\n", strnstr(str, to_find, len));
// }