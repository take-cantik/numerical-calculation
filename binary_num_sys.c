#include <stdio.h>
#include <math.h>

double f(double x) {
    return x * cosh(x) - 1;
}

void bisection(double xl_init, double xr_init) {
	double xc, xl, xr;
	double yc, yl, yr;
	int i = 0;

	xl = xl_init;
    yl = f(xl);
	xr = xr_init;
    yr = f(xr);
	
    while (xr - xl > 0.000001) {
        i++;
		xc = (xl + xr) / 2;
		yl = f(xl);
		yr = f(xr);
		yc = f(xc);
		printf("%2d %9.6f %9.6lf %9.6lf \n", i, xl, xc, xr);
		printf("   %9.6f %9.6lf %9.6lf \n", yl, yc, yr);

		if (yc * yr <= 0.0) {
		    xl = xc;
		} else {
		    xr = xc;
		}
	}

	yc = f(xc);
	printf("x=%9.6lf f(x)=%9.6lf\n\n", xc, yc);
}

int main(void) {
    double xl_init = 0;
    double xr_init = 2;

	bisection(xl_init, xr_init);

    return 0;
}

