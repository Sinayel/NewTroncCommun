/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanis <yanis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 05:12:27 by yanis             #+#    #+#             */
/*   Updated: 2025/10/07 05:24:00 by yanis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	handle_key(int keycode, t_env *env)
{
	int	new_x;
	int	new_y;

	new_x = env->img.spawn_x;
	new_y = env->img.spawn_y;
	if (keycode == 122)
		new_x--;
	else if (keycode == 115)
		new_x++;
	else if (keycode == 113)
		new_y--;
	else if (keycode == 100)
		new_y++;
	if (keycode == 65307 || (env->img.map[new_x][new_y] == 'E'
			&& env->img.obj == env->img.count_c)) //! Sa leaks de malade !!!
		clean_exit(env);
	if (env->img.map[new_x][new_y] == 'C' && env->img.obj < env->img.count_c)
	{
		env->img.obj++;
		env->img.map[new_x][new_y] = '0';
		display_choice('0', env, new_x, new_y);
	}
	if (env->img.map[new_x][new_y] != '1')
		check_wall(env, new_x, new_y);
	return (0);
}

void	check_wall(t_env *env, int new_x, int new_y)
{
	char	*mv_str;

	env->img.mv_count++;
	printf("%d\n", env->img.mv_count);   // Compte total des mouvements
	mv_str = ft_itoa(env->img.mv_count); //! Sa peux Leak
	display_choice('1', env, 0, 0);
	if (mv_str)
	{
		mlx_string_put(env->mlx, env->win, 0, 10, 252, mv_str);
		free(mv_str);
	}
	display_choice(env->img.map[env->img.spawn_x][env->img.spawn_y], env,
		env->img.spawn_x, env->img.spawn_y);
	env->img.spawn_x = new_x;
	env->img.spawn_y = new_y;
	display_image(env, "sprites/kitty.xpm", env->img.spawn_x * 40,
		env->img.spawn_y * 40);
}

int	render_map(void)
{
	t_env	*env;
	char	*mv_str;
	int		x;
	int		y;

	env = get_data();
	x = 0;
	mv_str = ft_itoa(env->img.mv_count); //! Sa peux leak
	while (x < env->img.x)
	{
		y = 0;
		while (y < env->img.y)
		{
			display_choice(env->img.map[x][y], env, x, y);
			y++;
		}
		x++;
	}
	display_image(env, "sprites/kitty.xpm", env->img.spawn_x * 40,
		env->img.spawn_y * 40);
	mlx_string_put(env->mlx, env->win, 0, 10, 252, mv_str);
	free(mv_str); //! A tout moment il leaks
	return (0);
}

void	display_image(t_env *env, char *xpm, int x, int y)
{
	env->img.img = mlx_xpm_file_to_image(env->mlx, xpm, &env->img.width,
			&env->img.height);
	if (!env->img.img)
	{
		printf("Erreur\nimpossible de charger l'image XPM\n");
		return ;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img.img, y, x);
}

void	display_choice(char c, t_env *env, int x, int y)
{
	if (c == '1')
		display_image(env, "sprites/terrain.xpm", x * 40, y * 40);
	else if (c == '0')
		display_image(env, "sprites/fond.xpm", x * 40, y * 40);
	else if (c == 'E')
		display_image(env, "sprites/rainbow.xpm", x * 40, y * 40);
	else if (c == 'C')
		display_image(env, "sprites/strawberry.xpm", x * 40, y * 40);
	else if (c == 'P')
		display_image(env, "sprites/fond.xpm", x * 40, y * 40);
}
