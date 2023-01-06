#include <stdio.h>
typedef int(*f_ptr)(int, int); 

int	mul(int n, int m) {
	return n * m;
}

int	div(int n, int m) {
	return m ? n / m : 0;
}

int	calc(int n, int	m, f_ptr op) {
	return	op(n, m);
}

int main(int argc, char* argv[]) {
	int x = 4, y = 5;
	printf("calc(x, y, mul) gives %d\n", calc(x, y, mul)); 
	printf("calc(x, y, div) gives %d\n", calc(x, y, div)); 
	return 0;
}