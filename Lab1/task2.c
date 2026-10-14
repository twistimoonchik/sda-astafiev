#include <stdio.h>

int main(void)
{
    double x;
    double y;

    printf("Enter x: ");
    scanf("%lf", &x);

    if (x > 0 && x <= 5) {
        y = x * x * x - 5 * x * x;
        printf("y = %g\n", y);
    } else if ((x >= -32 && x < -20) || x > 10) {
        y = x * x - 3;
        printf("y = %g\n", y);
    } else {
        printf("Function not defined\n");
    }

    return 0;
}