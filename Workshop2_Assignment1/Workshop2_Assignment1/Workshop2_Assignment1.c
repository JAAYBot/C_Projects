/*
Week 2 Assignment 1
John McCormack

*/
#define BASIC_PAY 200
#define PERCENTAGE 0.09

#include <stdio.h>

void main(void) {

	float sales_dollars = 0, total = 0;

	printf("Please Enter Sales amount in Dollars or -1 to exit!\n");
	printf("Entering characters will cause an error!\n");
	scanf("\n%f", &sales_dollars);
	
	while ((int)sales_dollars > -1) { //cast sales_dollar to int for comparison with -1

		total = BASIC_PAY + (sales_dollars * PERCENTAGE); // defined BASIC_PAY and PERCENTAGE
		printf("Total Earned = $%.2f\n", total);

		printf("Please Enter Sales amount in Dollars or -1 to exit!\n");
		printf("Entering characters will cause an error!\n");
		scanf("\n%f", &sales_dollars);
		
	};
	getch();
}
