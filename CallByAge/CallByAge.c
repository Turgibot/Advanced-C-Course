#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef void(*age_fp)(int);

void young(int x) {
	printf("%d years old - you are young.\n", x);
}

void old(int y) {
	printf("Age of% d - you are experienced.\n", y);
}

int main(int argc, char* argv[]){
	int age;
	printf("How old are you? ");
	scanf("%d",	&age);
	age_fp fp = (age > 30) ? old : young;
	fp(age);
	return 0;

}

