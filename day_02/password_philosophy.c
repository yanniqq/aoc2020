#include <stdio.h>
#include <string.h>

int main(void){
	
	printf("Advent of Code 2020\n");
	printf("Day 2 - Task 1\n\n");
		
	FILE * f;
	char line[64];
	int numValid = 0;
	
	f = fopen("input.txt","r");
	if( f == NULL ){
		printf("Error while opening input.txt\n");
		return 1;
	}
	
	while (fgets(line, sizeof(line), f)) {
		int min = 0;
		int max = 0;
		char letter;
		char password[64];
		int count = 0;
		sscanf(line, "%d-%d %c: %s", &min, &max, &letter, password);
		//printf("Letter: %c Min: %d Max: %d Password: %s\n", letter, min, max, password);
		//printf("%s",line);
		
		for(int i = 0; i < strlen(password); i++){
			if(password[i] == letter){
				count++;
			}
			if(count > max){
				break;
			}
		}
		
		if(count <= max && count >= min){
			numValid++;
		}		
	}
	
	printf("Valid passwords: %d\n",numValid);
	
	fclose(f);
	return 0;
}	