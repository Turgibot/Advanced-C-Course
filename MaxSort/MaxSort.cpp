#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef int (*comp_fp)(void* a, void* b);

int comp_int(void* a, void* b)
{
	return *(int*)a - *(int*)b;
}
int comp_int_desc(void* a, void* b)
{
	return *(int*)b - *(int*)a;
}

int find_max_idx(void* arr, int num_elements, int element_size, comp_fp fp)
{
	int idx = 0;
	for (int i = 1; i < num_elements; i++)
		if (fp((char*)arr + i * element_size, (char*)arr + idx * element_size) > 0)
			idx = i;
	return idx;
}
void swap(void* a, void* b, int num_bytes)
{
	char* temp = (char*)malloc(num_bytes); 
	assert(temp);
	for (int i = 0; i < num_bytes; i++)
	{
		temp[i] = ((char*)a)[i]; ((char*)a)[i] = ((char*)b)[i]; ((char*)b)[i] = temp[i];
	}
	free(temp);
}

void max_sort(int* arr, int num_elements, int element_size, comp_fp fp)
{
	for (int len = num_elements; len > 1; len--)
	{
		int idx = find_max_idx(arr, len, element_size, fp);
		swap((char*)arr + idx * element_size, (char*)arr + (len - 1) * element_size, element_size);
	}
}

int main()
{
	int arr1[] = { 120,55,80,4,-8,0,100 };
	int n1 = 7;
	max_sort(arr1, n1, sizeof(int), comp_int);
	for (size_t i = 0; i < n1; i++)
	{
		printf("%d ", arr1[i]);
	}
	printf("\n");
	max_sort(arr1, n1, sizeof(int), comp_int_desc);
	for (size_t i = 0; i < n1; i++)
	{
		printf("%d ", arr1[i]);
	}

	return 0;
}

