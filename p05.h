char* get_buffer_with_syscalls(char *argv[]);
char* get_buffer_without_syscalls(char *argv[]);
int get_size_of_file(FILE *fp);
int get_size_of_file_descriptor(int fd);
void read_file_and_store_in_buffer(FILE *fp, int file_size, char *buffer);
void read_file_descriptor_and_store_in_buffer(int fp, int file_size, char *buffer);
void to_lower_case(char *string);
int get_num_occurrences_of_substring_in_buffer(char *buffer, char *substring);
