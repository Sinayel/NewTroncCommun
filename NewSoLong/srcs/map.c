/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanis <yanis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 00:31:27 by yanis             #+#    #+#             */
/*   Updated: 2025/10/09 17:41:40 by yanis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	len_error(t_env *env, int fd)
{
	if (env->img.i == 1)
		print_error(1);
	env->img.i = 0;
	env->img.map[env->img.x] = NULL;
	close(fd);
}

int	init_map(t_env *env, int fd)
{
	char	*line;
	int		len;

	line = get_next_line(fd);
	while (line)
	{
		if (*line == '\0')
		{
			free(line);
			line = get_next_line(fd);
			env->img.i = 1;
			continue ;
		}
		env->img.map[env->img.x] = ft_strdup(line);
		free(line);
		if (env->img.x == 0)
			len = ft_strlen_map(env->img.map[env->img.x]);
		env->img.y = ft_strlen_map(env->img.map[env->img.x]);
		if (len != env->img.y)
			env->img.i = 1;
		env->img.x++;
		line = get_next_line(fd);
	}
	len_error(env, fd);
	return (1);
}

void	print_map(void)
{
	t_env	*env;
	int		x;

	env = get_data();
	x = -1;
	while (env->img.map[++x])
		putstr_fd(env->img.map[x], 1);
	putstr_fd("\n", 1);
}

char	**copy_map(t_env *env)
{
	int		i;
	char	**copy;

	i = 0;
	copy = malloc(sizeof(char *) * (env->img.x + 1));
	while (i < env->img.x)
	{
		copy[i] = strdup(env->img.map[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
