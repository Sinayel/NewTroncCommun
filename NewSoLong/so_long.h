/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanis <yanis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:30:51 by yanis             #+#    #+#             */
/*   Updated: 2025/10/02 18:50:18 by yanis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

//! Libft et include dans le gnl.h pour des raison de clonflit avec strlen et strjoin
#include "NewGetNextLine/get_next_line.h"
#include "minilibx-linux/mlx.h"

typedef struct s_data
{
    int x;
    int y;
    int spawn_x;
    int spawn_y;
    int count_c;
    int found_c;
    char **map;
    void *img;
    char *addr;
} t_data;

typedef struct s_env
{
    void *mlx;
    void *win;
    t_data img;
} t_env;

t_env	*get_data(void);

#endif