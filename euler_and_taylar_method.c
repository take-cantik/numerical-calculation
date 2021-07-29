#include <stdio.h>
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846264338327950288
#endif

// 関数f
double f(double x, double y) {
  return -6 * y + 5 * exp(-x);
}

// 関数fの変数xに関する偏微分
double fx(double x) {
  return -5 * exp(-x);
}

// 関数fの変数yに関する偏微分
double fy(void) {
  return -6;
}

void fname(void) {
  printf("f = -6*y+5*exp(-x) \n");
}

void setumei(char* s, double x0, double x1, double y0, int n) {
  printf("\n方法:%s  区間:[%5.2f, %5.2f] 初期値:%5.2f 分割数:%d\n", s, x0, x1, y0, n);
}

/* オイラー法 */
void Euler(double x0, double x1, double y0, int n) {
  int k;
  double h = (x1 - x0) / n;
  double x = x0;
  double Y = y0;
  double F;

  setumei("Euler", x0, x1, y0, n);
  fname();

  printf("x=%5.2f Y=%8.5f\n", x, Y);

  for (k = 0; k < n; ++k) {
    //　ここにコードを埋めてオイラー法を完成させる．
    Y = Y + f(x, Y) * h;
    x += h;

    printf("x=%5.2f Y=%8.5f\n", x, Y);
  }
}

/* 2次のテイラー展開法 */
void Taylar2(double x0, double x1, double y0, int n) {
  int k;
  double h = (x1 - x0) / n;
  double x = x0;
  double Y = y0;
  double F;

  setumei("Taylar2", x0, x1, y0, n);
  fname();

  printf("x=%5.2f Y=%8.5f\n", x, Y);
  
  for (k = 0; k < n; ++k) {
    //　ここにコードを埋めて2次のテイラー展開法を完成させる．
    Y = Y + h * f(x, Y) + h * h / 2 * (fx(x) + fy() * f(x, Y));
    x += h;

    printf("x=%5.2f Y=%8.5f\n", x, Y);
  }
}

int main(void) {
  double n = 30; /* 分割数 */
  double x0 = 0.0, x1 = 3.0;
  double y0 = 1.0; /* 初期値 */

  Euler(x0, x1, y0, n);
  Taylar2(x0, x1, y0, n);

  return 0;
}

