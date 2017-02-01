/*
John McCormack

MCT609

Week 4 Question 2

November 13, 2016

Calculate e using both recursion and looping 
and compare results
*/
#include <stdio.h>
#include <math.h>
#include <time.h>

#define TIMES 50
#define DELAY 20000000

double factorial_recursion(int fac);
double factorial_loop(int fac);
void time_extend(int i);

void main(void) {
	
	// e = 2.71828
	
	double e = 1;
	int i;


	clock_t start_l, end_l, start_r, end_r;

	////////Calculate e using Recursion////////
	printf("********Calculate e using Recursion********\n");
	start_r = clock();
	for (i = 1; i <= TIMES; ++i){
		time_extend(DELAY);
		e += (1 / factorial_recursion(i));
	}
	end_r = clock();
	double total_r = (double)(end_r - start_r) / CLOCKS_PER_SEC;

	printf("Start: %ld\n", start_r);
	printf("End: %ld\n", end_r);
	printf("Total: %lf\n", total_r);
	printf("e = %.5lf\n", e);
	
	e = 1; //reset e

	////////Test for Factorial Loop 20////////
	printf("********Calculate e using Looping********\n");
	start_l = clock();
	for (i = 1; i <= TIMES; ++i) {
		time_extend(DELAY);
		e += (1 / factorial_loop(i));
	}
	end_l = clock();
	double total_l = (double)(end_l - start_l) / CLOCKS_PER_SEC;
	
	printf("Start: %ld\n", start_l);
	printf("End: %ld\n", end_l);
	printf("Total: %lf\n", total_l);
	printf("e = %.5lf\n", e);
	
	/*
	////////Test for Factorial Recursion 20////////
	printf("********Precision test for Factorial Recursion 20********\n");
	double check = factorial_recursion(20);
	printf("Value: %lf\n", check);
	
	check = 0; //reset check

	////////Test for Factorial Loop 20////////
	printf("********Precision test Factorial Loop 20********\n");
	check = factorial_loop(20);
	printf("Value: %lf\n", check);
	*/	
	getchar();

}

double factorial_recursion(int fac) {
	if (fac > 1)
		return (fac * factorial_recursion(fac - 1));
	else 
		return (double)fac;

}

double factorial_loop(int fac) {
	double fac_loop = 1.0;
	int i;
	
	for (i = fac; i > 0; --i) {
		fac_loop = fac_loop * i;
	}
	return fac_loop;
}

void time_extend(int i){
	int a = 1;
	for (i; i > 0; --i) {
		a += a;
	}
		return;
}