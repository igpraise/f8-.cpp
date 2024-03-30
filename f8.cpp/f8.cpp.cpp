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
