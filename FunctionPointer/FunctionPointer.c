#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


void plus(void* pa, void* pb, void (*fp)(void*, void*));
void add_int(int* pa, int* pb); 
void add_str(char* s1, char* s2);

typedef void(*addfp)(void*, void*);
//void plus(void* pa, void* pb, addfp fp);

int main(int argc, char* argv[])
{
	int a = 1, b = 1; 
	plus(&a, &b, add_int);
	plus("hello ", "world", add_str); 
	return 0;

}

void plus(void* pa, void* pb, void (*fp)(void*, void*)) {
	fp(pa, pb);
}

void add_int(int* pa, int* pb)
{
	printf("%d + %d = %d\n", *pa, *pb, *pa + *pb);
}


void add_str(char* s1, char* s2)
{
	int t_int = strlen(s1) + strlen(s2) + 1; char* t_string;
	assert(t_string = (char*)malloc(t_int * sizeof(char))); 
	strcpy(t_string, s1);
	strcat(t_string, s2);
	printf("%s + %s = %s\n", s1, s2, t_string);
	free(t_string);
}
