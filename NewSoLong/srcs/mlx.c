/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanis <yanis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 05:12:27 by yanis             #+#    #+#             */
/*   Updated: 2025/10/09 01:53:22 by yanis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	render_map(void)
{
	t_env	*env;
	char	*mv_str;
	int		x;
	int		y;

	env = get_data();
	x = 0;
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
	mv_str = ft_itoa(env->img.mv_count);
	display_image(env, "sprites/kitty.xpm", env->img.spawn_x * 40,
		env->img.spawn_y * 40);
	mlx_string_put(env->mlx, env->win, 0, 10, 0xFF0000, mv_str);
	free(mv_str);
	return (0);
}

void	display_image(t_env *env, char *xpm, int x, int y)
{
	env->img.img = mlx_xpm_file_to_image(env->mlx, xpm, &env->img.width,
			&env->img.height);
	if (!env->img.img)
	{
		putstr_fd("Erreur\nimpossible de charger l'image XPM\n", 2);
		clean_exit(env);
		return ;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img.img, y, x);
	mlx_destroy_image(env->mlx, env->img.img);
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

void	clean_exit(t_env *env)
{
	putstr_fd("Exit\n", 1);
	if(env->img.map)
	{
		free_map(env->img.map);
		env->img.map = NULL;
	}
	if(env->win)
	{
		mlx_destroy_window(env->mlx, env->win);
		mlx_destroy_display(env->mlx);
		free(env->mlx);
		env->win = NULL;
		env->mlx = NULL;
	}
	if(env->mlx)
	{
		mlx_destroy_display(env->mlx);
		free(env->mlx);
		env->mlx = NULL;
	}
	exit(EXIT_SUCCESS);
}
