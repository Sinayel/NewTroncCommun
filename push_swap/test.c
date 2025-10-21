#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct s_data
{
    int i;
    struct s_data *next;
}               t_data;

t_data *init_lst(t_data *data, int nb)
{
    data = malloc(sizeof(t_data));
    if(!data)
        return NULL;
    data->i = nb;
    data->next = NULL;
    return data;
}

t_data *add_back(t_data *data, int str)
{
    t_data *tmp;
    t_data *new_node;
    new_node = malloc(sizeof(t_data));
    if(!new_node)
        return data;
    new_node->i = str;
    new_node->next = NULL;
    if(!data)
        return new_node;
    tmp = data;
    while(tmp->next)
        tmp = tmp->next;
    tmp->next = new_node;
    return data;
}

t_data *add_front(t_data *data, int str)
{
    t_data *new_node = malloc(sizeof(t_data));
    if(!new_node)
        return data;
    new_node->i = str;
    new_node->next = data;
    return new_node;
}

void print_list(t_data *data)
{
    int i = 0;
    while(data)
    {
        printf("%d\n", data->i);
        data = data->next;
        i++;
    }
}

int	ascending(int a, int b)
{
	return (a <= b);
}

t_data	*sort_list(t_data *lst, int (*cmp)(int, int))
{
    t_data *tmp = lst;
    int nb = 0;
    if(tmp)
    {
        while(tmp && tmp->next)
        {
            if(!cmp(tmp->i, tmp->next->i))
            {
                nb = tmp->i;
                tmp->i = tmp->next->i;
                tmp->next->i = nb;
                tmp = lst;
            }
            tmp = tmp->next;
        }
    }
    return lst;
}

int main(int argc, char *argv[])
{
    t_data *data;
    srand(time(NULL));
    int rd = rand() % 100;
    int i = 0;
    data = init_lst(data, rd);
    rd = rand() % 100;
    while(++i < 10)
    {
        data = add_back(data, rd);
        rd = rand() % 100;
    }
    printf("Liste avant trie :\n");
    print_list(data);
    printf("\nListe triee :\n");
    data = sort_list(data, ascending);
    print_list(data);
    return 0;
}
