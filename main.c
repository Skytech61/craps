#include <stdio.h>
#include <stdlib.h>
#include <myconio.h>
#include <time.h>
#include <ctype.h>

#define TRUE    1
#define FALSE   0
#define CONSOLE_WIDTH 120 // 80 default

int main(int argc, char *argv[])
{
    int win = 0, draft = 1, de1 = 0, de2 = 0, sum = 0, firstSum = 0;
    char replay;
    
    srand(time(NULL));

    do
    {
        clrscr();
        
        textcolor(LIGHTBLUE);
        gotoxy(1, 1);
        printf("HELHa");

        textcolor(LIGHTBLUE);
        gotoxy((CONSOLE_WIDTH - 10), 1);
        printf("Montignies");

        textcolor(LIGHTBLUE);
        gotoxy((CONSOLE_WIDTH - 13) / 2, 5);
        printf("JEUX DU CRAPS");

        draft = 1;
        de1 = 1 + rand() % 6;
        de2 = 1 + rand() % 6;
        sum = de1 + de2;

        textcolor(LIGHTCYAN);
        gotoxy((CONSOLE_WIDTH - 11) / 2, 7);
        printf("Jet %d : %d %d\n", draft, de1, de2);

        if (sum == 2 || sum == 3 || sum == 12)
        {
            win = FALSE;
        }
        else
        {
            if (sum == 7 || sum == 11)
            {
                win = TRUE;
            }
            else
            {
                firstSum = sum;

                do
                {
                    draft++;

                    Sleep(1000);
                    textcolor(LIGHTCYAN);
                    for (int i = 0; i < 20; i++)
                    {
                        de1 = 1 + rand() % 6;
                        de2 = 1 + rand() % 6;
                        sum = de1 + de2;

                        clreol();
                        gotoxy((CONSOLE_WIDTH - 11) / 2, 8); 
                        printf("Jet %d : %d %d\n", draft, de1, de2);
                        Sleep(100);
                    }
                }
                while (sum != firstSum && sum != 7);

                if (sum == 7)
                {
                    win = FALSE;
                }
                else
                {
                    win = TRUE;
                }
            }
        }

        if (win)
        {
            textcolor(GREEN);
            gotoxy((CONSOLE_WIDTH - 13) / 2, 10); 
            printf("!!! GAGNE !!!");
        }
        else
        {
            textcolor(RED);
            gotoxy((CONSOLE_WIDTH - 13) / 2, 10); 
            printf("!!! PERDU !!!\n");
        }

        textcolor(MAGENTA);
        gotoxy((CONSOLE_WIDTH - 21) / 2, 20); 
        printf("Recommencer (o/n) ? ");
   
        textcolor(YELLOW);
        fflush(stdin);
        scanf("%c", &replay);
        textcolor(LIGHTGRAY);
    }
    while (tolower(replay) == 'o');

    return 0;
}
