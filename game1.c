#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

int GetLoc(char map[], int size) 
{
    for (int i = 0; i < 200; i++)
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
    char world[] =  "####################\n"
                    "#                  #\n"
                    "#####----##        #\n"
                    "#         #        #\n"
                    "#         # ########\n"
                    "#    ######        #\n"
                    "#         #####    #\n"
                    "#####     |       ##\n"
                    "#         #       *#\n"
                    "###### #############\n";

    int world_leng = sizeof(world) / sizeof(world[0]);
    int new_pos;

    srand(time(NULL));

    for (int i = 0; i < 5; i++)
    {
        while (1) 
        {
            int rand_loc = random_in_range(0, world_leng - 1);
            if (world[rand_loc] == ' ') 
            {
                world[rand_loc] = '$';
                break;
            }
        }
    }

    // main game
    while (1)
    {
        system("cls");
        printf("%s", world);
        int pos = GetLoc(world, world_leng);
        if (pos == -1) break;


        ch = _getch();
        new_pos = pos;
        if (ch == 27) {
            break;
        }
        if (ch == 'w') {
            new_pos -= 21;
        }
        else if (ch == 'a') {
            new_pos -= 1;
        }
        else if (ch == 's' ) {
            new_pos += 21;
        }
        else if (ch == 'd' ) {
            new_pos += 1;
        }


        if (world[new_pos] != '#')
        {
            world[pos] = ' ';
            world[new_pos] = '*';
        }

        Sleep(1);
    }

    
    printf("Press button to Exit...");
    getch();

    return 0;
}
