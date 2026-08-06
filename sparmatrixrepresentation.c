#include <stdio.h>

int main() {
    int a[20][20], t[50][3];
    int rows, cols, i, j, k = 1;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter the matrix:\n");
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            scanf("%d", &a[i][j]);

    // Create tuple representation
    t[0][0] = rows;
    t[0][1] = cols;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (a[i][j] != 0) {
                t[k][0] = i;
                t[k][1] = j;
                t[k][2] = a[i][j];
                k++;
            }
        }
    }

    t[0][2] = k - 1;

    printf("\nTuple Representation:\n");
    printf("Row Col Value\n");

    for (i = 0; i < k; i++)
        printf("%d   %d   %d\n", t[i][0], t[i][1], t[i][2]);

    // Transpose
    printf("\nTranspose in Tuple Representation:\n");
    printf("Row Col Value\n");

    printf("%d   %d   %d\n", t[0][1], t[0][0], t[0][2]);

    for (j = 0; j < cols; j++) {
        for (i = 1; i < k; i++) {
            if (t[i][1] == j)
                printf("%d   %d   %d\n",
                       t[i][1], t[i][0], t[i][2]);
        }
    }

    return 0;
}