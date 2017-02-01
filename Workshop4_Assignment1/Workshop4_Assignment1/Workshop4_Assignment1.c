/*
John McCormack

MCT609

Week 4 Question 1

November 13, 2016

Define a function called hypotenuse that calculates the 
length of the hypotenuse of a right triangle when the 
other two sides are given
*/

#include <stdio.h>
#include <math.h>

double hypotenuse(double side_1, double side_2);

void main(void) {

	printf("For test values of lenght: 3.0 and height: 4.0 the hypotenuse: %.2lf\n", hypotenuse(3.0, 4.0));
	printf("For test values of lenght: 5.0 and height: 12.0 the hypotenuse: %.2lf\n", hypotenuse(5.0, 12.0));
	printf("For test values of lenght: 8.0 and height: 15.0 the hypotenuse: %.2lf\n", hypotenuse(8.0, 15.0));

	getch();

}

double hypotenuse(double side_1, double side_2) {

	return sqrt(pow(side_1, 2) + pow(side_2, 2));;

}