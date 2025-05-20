#include <stdio.h>

int main() {
	int i,j,k;
    int A[3][3], B[3][3], C[3][3];

    printf("Enter elements of first 3x3 matrix (A):\n");
    for ( i = 0; i < 3; i++)
        for ( j = 0; j < 3; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &A[i][j]);
        }

    printf("\nEnter elements of second 3x3 matrix (B):\n");
    for ( i = 0; i < 3; i++)
        for ( j = 0; j < 3; j++) {
            printf("B[%d][%d] = ", i, j);
            scanf("%d", &B[i][j]);
        }

    for ( i = 0; i < 3; i++)
        for ( j = 0; j < 3; j++) {
            C[i][j] = 0;
            for ( k = 0; k < 3; k++)
                C[i][j] += A[i][k] * B[k][j];
        }

    printf("\nResultant matrix after multiplication (C = A x B):\n");
    for ( i = 0; i < 3; i++) {
        for ( j = 0; j < 3; j++)
            printf("%d\t", C[i][j]);
        printf("\n");
    }

    return 0;
}


