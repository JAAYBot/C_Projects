/*
John McCormack

MCT609

Week 3 Question 2

November 06, 2016

Write a program that first reads and stores five numbers (each between 1 and 30). 
Then, for each number read, your program should print a line containing that number 
of adjacent asterisks
*/

#include <stdio.h>

void main(void) {

	int j = 0;
	
	printf("Please Enter 5 Numbers Seperated by a Space\n");
	printf("Example 1 2 3 4 5\n");
	printf("Alternatively, Enter each number individually\n");
	printf("and its corresponding * value will be printed\n");

	for (j; j < 5; ++j) {

		int number = 0, counter = 0;
	
		scanf("%d", &number);

		for (counter; counter < number; ++counter)
			printf("*");
	
		printf("\n");
	}

	getch();
}