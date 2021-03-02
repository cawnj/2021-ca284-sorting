#include <stdio.h>
#include <stdlib.h>

int * read_from_file(char*, size_t*);
void write_to_file(char*, int*, size_t);

int * read_from_file(char *filename, size_t *arr_size)
{
    /* info on reading from files from https://stackoverflow.com/a/43107822 */
    FILE *file;
    file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        exit(EXIT_FAILURE);
    }
    
    /* variables needed for getline() */
    size_t read;
    char *line = NULL;
    size_t line_len = 0;

    /* create a buffer, which will increase based on amount of numbers read */
    size_t buffer_size = 32;
    int *arr = (int *)malloc(sizeof(int) * buffer_size);

    /* read until eof */
    int seek = 0;
    while((read = getline(&line, &line_len, file)) != -1) {
        /* add num to our array */
        arr[seek++] = atoi(line);

        /* when buffer is full, increase its size */
        if (seek % buffer_size == 0) {
            buffer_size += 32;
            arr = (int *)realloc(arr, sizeof(int) * buffer_size);
        }
    }

    /* found fix for annoying pointer stuff from https://stackoverflow.com/a/11657653 */
    *arr_size = seek;
    /* finished, remember to free memory later */
    fclose(file);
    return arr;
}

void write_to_file(char *filename, int *arr, size_t arr_size)
{
    /* write array to file */
	FILE *file;
	file = fopen(filename, "wb");
	for ( int i = 0; i < arr_size; i++ )
        /* fprintf > fwrite; as fwrite writes the binary data
            unlike fprintf which writes the string representation of the data */
		fprintf(file, "%d\n", arr[i]);
	fclose(file);
    printf("Output saved to '%s'\n", filename);
}
