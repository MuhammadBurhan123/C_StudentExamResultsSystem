#include <stdio.h>

struct Student {
    char name[50];
    int rollNumber;
    int age;
    float marks[3];
    char grade;
};

struct Student students[25];

void loadResults() {
    FILE *file = fopen("results.txt", "r");
    if (file == NULL) {
        printf("File not found or unable to open.\n");
        return;
    }

    for (int i = 0; i < 25; i++) {
        fscanf(file, "%s %d %d %f %f %f", students[i].name, &students[i].rollNumber, &students[i].age,
               &students[i].marks[0], &students[i].marks[1], &students[i].marks[2]);

        float average = (students[i].marks[0] + students[i].marks[1] + students[i].marks[2]) / 3.0;
        students[i].grade = (average >= 70) ? 'A' : (average >= 60) ? 'B' : 'C';
    }

    fclose(file);
}

void saveResults() {
    FILE *file = fopen("results.txt", "w");
    if (file == NULL) {
        printf("Unable to create or open file for writing.\n");
        return;
    }

    for (int i = 0; i < 25; i++) {
        fprintf(file, "%s %d %d %.2f %.2f %.2f\n", students[i].name, students[i].rollNumber,
                students[i].age, students[i].marks[0], students[i].marks[1], students[i].marks[2]);
    }

    fclose(file);
}

void inputStudentData() {
    for (int i = 0; i < 25; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]s", students[i].name);
        printf("Roll Number: ");
        scanf("%d", &students[i].rollNumber);
        printf("Age: ");
        scanf("%d", &students[i].age);
        printf("Marks for three subjects: ");
        scanf("%f %f %f", &students[i].marks[0], &students[i].marks[1], &students[i].marks[2]);

        float average = (students[i].marks[0] + students[i].marks[1] + students[i].marks[2]) / 3.0;
        students[i].grade = (average >= 70) ? 'A' : (average >= 60) ? 'B' : 'C';
    }

    saveResults();
}

void displayResults() {
    for (int i = 0; i < 25; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Roll Number: %d\n", students[i].rollNumber);
        printf("Age: %d\n", students[i].age);
        printf("Marks: %.2f %.2f %.2f\n", students[i].marks[0], students[i].marks[1], students[i].marks[2]);
        printf("Grade: %c\n", students[i].grade);
        printf("\n");
    }
}

int main() {
    loadResults();
    displayResults();

    inputStudentData();

    displayResults();

    return 0;
}
