#include <stdio.h>
#include <ctype.h>

#define MAX_SIZE 100

char infix[MAX_SIZE];
char postfix[MAX_SIZE];
char stack[MAX_SIZE];
int top = -1;

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

void push(char op) {
    stack[++top] = op;
}

char pop() {
    if (top == -1) {
        return -1;
    } else {
        return stack[top--];
    }
}

int is_operand(char ch) {
    return isalnum(ch);
}

int is_operator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

void infix_to_postfix() {
    int i, j = 0;
    char ch;

    for (i = 0; infix[i] != '\0'; i++) {
        if (is_operand(infix[i])) {
            postfix[j++] = infix[i];
        } else if (is_operator(infix[i])) {
            while (top != -1 && precedence(infix[i]) <= precedence(stack[top])) {
                ch = pop();
                if (ch != -1) {
                    postfix[j++] = ch;
                }
            }
            push(infix[i]);
        } else if (infix[i] == '(') {
            push(infix[i]);
        } else if (infix[i] == ')') {
            while ((ch = pop()) != '(') {
                postfix[j++] = ch;
            }
        }
    }
    while (top != -1) {
        ch = pop();
        if (ch != -1) {
            postfix[j++] = ch;
        }
    }
    postfix[j] = '\0';
}

int main() {
    printf("Masukkan notasi infix: ");
    scanf("%s", infix);
    infix_to_postfix();
    printf("Notasi postfix: %s\n", postfix);
    return 0;
}
