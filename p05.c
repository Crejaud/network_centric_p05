#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "p05.h"

static const char *SYSTEM_CALL_FLAG = "--systemcalls";

int main(int argc, char *argv[]) {

	//printf("%d\n", argc);

	/* If there isn't even the file name argument and/or at least one substring argument, then exit */
	if (argc <= 2) {
		exit(1);	
	}

	bool should_use_systemcalls = false;
	int arg_index;
	for (arg_index = 2; arg_index < argc; arg_index++) {
		if (strcmp(SYSTEM_CALL_FLAG, argv[arg_index]) == 0) {
			/* if there is only the file and the flag, then exit */
			if (argv == 2) {
				exit(1);
			}
			should_use_systemcalls = true;
		}
	}

	char *buffer;

	if (should_use_systemcalls) {
		buffer = get_buffer_with_syscalls(argv);	
	}
	else {
		buffer = get_buffer_without_syscalls(argv);	
	}
	
	/* Set buffer to all lower case */
	to_lower_case(buffer);
	//printf("%s\n", buffer);

	/* Get number of occurrences of each substring inside the buffer */
	int arg_index;
	for (arg_index = 2; arg_index < argc; arg_index++) {
		/* if this is the system call flag, then skip this argument */
		if (strcmp(SYSTEM_CALL_FLAG, argv[arg_idnex]) == ) {
			continue;
		}
		to_lower_case(argv[arg_index]);
		//printf("%s\n", argv[arg_index]);
		int num_occurrences = get_num_occurrences_of_substring_in_buffer(buffer, file_size, argv[arg_index]);
		printf("%d\n", num_occurrences);
	}  

	/* Close file */
	fclose(fp);

	return 0;
}

/* Get buffer with system calls */
char* get_buffer_with_syscalls(char *argv[]) {
	/* Open file descriptor from 2nd argument */
	int input_fd = open(argv[1], O_RDONLY);
	
	/* If file descriptor wasn't found */
	if (input_fd == -1) {
		perror("open (syscalls)");
		exit(1);
	}

	
}

/* Get buffer without system calls */
char* get_buffer_without_syscalls(char *argv[]) {
	/* Open file from 2nd argument */
	FILE *fp = fopen(argv[1], "r");

	/* File name does not exist, so exit */
	if (fp == NULL) {
		perror("open (no syscalls)");
		exit(1);
	}

	/* Get size of file */
	int file_size = get_size_of_file(fp);

	/* Read file and store in buffer of size file_size */
	char *buffer = (char *) malloc(file_size * sizeof(char));
	read_file_and_store_in_buffer(fp, file_size, buffer);

	return buffer;
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

void read_file_and_store_in_buffer(FILE *fp, int file_size, char *buffer) {
	int end_pos = fread((void *) buffer, 1, file_size - 1, fp);
	/* set end of buffer at end_pos */
	//printf("End position: %d\n", end_pos);
	buffer[end_pos] = 0;
}

void to_lower_case(char *string) {
	int i;
	for (i = 0; string[i]; i++) {
		string[i] = tolower(string[i]);
	}
}

int get_num_occurrences_of_substring_in_buffer(char *buffer, int file_size, char *substring) {
	int num_occurrences = 0;
	char *haystack = buffer;
	//printf("haystack: %s\n", haystack);
	//printf("substring: %s\n", substring);

	while (haystack != NULL) {
		haystack = strstr(haystack, substring);
		//printf("haystack: %s\n", haystack);
		if (haystack != NULL) {
			if (strlen(haystack) >= 1) {
				haystack += 1;
				//printf("remaining: %s\n", substring);
			}
			num_occurrences++;
		}
	}

	return num_occurrences;	
}
