#include <stdio.h>
#include <math.h>

double AtXy0_2(void) {
  double data1[] = {0.2, 0.6, 0.8, 1.0, 1.4, 1.6, 2.0, 3.0};
  double data2[] = {0.672, 0.422, 0.359, 0.311, 0.236, 0.207, 0.158, 0.158};
  int n = 8;

  int i;
  double sum = 0.0;
  for (i = 0; i < n; i++) {
    sum += log10(data1[i]) * log10(data2[i]);
  }

  return sum;
}

void printAb(double Ab[2][3]) {
  int i, j;

  for (i = 0; i < 2; i++) {
    for (j = 0; j < 3; j++) {
      printf("%lf ", Ab[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

int main(void) {
  // printf("ans = %lf\n", AtXy0_2());
  // printf("log(489/25) = %lf\n", log10(489.0 / 25.0));
  // printf("log(53 / 5) = %lf\n", log10(53.0 / 5.0));
  // printf("log(2.523) = %lf\n", log10(2.523));

  double Ab[2][3];
  Ab[0][0] = 1.291369; Ab[0][1] = 1.025306; Ab[0][2] = -0.607922;
  Ab[1][0] = 1.025306; Ab[1][1] = 8; Ab[1][2] = 0.401917;
  printAb(Ab);

  int i, j, k;
  int n = 2, m = 3;
  for (k = 0; k < n; k++) {
	  for (j = k + 1; j < m; j++) {
	    Ab[k][j] /= Ab[k][k];
	  }
	  Ab[k][k] = 1;
	  for (i = 0; i < n; i++) {
	    if (i == k) {
	      continue;
	    }
	    for (j = k + 1; j < m; j++) {
	      Ab[i][j] -= Ab[i][k] * Ab[k][j];
	    }
	    Ab[i][k] = 0;
	  }

    printAb(Ab);
  }
  
  printf("b = %lf, A = %lf", Ab[0][2], Ab[1][2]);

  return 0;
}
