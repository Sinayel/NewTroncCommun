/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanis <yanis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:09:52 by yanis             #+#    #+#             */
/*   Updated: 2025/10/22 01:14:46 by yanis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *get_data()
{
    static t_stack stack;

    return (&stack);
}

t_stack	*init(t_stack *lst, int nb)
{
	lst = malloc(sizeof(t_stack));
	if (!lst)
		return (NULL);
	lst->nb = nb;
    lst->id = -1;
	lst->next = NULL;
	return (lst);
}

t_stack	*add_back(t_stack *lst, int nb)
{
	t_stack	*tmp;
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (lst);
	new_node->nb = nb;
    new_node->id = -1;
	new_node->next = NULL;
	if (!lst)
		return (new_node);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
	return (lst);
}

void print_list(t_stack *list)
{
    while(list)
    {
        printf("|  %d\t|\n", list->nb);
        printf("|  %d\t|\n", list->id);
        if(list->next)
            printf("---------");
        printf("\n");
        list = list->next;
    }
}

int ft_strlen(t_stack *list)
{
    int i = 0;
    while(list)
    {
        list = list->next;
        i++;
    }
    return i;
}

t_stack *id_list(t_stack *list)
{
    t_stack *tmp;
    t_stack *min_node;
    int len = ft_strlen(list);
    int i;
    int min;

    for (i = 0; i < len; i++)
    {
        tmp = list;
        min = __INT_MAX__;
        min_node = NULL;

        while (tmp)
        {
            if (tmp->id == -1 && tmp->nb < min)
            {
                min = tmp->nb;
                min_node = tmp;
            }
            tmp = tmp->next;
        }

        if (min_node)
            min_node->id = i;
    }
    return list;
}

int main(int argc, char *argv[])
{
    if(argc >= 2) //! A Changer apres sa dois pouvoir prendre autant d'agument que l'on souhaite
    {
        int i = 2;
        t_stack *stack;
        srand(time(NULL));
        int rd = rand() % 100;
        stack = init(stack, atoi(argv[1]));
        rd = rand() % 100;
        while(i <= argc - 1)
        {
            stack = add_back(stack, atoi(argv[i]));
            rd = rand() % 100;
            i++;
        }
        stack = id_list(stack);
        print_list(stack);
    }
}
