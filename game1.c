#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

int GetLoc(char map[], int size) 
{
    for (int i = 0; i < size; i++)
    {
        if (map[i] == '*') 
        {
            return i;
        }
    }
    return -1;
}

int random_in_range(int min, int max) 
{
    return rand() % (max - min + 1) + min;
}

int game1(void) 
{
    char ch;
    char map[] =  "####################\n"
                    "#                  #\n"
                    "#####----##        #\n"
                    "#         #        #\n"
                    "#         # ########\n"
                    "#    ######        #\n"
                    "#         #####    #\n"
                    "#####     |       ##\n"
                    "#         #       *#\n"
                    "###### #############\n";

    int map_leng = sizeof(map) / sizeof(map[0]);
    int new_pos;
    int where_plr;

    srand(time(NULL));

    for (int i = 0; i < 5; i++)
     {
        while (1) 
        {
            int rand_loc = random_in_range(0, map_leng - 1);
            if (map[rand_loc] == ' ') 
            {
                map[rand_loc] = '$';
                break;
            }
        }
    }

    // main game
    while (1) {
        system("cls");
        printf("%s", map);
        where_plr = GetLoc(map, map_leng);
        if (where_plr == -1) break;


        ch = _getch();
        new_pos = where_plr;
        if (ch == 27) break;
        else if (ch == 'w') new_pos -= 21;
        else if (ch == 'a') new_pos -= 1;
        else if (ch == 's' ) new_pos += 21;
        else if (ch == 'd' ) new_pos += 1;


        if (map[new_pos] != '#')
        {
            map[where_plr] = ' ';
            map[new_pos] = '*';
        }

        Sleep(1);
    }

    
    printf("Press button to Exit...");
    getch();

    return 0;
}
