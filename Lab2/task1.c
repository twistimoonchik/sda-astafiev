#include <math.h>
#include <stdio.h>
#include <stdlib.h>
 
#define PI 3.14159265358979323846
 
int main() {
  double x = 1;
 
  int n;
  printf("Enter x n: ");
  scanf("%d", &n);
 
  int op_c = 0;
 
  double P = 1;
  op_c += 1;
 
  double two_x = 2 * x; // 2x рахуємо один раз
  op_c += 2;
 
  op_c += 2; // i = -n
  for (int i = -n; i <= n; i++) {
    op_c += 1; // i <= n
 
    // sgn(i): 1, -1 або 0
    int sgn;
    if (i > 0) {
      sgn = 1;
      op_c += 2; // i > 0, sgn = 1
    } else if (i < 0) {
      sgn = -1;
      op_c += 3; // i > 0, i < 0, sgn = -1
    } else {
      sgn = 0;
      op_c += 3; // i > 0, i < 0, sgn = 0
    }
 
    int m = abs(i); // кількість доданків у внутрішній сумі
    op_c += 2;      // виклик abs, =
 
    // внутрішній цикл: сума pi + pi + ... + pi (m разів)
    double sum = 0;
    op_c += 1; // sum = 0
 
    op_c += 1; // j = 1
    for (int j = 1; j <= m; j++) {
      op_c += 1; // j <= m
      sum += PI;
      op_c += 2; // +=
      op_c += 1; // j++
    }
    op_c += 1; // j <= m (якщо false)
 
    double numerator = two_x - sgn * sum;
    op_c += 3; // sgn * sum, -, =
    double denominator = x + sgn * sum;
    op_c += 3; // sgn * sum, +, =
 
    P *= numerator / denominator;
    op_c += 3; // /, *, =
 
    op_c += 1; // i++
  }
  op_c += 1; // i <= n (якщо false)
 
  P *= 0.5;
  op_c += 2;
 
  double lib = cos(x); // еталон для перевірки
  op_c += 2;           // виклик cos, =
  double error = fabs(P - lib);
  op_c += 3; // -, виклик fabs, =
 
  printf("\nP: %.7lf\n", P);
  printf("cos(x) (library): %.7lf\n", lib);
  printf("delta: %.7lf\n", error);
  printf("Number of operation: %d\n", op_c);
 
  return 0;
}