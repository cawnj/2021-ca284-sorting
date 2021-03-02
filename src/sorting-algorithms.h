#include <stdio.h>
#include <stdlib.h>

int compare_ints (const void*, const void*);
int compare_ints_reverse (const void*, const void*);
void partial_sort(int*, size_t);
void selection_sort(int*, size_t);
void swap(int*, int*);
void merge_sort_handler(int*, size_t);
void merge_sort(int, int, int*, int*);
int get_max(int*, size_t);
void count_sort(int*, size_t, int);
void radix_sort(int*, size_t);


//
/* C QSort */
// 
// source: Donal Fitzpatrick


int compare_ints (const void *a, const void *b)
{
	const int *da = (const int *) a;
	const int *db = (const int *) b;

	return (*da > *db) - (*da < *db);
}

int compare_ints_reverse (const void *a, const void *b)
{
	const int *da = (const int *) a;
	const int *db = (const int *) b;

	/* flip comparison for reverse compare */
	return (*da < *db) - (*da > *db);
}

void partial_sort(int *arr, size_t arr_size)
{
	/* create array half the size of original */
	size_t sorted_size = arr_size / 2;
	int *aux = (int *)malloc(sizeof(int) * arr_size);
	for ( int i = 0; i < sorted_size; i++ )
		aux[i] = arr[i];
	/* sort this smaller array and overwrite original array */
	qsort(aux, sorted_size, sizeof(int), compare_ints);
	for ( int i = 0; i < sorted_size; i++ )
		arr[i] = aux[i];
	/* heap memory, so we must free */
	free(aux);
}


//
/* Selection Sort */
//
// source: https://www.geeksforgeeks.org/selection-sort/


void selection_sort(int *arr, size_t arr_size)
{
	int i, j, min_idx;
	for (i = 0; i < arr_size-1; i++) {
		min_idx = i;
		/* find smallest value */
		for (j = i; j < arr_size; j++)
			if (arr[j] < arr[min_idx]) 
				min_idx = j;
		/* swap arr[i] with the smallest value */
		swap(&arr[min_idx], &arr[i]);
	} 
}

/* swap two values */
void swap(int *xp, int *yp) 
{ 
	int temp = *xp; 
	*xp = *yp; 
	*yp = temp; 
}


//
/* Merge Sort */
//
// source: https://hackr.io/blog/merge-sort-in-c


/* merge sort handler
	creates secondary array and runs merge sort with correct parameters */
void merge(int *arr, size_t arr_size)
{
	int *aux = (int *)malloc(sizeof(int) * arr_size);
	merge_sort(0, arr_size-1, arr, aux);
	free(aux);
}

void merge_sort(int i, int j, int arr[], int aux[]) {
	if (j <= i)
		return;
	int mid = (i + j) / 2;

	/* divide and conquer - recursive*/
	merge_sort(i, mid, arr, aux);
	merge_sort(mid+1, j, arr, aux);

	int ptr_left = i;
	int ptr_right = mid + 1;
	int k;

	/* choose which element to add to our sorted array */
	for (k = i; k <= j; k++) {
		/* ptr_left has reached its limit, so add ptr_right */
		if (ptr_left == mid + 1) {
			aux[k] = arr[ptr_right];
			ptr_right++;
		} 
		/* ptr_right has reached its limit, so add ptr_left */
		else if (ptr_right == j + 1) {
			aux[k] = arr[ptr_left];
			ptr_left++;
		} 
		/* ptr_left is the smaller element, so add it */
		else if (arr[ptr_left] < arr[ptr_right]) {
			aux[k] = arr[ptr_left];
			ptr_left++;
		} 
		/* ptr_right is the smaller element, so add it */
		else {
			aux[k] = arr[ptr_right];
			ptr_right++;
		}
	}

	/* overwrite original array with new sorted array */
	for (k = i; k <= j; k++)
		arr[k] = aux[k];
}


//
/* Radix Sort */
//
// source: https://www.geeksforgeeks.org/radix-sort/


/* function that will return the biggest element in an array */
int get_max(int *arr, size_t arr_size)
{
	int max = arr[0];
	for (int i = 0; i < arr_size; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}

void count_sort(int *arr, size_t arr_size, int exp)
{
	/* secondary array, which will be sorted */
	int *aux = (int *)malloc(sizeof(int) * arr_size);
	int i, count[10] = { 0 };

	/* storing count of matches based on digit */
	for (i = 0; i < arr_size; i++)
		count[(arr[i] / exp) % 10]++;
	
	for (i = 1; i < 10; i++)
		count[i] += count[i-1];
	
	/* build output array */
	for (i = arr_size-1; i >= 0; i--) {
		aux[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}
	
	/* overwite original array with the new sorted one */
	for (i = 0; i < arr_size; i++)
		arr[i] = aux[i];
	
	free(aux);
}

void radix_sort(int *arr, size_t arr_size)
{
	int max = get_max(arr, arr_size);

	/* perform count sort for each digit/power of 10 */
	for (int exp = 1; max / exp > 0; exp *= 10)
		count_sort(arr, arr_size, exp);
}
