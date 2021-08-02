/*
  Differential equation - Runge-Kutta
*/

#include <stdio.h>
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846264338327950288
#endif

void setumei(char* s, double x0, double x1, double y0, int n) {
  printf("方法:%s  区間:[%5.2f, %5.2f] 初期値:%5.2f 分割数:%d\n", s, x0, x1, y0, n);
}

/* dy/dx = f(x,y) である関数 f(x,y) */
double f(double x, double y) {
  return y - 12 * x + 3;
}

int main(void) {
  double x0 = 0.0; // xの区間
  double x1 = 1.0; // xの区間
  double n = 10;   // 分割数
  double y0 = 1.0; // yの初期値
  int k;
  double h, x, Y;
  double F, k1, k2, k3, k4;

  h = (x1 - x0) / n;
  x = x0;
  Y = y0;
  
  setumei("Runge Kutta 4", x0, x1, y0, n);
  printf("#     xk               Yk\n");
  printf("%5.2f %15.12f\n", x, Y);

  for (k = 0; k < n; ++k) {
    /* ここに4次のルンゲ・クッタ法を埋める */
    k1 = h * f(x, Y);
    k2 = h * f(x + h / 2, Y + k1 / 2);
    k3 = h * f(x + h / 2, Y + k2 / 2);
    k4 = h * f(x + h, Y + k3);
    Y = Y + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
    x += h;

    printf("%5.2f %15.12f\n", x, Y);
  }

  return 0;
}

