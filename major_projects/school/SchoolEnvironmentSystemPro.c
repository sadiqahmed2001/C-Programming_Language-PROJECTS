#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_ID_LENGTH 20
#define MAX_ADDRESS_LENGTH 100
#define MAX_STUDENTS 100
#define MAX_TEACHERS 50
#define MAX_STAFF 50

// Structure for storing student information
struct Student {
    char name[MAX_NAME_LENGTH];
    char id[MAX_ID_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    float cgpa;
    int attendance;
};

// Structure for storing teacher information
struct Teacher {
    char name[MAX_NAME_LENGTH];
    char id[MAX_ID_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    int experienceYears;
};

// Structure for storing staff information
struct Staff {
    char name[MAX_NAME_LENGTH];
    char id[MAX_ID_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    char department[MAX_NAME_LENGTH];
};

// Function to add a new student record
void addStudent(struct Student students[], int *numStudents) {
    if (*numStudents >= MAX_STUDENTS) {
        printf("Maximum number of students reached.\n");
        return;
    }

    printf("Enter student name: ");
    scanf("%s", students[*numStudents].name);
    printf("Enter student ID: ");
    scanf("%s", students[*numStudents].id);
    printf("Enter student address: ");
    scanf("%s", students[*numStudents].address);
    printf("Enter student CGPA: ");
    scanf("%f", &students[*numStudents].cgpa);
    printf("Enter student attendance: ");
    scanf("%d", &students[*numStudents].attendance);

    (*numStudents)++;
}

// Function to add a new teacher record
void addTeacher(struct Teacher teachers[], int *numTeachers) {
    if (*numTeachers >= MAX_TEACHERS) {
        printf("Maximum number of teachers reached.\n");
        return;
    }

    printf("Enter teacher name: ");
    scanf("%s", teachers[*numTeachers].name);
    printf("Enter teacher ID: ");
    scanf("%s", teachers[*numTeachers].id);
    printf("Enter teacher address: ");
    scanf("%s", teachers[*numTeachers].address);
    printf("Enter teacher experience (in years): ");
    scanf("%d", &teachers[*numTeachers].experienceYears);

    (*numTeachers)++;
}

// Function to add a new staff record
void addStaff(struct Staff staff[], int *numStaff) {
    if (*numStaff >= MAX_STAFF) {
        printf("Maximum number of staff reached.\n");
        return;
    }

    printf("Enter staff name: ");
    scanf("%s", staff[*numStaff].name);
    printf("Enter staff ID: ");
    scanf("%s", staff[*numStaff].id);
    printf("Enter staff address: ");
    scanf("%s", staff[*numStaff].address);
    printf("Enter staff department: ");
    scanf("%s", staff[*numStaff].department);
    (*numStaff)++;

}

// Function to display menu options
void displayMenu() {
    printf("\n*********WELCOME-TO-SMART_SCHOOL_FROM_PARALLEL_UNIVERSE************ ");
    printf("\n#School_Database: \n");
    printf("1. Add Student\n");
    printf("2. Add Teacher\n");
    printf("3. Add Staff\n");
    printf("4. views\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}




int main() {
    struct Student students[MAX_STUDENTS];
    struct Teacher teachers[MAX_TEACHERS];
    struct Staff staff[MAX_STAFF];
    int numStudents = 0;
    int numTeachers = 0;
    int numStaff = 0;
    int choice;


    void DisplayStudent(struct Student students[],int numStudents){
    // Print the entered details
    for (int i = 0; i < numStudents; i++){
    printf("Student Added:\n");
    printf("Name: %s\n", students[i].name);
    printf("ID: %s\n", students[i].id);
    printf("Address: %s\n", students[i].address);
    printf("CGPA: %.2f\n", students[i].cgpa);
    printf("Attendance: %d\n", students[i].attendance);}
    }



    void DisplayTeacher(struct Teacher teachers[], int numTeachers){
    // Print the entered  details
    for(int i=0;i< numTeachers;i++){
    printf("Teacher Added:\n");
    printf("Name: %s\n", teachers[i].name);
    printf("ID: %s\n", teachers[i].id);
    printf("Address: %s\n", teachers[i].address);
    printf("Experience (in years): %d\n", teachers[i].experienceYears);}

    }
    void DisplayStaff(struct Staff staff[], int numStaff){
    // Print the entered details
    for(int i=0;i< numStaff; i++){
    printf("Staff Added:\n");
    printf("Name: %s\n", staff[i].name);
    printf("ID: %s\n", staff[i].id);
    printf("Address: %s\n", staff[i].address);
    printf("Department: %s\n", staff[i].department);}
    }

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &numStudents);
                break;
            case 2:
                addTeacher(teachers, &numTeachers);
                break;
            case 3:
                addStaff(staff, &numStaff);
                break;
            case 4:
            printf("#### All Updated Details Is Here: ####");
                DisplayStudent(students,numStudents);
                DisplayTeacher(teachers,numTeachers);
                DisplayStaff(staff, numStaff);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}