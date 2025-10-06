/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanis <yanis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:01:30 by yanis             #+#    #+#             */
/*   Updated: 2025/10/06 21:19:27 by yanis            ###   ########.fr       */
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
	env->img.width = 20;
	env->img.height = 20;
	env->mlx = mlx_init();
}

int close_win(int keycode, t_env *env)
{
	printf("keycode = %d\n", keycode);
	if(keycode == 65307)
	{
		printf("Fermeture\n");
		mlx_destroy_window(env->mlx, env->win);
		exit(1);
	}
	return 0;
}

void display_image(t_env *env)
{
    env->img.img = mlx_xpm_file_to_image(env->mlx, "kitty.xpm", &env->img.width, &env->img.height);
    if (!env->img.img)
    {
        printf("Erreur\nimpossible de charger l'image XPM\n");
        return;
    }
    mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
}


int	main(int argc, char *argv[])
{
	t_env	*env;
	char	**cpy_map;
	int fd;

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
				check_path(cpy_map, env->img.spawn_x, env->img.spawn_y); //* Parsing des obj Fini
				if (env->img.found_c == env->img.count_c && env->img.found_e == 1 && env->img.found_p == 1)
					printf("Check Path : OK\n\n");
				else
					print_error(3);
				// printf("count c = %d | c = %d\n", env->img.count_c, found_c);
			}
			if (cpy_map)
				free_map(cpy_map);
		}
		if (env->img.map)
		{
			print_map();
			free_map(env->img.map);
		}
	}
	printf("x = %d | y = %d\n", env->img.x, env->img.y);
	env->img.x = 800;
	env->img.y = 600;
	env->win = mlx_new_window(env->mlx, env->img.x, env->img.y, "So Long");
	display_image(env);
	mlx_key_hook(env->win, close_win, env);
	mlx_loop(env->mlx);
	return (0);
}
