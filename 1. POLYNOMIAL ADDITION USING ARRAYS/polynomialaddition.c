#include <stdio.h>

int main() {
    int p1[20] = {0}, p2[20] = {0}, sum[20] = {0};
    int d1, d2, i, max;

    printf("Enter degree of first polynomial: ");
    scanf("%d", &d1);

    printf("Enter coefficients of first polynomial:\n");
    for (i = d1; i >= 0; i--) {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &p1[i]);
    }

    printf("\nEnter degree of second polynomial: ");
    scanf("%d", &d2);

    printf("Enter coefficients of second polynomial:\n");
    for (i = d2; i >= 0; i--) {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &p2[i]);
    }

    max = (d1 > d2) ? d1 : d2;

    // Add corresponding coefficients
    for (i = 0; i <= max; i++)
        sum[i] = p1[i] + p2[i];

    printf("\nSum of polynomials: ");

    for (i = max; i >= 0; i--) {
        if (sum[i] != 0) {
            if (i != max && sum[i] > 0)
                printf(" + ");

            if (i == 0)
                printf("%d", sum[i]);
            else if (i == 1)
                printf("%dx", sum[i]);
            else
                printf("%dx^%d", sum[i], i);
        }
    }

    printf("\n");

    return 0;
}