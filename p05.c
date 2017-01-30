#include <stdio.h>
#include <stdlib.h>
#include "p05.h"

int main(int argc, char *argv[]) {

	printf("%d\n", argc);

	/* If there isn't even the file name argument, then exit */
	if (argc <= 1) {
		exit(1);	
	}

	/* Open file from 2nd argument */
	FILE *fp = fopen(argv[1], "r");

	/* Second argument should be file name
	 * The rest of the arguments are sub-strings that are to be searched for in the file
	 */

	/* File name does not exist, so exit */
	if (fp == NULL) {
		perror("fp");
		exit(1);
	}

	/* Get size of file */
	int file_size = get_size_of_file(fp);

	/* Read file and store in buffer of size file_size */
	char buffer[file_size];
	read_file_and_store_in_buffer(fp, file_size, buffer);
	printf("%s\n", buffer);

	/* Close file */
	fclose(fp);

	return 0;
}

/* Get the size of the file by seeking to the end,
 * getting the position,
 * then rewinding the file pointer back to the start
*/
int get_size_of_file(FILE *fp) {
	fseek(fp, 0L, SEEK_END);
	int file_size = ftell(fp);
	rewind(fp);
	return file_size;
}

void read_file_and_store_in_buffer(FILE *fp, int file_size, char buffer[]) {
	int end_pos = fread((void *) buffer, 1, file_size - 1, fp);
	/* set end of buffer at end_pos */
	printf("End position: %d\n", end_pos);
	buffer[end_pos] = 0;
}
