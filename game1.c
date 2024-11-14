#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

int GetLoc(char map[], int size) {
    for (int i = 0; i < 200; i++) {
        if (map[i] == '*') {
            return i;
        }
    }
    return -1;
}

int random_in_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int game1(void) {
    // int frm_upd;
    // printf("Frame update in ms: ");
    // scanf("%d", &frm_upd);
    // frm_upd = frm_upd <= 0 ? 1 : frm_upd;

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

    srand(time(NULL));

    for (int i = 0; i < 5; i++) {
        while (1) {
            int rand_loc = random_in_range(0, world_leng - 1);
            if (world[rand_loc] == ' ') {
                world[rand_loc] = '$';
                break;
            }
        }
    }

    // main game
    while (1) {
        system("cls");
        printf("%s", world);
        int pos = GetLoc(world, world_leng);
        if (pos == -1) break;

        // if (_kbhit()) {
            ch = _getch();
            if (ch == 27) {
                break;
            }
            if (ch == 'w' && world[pos - 21] != '#') {
                world[pos] = ' ';
                world[pos - 21] = '*';
            }
            else if (ch == 'a' && world[pos - 1] != '#') {
                world[pos] = ' ';
                world[pos - 1] = '*';
            }
            else if (ch == 's' && world[pos + 21] != '#') {
                world[pos] = ' ';
                world[pos + 21] = '*';
            }
            else if (ch == 'd' && world[pos + 1] != '#') {
                world[pos] = ' ';
                world[pos + 1] = '*';
            }


            // printf("You pressed: %c (ASCII: %d)\n", ch, ch);
        // }

        Sleep(1);
    }

    
    printf("Press button to Exit...");
    getch();

    return 0;
}
