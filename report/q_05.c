#include <stdio.h>
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846264338327950288
#endif

// dV1/dt
double f_1(double v_1, double v_2, double t) {
  return (-0.2 * v_1 + 0.1 * v_2 + sin(40000 * M_PI * t)) * 100000;
}

// dV2/dt
double f_2(double v_1, double v_2) {
  return (v_1 - v_2) * 10000;
}

int main(void) {
  double t_0 = 0.0;
  double t_1 = 0.0001;
  double n = 40;

  double v1_0 = 0.0;
  double v2_0 = 0.0;

  int k;
  double h, v_1, v_2, t;
  double v1_1, v1_2, v2_1, v2_2;

  h = (t_1 - t_0) / n;
  t = t_0;
  v_1 = v1_0;
  v_2 = v2_0;
  
  for (k = 0; k < n; k++) {
    v1_1 = v_1 + h * f_1(v_1, v_2, t);
    v2_1 = v_2 + h * f_2(v_1, v_2);
    t += h;

    v1_2 = v_1 + h * f_1(v1_1, v2_1, t);
    v2_2 = v_2 + h * f_2(v1_1, v2_1);

    v_1 = (v1_1 + v1_2) / 2;
    v_2 = (v2_1 + v2_2) / 2;

    printf("%d回目： t = %lf[s], V1 = %lf, V2 = %lf\n", k + 1, t, v_1, v_2);
  }

  return 0;
}

