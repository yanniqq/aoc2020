#include <stdio.h>
#include <stdlib.h>

#define NUM_LINES 200

int compare_func (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main(void){
	
	int numbers[NUM_LINES];
	int i,j,k;
		
	printf("Advent of Code 2020\n");
	printf("Day 1 - Task 2\n\n");
	
	//Supply input on STDIN
	for( i = 0; i < NUM_LINES; i++){
		scanf("%i", &numbers[i]);
	}
	
	qsort(numbers,NUM_LINES,sizeof(int),compare_func);
	
	for( i = 0; i < NUM_LINES-2; i++){
		for( j = i+1 ; j < NUM_LINES-1; j++){
			for( k = j+1 ; k < NUM_LINES; k++){
				printf("I %i + J %i + K %i = %i\n",numbers[i],numbers[j],numbers[k],numbers[i]+numbers[j]+numbers[k]);
				if(numbers[i]+numbers[j]+numbers[k] == 2020){
					printf("%i\n",numbers[i]*numbers[j]*numbers[k]);
					return 0;
				}
				if(numbers[i]+numbers[j]+numbers[k] > 2020){
					break;
				}
			}
			if(numbers[i]+numbers[j]+numbers[k] > 2020){
				break;
			}
		}
	}
	
	return 1;
}