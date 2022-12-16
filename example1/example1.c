#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void main()
{
	FILE* pFile;
	char buffer[80];

	pFile = fopen("myfile.txt", "rt");
	if (pFile == NULL) {  //file does not exists
		printf("Error opening file");
		exit(1);
	}
	else {
		while (!feof(pFile))
			if (fgets(buffer, 80, pFile) != NULL)
				printf("%s", buffer);
		fclose(pFile);
	}
}
