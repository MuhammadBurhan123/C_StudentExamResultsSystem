#include <stdio.h>

// Define a structure named Student
struct Student {
    char name[50];
    int rollNumber;
    int age;
    float marks[3];
    char grade;
};

// Declare an array of 25 Student structures
struct Student students[25];

// Function to load student information from "results.txt"
void loadResults() {
    FILE *file = fopen("results.txt", "r");
    if (file == NULL) {
        printf("File not found or unable to open.\n");
        return;
    }

    for (int i = 0; i < 25; i++) {
        fscanf(file, "%s %d %d %f %f %f", students[i].name, &students[i].rollNumber, &students[i].age,
               &students[i].marks[0], &students[i].marks[1], &students[i].marks[2]);

        // Calculate grade based on marks
        float average = (students[i].marks[0] + students[i].marks[1] + students[i].marks[2]) / 3.0;
        students[i].grade = (average >= 70) ? 'A' : (average >= 60) ? 'B' : 'C';
    }

    fclose(file);
}

// Function to save student information to "results.txt"
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

// Function to input details for each student and save to "results.txt"
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

        // Calculate grade based on marks
        float average = (students[i].marks[0] + students[i].marks[1] + students[i].marks[2]) / 3.0;
        students[i].grade = (average >= 70) ? 'A' : (average >= 60) ? 'B' : 'C';
    }

    saveResults(); // Save to file after inputting data
}

// Function to display results
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
    // Example usage
    loadResults();
    displayResults();

    // Input new data
    inputStudentData();

    // Display updated results
    displayResults();

    return 0;
}
