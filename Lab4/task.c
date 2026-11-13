#include <stdio.h>

#define M 9   
#define N 9   

int binary_search_2(float A[M][N], int col, float x, int *steps)
{
    int L = 0, R = M - 1, i, res;

    *steps = 0;
    while (L < R)
    {
        i = (L + R) / 2;
        (*steps)++;
        if (A[i][col] > x)   
            L = i + 1;
        else                 
            R = i;
    }
    if (A[R][col] == x)      
        res = R;
    else
        res = -1;
    return res;
}

int main()
{
    float A[M][N] = {
        {35.0, 30.0, 32.5, 31.0, 34.0, 33.5, 35.0, 29.5, 32.0},
        {35.0, 26.5, 27.0, 25.5, 29.0, 28.0, 30.5, 29.5, 26.0},
        {35.0, 26.5, 21.5, 25.5, 24.0, 28.0, 23.5, 29.5, 19.5},
        {28.5, 26.5, 16.0, 20.0, 24.0, 28.0, 18.0, 29.5, 19.5},
        {22.0, 26.5, 16.0, 14.5, 24.0, 21.0, 18.0, 20.5, 19.5},
        {22.0, 19.0, 16.0,  9.0, 17.5, 21.0, 12.0, 14.0, 19.5},
        {15.5, 12.5, 16.0,  3.5, 11.0, 21.0, 12.0,  7.5, 10.0},
        { 9.0,  5.0,  8.5,  3.5,  4.5,  6.0, 12.0,  2.0,  4.0},
        { 2.5, -3.0,  1.0,  3.5, -2.0,  0.0, 12.0, -1.5,  0.0}
    };
    float x;
    int i, j, r, steps, total = 0, found = 0;

    printf("Matrix A[%d,%d]:\n", M, N);
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
            printf("%6.1f", A[i][j]);
        printf("\n");
    }

    printf("\nEnter X: ");
    scanf("%f", &x);
    printf("\n");

    for (j = 0; j < N; j++)
    {
        r = binary_search_2(A, j, x, &steps);
        total += steps;
        if (r != -1)
        {
            printf("A[%d][%d] = %.1f;\n", r + 1, j + 1, x);
            found = 1;
        }
    }
    if (!found)
        printf("Number %.2f not found.\n", x);

    printf("\nBinary search steps: %d (linear search: up to %d)\n", total, M * N);

    return 0;
}