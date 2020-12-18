#include <stdio.h>

#define LENGTH 32

int main(void){
	printf("Advent of Code 2020\n");
	printf("Day 3 - Task 1\n\n");
	
	int right, down;
	char line[LENGTH];
	int icol,irow;
	int num_trees=0;
	right = 3;
	down = 1;
	icol = 0;
	irow = 0;
	
	FILE *file = fopen("input.txt","r");
	
	while(fscanf(file, "%s", line) > 0) {
		if((line[icol % (LENGTH - 1)] == '#') && (irow % down == 0)){
			num_trees++;
		}
		
		if(irow % down == 0){
			icol += right;
		}
		
		irow++;
		//printf("%s\n",line);
		
	}
	
	
	printf("%d trees with slope %d right, %d down\n",num_trees, right, down); 
	fclose(file);
	
	return 0;
}