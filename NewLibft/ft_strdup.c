/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylouvel <ylouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 19:07:01 by ylouvel           #+#    #+#             */
/*   Updated: 2025/09/21 19:10:00 by ylouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strdup(const char *s1)
{
	int		i;
	char	*str;

	if (!s1)
		return (NULL);
	i = -1;
	str = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	while (s1[++i])
		str[i] = s1[i];
	str[i] = '\0';
	return (str);
}
