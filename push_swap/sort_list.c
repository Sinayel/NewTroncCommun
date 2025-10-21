#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct s_list
{
	int				i;
	struct s_list	*next;
}					t_list;

int	ascending(int a, int b)
{
	return (a <= b);
}

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*tmp;
	int		nb;

	nb = 0;
	tmp = lst;
	if (!tmp)
		return (lst);
	while (tmp && tmp->next)
	{
		if (cmp(tmp->i, tmp->next->i))
		{
			nb = tmp->i;
			tmp->i = tmp->next->i;
			tmp->next->i = nb;
			tmp = lst;
		}
		tmp = tmp->next;
	}
	return (lst);
}

t_list	*init(t_list *lst, int nb)
{
	lst = malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->i = nb;
	lst->next = NULL;
	return (lst);
}

t_list	*add_back(t_list *lst, int nb)
{
	t_list	*tmp;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (lst);
	new_node->i = nb;
	new_node->next = NULL;
	if (!lst)
		return (new_node);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
	return (lst);
}

void	print_lst(t_list *lst)
{
	while (lst)
	{
		printf("%d\n", lst->i);
		lst = lst->next;
	}
}

t_list	*ft_pa(t_list *lst_a, t_list **lst_b)
{
	t_list	*tmp;

	if (!lst_b || !*lst_b)
		return (lst_a);
	tmp = *lst_b;
	*lst_b = (*lst_b)->next;
	tmp->next = lst_a;
	return (tmp);
}

t_list	*ft_pb(t_list *lst_a, t_list **lst_b)
{
    t_list	*tmp;
    if (!lst_a || !*lst_b)
        return (lst_b);
    tmp = lst_a;
    lst_a = lst_a->next;
    tmp->next = *lst_b;
    *lst_b = tmp;
    return (lst_a);
}

t_list	*ft_sa(t_list *lst_a)
{
	t_list	*tmp;
	int		nb;

	tmp = lst_a;
	if (!tmp)
		return (lst_a);
	nb = 0;
	if (tmp && tmp->next)
	{
		nb = tmp->i;
		tmp->i = tmp->next->i;
		tmp->next->i = nb;
	}
	return (lst_a);
}

t_list	*ft_ra(t_list *lst_a)
{
	t_list	*tmp;
	int		first_value;

	tmp = lst_a;
	if (!tmp)
		return (lst_a);
	if (tmp && tmp->next)
	{
		first_value = tmp->i;
		while (tmp->next)
		{
			tmp->i = tmp->next->i;
			tmp = tmp->next;
		}
		tmp->i = first_value;
	}
	return (lst_a);
}

t_list	*ft_rra(t_list *lst_a)
{
	t_list	*tmp;
	int		last_value;
	t_list	*prev;

	tmp = lst_a;
	if (!tmp)
		return (lst_a);
	if (tmp && tmp->next)
	{
		while (tmp->next)
			tmp = tmp->next;
		last_value = tmp->i;
		while (tmp != lst_a)
		{
			prev = lst_a;
			while (prev->next != tmp)
				prev = prev->next;
			tmp->i = prev->i;
			tmp = prev;
		}
		lst_a->i = last_value;
	}
	return (lst_a);
}

int	main(void)
{
	int		j;
	int		rd;
	t_list	*lst;

	srand(time(NULL));
	j = 1;
	rd = rand() % 100;
	lst = init(NULL, rd);
	while (j < 10)
	{
		rd = rand() % 100;
		lst = add_back(lst, rd);
		j++;
	}
	printf("List :\n");
	print_lst(lst);
	// lst = sort_list(lst, ascending);
	lst = ft_rra(lst);
	printf("\nSort List :\n");
	print_lst(lst);
}
