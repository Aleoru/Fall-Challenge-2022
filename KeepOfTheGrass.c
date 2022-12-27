#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

// 1 = me, 0 = foe, -1 = neutral
 typedef struct s_map
 {
    int scrap_amount;
    int owner;
    int units;
    int recycler;
    int can_build;
    int can_spawn;
    int in_range_of_recycler; 
 }  t_map;

int main()
{
    int width;
    int height;
    int to_x;
    int to_y;
    int r_x;
    int r_y;
    scanf("%d%d", &width, &height);
    t_map   map[height][width];

    // game loop
    while (1) {
        int my_matter;
        int opp_matter;
        scanf("%d%d", &my_matter, &opp_matter);
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                scanf("%d%d%d%d%d%d%d", &map[i][j].scrap_amount, &map[i][j].owner, &map[i][j].units, &map[i][j].recycler,
                    &map[i][j].can_build, &map[i][j].can_spawn, &map[i][j].in_range_of_recycler);
            }
        }
        for (int y = 0; y < height; y++)
        {
            int x = 0;
            while (x < width)
            {
                if (map[y][x].owner == 0 && map[y][x].units > 0)
                {
                    to_x = x;
                    to_y = y;
                }
                if (map[y][x].owner == 1 && map[y][x].units == 0)
                {
                    r_x = x;
                    r_y = y;
                }
                if (map[y][x].owner == 1 && map[y][x].units > 0)
                {
                    if (map[y][x + 1].scrap_amount > 0 && x + 1 < width && map[y][x + 1].owner != 1)
                        printf("MOVE %d %d %d %d %d;", map[y][x].units, x, y, x + 1, y);
                    else if (map[y][x - 1].scrap_amount > 0 && x - 1 >= 0 && map[y][x - 1].owner != 1)
                        printf("MOVE %d %d %d %d %d;", map[y][x].units, x, y, x - 1, y);
                    else if (map[y + 1][x].scrap_amount > 0 && y + 1 < height && map[y + 1][x].owner != 1)
                        printf("MOVE %d %d %d %d %d;", map[y][x].units, x, y, x, y + 1);
                    else if (map[y - 1][x].scrap_amount > 0 && y - 1 >= 0 && map[y - 1][x].owner != 1)
                        printf("MOVE %d %d %d %d %d;", map[y][x].units, x, y, x, y - 1);
                    else
                        printf("MOVE %d %d %d %d %d;", map[y][x].units, x, y, to_x, to_y);
                    if (my_matter >= 30)
                        printf("SPAWN %d %d %d;", 1, x, y);
                }
                /*if (map[y][x].owner == 1 && !map[y][x].in_range_of_recycler && my_matter >= 10)
                    printf("BUILD %d %d;", x, y);*/
                x++;
            }
            if (my_matter >= 30)
                printf("SPAWN %d %d %d;", 1, r_x, r_y);
        }
            

        // Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");

        printf("WAIT\n");
    }

    return 0;
}
