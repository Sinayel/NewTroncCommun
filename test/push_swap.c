#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack
{
    int value;
    int index;
    struct s_stack *next;
}   t_stack;

/* --------------------- UTILS --------------------- */

t_stack *new_node(int value)
{
    t_stack *node = malloc(sizeof(t_stack));
    node->value = value;
    node->index = -1;
    node->next = NULL;
    return node;
}

void append_node(t_stack **stack, int value)
{
    t_stack *new = new_node(value);
    if (!*stack)
        *stack = new;
    else
    {
        t_stack *tmp = *stack;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
    }
}

int stack_size(t_stack *a)
{
    int i = 0;
    while (a)
    {
        i++;
        a = a->next;
    }
    return i;
}

/* --------------------- STACK OPS --------------------- */

void pa(t_stack **a, t_stack **b)
{
    if (!*b)
        return;
    t_stack *tmp = *b;
    *b = (*b)->next;
    tmp->next = *a;
    *a = tmp;
    printf("pa\n");
}

void pb(t_stack **a, t_stack **b)
{
    if (!*a)
        return;
    t_stack *tmp = *a;
    *a = (*a)->next;
    tmp->next = *b;
    *b = tmp;
    printf("pb\n");
}

void ra(t_stack **a)
{
    if (!*a || !(*a)->next)
        return;
    t_stack *first = *a;
    t_stack *tmp = *a;
    while (tmp->next)
        tmp = tmp->next;
    *a = first->next;
    first->next = NULL;
    tmp->next = first;
    printf("ra\n");
}

/* --------------------- INDEXING --------------------- */

void index_stack(t_stack *a)
{
    t_stack *i;
    t_stack *j;
    int rank;

    for (i = a; i != NULL; i = i->next)
    {
        rank = 0;
        for (j = a; j != NULL; j = j->next)
            if (j->value < i->value)
                rank++;
        i->index = rank;
    }
}

/* --------------------- RADIX SORT --------------------- */

void push_swap(t_stack **a, t_stack **b)
{
    int size = stack_size(*a);
    int max_bits = 0;
    int i = 0;
    int j = 0;
    int max_index = size - 1;

    while ((max_index >> max_bits) != 0)
        max_bits++;

    for (i = 0; i < max_bits; i++)
    {
        j = 0;
        while (j < size)
        {
            int num = (*a)->index;
            if (((num >> i) & 1) == 1)
                ra(a);
            else
                pb(a, b);
            j++;
        }
        while (*b)
            pa(a, b);
    }
}

/* --------------------- DISPLAY --------------------- */

void print_stack(t_stack *a, const char *name)
{
    printf("%s: ", name);
    while (a)
    {
        printf("[%d|i=%d] ", a->value, a->index);
        a = a->next;
    }
    printf("\n");
}

/* --------------------- MAIN --------------------- */

int main(int argc, char **argv)
{
    t_stack *a = NULL;
    t_stack *b = NULL;

    if (argc < 2)
    {
        printf("Usage: %s <nombres>\n", argv[0]);
        return 1;
    }

    // Parsing des nombres passés en argument
    for (int i = 1; i < argc; i++)
    {
        char *end;
        long val = strtol(argv[i], &end, 10);

        // Vérification d'erreur : pas un nombre ou dépassement de int
        if (*end != '\0' || val < -2147483648 || val > 2147483647)
        {
            fprintf(stderr, "Erreur: argument invalide '%s'\n", argv[i]);
            return 1;
        }

        append_node(&a, (int)val);
    }

    printf("Pile avant tri :\n");
    print_stack(a, "A");

    // Attribution des indices
    index_stack(a);
    printf("\nIndices attribués :\n");
    print_stack(a, "A");

    // Tri avec le radix sort
    printf("\n--- Tri radix ---\n");
    push_swap(&a, &b);

    printf("\nPile après tri :\n");
    print_stack(a, "A");

    return 0;
}

