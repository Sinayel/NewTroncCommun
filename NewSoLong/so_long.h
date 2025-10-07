/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanis <yanis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:30:51 by yanis             #+#    #+#             */
/*   Updated: 2025/10/07 04:43:31 by yanis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//! Libft et include dans le gnl.h
//! pour des raison de clonflit avec strlen
# include "NewGetNextLine/get_next_line.h"
# include "minilibx-linux/mlx.h"

typedef struct s_data
{
	int		x;
	int		y;
	int		spawn_x;
	int		spawn_y;
	int		count_c;
	int		found_c;
	int		found_e;
	int		found_p;
	char	**map;
	void	*img;
	int		width;
	int		height;
	int		mv_count;
	int		obj;
}			t_data;

typedef struct s_env
{
	void	*mlx;
	void	*win;
	t_data	img;
}			t_env;

//* Utils
t_env		*get_data(void);
int			count_lines(char *url_map);
int			ft_strlen_map(char *str);
int			print_error(int i);
void		free_map(char **map);

//! Map
int			init_map(t_env *env, int fd);
void		define_spawn(int x, int y, char **map, int *count);
char		**copy_map(t_env *env);
void		print_map(void);
int			render_map(void);

//? Parsing
int			parsing(t_env *env);
void		check_path(char **map, int x, int y);

//Todo Mlx
void	display_image(t_env *env, char *xpm, int x, int y);
void	display_choice(char c, t_env *env, int x, int y);

#endif