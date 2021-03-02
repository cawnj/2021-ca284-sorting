#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "filerw.h"
#include "sorting-algorithms.h"

/* constant variables */
#define MAX_NUM 100000
#define OUTPUT "data.txt"
/* error messages */
#define ERR_ARGS "Error: Insufficient command line arguments, please try again.\n"
#define ERR_NUM "Error: Only positive whole numbers are permitted, please try again.\n"
#define ERR_CHOICE "Error: Invalid choice, please try again.\n"

bool valid(int, char const**);
int * generate_rand(size_t);
void manipulate(int*, size_t);

int main(int argc, char const *argv[])
{
	/* ensure valid input */
	if ( !(valid(argc, argv)) ) {
		exit(EXIT_FAILURE);
	}

	/* n is amount of numbers to generate */
	size_t n;
	n = atoi(argv[1]);

	/* create array of random numbers */
	int *arr;
	arr = generate_rand(n);
	/* manipulate our array */
	manipulate(arr, n);

	/* output, free memory, and exit successfully */
	write_to_file(OUTPUT, arr, n);
	free(arr);
	return 0;
}

bool valid(int argc, char const *argv[])
{
	/* must have one argument */
	if (argc < 2) {
		fprintf(stderr, ERR_ARGS);
		return false;
	}
	/* ensure input is a valid number */
	char *str = (char *)argv[1];
	for ( int i = 0; i < strlen(str); i++ ) {
		char ch = str[i];
		if ( !(isdigit(ch)) ) {
			fprintf(stderr, ERR_NUM);
			return false;
		}
	}
	return true;
}

int * generate_rand(size_t n)
{
	printf("Generating %ld random numbers...\n", n);
	/* set seed based on current time */
	srand(time(NULL));
	/* create integer array using heap memory */
	int *arr = (int *)malloc(sizeof(int) * n);
	for ( int i = 0; i < n; i++ )
		/* generate nums up to MAX_NUM */
		arr[i] = rand() % MAX_NUM;
	return arr;
}

void manipulate(int *arr, size_t arr_size)
{
	/* get user input */
	char str[3];
	printf("\n"
		"1) Random\n"
		"2) Sorted\n"
		"3) Partially Sorted\n"
		"4) Reverse Sorted\n\n"
		"Please choose one: ");
	fgets(str, 3, stdin);

	/* input must be a single char AND a digit AND between 1 and 4 */
	if ( !(str[1] == '\n' && isdigit(str[0]) && str[0] >= '1' && str[0] <= '4' ) ) {
		fprintf(stderr, ERR_CHOICE);
		exit(EXIT_FAILURE);
	}

	/* switch case based on the users input */
	switch(atoi(str)) {
		case 1: break;
		case 2: qsort(arr, arr_size, sizeof(int), compare_ints); break;
		case 3: partial_sort(arr, arr_size); break;
		case 4: qsort(arr, arr_size, sizeof(int), compare_ints_reverse); break;
	}
}
