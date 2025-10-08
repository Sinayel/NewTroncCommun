/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanis <yanis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:01:30 by yanis             #+#    #+#             */
/*   Updated: 2025/10/08 17:41:22 by yanis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//? (Au cas ou) sert a enlever les tabs et espace au debut de la map
// char *clean_line(char *str)
// {
//     int i;
//     int j;
//     i = 0;
//     j = 0;
//     while (str[i] == ' ' || str[i] == '\t')
//         i++;
//     char *clean;
//     clean = malloc(sizeof(char) * (ft_strlen_map(str + i) + 1));
//     if (!clean)
//         return (NULL);
//     while (str[i])
//     {
//         clean[j++] = str[i];
//         i++;
//     }
//     clean[j] = '\0';
//     free(str);
//     return (clean);
// }

void	clean_exit(t_env *env)
{
	if(env->img.mv_count != 0)
		printf("%d\nExit\n", ++env->img.mv_count);
	else
		printf("%d\nExit\n", env->img.mv_count);
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

void	init_all(t_env *env, char *url_map)
{
	env->img.map = malloc(sizeof(char *) * (count_lines(url_map) + 1));
	//! A free sinon Leaks
	env->img.count_c = 0;
	env->img.found_c = 0;
	env->img.found_p = 0;
	env->img.x = 0;
	env->img.width = 40;
	env->img.height = 40;
	env->img.mv_count = 0;
	env->img.obj = 0;
	env->mlx = mlx_init();
}

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

void game_loop(t_env *env)
{
	env->win = mlx_new_window(env->mlx, 800, 600, "So Long");
	render_map();
	mlx_key_hook(env->win, handle_key, env);
	mlx_hook(env->win, 2, 1L<<0, handle_key_press, env);
	mlx_do_key_autorepeaton(env->mlx);
	mlx_loop(env->mlx);
}

void check_parsing(t_env *env, char **cpy_map)
{
	check_path(cpy_map, env->img.spawn_x, env->img.spawn_y);
	if (env->img.found_c == env->img.count_c
		&& env->img.found_e == 1 && env->img.found_p == 1)
		printf("Check Path : OK\n\n");
	else
	{
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

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		t_env	*env;
		char	**cpy_map;
		int		fd;

		env = get_data();
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (0);
		check_ber(argv[1], env);
		init_all(env, argv[1]);
		if (init_map(env, fd))
		{
			cpy_map = copy_map(env);
			if (parsing(env))
				check_parsing(env, cpy_map);
			if (cpy_map)
				free_map(cpy_map);
		}
		if(env->img.gnl_error == 1)
			clean_exit(env);
		game_loop(env);
	}
	return (0);
}
