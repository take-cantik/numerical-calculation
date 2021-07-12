/* ニュートン法 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* f(x)に解きたい方程式を埋める． */
double  f(double x) {
    return cos(x) - x;
}

/* df(x) は f(x) の導関数 */
double df(double x) { 
    return -sin(x) - 1;
}

// ここにニュートン法のプログラムを埋める．
// 途中経過の出力は次のようにする．
// printf("%2d x=%9.6lf f(x)=%9.6lf f'(x)=%9.6lf\n", i, x, y, dy);
void newton(double *x) {
  double y, dy;
  double x_old;
  int i = 0;

  while (1) {
    i++;
    
    x_old = *x;
    y = f(x_old);
    dy = df(x_old);
    
	printf("%2d x=%9.6lf f(x)=%9.6lf f'(x)=%9.6lf\n", i, *x, y, dy);
	
	*x = x_old - (y / dy);
    if (fabs(*x - x_old) < 0.000001f) {
        break;
    }
  }
}

int main(void) {
  double x = 1.3;
  newton(&x);
  
  // 最終的な結果の出力 
  printf("x=%9.6lf f(x)=%9.6lf\n\n", x, f(x));
  return 0;
}

