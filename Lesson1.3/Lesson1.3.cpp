// Lesson1.3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 2

struct name
{
	const char* token;
	union {
		int ival;
		const char* sval;
	} u;
} symtab[SIZE];

void show(struct name val)
{
	if (strcmp(val.token, "integer") == 0)
		printf("\n%s union value %d ", val.token, val.u.ival);
	else printf("\n%s union value %s ", val.token, val.u.sval);
}


void main() {
	int i = 0;
	symtab[0].token = "integer";
	symtab[0].u.ival = 8;
	symtab[1].token = "string";
	symtab[1].u.sval = "someValue";

	for (; i < SIZE; i++)
		show(symtab[i]);
}


