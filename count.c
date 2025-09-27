// Saxon Meznarich ID: 07700035359
 #include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_WORD_LENGTH 30

int main(int argc, char *argv[]) {

	FILE *file;
    char *filename = argv[1];

	//Check if file was received
	if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

	//Check if not folder
	struct stat cstate;
	if (stat(filename, &cstate) ==0) {
		if(S_ISDIR(cstate.st_mode)) { 
		fprintf(stderr, "This is a directory: %s \n", filename);
		return 1;}
	}

	file = fopen(filename, "r");

	char word[MAX_WORD_LENGTH+1];
	int count = 0;

	//check if file can open
	if (file == NULL) {
           perror("Error opening file");
           return 1;
       }

	//counting the number of words that appear in the file
	while(fscanf(file, "%s", word)==1)
	{ ++count;
	}

	printf("%d\n", count);
	//deallocating pointer
	fclose(file);
	return 0;
}

