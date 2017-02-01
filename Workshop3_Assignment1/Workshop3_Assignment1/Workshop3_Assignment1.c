/*
John McCormack

MCT609

Week 3 Question 1

November 06, 2016

Write for statements that print the following sequences of values:
a) 1, 2, 3, 4, 5, 6, 7
b) 3, 8, 13, 18, 23
c) 20, 14, 8, 2, -4, -10
d) 19, 27, 35, 43, 51
*/

#include <stdio.h>

void main(void) {

	
	int i = 0;
	int j = 0;

	int myarray[] = { 1, 1, 7, 3, 5, 23, 20, -6, -10, 19, 8, 51 };
		
	for (j; j < 4; ++j) {

		switch (j) {
		case 0:
			printf("a) ");
			break;
		case 1:
			printf("b) ");
			break;
		case 2:
			printf("c) ");
			break;
		case 3:
			printf("d) ");
			break;
		default:
			printf("Error!!\n");
		}
			
		int start_value = myarray[i];
		int step_value = myarray[i + 1];
		int end_value = myarray[i + 2] + step_value;
		int output = myarray[i];

		for (start_value; start_value != end_value; start_value+=step_value) {
		
			printf("%3d, ", output);
			output += step_value;
		}

		i += 3;
		printf("\n");
	}

	getch();
}