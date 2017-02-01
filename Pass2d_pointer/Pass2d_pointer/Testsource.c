

#define ROWS 4
#define COLS 3
#include <stdio.h>
#include <string.h>



void bubble_sort_array(char *ptr[ROWS][COLS]);

void main(void) {

	char storage_array[ROWS][COLS] = { { 'D','D','D' },{ 'A', 'B','A' },{ 'B','B','B' },{ 'A','A','A' } };

	bubble_sort_array(storage_array);
	int i = 0;
	printf("\n");
	printf("Array %s\n", storage_array[i]);
	getch();

}

void bubble_sort_array(char *ptr[ROWS][COLS]) {

	int i = 0, j = 0;

	printf("Array %s\n", *(ptr+i));

	char myarray[20];
	strncpy(myarray, *(ptr + i), 3);
	
	printf("Array %s\n", myarray);


}