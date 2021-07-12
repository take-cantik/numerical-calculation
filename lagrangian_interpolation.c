/*
　ラグランジュ補間公式 lagrange.c
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define maxN 20 /* 分点の最大個数 */

int    n;            /* 区間の個数 */
double X[maxN];      /* 各分点の x の値を記憶する */
double Y[maxN];      /* 各分点の y の値を記憶する */

/* 分点の表示を行う */
void printXY()
{
  int k;

  printf("分点\n");
  printf("-------------------------------------------------------\n");
  printf("  k     X[k]       Y[k]\n");
  for (k=0;k<=n;++k)
    printf(" %2d  %9.6f  %9.6f\n", k, X[k],Y[k]);
  printf("-------------------------------------------------------\n");
}

double L(int k, double xx) {
  double p = 1.0;
  int i;

  // ここで，p=(x-X[0])*...*(x-X[k-1])*(x-X[k+1])*...*(x-X[n]) を計算する

  return p;	
}

double Lagrange(double xx) 
{
    int k;
    double sum;

    sum = 0.0;

    // ここでsum = Y[0]*L(0,x)/L(0,X[0])+...+Y[n]*L(n,x)/L(n,X[n])を計算する．

    return sum;
}

int main()
{
  double xx = 1.5;
  int bunten = 4;

  n = bunten - 1;
  X[0] = -1.0; Y[0] = 0.7963;
  X[1] =  0.0; Y[1] = 1.0;
  X[2] =  1.0; Y[2] = 2.7140;
  X[3] =  2.0; Y[3] = 6.9089;

  printXY();

  printf("%9.6f   %9.6f\n", xx, Lagrange(xx));

}

