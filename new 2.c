#inlcude <stdio.h>
#inlcude <stdlib.h>
#include <string.h>

/* typedef struct CokeData {
	char barcode[25];
	char heightdev[25];	
} CokeData; */

int main(void) {
	FILE *cokeFile = NULL;
	char filename[100];
	char array[100];
	// int i = 0;
	int rows = 0;
	
	printf("Enter the filename: ");
	scanf("%s", filename);
	
	cokeFile = fopen(filename, "r");
	
	if (cokeFile == NULL) {
		printf("Could not open the file.\n");
		return -1;
	}
	
	for (rows = 0; !feof(cokeFile); rows++) {
		fgets(array, 100, cokeFile);
	}
	
	rewind(cokeFile);
	
	fclose(cokeFile);

	return 0;
}