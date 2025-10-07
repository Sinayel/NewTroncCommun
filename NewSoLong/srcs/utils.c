/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanis <yanis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 00:28:13 by yanis             #+#    #+#             */
/*   Updated: 2025/10/07 15:09:47 by yanis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_env	*get_data(void)
{
	static t_env	data;

	return (&data);
}

int	print_error(int i)
{
	t_env *env;
	env = get_data();
	if (i == 1)
	{
		env->img.gnl_error = 1;
		printf("Error\n");
		printf("You have to put the same len of each line for the map\n");
		return (0);
	}
	else if (i == 2)
	{
		env->img.gnl_error = 1;
		printf("Error\nWrong map maybe try to lock the map\n");
		return (0);
	}
	else if (i == 3)
	{
		printf("Error\nAll the object as to be foundable\n");
		return (0);
	}
	else if (i == 4)
	{
		printf("Error too many P or E\n");
		return (0);
	}
	return (0);
}

int	ft_strlen_map(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	count_lines(char *url_map)
{
	int		fd;
	char	*line;
	int		count;

	fd = open(url_map, O_RDONLY);
	if (fd == -1)
		return (-1);
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (*line != '\n')
			count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
