#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include "filerw.h"
#include "sorting-algorithms.h"

/* constant values */
#define OUTPUT "sorted.txt"
/* error messages */
#define USAGE "Usage: sort -s/m/r [filename]\n"\
			  "Options:\n"\
			  "-h               Print help and exit.\n"\
			  "-s               Use selection sort.\n"\
			  "-m               Use merge sort.\n"\
			  "-r               Use radix sort.\n"
#define ERR_INFO "Try 'sort -h' for more information.\n"
#define ERR_SYNTAX "Error: Missing arguments: sort -s/m/r [filename]\n"

char *filename;
enum MODE { NOT_SELECTED, SELECTION_SORT, MERGE_SORT, RADIX_SORT }; 
enum MODE mode = NOT_SELECTED;

void argParser(int, char**);
void sort(enum MODE, int*, size_t);

int main(int argc, char *argv[])
{
	/* parse arguments and create array */
	argParser(argc, argv);
	int *arr;
	size_t arr_size;
	arr = read_from_file(filename, &arr_size);

	/* help with timing from https://stackoverflow.com/q/12231166 */
	clock_t start = clock();
	sort(mode, arr, arr_size);
	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;
	printf("Time elapsed is %fms\n", time_spent);

	/* output, free memory, and exit successfully */
	write_to_file(OUTPUT, arr, arr_size);
	free(arr);
	return 0;
}

void argParser(int argc, char *argv[])
{
	/* argument parsing, help from https://stackoverflow.com/a/24479532 */
	int opt;
	while ((opt = getopt(argc, argv, "hsmr")) != -1) {
		switch (opt) {
		case 'h': printf("%s", USAGE); exit(0);
		case 's': mode = SELECTION_SORT; break;
		case 'm': mode = MERGE_SORT; break;
		case 'r': mode = RADIX_SORT; break;
		default:
			fprintf(stderr, ERR_INFO);
			exit(EXIT_FAILURE);
		}
	}
	
	/* only copy filename argument if it even exists */
	if (argv[optind] != NULL)
		filename = strdup(argv[optind]); 

	/* invalid input checks */
	if (filename == NULL || mode == 0) {
		printf("%s%s", ERR_SYNTAX, ERR_INFO);
		exit(EXIT_FAILURE);
	}
}

/* function to handle which sorting algorithm to use */
void sort(enum MODE mode, int *arr, size_t arr_size)
{
	printf("Sorting %ld numbers using ", arr_size);

	if (mode == SELECTION_SORT) {
		printf("Selection Sort\n");
		selection_sort(arr, arr_size);
	} else if (mode == MERGE_SORT) {
		printf("Merge Sort\n");
		merge(arr, arr_size);
	} else if (mode == RADIX_SORT) {
		printf("Radix Sort\n");
		radix_sort(arr, arr_size);
	}
}
