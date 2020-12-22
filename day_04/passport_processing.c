#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BYR (1 << 0)
#define IYR (1 << 1)
#define EYR (1 << 2)
#define HGT (1 << 3)
#define HCL (1 << 4)
#define ECL (1 << 5)
#define PID (1 << 6)
#define CID (1 << 7)




size_t get_file_size(const char * name){
  FILE * f = fopen(name, "r");
  fseek(f, 0, SEEK_END);
  size_t size = ftell(f);
  fclose(f);
  return size;
}

void read_file(const char * name, char * buffer, size_t size){
  FILE * f = fopen(name, "r");
  fread(buffer, size, 1, f);
  fclose(f);
}


int validate_passports(char * input){
	int valid = 0;
	int passport_count = 0;
	
	int found_fields;
	
	char *head = input;
	char *tail;
	char current_passport[256];
	
	
	
	while(1){		
		found_fields = 0;
		tail = strstr(head,"\n\n");
		if(tail){
			int passport_length = (tail - head);
			printf("Length of passport: %d\n",passport_length);
			
			strncpy(current_passport, head, passport_length);
			current_passport[passport_length] = '\0';
			passport_count++;
			printf("~~PASSPORT %d~~\n%s\n",passport_count,current_passport);
			
			if(
			
			//Done processing the current passport.
			//Prepare pointers for next passport.
			head = (tail + 2);
		} else {
			//strtok did not find another passport
			break;
		}
	}	
	
	return valid;
	
	while(*input != '\0'){
		int fields = 0;
		
		
		
		printf("%c",*input++);
		
		
		
		
		
		if(*input == '\n' && *(input+1)=='\n'){
			passport_count++;
			printf("END OF PASSPORT");
		}
		
	}
	
	printf("\nValidated %d passports\n",passport_count);
	return valid;
}

int main(void){
	
	printf("Advent of Code 2020\n");
	printf("Day 04 - Task 1\n");

	size_t size = get_file_size("input.txt");
	printf("Input size: %d bytes\n",size);
	char * input = malloc(size);
	read_file("input.txt", input, size);
	
	int valid = validate_passports(input);
	printf("There are %d valid passports\n", valid);
	
	return 0;
}