/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanis <yanis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 22:57:35 by yanis             #+#    #+#             */
/*   Updated: 2025/10/09 10:41:11 by yanis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int handle_key_press(int keycode, t_env *env)
{
	if (keycode == 119)
		env->img.key_w = 1;
	if (keycode == 97)
		env->img.key_a = 1;
	if (keycode == 115)
		env->img.key_s = 1;
	if (keycode == 100)
		env->img.key_d = 1;
	if (keycode == 65307)
		clean_exit(env);
	return 0;
}

void	handle_keycode(int keycode, int *new_x, int *new_y)
{
	if (keycode == 122 || keycode == 65362)
		(*new_x)--;
	else if (keycode == 115 || keycode == 65364)
		(*new_x)++;
	else if (keycode == 113 || keycode == 65361)
		(*new_y)--;
	else if (keycode == 100 || keycode == 65363)
		(*new_y)++;
}

int	handle_key(int keycode, t_env *env)
{
	int	new_x;
	int	new_y;

	new_x = env->img.spawn_x;
	new_y = env->img.spawn_y;
	if (keycode == 122 || keycode == 115 || keycode == 113 || keycode == 100
		|| keycode == 65363 || keycode == 65364 || keycode == 65362
		|| keycode == 65361)
		handle_keycode(keycode, &new_x, &new_y);
	if (env->img.map[new_x][new_y] == 'C' && env->img.obj < env->img.count_c)
	{
		env->img.obj++;
		env->img.map[new_x][new_y] = '0';
		display_choice('0', env, new_x, new_y);
	}
	if (env->img.map[new_x][new_y] != '1' || keycode == 65307)
		check_wall(env, new_x, new_y, keycode);
	if (keycode == 65307 || (env->img.map[new_x][new_y] == 'E'
		&& env->img.obj == env->img.count_c))
			clean_exit(env);
	return (0);
}
