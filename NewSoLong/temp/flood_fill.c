#include <stdio.h>

#define SIZE 5

void print_save_map(int save_map[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            printf("%d", save_map[i][j]);
        printf("\n");
    }
    printf("\n");
}

void flood_fill(char **map, int x, int y, int save_map[SIZE][SIZE], int *found_p, int *found_e, int *found_c)
{
    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE)
        return;
    if (map[x][y] == '1' || save_map[x][y] == 1)
        return;
    save_map[x][y] = 1;
    if (map[x][y] == 'P')
        *found_p = 1;
    if (map[x][y] == 'E')
        *found_e = 1;
    if (map[x][y] == 'C')
        *found_c = 1;
    flood_fill(map, x - 1, y, save_map, found_p, found_e, found_c);
    flood_fill(map, x + 1, y, save_map, found_p, found_e, found_c);
    flood_fill(map, x, y - 1, save_map, found_p, found_e, found_c);
    flood_fill(map, x, y + 1, save_map, found_p, found_e, found_c);
}

int main()
{
    int save_map[SIZE][SIZE] = {0};
    char *map[SIZE] = {
        "11111",
        "1P001",
        "101C1",
        "10E11",
        "11111"
    };

    int found_p = 0;
    int found_e = 0;
    int found_c = 0;

    printf("Starting flood fill\n\n");
    flood_fill(map, 1, 1, save_map, &found_p, &found_e, &found_c);

    int result = (found_p && found_e && found_c) ? 1 : 0;
    printf("Result (found both P, E and C): %d\n", result);

    printf("Final save_map:\n");
    print_save_map(save_map);
    return 0;
}
