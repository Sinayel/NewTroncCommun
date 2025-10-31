/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanis <yanis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 00:47:22 by yanis             #+#    #+#             */
/*   Updated: 2025/10/31 02:58:55 by yanis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_data
{
	char			**args;
	int				count;
	int				split;
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
void				sort_four_to_five_elements(t_stack **a, t_stack **b);
void				sort_three(t_stack **stack);
int					is_sorted(t_stack *stack);
t_data				*parsing(int argc, char *argv[]);

//? Linked List
t_stack				*init_stack(int argc, char *argv[]);
t_stack				*add_front(t_stack *stack, int nb, int index);
void				free_stack(t_stack **stack);
void 				assign_index(t_stack *stack);
// Commands
void				ft_rotate(t_stack **stack, char name);
void				ft_push(t_stack **from, t_stack **to, char name);
void				ft_reverse_rotate(t_stack **stack, char name);
void				ft_swap(t_stack **stack, char name);

//* Utils
t_data				*get_data(void);
int					strlenStack(t_stack *stack);
int					is_digit_tab(char *argv);
int					tabLen(char **argv);
void				free_tabtab(char **argv);

#endif