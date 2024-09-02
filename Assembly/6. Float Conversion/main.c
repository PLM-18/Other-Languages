#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declaration of the assembly function
extern float convertToFloat(char* num);

// Function to convert and print floats
void convertTo(char* num) {
    float result = convertToFloat(num);
    printf("The float value is: %f\n", result);
}

// Function to extract and convert floats
void extractAndConvert(int num) {
    char input[256];
    printf("Enter %d float numbers separated by spaces (e.g., | 32.133 45.66 -21.255 |):\n", num);
    
    // Read the input line
    if (fgets(input, sizeof(input), stdin) == NULL) {
        perror("Error reading input");
        return;
    }

    // Remove leading and trailing '|' and spaces
    char *start = strchr(input, '|');
    char *end = strrchr(input, '|');

    if (start != NULL && end != NULL && end > start) {
        start++;
        *end = '\0';  // Terminate the string before the trailing '|'
    } else {
        printf("Invalid input format\n");
        return;
    }

    // Tokenize the input string and convert each token to a float
    char *token = strtok(start, " ");
    for (int i = 0; i < num && token != NULL; i++) {
        convertTo(token);
        token = strtok(NULL, " ");
    }
}

int main() {
    int num = 4;  // Number of float values expected
    extractAndConvert(num);
    return 0;
}
