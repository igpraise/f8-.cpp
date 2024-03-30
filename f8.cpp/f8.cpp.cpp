#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 20
#define MAX_LOCATION_LENGTH 256

struct MyData {
    int howMany;
    char theText[MAX_LENGTH + 1];
    char directoryPath[MAX_LOCATION_LENGTH];
    char filename[MAX_LENGTH + 1];
};

void createTextFile(struct MyData args) {
    FILE* file;
    char location[MAX_LOCATION_LENGTH];

    // Construct full location of the file
    snprintf(location, sizeof(location), "%s/%s", args.directoryPath, args.filename);

    // Open file for writing
    file = fopen(location, "w");
    if (file == NULL) {
        fprintf(stderr, "Error: Unable to open file %s\n", location);
        exit(1);
    }

    // Write 'theText' howMany times to the file
    for (int i = 0; i < args.howMany; i++) {
        fputs(args.theText, file);
        fputc('\n', file);
    }

    // Close the file
    fclose(file);

    printf("Text file created successfully at location: %s\n", location);
}

int main(int argc, char* argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Error: Incorrect number of arguments\n");
        fprintf(stderr, "Usage: %s <positive integer> <string> <string> <string>\n", argv[0]);
        exit(1);
    }

    // Convert first argument to integer
    int howMany = atoi(argv[1]);
    if (howMany <= 0) {
        fprintf(stderr, "Error: First argument must be a positive integer\n");
        exit(1);
    }

    // Check length of strings
    if (strlen(argv[2]) > MAX_LENGTH || strlen(argv[3]) > MAX_LENGTH || strlen(argv[4]) > MAX_LENGTH) {
        fprintf(stderr, "Error: String length exceeds maximum length of %d\n", MAX_LENGTH);
        exit(1);
    }

    // Create MyData struct
    struct MyData myArgs;
    myArgs.howMany = howMany;
    strcpy(myArgs.theText, argv[2]);
    strcpy(myArgs.directoryPath, argv[3]);
    strcpy(myArgs.filename, argv[4]);

    // Create text file
    createTextFile(myArgs);

    return 0;
}