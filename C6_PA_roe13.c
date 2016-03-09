/*
   Assignment C6: Input/Output and Struct
   File: C6_PA_roe13.c
   Date: 2 March 2016
   By: Nathaniel Roe
   Section: 03, 1:30
   Team: 42

   ELECTRONIC SIGNATURE
   Nathaniel Roe
   The electronic signature above indicates that the program submitted for 
   evaluation is my individual work and I have a general understanding for 
   all aspects of its development and execution.
   
   Program Description
   This code accesses information related to Pokemon 
*/

// Import necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct data type
typedef struct PokemonData {
	char pokemon[25];
	char type[25];
	char height[25];  
	char healthpts[25]; 
	char attack[25];    
	char defense[25];
	char evolution[25];	
} PokemonData;

// Main program
int main(void){
	FILE* pokeFile   = NULL; 
	FILE* outputFile = NULL;
	char filename[20];
	char newfile[]   = "C6_PA_roe13_output.txt"; // Output file
	char colopt[20];
	char array[100];
	int i            = 0; // counter
	int j            = 0; // counter
	int k            = 0; // counter
	int rows         = 0;
	int minimum      = 0;
	PokemonData Max;
	
	// Initialy set each value in max to "ZZZ" for alphabetizing
	strcpy(Max.pokemon, "ZZZ");
	strcpy(Max.height, "ZZZ");
	strcpy(Max.healthpts, "ZZZ");
	strcpy(Max.attack, "ZZZ");
	strcpy(Max.defense, "ZZZ");
	strcpy(Max.evolution, "ZZZ");
	
	// Prompt user input
	printf("Please input the filename: ");
	scanf("%s", filename);
	
	// Open file for reading
	pokeFile = fopen(filename, "r");
	
	// Open output file for writing and reading
	outputFile = fopen(newfile, "w+");
	
	// Check to see if file opened correctly
	if (pokeFile == NULL) {
		printf("Could not open the file.\n");
		return -1;
	}
	
	printf("Please input column numbers to access: ");
	scanf(" %[^\n]s", colopt); //read in as string including spaces
	
	// Count rows in file
	for (rows = 0; !feof(pokeFile); rows++) {
		fgets(array, 100, pokeFile);
	}
	
	rewind(pokeFile); // rewind to beginning of file
	
	PokemonData pokestruct[rows]; 
	
	// Assign values to struct
	for (i = 0; i <= rows; i++) {
		fscanf(pokeFile, "%s %s %s %s %s %s %s\n", pokestruct[i].pokemon,  \
		pokestruct[i].type, pokestruct[i].height, pokestruct[i].healthpts, pokestruct[i].attack, \
		pokestruct[i].defense, pokestruct[i].evolution);
	}
	
	rewind(pokeFile); // rewind to beginning of file
	
	// Output headers to file
		for (j = 0; colopt[j] != '\0'; j++) {
			if (colopt[j] != ' ') {
				if (colopt[j] == '1') {
					fprintf(outputFile, "%-11s ", pokestruct[0].pokemon);	
				}
						
				else if (colopt[j] == '2') {
					fprintf(outputFile, "%-11s ", pokestruct[0].type);
				}
						
				else if (colopt[j] == '3') {
					fprintf(outputFile, "%-11s ", pokestruct[0].height);
				}
						
				else if (colopt[j] == '4') {
					fprintf(outputFile, "%-11s ", pokestruct[0].healthpts);
				}
						
				else if (colopt[j] == '5') {
					fprintf(outputFile, "%-11s ", pokestruct[0].attack);
				}
						
				else if (colopt[j] == '6') {
					fprintf(outputFile, "%-11s ", pokestruct[0].defense);
				}
						
				else if (colopt[j] == '7') {
					fprintf(outputFile, "%-11s ", pokestruct[0].evolution);				
				}
			}	
		}		
		
		fprintf(outputFile, "\n"); //newline
		rewind(pokeFile); // rewind to beginning of file
		
	// Alphabetize
		for (i = 1; i < rows; i++) {
			minimum = i;
			for(k = 1; k < rows; k++) {
				if (strcmp(pokestruct[k].pokemon, pokestruct[minimum].pokemon) < 0) {
					minimum = k;
				}
			}

			rewind(pokeFile); // rewind to start of file
			
	// Output other rows to new file
			for (j = 0; colopt[j] != '\0'; j++) {
				if (colopt[j] != ' ') {
					if (colopt[j] == '1') {
						fprintf(outputFile, "%-11s ", pokestruct[minimum].pokemon);	
					}
						
					else if (colopt[j] == '2') {
						fprintf(outputFile, "%-11s ", pokestruct[minimum].type);
					}
						
					else if (colopt[j] == '3') {
						fprintf(outputFile, "%-11s ", pokestruct[minimum].height);
					}
						
					else if (colopt[j] == '4') {
						fprintf(outputFile, "%-11s ", pokestruct[minimum].healthpts);
					}
						
					else if (colopt[j] == '5') {
						fprintf(outputFile, "%-11s ", pokestruct[minimum].attack);
					}
						
					else if (colopt[j] == '6') {
						fprintf(outputFile, "%-11s ", pokestruct[minimum].defense);
					}
						
					else if (colopt[j] == '7') {
						fprintf(outputFile, "%-11s ", pokestruct[minimum].evolution);				
					}
						
					else {
						printf("Error: Attempted to access non-existing column.\n");
						return -1;
					}
				}
			}
			strcpy(pokestruct[minimum].pokemon, Max.pokemon);
			fprintf(outputFile, "\n"); // newline for each row
		}

	// Close file
	fclose(pokeFile);
	
	// Check to see output file opened correctly
	if (outputFile == NULL) {
		printf("Could not create new file.\n");
		return -1;
	}
	
	// Close file
	fclose(outputFile);

	return 0;
}