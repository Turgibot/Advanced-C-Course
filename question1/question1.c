#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void square(int* p);


void main()
{
	int i = 100;
	int* ptr = &i;
	square(ptr);
	printf("%d     %d", *ptr, i);
}

void square(int* p)
{
	*p *= 2;
}