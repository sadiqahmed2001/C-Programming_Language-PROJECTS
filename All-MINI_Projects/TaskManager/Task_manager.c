#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_TASK_LENGTH 50

struct Task {
    char description[MAX_TASK_LENGTH];
    int completed;
};

struct Task tasks[MAX_TASKS];
int taskCount = 0;

void addTask(const char *description) {
    if (taskCount < MAX_TASKS) {
        strcpy(tasks[taskCount].description, description);
        tasks[taskCount].completed = 0;
        taskCount++;
        printf("Task added successfully.\n");
    } else {
        printf("Task list is full. Cannot add more tasks.\n");
    }
}

void markCompleted(int index) {
    if (index >= 0 && index < taskCount) {
        tasks[index].completed = 1;
        printf("Task marked as completed.\n");
    } else {
        printf("Invalid task index.\n");
    }
}

void listTasks() {
    printf("Tasks:\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d. [%s] %s\n", i + 1, tasks[i].completed ? "X" : " ", tasks[i].description);
    }
}

void removeTask(int index) {
    if (index >= 0 && index < taskCount) {
        for (int i = index; i < taskCount - 1; i++) {
            strcpy(tasks[i].description, tasks[i + 1].description);
            tasks[i].completed = tasks[i + 1].completed;
        }
        taskCount--;
        printf("Task removed successfully.\n");
    } else {
        printf("Invalid task index.\n");
    }
}

int main() {
    int choice, index;
    char description[MAX_TASK_LENGTH];

    while (1) {
        printf("\nTask Manager\n");
        printf("1. Add Task\n");
        printf("2. Mark Task as Completed\n");
        printf("3. List Tasks\n");
        printf("4. Remove Task\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter task description: ");
                scanf(" %[^\n]s", description);
                addTask(description);
                break;
            case 2:
                printf("Enter task index to mark as completed: ");
                scanf("%d", &index);
                markCompleted(index - 1);
                break;
            case 3:
                listTasks();
                break;
            case 4:
                printf("Enter task index to remove: ");
                scanf("%d", &index);
                removeTask(index - 1);
                break;
            case 5:
                printf("Exiting Task Manager.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
