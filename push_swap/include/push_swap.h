/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanis <yanis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 00:47:22 by yanis             #+#    #+#             */
/*   Updated: 2025/10/27 09:36:18 by yanis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	char			**args;
}					t_data;

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	t_data			data;
}					t_stack;

//! Main
void				push_swap(t_stack **stack_a, t_stack **stack_b);
t_data				*parsing(int argc, char *argv[]);
int					is_sorted(t_stack *stack);
void				sort_three(t_stack **stack);

//? Linked List
t_stack				*init_stack(int argc, char *argv[]);

//* Utils
t_stack				*get_dataS(void);
t_data				*get_data(void);
void				free_stack(t_stack **stack);
int					is_digit_tab(char *argv);
int					tabLen(char **argv);
void				free_tabtab(char **argv);

#endif