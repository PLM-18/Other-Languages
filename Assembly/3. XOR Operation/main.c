#include <stdio.h>

// Declare the assembly function
extern void _start();

int main() {
    _start();
    
    printf("Rotated%s\n"); // Should print "1930507175 1930507143 1930506775 1930507047"
    return 0;
}