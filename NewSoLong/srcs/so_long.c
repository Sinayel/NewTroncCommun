/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanis <yanis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:01:30 by yanis             #+#    #+#             */
/*   Updated: 2025/10/07 15:08:00 by yanis            ###   ########.fr       */
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
	env->mlx = mlx_init(); //! Je crois que sa peux leaks (a verifier)
}

//! Pas d'exit qui free donc y'a vla les leaks
int	main(int argc, char *argv[])
{
	t_env	*env;
	char	**cpy_map;
	int		fd;

	env = get_data();
	init_all(env, argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (0);
	if (argc == 2)
	{
		//! Leaks a gerer en cas d'erreur
		if (init_map(env, fd)) //* Init Map Fini
		{
			cpy_map = copy_map(env);
			printf("init map : OK\n");
			//! Peux leaks
			if (parsing(env)) //* Parsing Fini
			{
				printf("Parsing : OK\n");
				check_path(cpy_map, env->img.spawn_x, env->img.spawn_y);
				//! Impossible de leaks
				//* Parsing des obj Fini
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
				// printf("count c = %d | c = %d\n", env->img.count_c, found_c);
			}
			if (cpy_map)
				free_map(cpy_map);
		}
		if(env->img.gnl_error == 1)
			clean_exit(env);
		//* Clear la map pour gerer les leaks (Faudra le gerer plutard)
		// if (env->img.map)
		// {
		print_map();
		// 	free_map(env->img.map);
		// }
	}
	env->win = mlx_new_window(env->mlx, 800, 600, "So Long");
	render_map();
	mlx_key_hook(env->win, handle_key, env);
	mlx_loop(env->mlx);
	return (0);
}
