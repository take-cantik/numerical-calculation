#include <stdio.h>
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846264338327950288
#endif

// d(v_1) / dt
double f_1(double v_1, double v_2, double t) {
  return (-0.2 * v_1 + 0.1 * v_2 + 0.1 * sin(40000 * M_PI * t)) * 100000;
}

// d(v_2) / dt
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
  double v_1[3], v_2[3];

  double h = (t_1 - t_0) / n;
  double t = t_0;
  v_1[0] = v1_0;
  v_2[0] = v2_0;

  printf(
    "t = %.1f[us], v_1 = %lf[mV], v_2 = %lf[mV]\n",
    t * 1000000, v_1[0] * 1000, v_2[0] * 1000
  );
  
  for (k = 0; k < n; k++) {
    v_1[1] = v_1[0] + h * f_1(v_1[0], v_2[0], t);
    v_2[1] = v_2[0] + h * f_2(v_1[0], v_2[0]);
    t += h;

    v_1[2] = v_1[0] + h * f_1(v_1[1], v_2[1], t);
    v_2[2] = v_2[0] + h * f_2(v_1[1], v_2[1]);

    v_1[0] = (v_1[1] + v_1[2]) / 2;
    v_2[0] = (v_2[1] + v_2[2]) / 2;

    printf(
      "t = %.1f[us], v_1 = %lf[mV], v_2 = %lf[mV]\n",
      t * 1000000, v_1[0] * 1000, v_2[0] * 1000
    );
  }

  return 0;
}

