#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main()
{
	float x = 10.5;
	float* pf = &x;
	float** ppf = &pf;
	float*** pppf = &ppf;

	printf("x       = %f \t &x=%p\n", x, &x);
	printf("pf     = %p    &px=%p\n", pf, &pf);
	printf("ppf   = %p    &ppx=%p\n", ppf, &ppf);
	printf("pppf = %p    &pppx=%p\n", pppf, &pppf);

	printf("Values of pointers : \n");
	printf("pppf = %p\n", pppf);
	printf("*pppf   = %p\n", *pppf);
	printf("**pppf    = %p\n", **pppf);
	printf("***pppf    = %f\n", ***pppf);
}
