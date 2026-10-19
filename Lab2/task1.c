#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159265358979323846

int main() {
  double x;
  printf("Enter x: ");
  scanf("%lf", &x);

  int n;
  printf("Enter n: ");
  scanf("%d", &n);

  int op_c = 0;

  op_c += 1; 
  if (x == 0.0) { 
    printf("cos(0) = 1.0000000\n");
    return 0;
  }

  double P = 1;
  op_c += 1;

  double two_x = 2 * x; 
  op_c += 2;

  op_c += 2; 
  for (int i = -n; i <= n; i++) {
    op_c += 1; 

    int sgn;
    if (i > 0) {
      sgn = 1;
      op_c += 2; 
    } else if (i < 0) {
      sgn = -1;
      op_c += 3; 
    } else {
      sgn = 0;
      op_c += 3; 
    }

    int m = abs(i); 
    op_c += 2;      

    double sum = 0;
    op_c += 1; 

    op_c += 1; 
    for (int j = 1; j <= m; j++) {
      op_c += 1; 
      sum += PI;
      op_c += 2; 
      op_c += 1; 
    }
    op_c += 1; 

    double numerator = two_x - sgn * sum;
    op_c += 3; 
    double denominator = x + sgn * sum;
    op_c += 3; 

    P *= numerator / denominator;
    op_c += 3; 

    op_c += 1; 
  }
  op_c += 1; 

  P *= 0.5;
  op_c += 2;

  double lib = cos(x); 
  op_c += 2;           
  double delta = fabs(P - lib);
  op_c += 3; 

  printf("P: %.7lf\n", P);
  printf("cos(x) (library): %.7lf\n", lib);
  printf("delta: %.7lf\n", delta);
  printf("Number of operation: %d\n", op_c);

  return 0;
}