#include <stdio.h>

void showMat(int** mat, int r, int c) {

	int i, j;
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++)
			printf("%4d", mat[i][j]);
		putchar('\n');
	}
}


void main() {
	int i = 0;
	int A[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
	int* ptrArr[3];
	for (i = 0; i < 3; i++)
		ptrArr[i] = A[i]; // same as &A[i] or &A[i][0]
	showMat(ptrArr, 3, 3);

}
