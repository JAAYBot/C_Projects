


#include <stdio.h>
#include <string.h>

void main(void) {

	int N = 2;
	int M = 6;
	int i = 0;
	int j = 0;
	int save_size[100];
	char **dynamic_array;

	//open file maybe and get numer of words, this will be N

	dynamic_array = (char **)malloc(sizeof(char *)*N);
	
	//back to start of file

	//read in first word to temp array, get size, (add 1 for '\0')
	// create dynamically arrary of this size and copy in 


	for (i = 0; i < N; i++) {
		printf("Enter lenght\n");
		// read in string/array & get size
		scanf("\n%d", &save_size[i]);
		dynamic_array[i] = (char *)malloc(sizeof(char)*save_size[i]);
	
		for (j = 0; j < save_size[i]; j++) {
			printf("enter char\n");
			char temp;
			scanf("\n%c", &temp);
			dynamic_array[i][j] = temp;
		}

		dynamic_array[i][save_size[i]-1] = '\0'; // might need to tweak to read in but so far so good
	}
		
	
	
	printf("Printing Array\n");
	for (i = 0; i < N; i++) {
		for (j = 0; j < save_size[i]; j++) {
			printf("%c", dynamic_array[i][j]);
		}
		printf("\n");
	}
	

	printf("string please.... %s\n", dynamic_array[0]);
	printf("last.... %s\n", dynamic_array[1]);
	

	getch();
}
