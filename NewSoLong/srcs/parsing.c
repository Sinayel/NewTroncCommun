/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanis <yanis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 00:29:29 by yanis             #+#    #+#             */
/*   Updated: 2025/10/11 20:40:08 by yanis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	exit_error(int i)
{
	if(i == 1)
		putstr_fd("Error\nNo map was found try a files who exist\n", 2);
	else if(i == 2)
		putstr_fd("Error\nPlease only 2 arguments is required\n", 2);
	return (0);
}

int	fail(int i)
{
	if (i == 1)
		print_error(5);
	else
		print_error(2);
	return (0);
}

int	parsing(t_env *env)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (env->img.map[x])
	{
		y = 0;
		while (env->img.map[x][y])
		{
			if (((x == 0 || x == env->img.x - 1 || y == 0 || y == env->img.y
						- 1) && env->img.map[x][y] != '1')
				|| !check_elem(env->img.map[x][y], env))
				return (fail(env->img.i));
			if (env->img.map[x][y] == 'P' || env->img.map[x][y] == 'E'
				|| env->img.map[x][y] == 'C')
				define_spawn(x, y, env->img.map);
			y++;
		}
		x++;
	}
	return (1);
}

void	define_spawn(int x, int y, char **map)
{
	t_env	*env;

	env = get_data();
	if (map[x][y] == 'P')
	{
		env->img.spawn_x = x;
		env->img.spawn_y = y;
	}
	if (map[x][y] == 'C')
		env->img.count_c++;
}

void	check_path(char **map, int x, int y)
{
	t_env	*env;

	env = get_data();
	if (x < 0 || y < 0 || !map[x] || map[x][y] == '\0')
		return ;
	if (map[x][y] == '1' || map[x][y] == 'V')
		return ;
	if (map[x][y] == 'P')
		env->img.found_p++;
	if (map[x][y] == 'E')
		env->img.found_e++;
	if (map[x][y] == 'C')
		env->img.found_c++;
	map[x][y] = 'V';
	check_path(map, x - 1, y);
	check_path(map, x, y + 1);
	check_path(map, x + 1, y);
	check_path(map, x, y - 1);
}
