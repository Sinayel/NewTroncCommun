/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanis <yanis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:16:15 by yanis             #+#    #+#             */
/*   Updated: 2025/10/24 00:51:17 by yanis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(char *str);
int		found_new_line(char *stash);
char	*ft_strjoin(char *s1, char *s2);
char	*save(char *stash);
char	*take_line(char *tmp);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);

#endif