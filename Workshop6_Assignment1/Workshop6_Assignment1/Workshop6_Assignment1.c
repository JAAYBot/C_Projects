/*
John McCormack

MCT609

Week 6 Question 1
Version 1 Global Array

November 26, 2016

Prompt the user for the names of the input and output files. You can prepare 
an input file with appropriate unsorted data. A simple file with one word per 
line will suffice. Declare and define three functions to perform the following tasks:

Read the data from the input file into an array.
Sort the array using the bubble sort algorithm.
Write the sorted data array to the output file.

*/

#define ROWS 50
#define COLS 20
#include <stdio.h>
#include <string.h>

char storage_array[ROWS][COLS];

void read_from_file(char* from_file_name);
void bubble_sort_array();
void write_to_file(char* to_file_name);

void main(void) {
		
	
	char from_file_name[20];
	char to_file_name[20];
	
	printf("Please enter the name of the file to read from in the form FILENAME.txt\n");
	scanf("\n%s", &from_file_name);
	printf("Please enter the name of the file to write to in the form FILENAME.txt\n");
	scanf("\n%s", &to_file_name);
	
	read_from_file(from_file_name);
	bubble_sort_array();
	write_to_file(to_file_name);
	printf("Finished operation, press any key to exit\n");

	getch();

}

void read_from_file(char* from_file_name) {
	
	int i = 0;
	char temp_array[20];
	FILE *fptr;
	
	if ((fptr = fopen(from_file_name, "r")) == NULL)
		printf("Error!!!\n");
	else {
		printf("Reading File...\n");
		while(fgets(temp_array, 20, fptr)){
			
			strncpy(storage_array[i], temp_array, strlen(temp_array));
			++i;
		}
		fclose(fptr);
	}
	return 0;
}

void write_to_file(char* to_file_name) {

	FILE *fptr = fopen(to_file_name, "w");
	int i = 0;

	if (fptr == NULL) {
		printf("Could Not open file\n");
	}
	else {
		printf("Printing to file...\n");
		while (i < ROWS) {

			fprintf(fptr, "%s", storage_array[i]);
			i++;
		}
		fclose(fptr);
	}
	return 0;
}

void bubble_sort_array() {

	int counter;
	char temp_array[COLS];

	for (counter = 0; counter < ROWS - 1; counter++) {

		int counter2;

		for (counter2 = 0; counter2 < ROWS - 1 - counter; counter2++) {

			int j = 0;
			while (storage_array[counter2][j] == storage_array[counter2 + 1][j]) {
				j++;
			}

			if (storage_array[counter2][j] > storage_array[counter2 + 1][j]) {

				strncpy(temp_array, storage_array[counter2], COLS);
				strncpy(storage_array[counter2], storage_array[counter2 + 1], COLS);
				strncpy(storage_array[counter2 + 1], temp_array, COLS);
			}
		}
	}

}