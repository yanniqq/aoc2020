#include <stdio.h>

#define LENGTH 32

int count_trees(int right, int down){
	
	char line[LENGTH];
	int icol,irow;
	int num_trees=0;
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
	
	
	fclose(file);
	
	printf("%d trees with slope %d right, %d down\n",num_trees, right, down); 
	return num_trees;

}

int main(void){
	printf("Advent of Code 2020\n");
	printf("Day 3 - Task 2\n\n");
	
	int result = 0;
	
	result = count_trees(1,1);
	result *= count_trees(3,1);
	result *= count_trees(5,1);
	result *= count_trees(7,1);
	result *= count_trees(1,2);
	
	printf("Result %d\n",result);
	return 0;
}