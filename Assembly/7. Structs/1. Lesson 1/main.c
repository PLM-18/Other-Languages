#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#define EPSILON 0.0001

struct Student {
    char name[50];
    int age;
    float gpa;
};

extern struct Student* createStudent(char *name, int age, float gpa);

void printStudent(struct Student* student) {
    printf("Name: %s\n", student->name);
    printf("Age: %d\n", student->age);
    printf("gpa: %.2f\n", student->gpa);
}

int main() {
    struct Student* student1 = createStudent("John", 18, 90.5);
    struct Student* student2 = createStudent("Alice", 19, 88.0);

    printStudent(student1);
    printStudent(student2);

    free(student1);
    free(student2);

    return 0;
}