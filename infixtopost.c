#include <stdio.h>
#include <string.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }
char peek() { return stack[top]; }
int isEmpty() { return top == -1; }

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

void infixToPostfix(char infix[]) {
    char postfix[100];
    int j = 0;

    for (int i = 0; i < strlen(infix); i++) {
        char c = infix[i];

        // If operand, add to output
        if (isalnum(c)) {
            postfix[j++] = c;
        }
        // If '(', push to stack
        else if (c == '(') {
            push(c);
        }
        // If ')', pop until '('
        else if (c == ')') {
            while (!isEmpty() && peek() != '(')
                postfix[j++] = pop();
            pop(); // remove '('
        }
        // If operator
        else if (isOperator(c)) {
            while (!isEmpty() && precedence(peek()) >= precedence(c))
                postfix[j++] = pop();
            push(c);
        }
    }

    // Pop remaining operators
    while (!isEmpty())
        postfix[j++] = pop();

    postfix[j] = '\0';
    printf("Infix   : %s\n", infix);
    printf("Postfix : %s\n", postfix);
}

int main() {
    char infix[100];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix);
    return 0;
}