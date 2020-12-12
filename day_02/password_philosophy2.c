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
		int pos1 = 0;
		int pos2 = 0;
		char letter;
		char password[64];
		int count = 0;
		sscanf(line, "%d-%d %c: %s", &pos1, &pos2, &letter, password);
		printf("Letter: %c Pos1: %d Pos2: %d Password: %s\n", letter, pos1, pos2, password);
		pos1--;
		pos2--;
		
		
		if(password[pos1] == letter){
			count++;
			printf("Pos1: %c - Letter: %c\n",password[pos1],letter);
		}
		if(password[pos2] == letter){
			count++;
			printf("Pos2: %c - Letter: %c\n",password[pos2],letter);
		}
		
		
		if(count == 1){
			numValid++;
		}		
	}
	
	printf("Valid passwords: %d\n",numValid);
	
	fclose(f);
	return 0;
}	