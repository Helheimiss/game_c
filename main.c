#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int game1(void);
int game2(void);


int main(void)
{
    char c;
    int choice = 1;
    const char chosen = '$';
    char text[] = 
    "  test 2d maze  \n"
    "  test 2d jump  \n";

    int find_int_text[] = 
    {
        0,
        (sizeof(text) / sizeof(text[0]) - 4) / 2,
        (sizeof(text) / sizeof(text[0]) - 4) / 2 + 2,
        (sizeof(text) / sizeof(text[0]) - 3)
    };

    text[find_int_text[0]] = chosen;
    text[find_int_text[1]] = chosen;
    text[find_int_text[2]] = ' ';
    text[find_int_text[3]] = ' ';

    while (1)
    {
        system("cls");
        printf("select a game or press esc or ctrl+c to exit\n");
        printf("%s", text);
        

        c = _getch();
        // printf("%c %d\n", c, c);

        if (c == 'w' || c == 72)
        {
            text[find_int_text[0]] = chosen;
            text[find_int_text[1]] = chosen;
            text[find_int_text[2]] = ' ';
            text[find_int_text[3]] = ' ';
            choice = 1;
        }
        else if(c == 115 || c == 80)
        {
            text[find_int_text[0]] = ' ';
            text[find_int_text[1]] = ' ';
            text[find_int_text[2]] = chosen;
            text[find_int_text[3]] = chosen;
            choice = 2;
        }
        else if (c == 3 || c == 27) 
        {
            choice = -1;
            break;
        }
        else if(c == 13 || c == 32)
        {
            if (choice == 1)
            {
                game1();
                    
            }
            else if (choice == 2)
            {
                game2();
            }
        }

        
        
    }
    
    // if (choice == 1)
    // {
    //     game1();
            
    // }
    // else if (choice == 2)
    // {
    //     game2();
    // }

    return 0;
}