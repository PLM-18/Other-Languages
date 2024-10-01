#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student {
    int id;
    char name[50];
    float marks;
};

struct Student* createStudent(int id, const char* name, float marks) {
    struct Student* student = (struct Student*)malloc(sizeof(struct Student));
    student->id = id;
    strcpy(student->name, name);
    student->marks = marks;
    return student;
}

/* void display(struct Student* student) {
    printf("Id is: %d\n", student->id);
    printf("Name is: %s\n", student->name);
    printf("Marks are: %.2f\n", student->marks);
} */

int main() {
    struct Student* student1 = createStudent(1, "John", 90.5);
    /* display(student1);
    free(student1); */
    return 0;
}