/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanis <yanis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 22:55:11 by yanis             #+#    #+#             */
/*   Updated: 2025/10/09 10:35:54 by yanis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_elem(char map, t_env *env)
{
	if (map == '1' || map == '0' || map == 'E' || map == 'P' || map == 'C')
	{
		env->img.i = 1;
		return (1);
	}
	env->img.i = 0;
	return (0);
}

void	check_wall(t_env *env, int new_x, int new_y, int keycode)
{
	char	*mv_str;
	if (keycode == 122 || keycode == 115 || keycode == 113 || keycode == 100
		|| keycode == 65363 || keycode == 65364 || keycode == 65362
		|| keycode == 65361 || keycode == 65307)
	{
		if (keycode == 65307)
			ft_putnbr_fd(0, 1);
		else if (keycode != 65307)
			ft_putnbr_fd(++env->img.mv_count, 1);
		putstr_fd("\n", 1);
	}
	mv_str = ft_itoa(env->img.mv_count);
	display_choice('1', env, 0, 0);
	if (mv_str)
	{
		mlx_string_put(env->mlx, env->win, 0, 10, 0xFF0000, mv_str);
		free(mv_str);
	}
	display_choice(env->img.map[env->img.spawn_x][env->img.spawn_y], env,
		env->img.spawn_x, env->img.spawn_y);
	env->img.spawn_x = new_x;
	env->img.spawn_y = new_y;
	display_image(env, "sprites/kitty.xpm", env->img.spawn_x * 40,
		env->img.spawn_y * 40);
}

void check_parsing(t_env *env)
{
	char **cpy_map;

	cpy_map = copy_map(env);
	check_path(cpy_map, env->img.spawn_x, env->img.spawn_y);
	if (env->img.found_c == env->img.count_c
		&& env->img.found_e == 1 && env->img.found_p == 1)
	{
		if (cpy_map)
			free_map(cpy_map);
		return ;
	}
	else
	{
		if(env->img.found_e > 1 || env->img.found_p > 1)
			print_error(4);
		else
			print_error(3);
		if (cpy_map)
			free_map(cpy_map);
		clean_exit(env);
	}
}

void	check_ber(char *str, t_env *env)
{
	int	len;

	len = ft_strlen(str);
	if (len < 4 || ft_strncmp(str + len - 4, ".ber", 4) != 0)
	{
		print_error(2);
		clean_exit(env);
	}
}
