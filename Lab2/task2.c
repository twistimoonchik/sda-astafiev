#include <math.h>
#include <stdio.h>

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

  double t = -n * PI;
  op_c += 3; 

  op_c += 2; 
  for (int i = -n; i <= n; i++) {
    op_c += 1; 

    double numerator = two_x - t;
    op_c += 2; 
    double denominator = x + t;
    op_c += 2; 

    P *= numerator / denominator;
    op_c += 3; 

    t += PI; 
    op_c += 2; 

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