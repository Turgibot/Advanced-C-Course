#include<stdio.h>
#include<string.h>

typedef union Data
{
	char cdata;
	int idata;
	float fdata;
	char sdata[20];
} data;

void main()
{
	data d1;
	d1.fdata = 3.14F;
	d1.idata = 10;
	d1.cdata = 65;/// 'A'
	strcpy(d1.sdata, "hi");
	printf("%s \n%c \n%d \n%f \n", d1.sdata, d1.cdata, d1.idata, d1.fdata);
}
