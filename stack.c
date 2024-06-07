#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

#define MAX 7

int top = -1;
char stack[MAX];

bool isFull()
{
    if (top == MAX - 1)
        return true;
    else
        return false;
}

bool isEmpty()
{
    if (top == -1)
        return true;
    else
        return false;
}

void push(char data)
{
    if (isFull())
        printf("Stack overflow\n");
    else
    {
        top++;
        stack[top] = data;
    }
}

char pop()
{
    if (isEmpty())
    {
        printf("Stack underflow\n");
        return -1;
    }
    else
    {
        char data = stack[top];
        top--;
        return data;
    }
}

void display()
{
    COORD coord = {0, 0};
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    printf("Stack\tPUSH Data\tPOP Data\n");
    for (int i = MAX - 1; i >= 0; i--)
    {
        GetConsoleScreenBufferInfo(hConsole, &csbi);
        coord.X = 0;
        coord.Y = csbi.dwCursorPosition.Y + 1;
        SetConsoleCursorPosition(hConsole, coord);

        printf("%d", i + 1);
        if (i <= top)
            printf("\t\t%c", stack[i]);
        else
            printf("\t\t");
        if (i == MAX - 1)
            printf("\t\t");
        else if (i == top + 1)
            printf("\t\t%c", stack[i]);
        printf("\n");
    }
}

int main()
{
    push('A');
    push('B');
    push('C');
    push('D');
    push('E');
    display();

    char choice;
    do
    {
        printf("\nApakah ada data yang akan dikeluarkan? [y/t]? ");
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y')
        {
            char data;
            printf("Tentukan data yang akan dikeluarkan: ");
            scanf(" %c", &data);
            bool found = false;
            for (int i = top; i >= 0; i--)
            {
                if (stack[i] == data)
                {
                    found = true;
                    for (int j = i; j < top; j++)
                    {
                        stack[j] = stack[j + 1];
                    }
                    top--;
                    break;
                }
            }
            if (found)
            {
                printf("%c berhasil dihapus dari stack\n", data);
                display();
            }
            else
            {
                printf("Data tidak ditemukan di dalam stack\n");
            }
        }
    } while (choice != 't' && choice != 'T');

    printf("\nEXIT\n");

    return 0;
}
