#include <stdio.h>

#define N 20    /* 行の最大サイズ */
#define M (N+1) /* 列の最大サイズ */

int n = 3;  /* 実際の行列のサイズ．最大Nまで． */
int m = 4;  /* m=n+1 */
double Ab[N][M];

void printAb(void) {
  int k, j, i;

  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      printf("%8.5lg ", Ab[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

int main(void) {
  int k, j, i;
  char z, zz;

  printf("Gauss-Jordan elimination\n");
  /*** 行列の入力 ***/
  Ab[0][0] = 2; Ab[0][1] = 3; Ab[0][2] =-1; Ab[0][3] = 1;
  Ab[1][0] = 1; Ab[1][1] = 1; Ab[1][2] = 2; Ab[1][3] = 0;
  Ab[2][0] = 3; Ab[2][1] =-1; Ab[2][2] = 1; Ab[2][3] = 2;

  printAb();

  /* Gauss-Jordan elimination */
  
  for (k = 0; k < n; k++) {
	/* ここにガウスジョルダン法のプログラムを書きなさい */
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
	
    printAb();
  }

  for (i = 0; i < n; i++) {
    printf("%4.3f\n", Ab[i][m - 1]);
  }
}

