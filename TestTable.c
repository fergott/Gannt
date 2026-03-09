#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "TestTable.h"

#include <stdlib.h>

void clearScreen(void) {
    // this function uses system commands to clear the screen as outlined in brief
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void PrintTable(inputs *data)
{
    const char *months[12] = {
        "Jeb", "Feb", "March", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };

    printf("\n%-20s", "Task"); //the "%-20" allows for there to be buffer room so the table is uniform
    for (int i = 0; i < 12; i++) // for loop that prints the headers/titles
    {
        printf("| %3s ", months[i]);
    }
    printf("| Dep\n");

    for (int i = 0; i < 100; i++) {
        printf("-"); //formatting
    }
    printf("\n");

    for (int i = 0; i < data->taskAmount; i++) {
        printf("%-20s", data->taskName[i]); // the "%-20" is most useful here where the length of task names is diferent

        for (int month = 1; month <= 12; month++) {
            if (month >= data->startMonth[i] && month <= data->endMonth[i]) {
                printf("| %-3s ", "XXX");
            } else {
                printf("| %-3s ", "");
            }
        }

        printf("| ");

        if (data->depCount[i] == 0) {
            printf("None");
        } else {
            for (int j = 0; j < data->depCount[i]; j++) {
                printf("%d", data->dependencies[i][j]);
                if (j < data->depCount[i] - 1) {
                    printf(" ");
                }
            }
        }

        printf("\n");
    }

    printf("\n");
}


//function to read the inputs into the struct
void readInputs(inputs *data)
{

    printf("how many tasks would you like to add?(1-10)");
    scanf("%d", &data->taskAmount);

    while (data->taskAmount < 1 || data->taskAmount > MAX_TASKS) {
        printf("Task amount must be between 1 and 10\n");
        printf("How many tasks would you like to add?: ");
        scanf("%d", &data->taskAmount);
    }

    for (int i = 0; i < data->taskAmount; i++) {
        printf("Task %d name (UNDERSCORES!!): ", i+1); //using underscores allows us to use the scanf function rather than fgets or something
        scanf("%99s", data->taskName[i]);

        printf("Start month(1-12): ");
        scanf("%d", &data->startMonth[i]);
        while (data->startMonth[i] < 1 || data->startMonth[i] > 12) {
            printf("Month must be between 1 and 12: ");
            scanf("%d", &data->startMonth[i]);
        }

        printf("End month(1-12)");
        scanf("%d", &data->endMonth[i]);
        while (data->endMonth[i] < data->startMonth[i] || data->endMonth[i] > 12) {
            printf("invalid month. Try again: ");
            scanf("%d", &data->endMonth[i]);
        }

        printf("how many dependencies for this task?: ");
        scanf("%d", &data->depCount[i]);

        if (data->depCount[i] < 0) data->depCount[i] = 0; //cant have negative dependencies
        if (data->depCount[i] > MAX_DEPS) data->depCount[i] = MAX_DEPS; // cant have more dependencies than tasks

        for (int j=0; j < data->depCount[i]; j++) {
            printf("Enter dependecy %d(Task number): ", j+1);
            scanf("%d", &data->dependencies[i][j]);

            while (data->dependencies[i][j] < 1 || data->dependencies[i][j] > data->taskAmount) {
                printf("Invalid task number. Enter again: ");
                scanf("%d", &data->dependencies[i][j]);
            }
        }
    }

}
// check for dependencies by using DFS
int depCheck(inputs *data, int task, int visited[], int stack[])
{
    //if task have already been explored it exits the loop
    if (stack[task])
    {
        return 1;
    }
    //skips already explored notes
    if (visited[task])
    {
        return 0;
    }
    //marks the tasks that are now being explored
//tracks what already been explored
    stack[task] = 1;
    // tracks tasks currently in the recursion path
    visited[task] = 1;
//loop through dependencies
    for (int i=0; i<data->depCount[task]; i++)
    {
        //-1 used because user enters tasks starting at 1, but array starts at 0
        int dep = data->dependencies[task][i]-1;
//explore dependency task, continues until a cycle is found and all paths are finished
        if (dep >= 0 && dep < data->taskAmount) {
            if (depCheck(data, dep, visited, stack)) {
                return 1;
            }
        }

    }
    //remove from recursion stack and return 0
    stack[task] = 0;
    return 0;
}
//check for dependencies by calling depCheck
int circDependency(inputs *data)
{
    int visited[MAX_TASKS]={0};
    int stack[MAX_TASKS]={0};
// starts DFS from each task and follows its dependencies, if encounters
// a task that already in the stack- a cycle exits
    for (int i=0;i < data->taskAmount; i++) {
        if (depCheck(data, i, visited, stack)) {
            return 1;
        }
    }
    return 0;
}
//function to turn dependency path by printing dependencies until visited[task]
void printDependencies(inputs *data, int task, int visited[])
{
    if (visited[task])
        return;

    visited[task] = 1;

    printf("%d", task + 1);

    for (int i = 0; i < data->depCount[task]; i++)
    {
        int dep = data->dependencies[task][i] - 1;

        if (dep >= 0 && dep < data->taskAmount)
        {
            printf(" -> %d", dep + 1);
            printDependencies(data, dep, visited);
        }
    }
}

// function to turn the input into lowercase to make program less case sensitive
void toLower(char string[MAX_LEN])
{
    for (int i = 0; string[i] != '\0'; i++)
    {
        string[i] = (char)tolower((unsigned char) string[i]);
    }
}

// this allows us to print the test gantt chart with preloaded data
void loadTestData(inputs *data)
{
    data->taskAmount = 10;

    // Task Names copied from the enum
    strcpy(data->taskName[BOOK_VENUE - 1], "Book Venue");
    strcpy(data->taskName[HIRE_PERFORMERS - 1], "Hire Performers");
    strcpy(data->taskName[ORDER_SOUND - 1], "Order Sound & Lighting");
    strcpy(data->taskName[MARKETING - 1], "Marketing");
    strcpy(data->taskName[TICKET_SALES - 1], "Ticket Sales");
    strcpy(data->taskName[HIRE_SECURITY - 1], "Hire Security");
    strcpy(data->taskName[EQUIPMENT_DELIVERY - 1], "Equipment Delivery");
    strcpy(data->taskName[SETUP_STAGE - 1], "Setup Stage");
    strcpy(data->taskName[REHEARSAL - 1], "Rehearsal");
    strcpy(data->taskName[EVENT_DAY - 1], "Event Day");

    // Initialize dependency counts
    for (int i = 0; i < MAX_TASKS; i++)
    {
        data->depCount[i] = 0;
    }

    // Dependencies

    // Hire Performers depends on Book Venue
    data->dependencies[HIRE_PERFORMERS - 1][0] = BOOK_VENUE;
    data->depCount[HIRE_PERFORMERS - 1] = 1;
    data->startMonth[HIRE_PERFORMERS - 1] = 2;
    data->endMonth[HIRE_PERFORMERS - 1] = 4;


    // Order Sound depends on Book Venue and Hire Performers
    data->dependencies[ORDER_SOUND - 1][0] = BOOK_VENUE;
    data->dependencies[ORDER_SOUND - 1][1] = HIRE_PERFORMERS;

    data->depCount[ORDER_SOUND - 1] = 2;

    // Marketing depends on Book Venue
    data->dependencies[MARKETING - 1][0] = BOOK_VENUE;
    data->depCount[MARKETING - 1] = 1;

    // Ticket Sales depends on Marketing
    data->dependencies[TICKET_SALES - 1][0] = MARKETING;
    data->depCount[TICKET_SALES - 1] = 1;

    // Hire Security depends on Book Venue
    data->dependencies[HIRE_SECURITY - 1][0] = BOOK_VENUE;
    data->depCount[HIRE_SECURITY - 1] = 1;

    // Equipment Delivery depends on Order Sound
    data->dependencies[EQUIPMENT_DELIVERY - 1][0] = ORDER_SOUND;
    data->depCount[EQUIPMENT_DELIVERY - 1] = 1;

    // Setup Stage depends on Equipment Delivery
    data->dependencies[SETUP_STAGE - 1][0] = EQUIPMENT_DELIVERY;
    data->depCount[SETUP_STAGE - 1] = 1;

    // Rehearsal depends on Setup Stage
    data->dependencies[REHEARSAL - 1][0] = SETUP_STAGE;
    data->depCount[REHEARSAL - 1] = 1;

    // Event Day depends on Rehearsaldata->startMonth[BOOK_VENUE - 1] = 1;
    data->endMonth[BOOK_VENUE - 1] = 2;

    data->startMonth[HIRE_PERFORMERS - 1] = 2;
    data->endMonth[HIRE_PERFORMERS - 1] = 4;
    data->dependencies[EVENT_DAY - 1][0] = REHEARSAL;
    data->depCount[EVENT_DAY - 1] = 1;

    //start and end month
    data->startMonth[BOOK_VENUE - 1] = 1;
    data->endMonth[BOOK_VENUE - 1] = 2;

    data->startMonth[HIRE_PERFORMERS - 1] = 2;
    data->endMonth[HIRE_PERFORMERS - 1] = 4;

    data->startMonth[ORDER_SOUND - 1] = 3;
    data->endMonth[ORDER_SOUND - 1] = 4;

    data->startMonth[MARKETING - 1] = 4;
    data->endMonth[MARKETING - 1] = 8;

    data->startMonth[TICKET_SALES - 1] = 4;
    data->endMonth[TICKET_SALES - 1] = 10;

    data->startMonth[HIRE_SECURITY - 1] = 8;
    data->endMonth[HIRE_SECURITY - 1] = 9;

    data->startMonth[EQUIPMENT_DELIVERY - 1] = 4;
    data->endMonth[EQUIPMENT_DELIVERY - 1] = 4;

    data->startMonth[SETUP_STAGE - 1] = 10;
    data->endMonth[SETUP_STAGE - 1] = 11;
    data->startMonth[REHEARSAL - 1] = 11;
    data->endMonth[REHEARSAL - 1] = 12;

}



//allows user to edit tasks already added to the struct
void editTask(inputs *data) {
    char target[MAX_LEN];
    int found = 0;// binary value to see if the task the user wants to change is actually in the struct already

    printf("Enter the task name you want to edit exactly: ");
    scanf("%99s", target);

    for (int i = 0;i < data->taskAmount; i++) {
        if (strcmp(target, data->taskName[i]) == 0) {
            found = 1;

            printf("Enter new task name (or same one): ");
            scanf("%99s", data->taskName[i]);

            printf("New start month (1 -12): ");
            scanf("%d", &data->startMonth[i]);
            while (data->startMonth[i] < 1 || data->startMonth[i] > 12) {
                printf("Invalid month. Month must be between 1 and 12: ");
                scanf("%d", &data->startMonth[i]);
            }

            printf("New end month (1 -12): ");
            scanf("%d", &data->endMonth[i]);
            while (data->endMonth[i] < data->startMonth[i] || data->endMonth[i] > 12) {
                printf("Invalid month. Month must be between 1 and 12: ");
                scanf("%d", &data->endMonth[i]);
            }

            printf("How many dependencies does this task have?: ");
            scanf("%d", &data->depCount[i]);

            if (data->depCount[i] < 0) data->depCount[i] = 0; //can't be negative
            if (data->depCount[i] > MAX_DEPS) data->depCount[i] = MAX_DEPS; // cant be greater than number of tasks

            for (int j = 0; j < data->depCount[i]; j++) {
                printf("Enter dependency %d(Task number): ", j+1);
                scanf("%d", &data->dependencies[i][j]);
            }
            printf("Task updated successfully");
            return;
        }
    }

    if (!found) {
        printf("Task does not exist.\n");
    }
}
