/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanis <yanis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:01:30 by yanis             #+#    #+#             */
/*   Updated: 2025/10/02 11:37:00 by yanis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_env *get_data(void)
{
    static t_env data;

    return (&data);
}

int print_error(int i)
{
    if (i == 1)
    {
        printf("\nMap Error\n");
        return 0;
    }
    else if (i == 2)
    {
        printf("Parsing Error\n");
        return 0;
    }
    else if (i == 3)
    {
        printf("Check Path Error\n");
        return 0;
    }
    return 0;
}

int ft_strlen_map(char *str)
{
    int i;
    i = 0;
    while (str[i] && str[i] != '\n')
        i++;
    return i;
}

int count_lines(char *url_map)
{
    int fd;
    char *line;
    int count;

    fd = open(url_map, O_RDONLY);
    if (fd == -1)
        return (-1);
    count = 0;
    while ((line = get_next_line(fd)))
    {
        if (*line != '\n')
            count++;
        free(line);
    }
    close(fd);
    return (count);
}

char *clean_line(char *str)
{
    int i;
    int j;
    i = 0;
    j = 0;
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    char *clean;
    clean = malloc(sizeof(char) * (ft_strlen_map(str + i) + 1));
    if (!clean)
        return NULL;
    while (str[i])
    {
        clean[j++] = str[i];
        i++;
    }
    clean[j] = '\0';
    free(str);
    return clean;
}

int init_map(char *url_map)
{
    int fd = open(url_map, O_RDONLY);
    if (fd == -1)
        return 0;
    t_env *env;
    env = get_data();
    env->img.x = 0;
    env->img.map = malloc(sizeof(char *) * (count_lines(url_map) + 1));
    char *line;
    int len;
    while ((line = get_next_line(fd)))
    {
        if (*line == '\0')
            continue;
        line = clean_line(line);
        env->img.map[env->img.x] = line;
        if (env->img.x == 0)
            len = ft_strlen_map(env->img.map[env->img.x]);
        env->img.y = ft_strlen_map(env->img.map[env->img.x]);
        if (len != env->img.y)
            return print_error(1);
        env->img.x++;
    }
    env->img.map[env->img.x] = NULL;
    close(fd);
    return 1;
}

void print_map()
{
    t_env *env;
    env = get_data();
    int x;
    x = -1;
    while (env->img.map[++x])
        printf("%s\n", env->img.map[x]);
}

int parsing(t_env *env)
{
    int x;
    int y;
    int seen[256] = {0};
    x = 0;
    y = 0;
    count = 0;
    while (env->img.map[x])
    {
        y = 0;
        while (env->img.map[x][y])
        {
            if(count > 2)
                return (print_error(2));
            if (env->img.map[x][y] != '1' && (x == 0 || x == (env->img.x - 1) || env->img.map[x][0] != '1' || env->img.map[x][env->img.y - 1] != '1'))
                return (print_error(2));
            if(env->img.map[x][y] == 'P' || env->img.map[x][y] == 'E' && !seen[env->img.map[x][y]])
                count++;
            if(env->img.map[x][y] == 'P')
            {
                env->img.spawn_x = x;
                env->img.spawn_y = y;
            }
            y++;
        }
        x++;
    }
    return 1;
}

void flood_fill(char **map, int x, int y, int *found_p, int *found_e, int *found_c)
{
    if (x < 0 || y < 0 || !map[x] || map[x][y] == '\0')
        return;
    if (map[x][y] == '1' || map[x][y] == 'V')
        return;
    if (map[x][y] == 'P')
        *found_p = 1;
    if (map[x][y] == 'E')
        *found_e = 1;
    if (map[x][y] == 'C')
        *found_c = 1;
    map[x][y] = 'V'; // marquer visité
    flood_fill(map, x - 1, y, found_p, found_e, found_c);
    flood_fill(map, x + 1, y, found_p, found_e, found_c);
    flood_fill(map, x, y - 1, found_p, found_e, found_c);
    flood_fill(map, x, y + 1, found_p, found_e, found_c);
}

char **copy_map(t_env *env)
{
    int i = -1;
    char **copy = malloc(sizeof(char *) * (env->img.x + 1));
    while (++i < env->img.x)
        copy[i] = strdup(env->img.map[i]);
    copy[i] = NULL;
    return copy;
}


int main(int argc, char *argv[])
{
    t_env *env;
    env = get_data();
    if (argc == 2)
    {
        if (init_map(argv[1])) //* Init Map Fini
            printf("init map : OK\n");
        if (parsing(env)) //* Parsing Fini
            printf("Parsing : OK\n");
        int found_p, found_e, found_c;
        found_c = 0;
        found_e = 0;
        found_p = 0;
        char **cpy_map = copy_map(env);
        printf("x = %d | y = %d\n", env->img.spawn_x, env->img.spawn_y);
        flood_fill(cpy_map, env->img.spawn_x, env->img.spawn_y, &found_p, &found_e, &found_c);
        printf("e = %d | c = %d | p = %d\n", found_e, found_c, found_p); //TODO: Trouve seulement 1 seul obj C, P ou E
        if(found_c && found_e && found_p)
            printf("Flood fill : OK\n\n");
        // if (check_path(env)) //! Check Path en travaux (il marche pas)
        //     printf("Path : OK\n\n");

        print_map();
    }
    // env.mlx = mlx_init();
    // env.img.x = 1920;
    // env.img.y = 1080;
    // env.win = mlx_new_window(env.mlx, env.img.x, env.img.y, "So Long");
    // env.img.img = mlx_new_image(env.mlx, env.img.x, env.img.y);

    // mlx_loop(env.mlx);
    return (0);
}
