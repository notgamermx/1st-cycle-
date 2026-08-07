#include <stdio.h>
#define MAX 10

int arr[MAX];
int top1 = -1;
int top2 = MAX;

int isFull()  { return top1 + 1 == top2; }
int isEmpty1(){ return top1 == -1;        }
int isEmpty2(){ return top2 == MAX;       }

void push(int x, int s) {
    if (isFull()) {
        printf("Memory Full! Cannot push %d onto Stack %d\n", x, s);
        return;
    }
    if (s == 1) {
        arr[++top1] = x;
        printf("Pushed %d onto Stack 1  [top1=%d]\n", x, top1);
    } else if (s == 2) {
        arr[--top2] = x;
        printf("Pushed %d onto Stack 2  [top2=%d]\n", x, top2);
    } else {
        printf("Invalid stack number! Use 1 or 2.\n");
    }
}

void pop(int s) {
    if (s == 1) {
        if (isEmpty1()) { printf("Stack 1 Underflow!\n"); return; }
        printf("Popped %d from Stack 1\n", arr[top1--]);
    } else if (s == 2) {
        if (isEmpty2()) { printf("Stack 2 Underflow!\n"); return; }
        printf("Popped %d from Stack 2\n", arr[top2++]);
    } else {
        printf("Invalid stack number! Use 1 or 2.\n");
    }
}

void peek(int s) {
    if (s == 1) {
        if (isEmpty1()) { printf("Stack 1 is Empty!\n"); return; }
        printf("Top of Stack 1: %d\n", arr[top1]);
    } else if (s == 2) {
        if (isEmpty2()) { printf("Stack 2 is Empty!\n"); return; }
        printf("Top of Stack 2: %d\n", arr[top2]);
    } else {
        printf("Invalid stack number! Use 1 or 2.\n");
    }
}

void display() {
    printf("\n--- Array State (size=%d) ---\n", MAX);
    printf("Index: ");
    for (int i = 0; i < MAX; i++) printf("[%2d] ", i);
    printf("\nValue: ");
    for (int i = 0; i < MAX; i++) {
        if (i <= top1)      printf("[%2d] ", arr[i]);
        else if (i >= top2) printf("[%2d] ", arr[i]);
        else                printf("[ __] ");
    }
    printf("\n");
    printf("Stack 1: ");
    if (isEmpty1()) printf("(empty)");
    for (int i = 0; i <= top1; i++) printf("%d ", arr[i]);
    printf("\nStack 2: ");
    if (isEmpty2()) printf("(empty)");
    for (int i = MAX-1; i >= top2; i--) printf("%d ", arr[i]);
    printf("\nFree slots: %d\n", top2 - top1 - 1);
    printf("-----------------------------\n");
}

int main() {
    int choice, val, s;
    while (1) {
        printf("\n1.Push  2.Pop  3.Peek  4.Display  5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value and stack (1 or 2): ");
                scanf("%d %d", &val, &s);
                push(val, s);
                break;
            case 2:
                printf("Enter stack (1 or 2): ");
                scanf("%d", &s);
                pop(s);
                break;
            case 3:
                printf("Enter stack (1 or 2): ");
                scanf("%d", &s);
                peek(s);
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}