#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


void plus(void* pa, void* pb, char type);

int main(int argc, char* argv[])
{
	int x = 2, y = 3;
	char s1[] = "Wawa", s2[] = "wiwa!";
	plus(&x, &y, 'i');
	plus(s1, s2, 's');
	return 0;


}

void plus(void* pa, void* pb, char type) {
	int	t_int;
	char* t_string;
	switch (type) {
	case 'i':
		t_int = *(int*)pa + *(int*)pb;
		printf("%d + %d = %d\n", *(int*)pa, *(int*)pb, t_int); break;
	case 's':
		t_int = strlen((char*)pa) + strlen((char*)pb) + 1;
		assert(t_string = (char*)malloc(t_int * sizeof(char)));
		strcpy_s(t_string, t_int, (char*)pa);
		strcat_s(t_string, t_int, (char*)pb);
		printf("%s + %s = %s\n", (char*)pa, (char*)pb, t_string);
		free(t_string);
	}
}
