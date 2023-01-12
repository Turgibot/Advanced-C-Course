#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void printLights(unsigned char lights)
{
	int j;
	unsigned char mask = 1;
	for (j = 0; j < 8; j++, mask <<= 1)
	{
		if (lights & mask)
			printf("\nroom #%d is lighted", j + 1);
		else
			printf("\nroom #%d is NOT lighted", j + 1);
	}
}

void main()
{
	unsigned char lights = 0x27;
	printLights(lights);
}
