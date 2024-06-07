#include <stdio.h>
#include <windows.h>

int maxSize = 6, i;
char data[6][6] = {"A", "B", "C", "D", "E"}, pilihan, pop[6][6];

void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int main()
{
    gotoxy(0,0);printf("Attach");
    gotoxy(9, 0);printf("PUSH Data");

    for(i=1; i<=7; i++)
    {
        gotoxy(3, 8-i);printf("%d", i);
    }

    for(i=0; i<=7; i++)
    {

        gotoxy(14, 7-i);printf("%s", data[i]);
    }

    gotoxy(0, 8);printf("\nTentukan manakah data yang akan dikeluarkan? ");
    scanf("%c", &pilihan);

    if(pilihan == 1)
    {

    }


    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

}
