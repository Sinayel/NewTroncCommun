#include <stdio.h>
#include <stdlib.h>

typedef struct s_data
{
	char			*name;
	struct s_data	*next;
}					t_data;

t_data	*get_data(void)
{
	static t_data	data;

	return (&data);
}

// t_data	*init_lst(char *str)
// {
// 	t_data	*data;

// 	data = malloc(sizeof(t_data));
// 	if (!data)
// 		return (NULL);
// 	data->name = str;
// 	data->next = NULL;
// 	return (data);
// }

// t_data	*add_first(t_data *data, char *str)
// {
// 	t_data	*new_node;

// 	new_node = malloc(sizeof(t_data));
// 	if (!new_node)
// 		return (data);
// 	new_node->name = str;
// 	new_node->next = data;
// 	return (new_node);
// }

t_data *add_back(t_data *data, char *str)
{
    t_data *tmp;
    t_data *new_node;
    new_node = malloc(sizeof(t_data));
    if(!new_node)
        return (data);
    new_node->name = str;
    new_node->next = NULL;
    if(!data)
        return (new_node);
    tmp = data;
    while(tmp->next)
        tmp = tmp->next;
    tmp->next = new_node;

    return (data);
}

t_data	*init_lst(char *str)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->name = str;
	data->next = NULL;
	return (data);
}

t_data *add_back(t_data *data, char *str)
{
    t_data *tmp;
    t_data *new_node;
    new_node = malloc(sizeof(t_data));
    if(!new_node)
        return (data);
    new_node->name = str;
    new_node->next = NULL;
    if(!data)
        return (new_node);
    tmp = data;
    while(tmp->next)
        tmp = tmp->next;
    tmp->next = new_node;
    return data;
}

t_data *add_front(t_data *data, char *str)
{
    t_data *new_node = malloc(sizeof(t_data));
    if(!new_node)
        return data;
    new_node->name = str;
    new_node->next = data;
    return new_node;
}

int	main(int argc, char *argv[])
{
	if (argc >= 2)
	{
		t_data *data;
		data = init_lst(argv[1]);
		int i = 1;
		while (i < argc - 1)
			data = add_front(data, argv[++i]);
		while (data)
		{
			printf("data->name = %s\ndata->ptr = %p\n", data->name, data);
			if (data->next)
				printf("\n");
			data = data->next;
		}
	}
}