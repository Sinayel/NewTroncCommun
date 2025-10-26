/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanis <yanis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:16:12 by yanis             #+#    #+#             */
/*   Updated: 2025/10/11 21:16:36 by yanis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*take_line(char *tmp)
{
	int		i;
	char	*line;

	i = 0;
	if (!tmp[0])
		return (NULL);
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (tmp[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
	{
		line[i] = tmp[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*save(char *stash)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	rest = malloc(sizeof(char) * (ft_strlen(stash) - i));
	if (!rest)
		return (NULL);
	i++;
	while (stash[i])
		rest[j++] = stash[i++];
	rest[j] = '\0';
	free(stash);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	int			cwc;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	cwc = 1;
	while ((!stash || !ft_strchr(stash, '\n')) && cwc != 0)
	{
		cwc = read(fd, buffer, BUFFER_SIZE);
		if (cwc == -1)
			return (NULL);
		buffer[cwc] = '\0';
		stash = ft_strjoiin(stash, buffer);
	}
	if (!stash)
	{
		printf("Slt c'est greg\n");
		return (NULL);
	}
	line = take_line(stash);
	if(line)
		printf("Pourquoi greg ?\n");
	stash = save(stash);
	return (line);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int fd;
// 	char *line;

// 	fd = open("tes2.txt", O_RDONLY);
// 	while ((line = get_next_line(fd)))
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }