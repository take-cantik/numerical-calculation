#include <stdio.h>
#define N 20    
#define M (2*N) 

double Ab[N][M];

void printAb(int n, int m) {
  int j, i;

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
	int n;
	int m;
	double m_ik;
	double U[N][N], y[N];
	double x[N];

	printf("- Solving linear equations with Gaussian elimination method -\n");
	printf("\n");

	n = 3;
	m = n + 1;
	
	/* Ab[][] */
	Ab[0][0] = 2; Ab[0][1] = 3; Ab[0][2] = 3; Ab[0][3] = 1;
	Ab[1][0] = 1; Ab[1][1] = 2; Ab[1][2] = 3; Ab[1][3] = 2;
	Ab[2][0] = 3; Ab[2][1] = 2; Ab[2][2] = 1; Ab[2][3] = 2;

	printAb(n, m);
	
	for (k = 0; k < n; k++) {
	  for (j = k + 1; j < m; j++) {
		Ab[k][j] = Ab[k][j] / Ab[k][k];
	  }
	  Ab[k][k] = 1.0;
      for (i = k + 1; i < n; i++) {
	 	for (j = k + 1; j < m; j++) {
	 	  Ab[i][j] = Ab[i][j] - Ab[i][k] * Ab[k][j];
	 	}
		Ab[i][k]=0.0;
	  }
	  printAb(n, m);
	}
	
	for (k=0; k<n; k++) {
	  for (j=0; j<n; j++) {
	    U[k][j] = Ab[k][j];
	  }
	  y[k] = Ab[k][n];
	}
	
	/* Backward substitution */
	x[n - 1] = y[n - 1] / U[n - 1][n - 1];
	for (k = n - 2; k >= 0; k--) {
	  x[k] = y[k];
	  for (j = k + 1; j < n; j++) {
	    x[k] -= U[k][j] * x[j];
	  }
      x[k] /= U[k][k];
	}

	for (k=0; k<n; k++) {
	  printf("     x[%d]=%8.5lg\n", k, x[k]);
	}
}

