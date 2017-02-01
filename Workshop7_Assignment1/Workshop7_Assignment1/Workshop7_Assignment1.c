/*
John McCormack

MCT609

Week 7 Question 1

December 3, 2016


*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>


char **dynamic_array;

void print_strings(int N);
int wordcount(FILE *fptr);
void read_in_file(FILE *fptr, int N);
void match_strings(int N);

void main(void) {

	char* to_match = { "ed" };
	char file_name[20];
	int N = 0, i = 0, j = 0;
	char c = ' ';
	FILE *fptr;

	printf("Please enter name of file to read in the form filename.txt\n");
	scanf("%s", &file_name);

	while ((fptr = fopen(file_name, "r")) == NULL) {
		printf("Error!!!\n");
		printf("Please enter name of file to read in the form filename.txt\n");
		scanf("%s", &file_name);
	}

	printf("Reading File...\n");

	N = wordcount(fptr);
	read_in_file(fptr, N);
	//print_strings(N);
	match_strings(N);
		
	fclose(fptr);
		
	getch();

}

int wordcount(FILE *fptr) {
	
	int wordcount = 0;
	char c = ' ';
	
	while (c != EOF) {
		
		while (isspace(c = fgetc(fptr)));
				
		if (c != EOF) {
			while ((c = fgetc(fptr)) != EOF && !isspace(c));

			++wordcount;
		}
	}
	rewind(fptr); // return pointer to start of file
	return wordcount;
}

void read_in_file(FILE *fptr, int N) {

	char str_temp[20];
	int i = 0, j = 0;
	dynamic_array = (char **)malloc(sizeof(char *)*N);

	for (i = 0; i < N; i++) {
		
		fscanf(fptr, "%s", &str_temp);
		dynamic_array[i] = (char *)malloc(sizeof(char)*(strlen(str_temp) + 1)); // extra space for \0 character
		strcpy(dynamic_array[i], str_temp);
		
	}

	return 0;
}

void print_strings(int N) {
	
	int i;
	printf("Printing Strings\n");
	for (i = 0; i < N; i++)
		printf("%s\n", dynamic_array[i]);

	return 0;
	
}

void match_strings(int N) {

	int i, count = 0;
	char d = 'd';
	char *ptr;

	printf("Matching....\nList of words contained in file ending in 'ed':\n");
		
	for (i = 0; i < N; i++) {
		ptr = strrchr(dynamic_array[i], d);
		if (ptr != NULL && (char*)*(ptr - 1) == 'e' && ((char*)*(ptr + 1) == '\0' || (char*)*(ptr + 1) == ',' || (char*)*(ptr + 1) == '.')) {
			*(ptr + 1) = '\0'; // wite \0 to space after d, this takes out char , . 
			printf("%s\n", dynamic_array[i]);
			count++;
		}
	}

	printf("Count of words ending in 'ed' = %d\n", count);
	return 0;

}