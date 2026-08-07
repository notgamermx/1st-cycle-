#include <stdio.h>

void display(int mat[][3], int n) {
    printf("Row Col Value\n");
    for (int i = 0; i < n; i++)
        printf("%d   %d   %d\n", mat[i][0], mat[i][1], mat[i][2]);
}

int main() {
    int a[20][3], b[20][3], sum[40][3];
    int n1, n2, i = 1, j = 1, k = 1;

    printf("Enter number of non-zero elements in Matrix A: ");
    scanf("%d", &n1);

    a[0][0] = a[0][1] = 0;
    a[0][2] = n1;

    printf("Enter row, column and value for A:\n");
    for (i = 1; i <= n1; i++)
        scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);

    printf("Enter number of non-zero elements in Matrix B: ");
    scanf("%d", &n2);

    b[0][0] = b[0][1] = 0;
    b[0][2] = n2;

    printf("Enter row, column and value for B:\n");
    for (i = 1; i <= n2; i++)
        scanf("%d %d %d", &b[i][0], &b[i][1], &b[i][2]);

    i = j = 1;

    while (i <= n1 && j <= n2) {
        if (a[i][0] == b[j][0] && a[i][1] == b[j][1]) {
            int value = a[i][2] + b[j][2];

            if (value != 0) {
                sum[k][0] = a[i][0];
                sum[k][1] = a[i][1];
                sum[k][2] = value;
                k++;
            }
            i++;
            j++;
        }
        else if (a[i][0] < b[j][0] ||
                (a[i][0] == b[j][0] && a[i][1] < b[j][1])) {
            sum[k][0] = a[i][0];
            sum[k][1] = a[i][1];
            sum[k][2] = a[i][2];
            i++;
            k++;
        }
        else {
            sum[k][0] = b[j][0];
            sum[k][1] = b[j][1];
            sum[k][2] = b[j][2];
            j++;
            k++;
        }
    }

    while (i <= n1) {
        sum[k][0] = a[i][0];
        sum[k][1] = a[i][1];
        sum[k][2] = a[i][2];
        i++;
        k++;
    }

    while (j <= n2) {
        sum[k][0] = b[j][0];
        sum[k][1] = b[j][1];
        sum[k][2] = b[j][2];
        j++;
        k++;
    }

    sum[0][0] = a[0][0];
    sum[0][1] = a[0][1];
    sum[0][2] = k - 1;

    printf("\nSum of Sparse Matrices:\n");
    display(sum, k);

    return 0;
}