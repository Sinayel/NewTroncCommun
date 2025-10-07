/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanis <yanis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:01:30 by yanis             #+#    #+#             */
/*   Updated: 2025/10/07 03:36:13 by yanis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	init_all(t_env *env, char *url_map)
{
	env->img.map = malloc(sizeof(char *) * (count_lines(url_map) + 1));
	env->img.count_c = 0;
	env->img.found_c = 0;
	env->img.found_p = 0;
	env->img.x = 0;
	env->img.width = 40;
	env->img.height = 40;
	env->img.mv_count = 0;
	env->mlx = mlx_init();
}

// int display_player(void *param)
// {
// 	t_env *env;
// 	env = (t_env *)param;
// 	display_image(env, "sprites/kitty.xpm", (env->img.spawn_x - 1) * 40, env->img.spawn_y * 40);
// 	return (0);
// }

int	close_win(int keycode, t_env *env)
{
	int	new_x;
	int	new_y;

	new_x = env->img.spawn_x;
	new_y = env->img.spawn_y;
	printf("keycode = %d\n", keycode);
	if (keycode == 65307)
	{
		printf("Fermeture\n");
		mlx_destroy_window(env->mlx, env->win);
		exit(1);
	}
	else if (keycode == 122)
		new_x--;
	else if (keycode == 115)
		new_x++;
	else if (keycode == 113)
		new_y--;
	else if (keycode == 100)
		new_y++;
	if (env->img.map[new_x][new_y] != '1')
	{
		env->img.mv_count++;
		printf("%d\n", env->img.mv_count); // Compte total des mouvements
		display_choice(env->img.map[env->img.spawn_x][env->img.spawn_y], env,
			env->img.spawn_x, env->img.spawn_y);
		env->img.spawn_x = new_x;
		env->img.spawn_y = new_y;
		display_image(env, "sprites/kitty.xpm", env->img.spawn_x * 40,
			env->img.spawn_y * 40);
	}
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

int	render_map(void)
{
	t_env	*env;
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
	display_image(env, "sprites/kitty.xpm", env->img.spawn_x * 40, env->img.spawn_y * 40);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_env	*env;
	char	**cpy_map;
	int		fd;
	int		x;
	int		y;

	env = get_data();
	init_all(env, argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (0);
	if (argc == 2)
	{
		if (init_map(env, fd)) //* Init Map Fini
		{
			cpy_map = copy_map(env);
			printf("init map : OK\n");
			if (parsing(env)) //* Parsing Fini
			{
				printf("Parsing : OK\n");
				check_path(cpy_map, env->img.spawn_x, env->img.spawn_y);
				//* Parsing des obj Fini
				if (env->img.found_c == env->img.count_c
					&& env->img.found_e == 1 && env->img.found_p == 1)
					printf("Check Path : OK\n\n");
				else
					print_error(3);
				// printf("count c = %d | c = %d\n", env->img.count_c, found_c);
			}
			if (cpy_map)
				free_map(cpy_map);
		}
		//* Clear la map pour gerer les leaks
		// if (env->img.map)
		// {
		print_map();
		// 	free_map(env->img.map);
		// }
	}
	printf("x = %d | y = %d\n", env->img.x, env->img.y);
	x = 800;
	y = 600;
	env->win = mlx_new_window(env->mlx, x, y, "So Long");
	printf("fenetre creee : %d x %d\n", x, y);
	render_map();
	mlx_key_hook(env->win, close_win, env);
	mlx_loop(env->mlx);
	return (0);
}
