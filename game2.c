#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

int Where(char map[], int map_size, char obj) {
    for (int i = 0; i < map_size; i++) {
        if (map[i] == obj) return i;
    }
    return -1;
}

void Debug_Info(char map[], int map_size, int where_plr, int where_obj, int path_contrl) {
    printf("<---debug---\n");
    printf("map size: %d\n\n", map_size);
    printf("where plr: %d\n", where_plr);
    printf("print plr: %c\n\n", map[where_plr]);
    
    printf("where obj: %d\n", where_obj);
    printf("print obj: %c\n\n", map[where_obj]);
    
    printf("path contrl: %d\n", path_contrl);
    printf("---debug--->\n");
}

int game2(void) {
    char map[] = 
    "                                                   \n"
    "                                                   \n"
    "                                                   \n"
    "                                                   \n"
    "      ?                                            \n"
    "      @                                            \n"
    "   #####       ####    #######     #####           \n";

    char c;
    const char PLR = '@';
    int map_size = sizeof(map) / sizeof(map[0]);
    int where_plr = Where(map, map_size, PLR);
    int where_obj = Where(map, map_size, '?');
    int path_contrl = where_plr - where_obj;
    int new_pos = where_plr;
    
    Debug_Info(map, map_size, where_plr, where_obj, path_contrl);
    getch();

    while (1) {
        where_plr = Where(map, map_size, PLR);
        if (where_plr == -1) break;

        system("cls");
        printf("%s", map);


        // if (_kbhit()) временно закрыт _kbhit
        // {


        c = _getch();
        // printf("button: %c, ascii: %d\n", c, c);

        new_pos = where_plr;

        if (c == 32 && map[where_plr + path_contrl] == '#')
        { 
            for (int i = 0; i < 3; i++)
            {
                new_pos -= (path_contrl);
            }
            
        } 
        else if (c == 's')
        {
            // new_pos += (path_contrl);
        } 
        else if (c == 'a')
        { 
            new_pos -= 1;
        } 
        else if (c == 'd') 
        { 
            new_pos += 1;
        } 
        else if (c == 3) break; 

        // } временно закрыт _kbhit

        if (map[new_pos + path_contrl] != '#')
        {
            new_pos += (path_contrl);
            // Sleep(100);
        }

        // можно ли переместить игрока
        if (map[new_pos] != '#') {
            map[where_plr] = ' ';
            map[new_pos] = PLR;
        }

        
        Sleep(1);

    }

    printf("Press button to Exit...");
    getch();

    return 0;
}
