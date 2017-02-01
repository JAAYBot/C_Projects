/*John McCormack 
WorkShop 1 Assignment 1 

Write a program that asks the user to enter two numbers, obtains them 
from the user and prints their sum, product, difference, quotient, and 
remainder.
*/

#include <stdio.h>

int main(void) {

	char c;
	
	do{

		long long x = 0; // long long larger than int
		long long y = 0;
		
		printf("Please Enter 2 whole numbers seperated by a space\n");
		printf("Numbers may not be more than 9 digits long each\n");
		printf("Numbers lager than 9 digits, charaters and symbols will result in errors!\n");
		scanf("%9lld%9lld", &x, &y); // scans in to long long integers limited to 9 places

		printf("\n%lld plus %lld = %lld\n", x, y, x + y);
		printf("%lld multiplied by %lld = %lld\n", x, y, x*y);
		printf("%lld minus %lld = %lld\n", x, y, x - y);
		y != 0 ? printf("%lld divided by %lld = %lld\nRemainder of %lld divided by %lld = %lld\n", x, y, x / y, x, y, x%y) : printf("Cannot  divide by Zero!! No answer to division or modulus operations!\n");
		
		printf("press y to run again or n to end\n");
		scanf("\n%c", &c);
		
	}while (c == 'y');

	return 0;

}