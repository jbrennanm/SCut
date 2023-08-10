#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void letters(char*);
void whitespace(char*);
void comma(char*);

/*
Author: Brennan Mitchell
Class: CSc 352
Description: This program recreates the Bash "cut" command.
It accepts 2 arguments.
The first argument can either be -l, -w, or -c, which represents cut by letter,
whitespace, or comma. The second argument is the numbers that you want to cut
from the command.
 */
int main(int argc, char * argv[]) {
	if (argc != 3) {
		printf("expected 2 command line arguments.\n");
		return 1;
	}
	for (int i = 0; i < strlen(argv[2]); i++) {
		if (isdigit(argv[2][i])) {
			continue;
		}
		else if (argv[2][i] == ',') {
			continue;
		}
		else if (argv[2][i] == '-') {
			continue;
		} else {
			printf("Invalid selection.\n");
			return 1;
		}
	}
	if (!isdigit(argv[2][0])) {
 	       printf("Invalid selection.\n");
               return 1;
        }
	if (!isdigit(argv[2][strlen(argv[2]) - 1])) {
               printf("Invalid selection.\n");
               return 1;
        }
	if (strcmp(argv[1], "-l") == 0) {
		letters(argv[2]);
	}
	else if (strcmp(argv[1], "-w") == 0) {
		whitespace(argv[2]);
	}
	else if (strcmp(argv[1], "-c") == 0) {
		comma(argv[2]);
	} else {
		printf("Invalid delimiter type.\n");
		return 1;
	}
	return 0;
}

/*
Function: letters
This function takes in one parameter which is going to be the list of indexes
passed in from the command line. This function then takes these indexes,
and uses them to parse through a given input and output the correct letters.  
*/
void letters(char args[]) {
	char buffer[102];
	int start = 0;
	while(fgets(buffer, 102, stdin) != NULL) {
 		for (int i = 0; i < strlen(args); i++) {
			if (args[i] == ',') {
				start = 0;
			} else {
				start = args[i] - '0';
				printf("%c ", buffer[start - 1]);
			}
		}
		printf("\n");
	}
}

/*
Function: whitespace
This function takes in one parameter which is going to be the list of indexes  
passed in from the command line. This function then takes these indexes,
and uses them to parse through a given input and output the correct words,
using the whitespace between the words as the delimiter.
*/
void whitespace(char args[]) {
	char buffer[102];
	int start = 0;
	int end = 0;
	while(fgets(buffer, 102, stdin) != NULL) {
		for (int i = 0; i < strlen(args); i++) {
			if (args[i] == ',') {
				continue;
				end++;
				start++;
			} else {
				int wordPrint = args[i] - '0';
				int counter = 1;
				for (int x = 0; x < strlen(buffer); x++) {
					if (buffer[x] == ' ' && counter == wordPrint) {
						counter++;
						printf(" ");
					}
					else if (counter == wordPrint) {
						if (buffer[x] != '\n') {
							printf("%c", buffer[x]);
						}
					}
					else if (buffer[x] == ' ') {
                                                counter++;
                                        }
				}
			}
		}
		printf("\n");
	}	
}

/*
Function: comma
This function takes in one parameter which is going to be the list of indexes
passed in from the command line. This function then takes these indexes,
and uses them to parse through a given input and output the correct words,
using the commas between the words as the delimiter.
*/
void comma(char args[]) {
        char buffer[102];
        int start = 0;
        int end = 0;
        while(fgets(buffer, 102, stdin) != NULL) {
                for (int i = 0; i < strlen(args); i++) {
                        if (args[i] == ',') {
                                continue;
                                end++;
                                start++;
                        } else {
                                int wordPrint = args[i] - '0';
                                int counter = 1;
                                for (int x = 0; x < strlen(buffer); x++) {
                                        if (buffer[x] == ',' && counter == wordPrint) {
                                                counter++;
                                                printf(" ");
                                        }
                                        else if (counter == wordPrint) {
                                                if (buffer[x] != '\n') {
                                                        printf("%c", buffer[x]);
                                                }
                                        }
                                        else if (buffer[x] == ',') {
                                                counter++;
                                        }
                                }
                        }
                }
		printf("\n");
        }
}
