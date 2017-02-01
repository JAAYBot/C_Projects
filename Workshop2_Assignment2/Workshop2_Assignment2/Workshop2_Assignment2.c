/* 
Week 2 Assignment 2
John McCormack

*/

#include <stdio.h>
#include <limits.h>

void main(void) {

	int counter = 1, largest = INT_MIN, number = 0; // largest_number value set to lowest possible value for INT
	printf("Please Enter 10 numbers. At the end the largest will be displayed\n");
	while(counter <= 10){

		printf("Please Enter Number %d\n", counter);
	
		scanf("%d", &number);
		
		if (number > largest)
			largest = number;
		
		counter++;
	};

	printf("The Largest Number Entered was = %d\n", largest);
	getch();
	
}
