#include <stdio.h>

int main(void)
{
    double x;
    double y;

    printf("Enter x: ");
    scanf("%lf", &x);

    if (x <= 0) {
        if (x < -32)
        {
            printf("Function not defined\n");
        } else {
            if (x < -20) 
            {
                y = x*x-3;
                printf("y = %g\n", y);
            } else {
                printf("Function not defined\n");
            } 
        }
    } else {
        if (x <= 5)
        {
            y = x*x*x-5*x*x;
            printf("y = %g\n", y);
        } else {
            if (x <= 10)
            {
               printf("Function not defined\n"); 
            } else {
                y = x*x-3;
                printf("y = %g\n", y);
            }
            
        }
        
    }
    return 0;
}