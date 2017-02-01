/* John McCormack
Workshop1 Assginment 2

Write a program that reads in the radius of a circle and prints the circle's diameter,
circumference and area. Use the constant value 3.14159 for pi symbol. Perform each of
these calculations inside the printf statement(s) and use the conversion specifier %f.
*/

#include <stdio.h>
#define PI 3.14159 

//const float PI = 3.14159; Another way to have a constant value

int main(void) {

	char c;

	do {

		float r = 0;

		printf("Please enter the radius of the circle\n");
		printf("Number is limited to 6 digits\n");
		printf("Symbols and characters will results in errors!\n");

		scanf("%6f", &r);	//takes input limited to 6 days

		printf("The circle's diameter = %f\n", 2 * r); //diameter
		printf("The circle's circumference = %f\n", 2 * PI*r); //circumference 
		printf("The circle's area = %f\n", PI*(r*r)); //area

		printf("press y to run again or n to end\n");
		scanf("\n%c", &c);

	} while (c == 'y');

	return 0;

}