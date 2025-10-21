/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanis <yanis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:09:50 by yanis             #+#    #+#             */
/*   Updated: 2025/10/22 00:43:04 by yanis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct s_stack
{
	int nb;
	int id;
	struct s_stack *next;
} t_stack;

#endif