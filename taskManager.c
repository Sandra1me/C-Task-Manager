/*
    Simple Task Manager
    ----------------------
    A beginner-friendly command-line Task Manager written in C. You can create tasks with a name, description, date, and priority, and manage them by marking them as completed or deleting them.

    Author: [Sandra Martin Elias]
    Date: [2025/08/26]
*/

#include <stdio.h>

// Define the structure for a task, including name, description, due date, priority, and status
struct taskManager{
    char name[100];
    char description[300];
    char date[20];
    int priority;
    int status; // 0 = pending, 1 = completed
};

int main() {
    // numTasks tracks the current number of tasks
    // maxTasks is the maximum number of tasks allowed
    // choice stores the user's menu selection
    // Index is used when modifying or deleting a task
    // found is a flag used for checking if any matching tasks exist
    int numTasks=0, maxTasks=30, choice, Index, found=0;
    struct taskManager tasks[maxTasks]; // Array of taskManager structs to store the tasks

    while(1) {
        // Display the main menu and get user input
        printf("----- Task Manager Menu -----\n");
        printf("1. Show all Tasks\n");
        printf("2. Show Pending Tasks\n");
        printf("3. Show Completed Tasks\n");
        printf("4. Add Task\n");
        printf("5. Delete Task\n");
        printf("6. Complete Task\n");
        printf("7. Exit\n");
        printf("Choose an option: ");
        scanf("%i", &choice);
        getchar(); // Clear newline character left in the input buffer

        switch (choice)
        {
        case 1: // Show all tasks
            if (numTasks == 0) {
                printf("No tasks available.\n");
            } else {
                for (int i = 0; i < numTasks; i++) {
                    printf("Task %d:\n", i + 1);
                    printf("Name: %s\n", tasks[i].name);
                    printf("Description: %s\n", tasks[i].description);
                    printf("Date: %s\n", tasks[i].date);
                    printf("Priority: %d\n", tasks[i].priority);
                    printf("Status: %s\n", tasks[i].status == 0 ? "Pending" : "Completed");
                    printf("-----------------------\n");
                }
            }
            break;
        case 2: // Show only pending tasks
            if (numTasks == 0) {
                printf("No tasks available.\n");
            } else {
                found = 0;
                for (int i = 0; i < numTasks; i++) {
                    if (tasks[i].status == 0) {
                        found = 1;
                        printf("Task %d:\n", i + 1);
                        printf("Name: %s\n", tasks[i].name);
                        printf("Description: %s\n", tasks[i].description);
                        printf("Date: %s\n", tasks[i].date);
                        printf("Priority: %d\n", tasks[i].priority);
                        printf("-----------------------\n");
                    }
                }
                if (found==0) {
                    printf("No pending tasks.\n");
                }
            }
            break;
        case 3:   // Show only completed tasks
            if (numTasks == 0) {
                printf("No tasks available.\n");
            } else {
                found = 0;
                for (int i = 0; i < numTasks; i++) {
                    if (tasks[i].status == 1) {
                        found = 1;
                        printf("Task %d:\n", i + 1);
                        printf("Name: %s\n", tasks[i].name);
                        printf("Description: %s\n", tasks[i].description);
                        printf("Date: %s\n", tasks[i].date);
                        printf("Priority: %d\n", tasks[i].priority);
                        printf("-----------------------\n");
                    }
                }
                if (found==0) {
                    printf("No completed tasks.\n");
                }
            }
            break;
        case 4:  // Add a new task to the list
            if (numTasks>=maxTasks) {
                printf("Task list is full!\n");
                break;
            } else {
                printf("Enter task name: ");
                scanf(" %[^\n]", tasks[numTasks].name);
                getchar(); // Clear newline character left in the input buffer
                printf("Enter task description: ");
                scanf(" %[^\n]", tasks[numTasks].description);
                getchar(); // Clear newline character left in the input buffer 
                printf("Enter task date (YYYY-MM-DD): ");
                scanf(" %[^\n]", tasks[numTasks].date);
                getchar(); // Clear newline character left in the input buffer
                printf("Enter task priority (1-5): ");
                scanf("%i", &tasks[numTasks].priority);
                getchar(); // Clear newline character left in the input buffer
                tasks[numTasks].status = 0; // When adding a task, it's marked as pending by default
                numTasks++;
                printf("Task added successfully!\n");
            }
            break;
        case 5:   // Delete a task by its number
            if (numTasks == 0) {
                printf("No tasks to delete.\n");
            } else {
                printf("Enter task number to delete (1-%d): ", numTasks);
                scanf("%i", &Index);
                getchar(); // Clear newline character left in the input buffer

                if (Index < 1 || Index > numTasks) {
                    printf("Invalid task number.\n");
                } else {
                    // Shift all tasks after the deleted one one position to the left
                    for (int i = Index - 1; i < numTasks - 1; i++) {
                        tasks[i] = tasks[i + 1];
                    }
                    numTasks--;
                    printf("Task deleted successfully!\n");
                }
            }
            break;
        case 6:  // Mark a task as completed
            if (numTasks == 0) {
                printf("No tasks to complete.\n");
            } else {
                printf("Enter task number to complete (1-%d): ", numTasks);
                scanf("%i", &Index);
                getchar(); // Clear newline character left in the input buffer

                if (Index < 1 || Index > numTasks) {
                    printf("Invalid task number.\n");
                } else {
                    tasks[Index - 1].status = 1;
                    printf("Task marked as completed!\n");
                }
            }
            break;
        case 7:  // Exit the program
            printf("Exiting Task Manager.\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }

    return 0;
}