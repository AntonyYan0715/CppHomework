#include <stdio.h>
#include <cstring>
#include <stdint.h>
#include <stdlib.h>

#define CHAR_NUM 10
#define COUNTER_SIZE (1 << CHAR_NUM)
#define STR_LEN_LIMIT 6

int32_t parse_string_to_int(const char *s) {
	int32_t ret = 0;
	for (int i = 0; i < strlen(s); i++) {
		ret |= (1 << (s[i] - 'A'));
	}
	return ret;
}

const char *parse_int_to_string(int data, char *buf) {
	int pos = 0;
	for (int i = 0; i < CHAR_NUM; i++) {
	  if ((data & (1 << i)) > 0) {
		  buf[pos++] = (char)('A' + i);
		}
	}
	buf[pos++] = '\0';
	return buf;
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		fprintf(stderr, "Param Error.\nUsage: ./parse <file_path>\n");
	}
	const char *filename = argv[1];
	uint64_t counter[COUNTER_SIZE];
	memset(counter, 0, sizeof(uint64_t) * COUNTER_SIZE);
	FILE *fp = NULL; 
	if ((fp = fopen(filename, "r")) == NULL) {
		fprintf(stderr, "File open err.\n");
		return 0;
	}
	fprintf(stderr, "Begin to parse.\n");
	char buf[STR_LEN_LIMIT];
	uint64_t total_type = 0;
	while(!feof(fp)) {
		fscanf(fp, "%s", buf);
	  if(counter[parse_string_to_int(buf)]++ == 0) {
		  total_type++;
		}
	}
	fprintf(stdout, "Total types of strings: %llu\n", total_type);
	for (int i = 0; i < COUNTER_SIZE; i++) {
		if (counter[i] > 0) {
			fprintf(stdout, "String contains character %s : %llu\n", parse_int_to_string(i, buf), counter[i]);
		}
	}

	return 0;
}
