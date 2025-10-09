/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanis <yanis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:01:30 by yanis             #+#    #+#             */
/*   Updated: 2025/10/09 18:04:52 by yanis            ###   ########.fr       */
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

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	cross_close(t_env *env)
{
	clean_exit(env);
	return (0);
}

t_env	*init_all(t_env *env, char *url_map)
{
	env->img.map = malloc(sizeof(char *) * (count_lines(url_map) + 1));
	env->img.count_c = 0;
	env->img.found_c = 0;
	env->img.found_p = 0;
	env->img.x = 0;
	env->img.i = 0;
	env->img.width = 40;
	env->img.height = 40;
	env->img.mv_count = 0;
	env->img.obj = 0;
	env->mlx = mlx_init();
	return (env);
}

void	game_loop(t_env *env)
{
	env->win = mlx_new_window(env->mlx, env->img.y * 40, env->img.x * 40,
			"So Long");
	render_map();
	mlx_hook(env->win, 17, 1L << 0, cross_close, env);
	mlx_key_hook(env->win, handle_key, env);
	mlx_do_key_autorepeaton(env->mlx);
	mlx_loop(env->mlx);
}

int	main(int argc, char *argv[])
{
	t_env	*env;
	int		fd;

	if (argc == 2)
	{
		env = get_data();
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (exit_error());
		check_ber(argv[1], env);
		init_all(env, argv[1]);
		if (init_map(env, fd))
		{
			if (parsing(env))
				check_parsing(env);
			else
				clean_exit(env);
		}
		if (env->img.gnl_error == 1)
			clean_exit(env);
		game_loop(env);
	}
	return (exit_error());
}
