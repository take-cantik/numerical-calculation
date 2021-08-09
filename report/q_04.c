#include <stdio.h>
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846264338327950288
#endif

#define maxn  1000

/* 積分する関数 */
double f(double x) { return  4 / (x*x + 1); }         

/* 関数 f の 原始関数 */
double F (double x){ return 4*atan(x);  }

/* 真の積分値 */
double true_value (double F(double), double a, double b) {
    double v=F(b)-F(a);
    printf("解析解         = %13.10f\n", v);
    return v; 
}

/* 関数 f の 積分区間 a から b までの定積分を，
   積分区間を n 等分する台形公式で求める */
double trapezoid(double f(double), double a, double b, int n) {
    double h   = (b-a)/n; /* 分割幅 */
    double x;
    double sum = 0.0;
    double v;
    int i;

    // ここに台形公式のコードを書く．
    for (i = 0; i<=n; i++) {
        x =a + h*i;
        if(i==0 || i==n)
        sum += f(x);
        else
        sum += 2*f(x);
    }
    v = h*sum/2.0;

    printf("trapezoid(%6.4f-%6.4f,%d分割)      = %13.10f\n", a, b, n, v);

    return v;
}

/* 関数 f の 積分区間 a から b までの定積分を，
   積分区間を n 等分するSimpson1/3公式で求める 
   ただし，n は 2 の倍数とする */
double simpson13(double f(double), double a, double b, int n) {
    double h   = (b-a)/n; /* 分割幅 */
    double x;
    double sum = 0.0;
    double v;
    int i;

    // ここにシンプソン1/3公式のコードを書く．
    for (i = 0; i <= n; i++) {
        x = a + h * i;
        if (i == 0 || i == n) {
        sum += f(x);
        } else {
        if (i % 2 == 0) {
            sum += 2 * f(x);
        } else {
            sum += 4 * f(x);
        }
        }
    }
    v = h*sum/3.0;
    printf("Simpson1/3公式(%6.4f-%6.4f,%d分割) = %13.10f\n", a, b, n, v);

  return v;
}

/* 関数 f の 積分区間 a から b までの定積分を，
   積分区間を n 等分するSimpson3/8公式で求める 
   ただし，n は 3 の倍数とする */
double simpson38(double f(double), double a, double b, int n){
    double h   = (b-a)/n; /* 分割幅 */
    double x;
    double sum = 0.0;
    double v;
    int i;

    // ここにシンプソン3/8公式のコードを書く．
    for (i = 0; i <= n; i++) {
        x = a + h * i;
        if (i == 0 || i == n) {
        sum += f(x);
        } else {
        if (i % 3 == 0) {
            sum += 2 * f(x);
        } else {
            sum += 3 * f(x);
        }
        }
    }
    v= 3*h*sum/8;

    printf("Simpson3/8公式(%6.4f-%6.4f,%d分割) = %13.10f\n", a, b, n, v);

  return v;
}

int main()
{
    int n = 50; /* 分割数 */
    double a = 0, b = 1;

    true_value(F, a, b);
    trapezoid (f, a, b, n);
    simpson13 (f, a, b, n);
    simpson38 (f, a, b, n);

    return 0;
}
