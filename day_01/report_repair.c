#include <stdio.h>
#include <stdlib.h>

#define NUM_LINES 200

int compare_func (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main(void){
	
	int numbers[NUM_LINES];
	int i,j;
		
	printf("Advent of Code 2020\n");
	printf("Day 1 - Task 1\n\n");
	
	//Supply input on STDIN
	for( i = 0; i < NUM_LINES; i++){
		scanf("%i", &numbers[i]);
	}
	
	qsort(numbers,NUM_LINES,sizeof(int),compare_func);
	
	for( i = 0; i < NUM_LINES-1; i++){
		for( j = i+1 ; j < NUM_LINES; j++){
			//printf("I %i + J %i = %i\n",numbers[i],numbers[j],numbers[i]+numbers[j]);
			if(numbers[i]+numbers[j] == 2020){
				printf("%i\n",numbers[i]*numbers[j]);
				return 0;
			}
			if(numbers[i]+numbers[j] > 2020){
				break;
			}
		}
	}
	
	return 1;
}