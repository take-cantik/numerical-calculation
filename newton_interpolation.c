/*
  ニュートンの補間多項式（一般の分点) Newton(x)
*/

#include <stdio.h>
#include <math.h>

#define maxN 20 /* 分点の最大個数 */

int n;            /* 区間の個数 */
double X[maxN];      /* 各分点の x の値を記憶する */
double Y[maxN];      /* 各分点の y の値を記憶する */

/* 分点の表示を行う */
void printXY(void) {
  int k;
  printf("分点\n");
  printf("-------------------------------------------------------\n");
  printf("  k     X[k]       Y[k]\n");

  for (k = 0; k <= n; ++k) {
    printf(" %2d  %9.6f  %9.6f\n", k, X[k], Y[k]);
  }
  printf("-------------------------------------------------------\n");
}

/* 一般の分点の差分商を記憶 F[i][j] は f[X[j],...,X[i]] を表す */
double F[maxN][maxN];

/* 一般の分点の差分商を計算する */
void makeF(void) {
  int i, j;
  double temp;

  // 配付資料の指示にしたって，ここに差分商の配列Fを作成する．
  for (i = 0; i <= n; i++) {
    F[i][i] = Y[i];
  }
  
  for (i = 1; i <= n; i++) {
    for (j = 0; j <= n - i; j++) {
      F[j][i + j] = (F[j + 1][i + j] - F[j][i + j - 1]) / (X[i + j] - X[j]);
    }
  }
  
  

  printf("\n差分商\n");
  printf("-------------------------------------------------------\n");

  for (i = 0; i <= n; i++) {
    for (j = i; j <= n; j++) {
      printf(" %9.6f", F[i][j]);
    }
    printf("\n");
  }
  printf("-------------------------------------------------------\n");
    
  printf("\nNewton補間多項式の係数\n");
  printf("-------------------------------------------------------\n");
 
  for (j = 0; j<= n; j++) {
    printf(" %9.6f", F[0][j]);
  }
  printf("\n");
  printf("-------------------------------------------------------\n");
}

/* 等間隔分点を用いた Newton 補間多項式 */
double Newton(double x) {
  double sum = 0, temp;
  int j, k;

  // ここで
  // pn(x) = c0 + c1*(x-X[0])+c2*(x-X[0])(x-X[1])
  //         + ... + cn*(x-X[0])(x-X[1])...(x-X[n-1])
  // を計算する．
  // ただし、このプログラム中では
  // c0 = F[0][0], c1 = F[0][1], ..., cn = F[0][n]
  // となっている．
  
  for (j = 0; j <= n; j++) {
    temp = F[0][j];
    for (k = 0; k < j; k++) {
      temp *= (x - X[k]); 
    }
    sum += temp;
  }

  return sum;
}

int main(void) {
  int i;
  double x, h;

  n = 4;
  X[0] = 0.0; Y[0] = 0.0;
  X[1] = 5.0; Y[1] = 10.0;
  X[2] = 20.0; Y[2] = -10.0;
  X[3] = 25.0; Y[3] = 5.0;
  X[4] = 40.0; Y[4] = 0.0;

  printXY();

  makeF();
  
  x = X[0];
  h = (X[4] - X[0]) / 20.0;
  for (i = 0; i <= 20; i++) {
    printf("%9.6f   %9.6f\n", x, Newton(x));
    x += h;
  }

  return 0;
}

