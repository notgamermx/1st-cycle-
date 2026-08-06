#include <stdio.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop()        { return stack[top--]; }
int isEmpty()     { return top == -1; }

int isPalindrome(char str[]) {
    int i, len = strlen(str);

    for (i = 0; i < len; i++)
        push(str[i]);

    for (i = 0; i < len; i++) {
        if (str[i] != pop())
            return 0;
    }
    return 1;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    if (isPalindrome(str))
        printf("\"%s\" is a Palindrome\n", str);
    else
        printf("\"%s\" is NOT a Palindrome\n", str);

    return 0;
}