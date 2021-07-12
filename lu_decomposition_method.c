#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define N 20    /* 行の最大サイズ */

double A[N][N];
double L[N][N];
double U[N][N];
double x[N];
double y[N];
double b[N];
int n;  /* 行列の実際のサイズ．最大 N まで．*/

void printAb(void) {
  int k, j, i;
  /*行列 Ab[][] の表示*/
  printf("A  b\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%8.5lg ", A[i][j]);
    }
    printf("    %8.5lg ", b[i]);
    printf("\n");
  }
  printf("\n");
}

void printLUxy(void) {
  int k, j, i;
  /*行列 Ab[][] の表示*/
  printf("L  U  x  y\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%6.4lg ", L[i][j]);
    }
    printf("    ");
    for (j = 0; j < n; j++) {
      printf("%6.4lg ", U[i][j]);
    }
    printf("    %6.4lg ", x[i]);
    printf("    %6.4lg ", y[i]);
    printf("\n");
  }
  printf("\n");
}

void LUdecomposition(void) {
  int k,j,i;
  /* ここにLU分解のコードを埋めなさい． */
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (i == j) {
        L[i][j] = 1;
      } else {
        L[i][j] = 0;
      }
      U[i][j] = 0;
    }
  }
  
  for (j = 0; j < n; j++) {
    U[0][j] = A[0][j];
    for (i = 1; i <= j; i++) {
      U[i][j] = A[i][j];
      for (k = 0; k < i; k++) {
        U[i][j] -= L[i][k] * U[k][j];
      }
    }
    
    for (i = j + 1; i < n; i++) {
      L[i][j] = A[i][j];
      for (k = 0; k < j; k++) {
        L[i][j] -= L[i][k] * U[k][j];
      }
      L[i][j] /= U[j][j];
    }
  }
}

void solveY(void) {
  int j,k;
  y[0] = b[0] / L[0][0];
  for (k = 1; k < n; k++) {
    y[k] = b[k];
    for (j = 0; j < k; j++) {
      y[k] -= L[k][j] * y[j];
    }
    y[k] /= L[k][k];
  }
}

void solveX(void) {
  int j,k;
  x[n - 1] = y[n - 1] / U[n - 1][n - 1];
  for (k = n - 2; k >= 0; k--) {
    x[k] = y[k];
    for (j = k + 1; j < n; j++) {
      x[k] -= U[k][j] * x[j];
    }
    x[k] /= U[k][k];
  }
}


void initAb(void) {
  n = 3;
  A[0][0] =  5; A[0][1] =  4; A[0][2] =  1; 
  A[1][0] = 10; A[1][1] =  9; A[1][2] =  4; 
  A[2][0] = 10; A[2][1] = 13; A[2][2] = 15;
  b[0] =  3.4;
  b[1] =  8.8;
  b[2] = 19.2;
}

int main(void) {
  initAb();
  printAb();
  
  LUdecomposition();
	
  solveY();
  solveX();
  
  printLUxy();
  
  return 0;
}

