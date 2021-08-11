#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define maxM 50 /* 近似するデータの最大個数 */

int m; /* 近似するデータの個数 */
double x[maxM]; /* 近似するデータの x   */
double y[maxM]; /* 近似するデータの y   */
/* 近似するデータは(x[0],y[0]),...,(x[m-1],y[m-1]になる) */

#define maxN 10 /* 多項式の最大次数＋１ */
int n; /* 多項式の次数 */
double c[maxN]; /* 多項式の係数 */
double A[maxN][maxN]; /* 正規方程式の A */
double b[maxN]; /* 正規方程式の b */

int solveOK; /* 正規方程式が解けたか */

// x の j 乗の計算
double g(double x, int j) {
  int i;
  double wk = 1.0;

  for (i = 0; i < j; ++i) {
    wk *= x;
  }

  return wk;
}

//出来た近似多項式の出力を計算
double calcOutput(double xx) {
  int i;
  double yy = 0.0;

  for (i = 0; i <= n; ++i) {
    yy += c[i] * g(xx, i);
  }

  return yy;
}

// 正規方程式を作る
// すなわち　A と b を作る
void makeAb(void) {
  int i, j, k;
  double wk;

  for (i = 0; i <= n; ++i) {
    for (j = 0; j <= n; ++j) {
      wk = 0.0;
      for (k = 0; k <= m - 1; k++) {
        wk += g(x[k], i + j);
      }
      A[i][j] = wk;
    }
  }

  for (i = 0; i <= n; ++i) {
    wk = 0.0;
    for (j = 0; j <= m - 1; j++) {
      wk += g(x[j], i) * y[j];
    }
    b[i] = wk;
  }
}


void swap(double *wk1, double *wk2) {
  double tmp;
  tmp = *wk1;
  *wk1 = *wk2;
  *wk2 = tmp;
}

// 正規方程式をガウスジョルダン法で解く
// ピボットがプログラム中のEPSILONより小さくなって解けないときは false を返す．
// ピボットが小さいと丸め誤差の影響を受け，正しい解が得られなくなる．
void solveAb(void) {
  int i, j, k;
  double EPSILON = 1e-15;

  for (k = 0; k <= n; ++k) {
    double ak = A[k][k];
    
    if (fabs(ak) <= EPSILON) {
      int ik = k+1;
      
      while (ik <= n && fabs(A[ik][k]) < EPSILON) {
        ++ik;
      }
      
      if (ik <= n) {
        for (j = k; j <= n; ++j) {
          swap(&A[k][j], &A[ik][j]);
        }
        
        swap(&b[k], &b[ik]);
        ak = A[k][k];
      } else {
        printf("Error: ピボットが零です! \n");
        solveOK = 0;
        return;
      }
    }

    for (j = k; j <= n; ++j) {
      A[k][j] /= ak;
    }
    b[k] = b[k] / ak;
    
    for (i = 0; i <= n; ++i) {
      if (i != k) {
        double aik = A[i][k];
        for (j = k; j <= n; ++j) {
          A[i][j] -= aik*A[k][j];
        }
        b[i] -= aik * b[k];
      }
    }
  }

  solveOK = 1;
}

// 多項式の係数を決定
void makeC(void) {
  int i;

  if (solveOK) {
    printf("近似多項式の係数\n");
    for (i = 0; i <= n; ++i) {
      c[i] = b[i];
      printf(" c[%d]=%5.2f\n", i, c[i]);
    }
  } else {
    printf("\n%d 次多項式で近似できません \n", n);
  }
}

int main(void) {
  int i, j;

  m = 10;
  n = 2;
  x[0] = -3.0; y[0] = 19.3;
  x[1] = -2.0; y[1] = 9.9;
  x[2] = -1.0; y[2] = 5.0;
  x[3] =  0.0; y[3] = 1.0;
  x[4] =  1.0; y[4] = 3.0;
  x[5] =  2.0; y[5] = 8.3;
  x[6] =  3.0; y[6] = 20.0;
  x[7] =  4.0; y[7] = 32.8;
  x[8] =  5.0; y[8] = 52.9;
  x[9] =  6.0; y[9] = 72.7;

  printf("近似するデータ\n");
  for (i = 0; i < m; ++i) {
    printf(" (%6.2f %6.2f)\n", x[i], y[i]);
  }

  makeAb();

  // 正規方程式を出力
  printf("正規方程式\n");
  for (i = 0; i <= n; ++i) {
    for (j = 0; j <= n; ++j) {
      printf("%6.2f ", A[i][j]);
    }
    printf("   %6.2f\n", b[i]);
  }

  solveAb();
  makeC();

  // 2乗誤差の計算
  double sum = 0;
  for (i = 0; i < m; ++i) {
    double tmp = calcOutput(x[i]) - y[i];
    sum += tmp * tmp;
  }

  printf("2乗誤差 = %8.4f\n", sum);

  return 0;
}

