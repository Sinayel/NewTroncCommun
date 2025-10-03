/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanis <yanis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 00:31:27 by yanis             #+#    #+#             */
/*   Updated: 2025/10/04 00:48:29 by yanis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_map(t_env *env, char *url_map)
{
	int		fd;
	char	*line;
	int		len;
	int		test;

	fd = open(url_map, O_RDONLY);
	if (fd == -1)
		return (0);
	test = 0;
	while ((line = get_next_line(fd)))
	{
		if (*line == '\0')
		{
			free(line);
			continue ;
		}
		env->img.map[env->img.x] = line;
		if (env->img.x == 0)
			len = ft_strlen_map(env->img.map[env->img.x]);
		env->img.y = ft_strlen_map(env->img.map[env->img.x]);
		if (len != env->img.y)
			print_error(1);
		env->img.x++;
	}
	if (test == 1)
	{
		free(line);
		env->img.map[env->img.x] = NULL;
		close(fd);
	}
	env->img.map[env->img.x] = NULL;
	close(fd);
	return (1);
}

void	print_map(void)
{
	t_env	*env;
	int		x;

	env = get_data();
	x = -1;
	while (env->img.map[++x])
		printf("%s\n", env->img.map[x]);
}

char	**copy_map(t_env *env)
{
	int		i;
	char	**copy;

	i = -1;
	copy = malloc(sizeof(char *) * (env->img.x + 1));
	while (++i < env->img.x)
		copy[i] = strdup(env->img.map[i]);
	copy[i] = NULL;
	return (copy);
}
