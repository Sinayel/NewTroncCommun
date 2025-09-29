/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanis <yanis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:16:15 by yanis             #+#    #+#             */
/*   Updated: 2025/09/29 15:31:39 by yanis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
// # define BUFFER_SIZE 4

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*save(char *stash);
char	*take_line(char *tmp);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);

#endif