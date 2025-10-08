/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanis <yanis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:30:51 by yanis             #+#    #+#             */
/*   Updated: 2025/10/08 23:52:00 by yanis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//! Libft et include dans le gnl.h
//! pour des raison de clonflit avec strlen
# include "../NewGetNextLine/get_next_line.h"
# include "../minilibx-linux/mlx.h"

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
	int		key_w;
	int		key_a;
	int		key_s;
	int		key_d;
	int		gnl_error;
	char	**map;
	void	*img;
	int		width;
	int		height;
	int		mv_count;
	int		i;
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
void		print_error(int i);
void		free_map(char **map);
void		clean_exit(t_env *env);
void		putstr_fd(char *str, int fd);

//! Map
int			init_map(t_env *env, int fd);
void		define_spawn(int x, int y, char **map, int *count);
char		**copy_map(t_env *env);
void		print_map(void);
int			render_map(void);

//? Parsing
int			parsing(t_env *env);
void		check_path(char **map, int x, int y);
int			check_elem(char map, t_env *env);
void 		check_parsing(t_env *env);
void		check_ber(char *str, t_env *env);

//* Handle
int 		handle_key_press(int keycode, t_env *env);
void		handle_keycode(int keycode, int *new_x, int *new_y);
int			handle_key(int keycode, t_env *env);

// Todo Mlx
void		display_image(t_env *env, char *xpm, int x, int y);
void		display_choice(char c, t_env *env, int x, int y);
int			render_map(void);
void 		check_wall(t_env *env, int new_x, int new_y, int keycode);

#endif