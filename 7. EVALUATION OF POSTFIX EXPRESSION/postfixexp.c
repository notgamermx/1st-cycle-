#include <stdio.h>
#include <ctype.h>
#include <string.h>

int stack[100];
int top = -1;

void push(int val) { stack[++top] = val; }
int pop() { return stack[top--]; }
int isEmpty() { return top == -1; }

int evaluatePostfix(char postfix[]) {
    int i, op1, op2, result;

    for (i = 0; i < strlen(postfix); i++) {
        char c = postfix[i];

        // If digit, push to stack
        if (isdigit(c)) {
            push(c - '0');  // convert char to int
        }
        // If operator, pop two operands and calculate
        else {
            op2 = pop();  // second operand popped first
            op1 = pop();  // first operand

            switch (c) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '^':
                    result = 1;
                    for (int j = 0; j < op2; j++) result *= op1;
                    break;
                default:
                    printf("Invalid operator: %c\n", c);
                    return -1;
            }
            push(result);  // push result back
        }
    }
    return pop();  // final result
}

int main() {
    char postfix[100];
    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    int ans = evaluatePostfix(postfix);
    printf("Result: %d\n", ans);
    return 0;
}