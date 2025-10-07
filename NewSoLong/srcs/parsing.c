/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanis <yanis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 00:29:29 by yanis             #+#    #+#             */
/*   Updated: 2025/10/07 14:27:45 by yanis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	parsing(t_env *env)
{
	int	x;
	int	y;
	int	count;

	x = 0;
	y = 0;
	count = 0;
	while (env->img.map[x])
	{
		y = 0;
		while (env->img.map[x][y])
		{
			if (env->img.map[x][y] != '1' && (x == 0 || x == (env->img.x - 1)
					|| env->img.map[x][0] != '1' || env->img.map[x][env->img.y
					- 1] != '1'))
				return (print_error(2));
			if (env->img.map[x][y] == 'P' || env->img.map[x][y] == 'E'
				|| env->img.map[x][y] == 'C')
				define_spawn(x, y, env->img.map, &count);
			y++;
		}
		x++;
	}
	return (1);
}

void	define_spawn(int x, int y, char **map, int *count)
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
	else
		(*count)++;
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
