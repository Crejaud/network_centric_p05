int get_size_of_file(FILE *fp);
void read_file_and_store_in_buffer(FILE *fp, int file_size, char *buffer);
void to_lower_case(char *string);
int get_num_occurrences_of_substring_in_buffer(char *buffer, int file_size, char *substring);
