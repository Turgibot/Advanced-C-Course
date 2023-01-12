#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

enum week { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };
typedef enum boolean { false, true } bool;
enum designFlags {
	BOLD = 1,
	ITALICS = 2,
	UNDERLINE = 4
};
int main()
{
	enum week today;
	today = Wednesday;
	printf("Day %x\n", today);

	if (today + Sunday == Friday)
		printf("Sunday is the new Friday\n");
	else
		printf("today + Sunday is %x\n", today + Sunday);

	bool isTheEnd = false;
	bool isGuyHappy = true;
	printf("%d\n", isTheEnd && isGuyHappy);

	int myDesign = BOLD | UNDERLINE;
	printf("%d", myDesign);


	return 0;
}

