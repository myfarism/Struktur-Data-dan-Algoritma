#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 5

struct Stack {
    int top;
    char data[MAX_SIZE];
};

void push(struct Stack *stack, char value) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack->top++;
    stack->data[stack->top] = value;
}

char pop(struct Stack *stack) {
    if (stack->top == -1) {
        printf("Stack underflow!\n");
        return ' ';
    }
    char value = stack->data[stack->top];
    stack->top--;
    return value;
}

void print_stack(struct Stack *stack) {
    printf("Atack         PUSH Data             POP Data\n");
    for (int i = MAX_SIZE - 1; i >= 0; i--) {
        printf("%d", i + 1);
        if (i <= stack->top) {
            printf("                            %c", stack->data[i]);
            if (i == stack->top) {
                printf("           ");
            } else {
                printf("           %c", stack->data[i+1]);
            }
        }
        printf("\n");
    }
}

int main() {
    struct Stack stack;
    stack.top = -1;

    push(&stack, 'A');
    push(&stack, 'B');
    push(&stack, 'C');
    push(&stack, 'D');
    push(&stack, 'E');

    char choice;
    do {
        print_stack(&stack);
        printf("Apakah ada data yang akan dikeluarkan [y/t]? ");
        scanf(" %c", &choice);
        if (choice == 'y') {
            char value;
            printf("Tentukan manakah data yang akan dikeluarkan? ");
            scanf(" %c", &value);
            int index = -1;
            for (int i = stack.top; i >= 0; i--) {
                if (stack.data[i] == value) {
                    index = i;
                    break;
                }
            }
            if (index == -1) {
                printf("Data tidak ditemukan!\n");
            } else {
                for (int i = index; i < stack.top; i++) {
                    stack.data[i] = stack.data[i+1];
                }
                pop(&stack);
            }
        }
    } while (choice == 'y');

    printf("EXIT\n");
    return 0;
}
